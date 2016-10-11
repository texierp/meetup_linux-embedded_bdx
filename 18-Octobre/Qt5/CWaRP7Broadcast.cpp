#include "CWaRP7Broadcast.h"
#include "QFile"

WaRP7Broadcast::WaRP7Broadcast(QObject *parent) :
    QObject(parent),
    m_res(false)
{
    m_socket = new QUdpSocket(this);

    m_socket->bind(QHostAddress::Broadcast, BROADCAST_PORT);

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(decode()));
}

void WaRP7Broadcast::decode()
{
    QByteArray payload;

    while ( m_socket->hasPendingDatagrams() )
    {
        QByteArray buffer;
        buffer.resize(m_socket->pendingDatagramSize());

        QHostAddress sender;
        quint16 sender_port;

        m_res = m_socket->readDatagram(buffer.data(),buffer.size(), &sender, &sender_port);

        qDebug() << "Message from " << sender << " port " << sender_port;
        qDebug() << "Msg: " << buffer;

        if(QString(buffer).compare("Request") == 0)
        {
            m_rawTemp = readValueFromFile("/sys/bus/iio/devices/iio\:device0/in_temp_raw");
            m_scaleTemp = readValueFromFile("/sys/bus/iio/devices/iio\:device0/in_temp_scale");
            m_temperature = m_rawTemp.toInt() * m_scaleTemp.toFloat();

            payload.append(QString::number(m_temperature));
        }

        // Broadcast buffer to HOST
        m_socket->writeDatagram(payload, sender, BROADCAST_PORT);
    }
}

QByteArray WaRP7Broadcast::readValueFromFile(QString filePath)
{
    QByteArray data;

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        data = file.readAll();
        data.remove(data.length() - 1, 1);
        file.close();
    }

    return data;
}


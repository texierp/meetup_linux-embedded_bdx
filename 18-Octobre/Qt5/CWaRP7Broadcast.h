#ifndef CWARP7BROADCAST_H
#define CWARP7BROADCAST_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>
#include <QString>
#include <QNetworkInterface>

#define BROADCAST_PORT 14250

class WaRP7Broadcast : public QObject
{
    Q_OBJECT

public:
    explicit WaRP7Broadcast(QObject *parent = 0);

signals:

public slots:
    void decode();

private:
    QUdpSocket *m_socket;
    bool m_res;
    QByteArray m_rawTemp;
    QByteArray m_scaleTemp;
    float m_temperature;

protected:

    QByteArray readValueFromFile(QString filePath);

};

#endif // CWARP7BROADCAST_H

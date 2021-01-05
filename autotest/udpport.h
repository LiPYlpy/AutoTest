#ifndef UDPPORT_H
#define UDPPORT_H

#include <QObject>
#include <QThread>
#include <QUdpSocket>
#include <QtNetwork>

class UDPPort : public QObject
{
    Q_OBJECT
public:
    explicit UDPPort(QObject *parent = nullptr);
    ~UDPPort();

    void GetLocalIP();

    //SLOT
    void SetPara(quint16 thisP, quint16 targetP, QString tarIP);

    void SetUdpAbort();

    void GetData();

    void WriteData(QByteArray byteArray);

signals:

    void ReceiveData(QByteArray recvdata);

private:
    QUdpSocket * udpSocket;
    quint16 thisPort;
    quint16 targetPort;
    QHostAddress thisIP;
    QHostAddress targetIP;

};










class UDPController : public QObject
{
    Q_OBJECT
    QThread * udpThread;
public:
    UDPController();
    ~UDPController();



    //SLOT

    void RecvUDPPara(quint16 thisPort, quint16 targetPort, QString targetIP);

    void RecvAbort();

    void SaveData(QByteArray byteArray);

    void GetWriteData(QByteArray byteArray);


signals:

    void SetUDPPara(quint16 thisPort, quint16 targetPort, QString targetIP);

    void SetUdpAbort();

    void SendUdpData(QByteArray byteArray);

    void WriteData(QByteArray byteArray);

private:
    UDPPort * myUDPPort;
};

#endif // UDPPORT_H

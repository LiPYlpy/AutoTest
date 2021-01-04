#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QThread>
#include <QMutex>


class SerialPort : public QObject
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = nullptr);
    ~SerialPort();
    void InitPort();

    //SLOT
    void GetSerialPara(QString portName, int baudRate,int dataBits,int stopBits, int parity);

    void GetData();

    void WriteData(QByteArray byteArray);

signals:
    //接受数据
    void ReceiveData(QByteArray buffer);

    //传递串口名
    void GetPortName(QStringList portName);

private:
    QSerialPort * serialPort;
    QMutex serialMutex;
};

class SerialController : public QObject
{
    Q_OBJECT
    QThread * serialThread;
public:
    SerialController();
    ~SerialController();

    //SLOT

    void GetSerialPara(QString portName, int baudRate,int dataBits,int stopBits, int parity);

    void GetWriteData(QByteArray byteArray);

    void SaveData(QByteArray byteArray);

    void startThread();

    void stopThread();



signals:

    void SetSerialPara(QString portName, int baudRate,int dataBits,int stopBits, int parity);

    void WriteData(QByteArray byteArray);

    void SendSerialData(QByteArray byteArray);

private:
    QMutex scMutex;
    SerialPort * mySerialPort;
    bool state;
};

#endif // SERIALPORT_H

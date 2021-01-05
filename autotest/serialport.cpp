#include "serialport.h"

SerialPort::SerialPort(QObject *parent) : QObject(parent)
{

}

SerialPort::~SerialPort()
{
    qDebug()<<"析构 SerialPort";
    serialPort->close();
    delete serialPort;
}

//初始化串口，建立串口接收信号槽连接
void SerialPort::InitPort()
{
    connect(serialPort,&QSerialPort::readyRead,this,&SerialPort::GetData,Qt::QueuedConnection);
}

//设置串口参数
void SerialPort::GetSerialPara(QString portName, int baudRate, int dataBits, int stopBits, int parity)
{
    serialPort = new QSerialPort(this);
    serialPort->setPortName(portName); //端口号
    qDebug()<<portName;
    serialPort->setBaudRate(baudRate); //波特率
    switch(dataBits)  {   //数据位数
    case 0: serialPort->setDataBits(QSerialPort::Data5);break;
    case 1: serialPort->setDataBits(QSerialPort::Data6);break;
    case 2: serialPort->setDataBits(QSerialPort::Data7);break;
    case 3: serialPort->setDataBits(QSerialPort::Data8);break;
    default:break;
    }
    switch (stopBits) {   //停止位
    case 0:serialPort->setStopBits(QSerialPort::OneStop);break;
    case 2:serialPort->setStopBits(QSerialPort::TwoStop);break;
    default:break;
    }
    switch (parity) {   //有无奇偶校验
    case 0:serialPort->setParity(QSerialPort::NoParity);break;
    case 1:serialPort->setParity(QSerialPort::OddParity);break;
    case 2:serialPort->setParity(QSerialPort::EvenParity);break;
    default:break;
    }
    //流控制
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    //串口缓冲区大小
    serialPort->setReadBufferSize(4000);
    if (serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "Port have been opened";
    }
    else
    {
        qDebug() << "open it failed";
    }
    InitPort();
}

//串口收到数据
void SerialPort::GetData()
{
    QByteArray recvData = serialPort->readAll();
    qDebug() << "handing thread is:" << QThread::currentThreadId();
    emit ReceiveData(recvData);
}

//通过串口发送数据
void SerialPort::WriteData(QByteArray byteArray)
{
    qDebug() << "write_id is:" << QThread::currentThreadId();
    qDebug()<< "data sent(发送的数据)：" << byteArray;
    serialPort->write(byteArray);
}

//串口线程控制器
SerialController::SerialController()
{
    mySerialPort = new SerialPort;
    serialThread = new QThread();
    mySerialPort->moveToThread(serialThread);
    state = true;

    //接收串口设置
    connect(this,&SerialController::SetSerialPara,mySerialPort,&SerialPort::GetSerialPara);
    //接收串口读取的数据
    connect(mySerialPort,&SerialPort::ReceiveData,this,&SerialController::SaveData);
    //发送指令
    connect(this,&SerialController::WriteData,mySerialPort,&SerialPort::WriteData);

    //开启线程
    serialThread->start();
}

SerialController::~SerialController()
{
    //关闭线程
    serialThread->requestInterruption();
    serialThread->quit();
    serialThread->wait();
    mySerialPort->deleteLater();
    serialThread->deleteLater();

    qDebug()<<"析构 SerialController";
}

void SerialController::GetSerialPara(QString portName, int baudRate, int dataBits, int stopBits, int parity)
{
    emit SetSerialPara(portName, baudRate, dataBits, stopBits, parity);
}

void SerialController::GetWriteData(QByteArray byteArray)
{
    emit WriteData(byteArray);
}

void SerialController::SaveData(QByteArray byteArray)
{
    emit SendSerialData(byteArray);
}

//开启串口通信线程
void SerialController::startThread()
{
    if(!state)
    {
        mySerialPort->moveToThread(serialThread);
        serialThread->start();
        state = true;
    }
    QString msg = QString("%1 -> %2 threadid:[%3]")
                .arg(__FILE__)
                .arg(__FUNCTION__)
                .arg((int)QThread::currentThreadId());

    qDebug() << msg;
}

//关闭串口通信线程
void SerialController::stopThread()
{
    QString msg = QString("%1 -> %2 threadid:[%3]")
                .arg(__FILE__)
                .arg(__FUNCTION__)
                .arg((int)QThread::currentThreadId());
    qDebug()<<msg;

    qDebug()<<"Port have been closed";
    if(state)
    {
        serialThread->requestInterruption();
        serialThread->quit();
        serialThread->wait();
        state = false;
    }
}


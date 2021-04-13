#include "udpport.h"

//初始化UDP，建立UDP通信信号槽连接
UDPPort::UDPPort(QObject *parent) : QObject(parent)
{
//    udpSocket = new QUdpSocket;
//    connect(udpSocket,&QUdpSocket::readyRead,this,&UDPPort::GetData);
}

UDPPort::~UDPPort()
{
//    delete udpSocket;
    qDebug()<<"析构 UDPPort";
}

//获取本机的IP
void UDPPort::GetLocalIP()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);
    QString   localIP="";

    QList<QHostAddress> addList=hostInfo.addresses();

    if (!addList.isEmpty())
    for (int i=0;i<addList.count();i++)
    {
        QHostAddress aHost=addList.at(i);
        if (QAbstractSocket::IPv4Protocol==aHost.protocol())
        {
            localIP=aHost.toString();
            break;
        }
    }
    QHostAddress local(localIP);
    thisIP = localIP;//存本机IP
}

//设置UDP连接参数
void UDPPort::SetPara(quint16 thisP, quint16 targetP, QString tarIP)
{
//    udpSocket = new QUdpSocket;
    udpSocket = new QUdpSocket;
    connect(udpSocket,&QUdpSocket::readyRead,this,&UDPPort::GetData);
    GetLocalIP();
    thisPort = thisP; //本机端口号
    targetPort = targetP; //目标端口号
    QHostAddress targetAddr(tarIP); //目标IP
    targetIP = targetAddr;
    udpSocket->abort();
    udpSocket->bind(thisPort); //绑定本机端口
//    qDebug()<<thisIP;
}

//解绑端口
void UDPPort::SetUdpAbort()
{
    udpSocket->abort();
}

//UDP接收数据
void UDPPort::GetData()
{
    QByteArray datagram;
    datagram.resize(udpSocket->pendingDatagramSize());
    udpSocket->readDatagram(datagram.data(),datagram.size(),&targetIP,&targetPort);   //根据目标IP，端口号获取数据
    QByteArray recvData=datagram.data();
    emit ReceiveData(recvData);
}

//UDP发送数据
void UDPPort::WriteData(QByteArray byteArray)
{
//    qDebug()<<"UDP 发送"<<byteArray;
    udpSocket->writeDatagram(byteArray,targetIP,targetPort);
}






UDPController::UDPController()
{
    myUDPPort = new UDPPort;
    udpThread = new QThread();
    myUDPPort->moveToThread(udpThread);

    //推出线程
    connect(udpThread,&QThread::finished,myUDPPort,&QObject::deleteLater);

    connect(this,&UDPController::SetUDPPara,myUDPPort,&UDPPort::SetPara);

    connect(this,&UDPController::SetUdpAbort,myUDPPort,&UDPPort::SetUdpAbort);

    connect(myUDPPort,&UDPPort::ReceiveData,this,&UDPController::SaveData);

    connect(this,&UDPController::WriteData,myUDPPort,&UDPPort::WriteData);

    //开启端口
    udpThread->start();
}

UDPController::~UDPController()
{
    udpThread->quit();
    udpThread->wait();
}

void UDPController::RecvUDPPara(quint16 thisPort, quint16 targetPort, QString targetIP)
{
    emit SetUDPPara(thisPort, targetPort, targetIP);
}

void UDPController::RecvAbort()
{
    emit SetUdpAbort();
}

void UDPController::SaveData(QByteArray byteArray)
{
    emit SendUdpData(byteArray);
}

void UDPController::GetWriteData(QByteArray byteArray)
{
    emit WriteData(byteArray);
}

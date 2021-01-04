#include "serialform.h"
#include "ui_serialform.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include "serialport.h"
#include <QtNetwork>
#include <QQueue>

QQueue<QStringList> cQueue;


SerialForm::SerialForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialForm)
{
    ui->setupUi(this);
    //串口参数选项
    InitUI();
    //搜索串口
    connect(ui->searchButton,&QPushButton::clicked,this,&SerialForm::SearchPort);

    //串口线程控制器
    serialController = new SerialController();

    //打开串口
    connect(ui->openButton,&QPushButton::clicked,[=](){
        if(ui->openButton->text()==QString("打开串口")) {
            //开始线程
            emit openThread();
            //获取参数
            QString portName = ui->portNameBox->currentText();
            int baudRate=ui->baudrateBox->currentText().toInt();
            int dataBits=ui->dataBitsBox->currentIndex();
            int stopBits=ui->stopBitsBox->currentIndex();
            int parity=ui->ParityBox->currentIndex();
            //发送参数
            emit SerialPara(portName,baudRate,dataBits,stopBits,parity);
            //下拉菜单控件失能
            ui->portNameBox->setEnabled(false);
            ui->baudrateBox->setEnabled(false);
            ui->dataBitsBox->setEnabled(false);
            ui->ParityBox->setEnabled(false);
            ui->stopBitsBox->setEnabled(false);
            ui->searchButton->setEnabled(false);
            ui->openButton->setText(QString("关闭串口"));
            //发送按键使能
            ui->sendButton->setEnabled(true);
        }
        else{
            //关闭串口线程
            emit closeThread();
            //下拉菜单控件使能
            ui->portNameBox->setEnabled(true);
            ui->baudrateBox->setEnabled(true);
            ui->dataBitsBox->setEnabled(true);
            ui->ParityBox->setEnabled(true);
            ui->stopBitsBox->setEnabled(true);
            ui->searchButton->setEnabled(true);
            ui->openButton->setText(QString("打开串口"));
            //发送按键失能
            ui->sendButton->setEnabled(false);
        }
    });


    //设置开关（串口 or UDP）二选一
    ui->radioBtnSerial->setChecked(true);
    ui->radioBtnUDP->setChecked(false);
    ui->pushButton_server_bind->setEnabled(false);
    ui->pushButton_server_bind_stop->setEnabled(false);

    //选择串口，使UDP选项失效
    connect(ui->radioBtnSerial,&QRadioButton::clicked,[=](){
        serialState = true;
        UdpState = false;
        ui->pushButton_server_bind->setEnabled(false);
        ui->pushButton_server_bind_stop->setEnabled(false);
        ui->searchButton->setEnabled(true);
        ui->openButton->setEnabled(true);
    });

    //选择UDP，使串口失效
    connect(ui->radioBtnUDP,&QRadioButton::clicked,[=](){
        UdpState = true;
        serialState = false;
        ui->searchButton->setEnabled(false);
        ui->openButton->setEnabled(false);
        ui->pushButton_server_bind->setEnabled(true);
        ui->pushButton_server_bind_stop->setEnabled(true);
    });

    /*******************************************************************************/

    //UDP线程控制器
    udpController = new UDPController;

    //发送UDP参数
    connect(this,&SerialForm::SendUDPPara,udpController,&UDPController::RecvUDPPara);

    //绑定端口
    connect(ui->pushButton_server_bind,&QPushButton::clicked,[=](){
        quint16 thisPort=ui->spinBox_server_port->value();
        quint16 targetPort=ui->spinTargetPort->value();
        QString targetIP=ui->comboTargetIP->currentText();
        //发送UDP参数
        emit SendUDPPara(thisPort,targetPort,targetIP);
        ui->spinBox_server_port->setEnabled(false);
        ui->spinTargetPort->setEnabled(false);
        ui->comboTargetIP->setEnabled(false);
    });

    //设置UDP参数
    connect(this,&SerialForm::SetUdpAbort,udpController,&UDPController::RecvAbort);

    //端口解绑
    connect(ui->pushButton_server_bind_stop,&QPushButton::clicked,[=](){
        emit SetUdpAbort();
        ui->spinBox_server_port->setEnabled(true);
        ui->spinTargetPort->setEnabled(true);
        ui->comboTargetIP->setEnabled(true);
    });

    /*********************************************************************************/



    //串口线程的开闭
    connect(this,&SerialForm::openThread,serialController,&SerialController::startThread);

    connect(this,&SerialForm::closeThread,serialController,&SerialController::stopThread);

    //发送串口设置参数
    connect(this,&SerialForm::SerialPara,serialController,&SerialController::GetSerialPara);


    //发送信息
    connect(ui->sendButton,&QPushButton::clicked,[=](){
        QString str = ui->sendTextEdit->toPlainText();
        QByteArray byteArray = HexQString2QByteArray(str);
        if(serialState)//串口发送
            emit SendByteArray(byteArray);
        if(UdpState)//UDP发送
            emit SendByUdp(HexQString2QByteArray(str));
    });

    //清空接收框
    connect(ui->clearButton,&QPushButton::clicked,[=](){
        ui->recvTextEdit->clear();
    });


    //发送
    connect(this,&SerialForm::SendByteArray,serialController,&SerialController::GetWriteData);

    connect(this,&SerialForm::SendByUdp,udpController,&UDPController::GetWriteData);

    //接收
    connect(serialController,&SerialController::SendSerialData,this,&SerialForm::OnReceive);

    connect(udpController,&UDPController::SendUdpData,this,&SerialForm::OnReceive);


    //解帧
    dataController = new DataController();

    connect(this,&SerialForm::Send2DataAnalysis,dataController,&DataController::SaveData);
    //接收帧数据
    connect(dataController,&DataController::SendPacData,this,&SerialForm::RecvPacData);


    //数据解析
    pacController = new PacController();
    //发送数据包
    connect(this,&SerialForm::Send2PacAnalysis,pacController,&PacController::SavePacData);
    //设置检测命令
    connect(this,&SerialForm::SendStandardState,pacController,&PacController::GetStandardState);
    //返回检测间隔
    connect(pacController,&PacController::ReSendCommand,this,&SerialForm::DetectResult);

    connect(pacController,&PacController::DetectFailed,this,&SerialForm::DetectFailed);
    //检测结束
    connect(this,&SerialForm::CommandOver,pacController,&PacController::CommandOver);
    //收到解析
    connect(pacController,&PacController::SendExplainInfo,this,&SerialForm::RecvExplainInfo);



}

SerialForm::~SerialForm()
{
    delete udpController;
    delete dataController;
    delete pacController;
    delete serialController;
    delete ui;
    qDebug()<<"析构 SerialForm";
}

void SerialForm::OnReceive(QByteArray tmpdata)
{
    QString recv = QByteArray2QString(tmpdata);
    //接收原始数据，转发给解帧线程
//    ui->recvTextEdit->append(tmpdata);
    emit Send2DataAnalysis(tmpdata);
}

//收到数据源包
void SerialForm::RecvPacData(QByteArray byteArray)
{
    //显示数据源包
    ui->recvTextEdit->clear();
    ui->recvTextEdit->append(byteArray.toHex());
    //发送给包解析\检测函数
    emit Send2PacAnalysis(byteArray);
}


//从文件中读取指令，并按一定间隔批量发送。
void SerialForm::TxtRecv(QStringList lineStr)
{
    //将文件中的指令写入队列
    QStringList command;
    for(int i = 1;i<lineStr.size();i++)
    {
        if(lineStr.at(i)=="######")
        {
            cQueue.enqueue(command);
            command.clear();
            continue;
        }
        command<<lineStr.at(i);
    }
    cQueue.enqueue(command);
    SendCommand();
}


//收到检测结果，发送到显示模块
void SerialForm::DetectResult(QString command, QStringList resultList)
{
    emit Send2RCForm(command, resultList);
    SendCommand();
}


//发送检测指令
void SerialForm::SendCommand()
{
    if(!cQueue.isEmpty())
    {
        QStringList command = cQueue.dequeue();
        QString sendCommand = command.at(0);
        QByteArray sendT = HexQString2QByteArray(sendCommand);
        emit SendStandardState(command);
        if(serialState)
            emit SendByteArray(sendT);
        if(UdpState)
            emit SendByUdp(sendT);
    }
    else
    {
        emit CommandOver();
        QString command = " ";
        QStringList resultList;
        resultList<< "One";
        emit Send2RCForm(command,resultList);
    }
}

//检查指令未匹配状态反馈
void SerialForm::DetectFailed(QString command)
{
    SendCommand();
    qDebug()<<"Command not Find:"<<command;
    QStringList resultList;
    resultList << "Command not Find:" << command;
    emit Send2RCForm(command,resultList);
}

//遥测数据解析\异常检测结果发送显示
void SerialForm::RecvExplainInfo(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList)
{
    emit SendExplainInfo(sysName, valueList, hexList, resultList);
}

//QByteArray转QString
QString SerialForm::QByteArray2QString(QByteArray buffer)
{
    buffer = buffer.toHex();
    uint16_t temp;
    QString recv;
    QString str;
    for(int i=0;i<buffer.size();i++)
    {
        //一个一个读取
        str = buffer.at(i);
        //转换成int(10进制)
        temp = str.toInt(nullptr,16);
        //转换成2进制QString,并补零
        recv.append(QString("%1").arg(temp, 4, 2, QChar('0')));
    }
    return recv;
}

QByteArray SerialForm::QString2QByteArray(QString str)
{
    QByteArray byteArray;
    QString temp;
    if(str.isEmpty()){
        byteArray="\x00";
        return byteArray;
    }
    switch (str.length()%8) {
    case 0:break;
    case 1:str.insert(0,QString("0000000"));break;
    case 2:str.insert(0,QString("000000"));break;
    case 3:str.insert(0,QString("00000"));break;
    case 4:str.insert(0,QString("0000"));break;
    case 5:str.insert(0,QString("000"));break;
    case 6:str.insert(0,QString("00"));break;
    case 7:str.insert(0,QString("0"));break;
    default:break;
    }
    for (int i = 0; i < str.length()/8; i++ ) {
          temp = str.mid(i*8,8);
          byteArray.append(temp.toInt(nullptr,2));
    }
    return byteArray;
}

//Hex的QString转QByteArray
QByteArray SerialForm::HexQString2QByteArray(QString str)
{
    QByteArray byteArray;
    int temp;
    if(str.size()%2 != 0)
    {
        temp = 0;
        byteArray.append(temp);
    }
    else
    {
        for (int i = 0;i<str.size();) {
            temp = str.mid(i,2).toInt(nullptr,16);
            byteArray.append(temp);
            i = i + 2;
        }
    }
    return byteArray;
}

//设置串口参数选项
void SerialForm::InitUI()
{
    QStringList baudList;   //波特率
    QStringList parityList; //校验位
    QStringList dataBitsList;   //数据位
    QStringList stopBitsList;   //停止位
    // 波特率    //波特率默认选择下拉第3项：9600
    baudList<<"1200"<<"2400"<<"4800"<<"9600"
           <<"14400"<<"19200"<<"38400"<<"56000"
          <<"57600"<<"115200";
    ui->baudrateBox->addItems(baudList);
    ui->baudrateBox->setCurrentIndex(9);
    // 校验      //校验默认选择无
    parityList<<"无"<<"奇"<<"偶";
    ui->ParityBox->addItems(parityList);
    ui->ParityBox->setCurrentIndex(0);
    // 数据位      //数据位默认选择8位
    dataBitsList<<"5"<<"6"<<"7"<<"8";
    ui->dataBitsBox->addItems(dataBitsList);
    ui->dataBitsBox->setCurrentIndex(3);
    // 停止位      //停止位默认选择1位
    stopBitsList<<"1"<<"2";
    ui->stopBitsBox->addItems(stopBitsList);
    ui->stopBitsBox->setCurrentIndex(0);
}


//搜寻串口端口号
void SerialForm::SearchPort()
{
    QStringList portName;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        // 自动读取串口号添加到端口portBox中
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            portName << info.portName();
            serial.close();
        }
    }
    qDebug()<<portName;
    ui->portNameBox->addItems(portName);
}

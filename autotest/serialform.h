#ifndef SERIALFORM_H
#define SERIALFORM_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include "analysisdata.h"
#include "serialport.h"
#include "analysispac.h"
#include "udpport.h"

namespace Ui {
class SerialForm;
}

class SerialForm : public QWidget
{
    Q_OBJECT

public:
    explicit SerialForm(QWidget *parent = nullptr);
    ~SerialForm();

    void InitUI();

    void SearchPort();

    void OnReceive(QByteArray tmpdata);

    void RecvPacData(QByteArray byteArray);

    void TxtRecv(QStringList lineStr);

    void RecvCommand(QStringList command);

    void DetectResult(QString command, QStringList resultList);

    void SendCommand();

    void DetectFailed(QString command);


    //tableWidget
//    void RecvExplainInfo(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList);

    void RecvExplainInfo(QVariant map2Display,QStringList resultList);


signals:
    //传递串口参数值
    void SerialPara(QString portName, int baudRate,int dataBits,int stopBits, int parity);

    //发送内容
    void SendByteArray(QByteArray byteArray);

    void SendTxtCommand(QStringList commandList);

    void SendByte(char &byte);

    void openThread();  //打开串口线程

    void closeThread();  //关闭串口线程

    void SendUDPPara(quint16 thisPort, quint16 targetPort, QString targetIP);

    void SetUdpAbort();

    void SendByUdp(QByteArray byteArray);

    void Send2DataAnalysis(QByteArray byteArray);

    void Send2PacAnalysis(QByteArray byteArray);

    void SendStandardState(QStringList standardArray);

    void SendCommandList(QStringList lineStr);

    void CommandOver();

    void Send2RCForm(QString stateDis, QStringList resultList);


    //tableWidget
//    void SendExplainInfo(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList);

    void SendExplainInfo(QVariant map2Display,QStringList resultList);

private:
    Ui::SerialForm *ui;


    UDPController * udpController;

    SerialController * serialController;

    DataController * dataController;

    PacController * pacController;


    QString QByteArray2QString(QByteArray buffer);
    QByteArray QString2QByteArray(QString str);
    QByteArray HexQString2QByteArray(QString str);
    QByteArray Bin2QByteArray(QString str);

    bool serialState = true;
    bool UdpState = false;
};

#endif // SERIALFORM_H

#ifndef ANALYSISPAC_H
#define ANALYSISPAC_H

#define PNUM 128

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <QVariantList>
#include "dataexplain.h"
#include <QQueue>
#include <QVariant>
#include <QMetaType>

class AnalysisPac : public QObject
{
    Q_OBJECT
public:
    explicit AnalysisPac(QObject *parent = nullptr);
    ~AnalysisPac();

    //SLOT

    void DataAnalyse();

    QStringList ResolveAttr_0_Switch(QString numName, QString str,int bit0, int bit1, int bitLen);

    QStringList ReSolveAttr_1_Threshold(QString numName, QString str);

//    QStringList ReSolveAttr_2(QString numName, QString str,int bit0, int bit1, int bitLen);

    QStringList ReSolveAttr_4(QString str);

signals:

//    void Send2Display(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList);

    void Send2Display(QVariant map2Display,QStringList resultList);

    void DetectisOver(QString command, QStringList resultList);

    void CommandnotFind(QString command);

    void Send2RCForm(QVariant map2Display);

private:
    QMutex pacMutex;

    QByteArray standardState;
};


class PacWriter : public QObject
{
    Q_OBJECT
public:
    PacWriter();
    ~PacWriter();

    //SLOT

    void SavePacData(QByteArray byteArray);

signals:

    void ExcuteData();

private:
    QMutex writeMutex;
};

class PacController : public QObject
{
    Q_OBJECT
    QThread * pacWriteThread;
    QThread * pacReadThread;
public:
    PacController();
    ~PacController();

    void OpenJson(QString jsonName);

    void OpenRuleJson(QString jsonName);

    //SLOT

    void buildMap();

    void SavePacData(QByteArray byteArray);

    void GetStandardState(QStringList byteArray);

    void CommandOver();

    void DetectisOver(QString command, QStringList resultList);

    void CommandnotFind(QString command);

    //tableWidget
//    void GetExplainInfo(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList);

    void GetExplainInfo(QVariant map2Display,QStringList resultList);

    void GetStatePerPac(QVariant map2Display);

signals:

    void Send2Save(QByteArray byteArray);

    void SetStandardState(QStringList standardArray);

    void ReSendCommand(QString command, QStringList resultList);

    void DetectFailed(QString command);

    //tableWidget
//    void SendExplainInfo(int sysName, QVariantList valueList, QVariantList hexList,QStringList resultList);

    void SendExplainInfo(QVariant map2Display,QStringList resultList);

    void SendStatePerPac(QVariant map2Display);

private:
    QMutex controllerMutex;

};

#endif // ANALYSISPAC_H

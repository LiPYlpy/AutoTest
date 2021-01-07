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

signals:

//    void Send2Display(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList);

    void Send2Display(QVariant map2Display,QStringList resultList);

    void DetectisOver(QString command, QStringList resultList);

    void CommandnotFind(QString command);

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


signals:

    void Send2Save(QByteArray byteArray);

    void SetStandardState(QStringList standardArray);

    void ReSendCommand(QString command, QStringList resultList);

    void DetectFailed(QString command);

    //tableWidget
//    void SendExplainInfo(int sysName, QVariantList valueList, QVariantList hexList,QStringList resultList);

    void SendExplainInfo(QVariant map2Display,QStringList resultList);



private:
    QMutex controllerMutex;

};

#endif // ANALYSISPAC_H

#ifndef ANALYSISDATA_H
#define ANALYSISDATA_H

#define NUM 128

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>
#include "analysispac.h"

class AnalysisData : public QObject
{
    Q_OBJECT
public:
    explicit AnalysisData(QObject *parent = nullptr);
    ~AnalysisData();

    //SLOT
    void FindPac(); //解帧

signals:

    void SendOut(QByteArray data);

private:
    QMutex analysisMutex;
};


class DataController : public QObject
{
    Q_OBJECT
    QThread * analysisThread;
public:
    DataController();
    ~DataController();

    //SLOT

    void SaveData(QByteArray byteArray);

    void SendPac(QByteArray byteArray);

signals:

    void FindHead();

    void SendPacData(QByteArray byteArray);

private:
    QMutex controllMutex;

};


#endif // ANALYSISDATA_H

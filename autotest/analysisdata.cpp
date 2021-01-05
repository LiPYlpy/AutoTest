#include "analysisdata.h"

uchar queue[(4095*11)]={0};  //实时遥测源码缓冲区 队列
int readPoint=0;  //读指针
int writePoint=0; //写指针

AnalysisData::AnalysisData(QObject *parent) : QObject(parent)
{

}

AnalysisData::~AnalysisData()
{
    qDebug()<<"析构 AnalysisData";
}



//匹配实时遥测帧头
void AnalysisData::FindPac()
{
    int byteN = 512;  //字节数 实时帧长度
    int qLen = 4095*11; //缓冲区长度
    int i = readPoint; //当前读指针
    int j = writePoint; //当前写指针（读指针不能超过写指针）


    int getPoint = -1; //记录找到实时遥测帧头的位置
    bool findPac = false; //找到帧头的标志

    int flag0 = -1; //第一帧头
    int flag00 = -1;
    int flag01 = -1;
    int flag1 = -1; //第二帧头
    int flag10 = -1;
    int flag11 = -1;
    int flag2 = -1; //第三帧头

    if(j<i)
        j=j+qLen;
    QByteArray byteData;
    while( i < j )
    {
        flag0 = i % qLen;
        flag1 = (i + byteN) % qLen;
        flag2 = (i + byteN*2) % qLen;
        //匹配帧头 两帧
        if( queue[flag0] == 0xeb && queue[flag1] == 0xeb && queue[flag2] == 0xeb)
        {
            flag00 = (i + 20) % qLen;
            flag01 = (i + 21) % qLen;
            flag10 = (i + byteN + 20) % qLen;
            flag11 = (i + byteN + 21) % qLen;
            //第一帧 主导头00 第二帧ff
            if(queue[flag00] == 0x00 && queue[flag01] == 0x00 && queue[flag10] == 0xff && queue[flag11] == 0xff)
            {
                getPoint = i;
                findPac = true; //找到
                break;
            }
            else
            {
                i++;
                findPac = false;
                continue;
            }
        }
        else
        {
            i++;
            findPac = false;
            continue;
        }
    }
    if(findPac)
    {
        int k;
        int p;
        for(k = (getPoint + 22); k < (getPoint + byteN); k++)
        {
            p = k%qLen; //数组中的真实位置
            byteData.append(queue[p]);
        }
        for(k = (getPoint + byteN + 22); k < (getPoint + byteN*2); k++)
        {
            p=k%qLen;
            byteData.append(queue[p]);
        }
        readPoint = k%qLen;  //记录当前读指针位置
    }

    if(findPac)
    {
        //发送数据源包
        emit SendOut(byteData);
    }
    byteData.clear();
}

DataController::DataController()
{
    //开解帧线程
    AnalysisData * analysisData = new AnalysisData;
    analysisThread = new QThread(this);
    analysisData->moveToThread(analysisThread);
    //退出线程
    connect(analysisThread,&QThread::finished,analysisData,&QObject::deleteLater);

    //解帧 从数据帧中获取包
    //实时遥测包
   connect(this,&DataController::FindHead,analysisData,&AnalysisData::FindPac);

   //发送数据源包
   connect(analysisData,&AnalysisData::SendOut,this,&DataController::SendPac);

    analysisThread->start();
}

DataController::~DataController()
{
    //关闭线程
    analysisThread->quit();
    analysisThread->wait();
    qDebug()<<"析构 DataController";
}

//将串口缓冲区的数据存入解帧缓冲区（queue）
void DataController::SaveData(QByteArray byteArray)
{
    controllMutex.lock();
//    qDebug()<<"byteArray"<<byteArray.size();
//    byteArray = byteArray.toHex();

//    QString str;
//    for (int i = 0; i<byteArray.length();) {
//        str = byteArray.at(i);
//        str.append(byteArray.at(i+1));
//        i=i+2;
//        queue[writePoint] = str.toInt(nullptr,16);  //用int存储
//        writePoint = writePoint + 1;

//    }


    //将文本数据分割并清洗
    QString str = QString(byteArray);
    QStringList temp = str.split(" ");
    for(int i = 0;i<temp.size();i++)
    {
        if(temp.at(i)=="")
            continue;
        if(temp.at(i)=="\r\n\r\n")
            continue;
        if(temp.at(i)=="\r\n")
            continue;
        queue[writePoint] = temp.at(i).toInt(nullptr,16);
        writePoint = (writePoint + 1)%(4095*11); //记录写指针
    }
    controllMutex.unlock();
    //触发解帧函数
    emit FindHead();
}

void DataController::SendPac(QByteArray byteArray)
{
    //将数据源包发给serialForm
    emit SendPacData(byteArray);
}






#include "analysispac.h"
#include <QMap>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

QQueue<QByteArray> pacQueue;   //数据源包存入的队列
QMap<QString,int> numMap;      //波道号对应的编号
QStringList cStringList;       //检测遥控指令

QMap<QString,QStringList> sysMap; //分系统对应的数据编号
QMap<QString,QStringList> divisionMap;  //各数据编号对应的类型、名、位置
QMap<QString,QJsonValue> jsonMap;    //各数据编号对应的处理方式

QMap<QString,QJsonValue> ruleMap;

QMap<QString,QStringList> displayMap;
QMap<QString,QStringList> cacheMap;

QStringList subSysName;        //分系统集合

bool detectFlag = false;       //检测标志

int count = 0;                 //接收的数据源包的帧计数

AnalysisPac::AnalysisPac(QObject *parent) : QObject(parent)
{

}

AnalysisPac::~AnalysisPac()
{
    qDebug()<<"析构 AnalysisPac";
}

PacWriter::PacWriter()
{

}

PacWriter::~PacWriter()
{

}

//将数据源包存入队列
void PacWriter::SavePacData(QByteArray byteArray)
{
    qDebug()<<"save data"<<QThread::currentThread();
    //加上写锁
    writeMutex.lock();
    pacQueue.enqueue(byteArray);
    qDebug()<<pacQueue.size();
    writeMutex.unlock();
    //发送数据源包解析
    emit ExcuteData();
}

//数据源包解析
void AnalysisPac::DataAnalyse()
{
    qDebug()<<"read data"<<QThread::currentThread();
    QByteArray dataPac;
    //加读锁
    pacMutex.lock();
    dataPac = pacQueue.dequeue();
    pacMutex.unlock();
    //获取应用过程标志
    int state = dataPac.mid(0,2).toHex().toInt(nullptr,16);
    int sysName;
    //获取子系统名称
    switch(state)
    {
    case 399:
        qDebug()<<"卫星实时遥测数据包";
        sysName=1;
        break;
    case 1474:
        qDebug()<<"轨道试验模式延时遥测数据包";
        sysName=2;
        break;
    case 1547:
        qDebug()<<"轨道非试验模式延时遥测数据包";
        sysName=3;
        break;
    case 1580:
        qDebug()<<"操作系统延时遥测数据包";
        sysName=4;
        break;
    case 1606:
        qDebug()<<"姿控延时遥测数据包";
        sysName=5;
        break;
    case 1633:
        qDebug()<<"电源延时遥测数据包";
        sysName=6;
        break;
    case 1682:
        qDebug()<<"星间测距延时遥测数据包";
        sysName=7;
        break;
    case 1717:
        qDebug()<<"GNSS1延时遥测数据包";
        sysName=8;
        break;
    case 1759:
        qDebug()<<"综合电子延时遥测数据包";
        sysName=9;
        break;
    case 1784:
        qDebug()<<"预留";
        sysName=10;
        break;
    case 1850:
        qDebug()<<"载荷延时工程遥测数据包";
        sysName=11;
        break;
    case 1922:
        qDebug()<<"姿控状态量延时遥测数据包";
        sysName=12;
        break;
    case 1950:
        qDebug()<<"历史实时遥测数据包";
        sysName=13;
        break;
    case 1957:
        qDebug()<<"填充帧数据包";
        sysName=14;
        break;
    case 1964:
        qDebug()<<"自遥测数据包";
        sysName=15;
        break;
    case 1969:
        qDebug()<<"GNSS3延时遥测数据包";
        sysName=16;
        break;
    case 1981:
        qDebug()<<"GNSS4延时遥测数据包";
        sysName=17;
        break;
    case 1988:qDebug()<<"RTOD延时遥测数据包";
        sysName=18;
        break;
    default:sysName = 0;break;
    }
    //数据源包 包数据域
    QByteArray dataArea = dataPac.mid(6);
    QVariantList valueList; //真实值
    QVariantList hexList;   //源码Hex
    QStringList resultList; //每个波道检测结果
    //针对每个子系统进行检测
    switch (sysName) {
    case 1:
        hexList << R19_Hex(dataArea.mid(0,40));
        valueList << R19_Value(dataArea.mid(0,40));

        hexList << R20_Hex(dataArea.mid(40,40));
        valueList << R20_Value(dataArea.mid(40,40));

        hexList << R21_Hex(dataArea.mid(80,24));
        valueList << R21_Value(dataArea.mid(80,24));

        hexList << R22_Hex(dataArea.mid(104,158));
        valueList << R22_Value(dataArea.mid(104,158));

        hexList << R23_Hex(dataArea.mid(262,180));
        valueList << R23_Value(dataArea.mid(262,180));

        hexList << R24_Hex(dataArea.mid(442,120));
        valueList << R24_Value(dataArea.mid(442,120));

        hexList << R25_Hex(dataArea.mid(562,60));
        valueList << R25_Value(dataArea.mid(562,60));

        hexList << R26_Hex(dataArea.mid(622,265));
        valueList << R26_Value(dataArea.mid(622,265));

        hexList << R27_Hex(dataArea.mid(887,8));
        valueList << R27_Value(dataArea.mid(887,8));
        break;
    case 2:break;
    case 3:break;
    case 4:break;
    case 5:break;
    case 6:break;
    case 7:break;
    case 8:break;
    case 9:break;
    case 10:break;
    case 11:break;
    case 12:break;
    case 13:break;
    case 14:break;
    case 15:break;
    case 16:break;
    case 17:break;
    case 18:break;
    default:break;
    }
    //获取检测结果
    resultList = DetectResult();
    QStringList testList;
    for(int i = 0; i < 896; i++)
    {
        testList<<"true";
    }
    //遥控指令检测模式
//    if(detectFlag)
//    {
//        //指令
//        QString command = cStringList.at(0).mid(6,4);
//        QString rule;
//        QStringList ruleList;
//        int index;
//        //匹配直接指令回传、间接指令回传
//        if(count>0 && (hexList.at(697).toString()==command || hexList.at(698).toString()== command))
//        {
//            //获取卫星标准状态
//            for(int i = 2; i<cStringList.size();i++)
//            {
//                rule = cStringList.at(i);
//                ruleList = rule.split(" ");
//                index = numMap.find(ruleList.at(0)).value();
//                //标志
//                if(ruleList.size()==3)
//                {
//                    if(hexList.at(index).toString()==ruleList.at(2))
//                    {
//                        resultList[index] = "true";
//                        testList[index] = "true";
//                    }
//                    else
//                    {
//                        resultList[index] = "false";
//                        testList[index] = "false";
//                    }
//                }
//                else    //阈值
//                {
//                    float tmp = valueList.at(index).toString().toFloat();
//                    if(tmp>=ruleList.at(2).toFloat() && tmp<=ruleList.at(3).toFloat())
//                    {
//                        resultList[index] = "true";
//                        testList[index] = "true";
//                    }
//                    else
//                    {
//                        resultList[index] = "false";
//                        testList[index] = "false";
//                    }
//                }
//            }
//            //反馈当前指令的检测结果
//            emit DetectisOver(command, testList);
//        }
//        //反馈指令未匹配
//        if(count == 0)
//        {
//            emit CommandnotFind(command);
//        }
//        count--;
//    }


    //将数据源包的解析结果和检测结果传出
//    emit Send2Display(sysName,valueList,hexList,resultList);




    for(int cnt=0;cnt < subSysName.size();cnt++)
    {
        QString numName = subSysName.at(cnt);//数据编号

        QStringList numList = sysMap.value(numName);
        for(int i = 0;i<numList.size();i++)
        {
            QString numThis = numList.at(i);
            QString attribute = divisionMap.value(numThis).at(0);//获取对应数据编号的attribute
            QString name = divisionMap.value(numThis).at(1);//获取对应数据编号的数据名
            int byte0,byte1,bit0,bit1; //
            byte0 = divisionMap.value(numThis).at(2).toInt();
            byte1 = divisionMap.value(numThis).at(3).toInt();
            bit0 = divisionMap.value(numThis).at(4).toInt();
            bit1 = divisionMap.value(numThis).at(5).toInt();
            QString decItem = dataArea.mid(byte0,byte1-byte0+1).toHex();   //获取源码（QString格式）
            int bitLen = (byte1-byte0+1)*8;
            QString hexItem = QString("%1").arg(decItem.toInt(nullptr,16),bitLen, 2, QChar('0'));
            QStringList displayList;  // 数据名 数据源码 数据值
            displayList<<name;
            switch (attribute.toInt()) {
            case 0:
                displayList<<ResolveAttr_0_Switch(numThis,hexItem,bit0,bit1,bitLen);
                displayMap.insert(numThis,displayList);
                break;
            case 1:
                displayList<<ReSolveAttr_1_Threshold(numThis,decItem);
                displayMap.insert(numThis,displayList);
                break;
            case 3:
                displayList<<decItem<<decItem;
                displayMap.insert(numThis,displayList);
                break;
            case 4:
                displayList<<ReSolveAttr_4(decItem);
                displayMap.insert(numThis,displayList);
                break;
            default:
                break;
            }
        }
    }
    qDebug()<<"Size:"<<displayMap.size();

    if(cacheMap.size() == 0){
        cacheMap = displayMap;
    }
    else
    {
        //////////////////////////////////// 第0类规则检测
        QJsonArray array0 = ruleMap.value("0").toArray();
        QJsonObject obj0;
        QString name0;
        for(int i=0;i<array0.size();i++)  //比较hex
        {
            obj0 = array0[i].toObject();
            name0 = obj0.keys().at(0);
            if(displayMap.value(name0).at(1) == obj0.value(name0).toString())
            {
                qDebug()<<name0<<"Yes";
            }
            else
            {
                qDebug()<<name0<<"No";
            }
        }
        //////////////////////////////////////////////////



        ////////////////////////////////////// 第1类规则检测
        QJsonArray array1 = ruleMap.value("1").toArray();
        QString name1;

        for(int i=0;i<array1.size();i++)
        {
            name1 = array1.at(i).toString();
            if(displayMap.value(name1).at(2).toInt()!=cacheMap.value(name1).at(2).toInt())
            {
                qDebug()<<name1<<"No";
            }
            else
            {
                qDebug()<<name1<<"Yes";
            }
        }
        ///////////////////////////////////////////////////


        qDebug()<<"////////////////////////////";
        qDebug()<<"////////////////////////////";

        ////////////////////////////////////////第2类规则检测
        QJsonArray array2 = ruleMap.value("2").toArray();
        QJsonObject obj2;
        QString name2;
        for(int i=0;i<array2.size();i++)
        {
            obj2 = array2.at(i).toObject();
            name2 = obj2.keys().at(0);
            QJsonArray state = obj2.value(name2).toArray();
            QJsonObject sw0 = state.at(0).toObject();
            QString sw0Name = sw0.keys().at(0);
            QJsonObject sw1 = state.at(1).toObject();
            QString sw1Name = sw1.keys().at(0);
            if(displayMap.value(name2).at(1)==sw0Name)
            {
                QJsonObject sw0Item = sw0.value(sw0Name).toObject();
                foreach(QString i, sw0Item.keys())
                {
                    QString value = sw0Item.value(i).toString();
                    QStringList small2Big = value.split("-");
                    if(displayMap.value(i).at(2).toFloat()>=small2Big.at(0).toFloat() && displayMap.value(i).at(2).toFloat()<=small2Big.at(1).toFloat() )
                    {
                        qDebug()<<i<<"Yes";
                    }
                    else
                    {
                        qDebug()<<i<<"No";
                    }
                }
            }
            if(displayMap.value(name2).at(1)==sw1Name)
            {
                QJsonObject sw1Item = sw1.value(sw1Name).toObject();
                foreach(QString i, sw1Item.keys())
                {
                    QString value = sw1Item.value(i).toString();
                    QStringList small2Big = value.split("-");
                    if(displayMap.value(i).at(2).toFloat()>=small2Big.at(0).toFloat() && displayMap.value(i).at(2).toFloat()<=small2Big.at(1).toFloat() )
                    {
                        qDebug()<<i<<"Yes";
                    }
                    else
                    {
                        qDebug()<<i<<"No";
                    }
                }
            }
        }
        /////////////////////////////////////////////////////

        /////////////////////////////////////////第4类规则检测
        QJsonObject obj4 = ruleMap.value("4").toObject();
        if(obj4.contains(QStringLiteral("time")))
        {
            ///...///
        }
        if(obj4.contains(QStringLiteral("count")))
        {
            QJsonArray countArray = obj4.value(QStringLiteral("count")).toArray();
            for(int i = 0; i < countArray.size(); i++)
            {
                QJsonArray compArray = countArray.at(i).toArray();
                int comp0 = displayMap.value(compArray.at(0).toString()).at(2).toInt();
                int comp1 = displayMap.value(compArray.at(1).toString()).at(2).toInt();
                int compValue = abs(comp0-comp1);
                if(compValue>10)
                {
                    qDebug()<<"No";
                }
                else
                {
                    qDebug()<<"Yes";
                }
            }
        }
        ///////////////////////////////////////////////////////////

        ////////////////////////////////////////第5类规则检测
        QJsonArray array5 = ruleMap.value("5").toArray();
        QString name5;
        for(int i = 0; i < array5.size(); i++)
        {
            name5 = array5.at(i).toString();
            int cacheValue = cacheMap.value(name5).at(2).toInt();
            int presentValue = displayMap.value(name5).at(2).toInt();
            if(cacheValue!=presentValue && presentValue==0)
            {
                qDebug()<<name5<<"No";
            }
            else
            {
                qDebug()<<name5<<"Yes";
            }
        }
        /////////////////////////////////////////////////////


        ////////////////////////////////////////////第6类规则检测
        QJsonArray array6 = ruleMap.value("6").toArray();
        QJsonObject obj6;
        QString name6;
        QString value6;
        QStringList s2B;
        for(int i = 0 ; i<array6.size(); i++)
        {
            obj6 = array6.at(i).toObject();
            name6 = obj6.keys().at(0);
            value6 = obj6.value(name6).toString();
            s2B = value6.split("-");
            if(displayMap.value(name6).at(2).toFloat()>=s2B.at(0).toFloat() && displayMap.value(name6).at(2).toFloat()<=s2B.at(1).toFloat())
            {
                qDebug()<<name6<<"Yes";
            }
            else
            {
                qDebug()<<name6<<"No";
            }
        }
        //////////////////////////////////////////////////////

        /*************************************************************************************************************************************/
        //控制存储历史数据

        /*************************************************************************************************************************************/


        cacheMap = displayMap;
    }









    qRegisterMetaType<QVariant>("QVariant");
    QVariant map2Display;
    map2Display.setValue(displayMap);
    emit Send2Display(map2Display,resultList);

    if(detectFlag)
    {
        //指令
        QString command = cStringList.at(0).mid(6,4);
        if(displayMap.value("TM-RCES-44").at(1)==command || displayMap.value("TM-RCES-45").at(1)==command)
        {
            QStringList testList;
            QString st;
            QStringList tmp;
            QString temp;
            testList<<"Result:";

            for(int i=2;i<cStringList.size();i++)
            {
                tmp = cStringList.at(i).split(" ");
                temp = tmp.at(0);
                st = temp + " " + displayMap.value(temp).at(1) + " " +displayMap.value(temp).at(2);
                if(tmp.at(1)=="0")
                {
                    if(tmp.at(2)==displayMap.value(temp).at(1))
                        st = st + "NO ERROR!!!";
                    else
                    {
                        st = st + "ERROR OCCURRED!!!";
                    }
                }
                if(tmp.at(1)=="1")
                {
                    float val,sd0,sd1;
                    val = displayMap.value(temp).at(2).toFloat();
                    sd0 = tmp.at(2).toFloat();
                    sd1 = tmp.at(3).toFloat();
                    if(val>=sd0 && val<=sd1)
                        st = st + "NO ERROR!!!";
                    else
                        st = st + "ERROR OCCURRED!!!";
                }
                testList << st;
            }

            emit DetectisOver(command, testList);
        }
        if(count == 0)
        {
            emit CommandnotFind(command);
        }
        count--;
    }

}

QStringList AnalysisPac::ResolveAttr_0_Switch(QString numName, QString str, int bit0, int bit1, int bitLen)
{
    QStringList displayList;
    QString tmp = str.mid(bitLen-bit0-1,(bit0-bit1+1));
    displayList << tmp;
    QJsonObject flagObj = jsonMap.value(numName).toObject();
    if(flagObj.contains(tmp))
        displayList << flagObj.value(tmp).toString();
    else
        displayList<<tmp;
    return displayList;
}

QStringList AnalysisPac::ReSolveAttr_1_Threshold(QString numName, QString str)
{
    QStringList displayList;

    displayList << str;
    QJsonArray transArray = jsonMap.value(numName).toArray();
    QString dataType = transArray.at(0).toString();
    float multi = transArray.at(1).toString().toFloat();
    float plus = transArray.at(2).toString().toFloat();
    QStringList typeIndex;
    typeIndex<<"uchar"<<"uint16"<<"uint32"<<"char"<<"int16"<<"int32"<<"float";
    switch (typeIndex.indexOf(dataType)) {
    case 0:
    {
        uchar temp = str.toUInt(nullptr,16);
        float res;
        res = temp*multi+plus;
        displayList<<QString("%1").arg(res);
        break;
    }
    case 1:
    {
        quint16 temp= str.toUInt(nullptr,16);
        float res;
        res = temp*multi+plus;
        displayList<<QString("%1").arg(res);
        break;
    }
    case 2:
    {
        quint32 temp = str.toUInt(nullptr,16);
        float res;
        res = temp*multi+plus;
        displayList<<QString("%1").arg(res);
        break;
    }
    case 3:
    {
        char temp = str.toInt(nullptr,16);
        float res;
        res = temp*multi+plus;
        displayList<<QString("%1").arg(res);
        break;
    }
    case 4:
    {
        qint16 temp = str.toInt(nullptr,16);
        float res;
        res = temp*multi+plus;
        displayList<<QString("%1").arg(res);
        break;
    }
    case 5:
    {
        qint32 temp = str.toInt(nullptr,16);
        float res;
        res = temp*multi+plus;
        displayList<<QString("%1").arg(res);
        break;
    }
    case 6:
    {
        qint32 c = str.toInt(nullptr,16);
        float temp = *(float*)&c;
        temp = temp*multi+plus;
        displayList<<QString("%1").arg(temp);
        qDebug()<<QString("%1").arg(temp);
        break;
    }
    default:
        break;
    }
    return displayList;
}

QStringList AnalysisPac::ReSolveAttr_4(QString str)
{
    QStringList displayList;
    displayList<<str;
    QString time;
    time = "20"+str.mid(0,2)+"年"+str.mid(2,2)+"月"+str.mid(4,2)+"日"+" "+str.mid(8,2)+"时"+str.mid(10,2)+"分"+str.mid(12,2)+"秒"+str.mid(14,2)+"百分秒";
    displayList<<time;
    return displayList;
}


PacController::PacController()
{
    PacWriter * writePac = new PacWriter();
    AnalysisPac * readPac = new AnalysisPac();
    pacWriteThread = new QThread();
    pacReadThread = new QThread();
    //数据源包进入队列线程
    writePac->moveToThread(pacWriteThread);
    //数据源包解析和检测线程
    readPac->moveToThread(pacReadThread);
    //对应波道号和序号
    buildMap();
    //退出线程
    connect(pacWriteThread,&QThread::finished,writePac,&QObject::deleteLater);
    connect(pacReadThread,&QThread::finished,readPac,&QObject::deleteLater);

    //数据源包写入
    connect(this,&PacController::Send2Save,writePac,&PacWriter::SavePacData);
    //启动解析
    connect(writePac,&PacWriter::ExcuteData,readPac,&AnalysisPac::DataAnalyse);
    //将解析结果和检测结果传出
    connect(readPac,&AnalysisPac::Send2Display,this,&PacController::GetExplainInfo);
    //将检测状反馈
    //检测到且完成
    connect(readPac,&AnalysisPac::DetectisOver,this,&PacController::DetectisOver);
    //未检测到对应指令
    connect(readPac,&AnalysisPac::CommandnotFind,this,&PacController::CommandnotFind);

    pacWriteThread->start();
    pacReadThread->start();

    //读取json文件
    QString jsonName = "dataParse_v1.json";
    OpenJson(jsonName);

    QString jsonName1 = "RuleBaselib.json";
    OpenRuleJson(jsonName1);
//    qDebug()<<subSysName;
//    qDebug()<<sysMap;
//    qDebug()<<divisionMap;
//    qDebug()<<jsonMap;

//    QString str= "3fffff";
//    qint32 c = str.toUInt(nullptr, 16);
//    float d = *(float*)&c;
//    QString radiation = QString("%1").arg(d);
//    qDebug()<<d;

//    char tmp = -55;
//    QStringList strList;
//    strList<<QString::number(tmp);
//    qDebug()<<strList;

}

PacController::~PacController()
{
    //关闭线程

    pacWriteThread->quit();
    pacReadThread->quit();

    pacWriteThread->wait();
    pacReadThread->wait();
    qDebug()<<"析构 PacController";
}

void PacController::OpenJson(QString jsonName)
{
    QString fileDir = "../"+jsonName;
    QFile file(fileDir);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString value = file.readAll();
    file.close();

//    int count = 0;
    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(),&parseJsonErr);
    if(!(parseJsonErr.error == QJsonParseError::NoError))
    {
        qDebug()<<tr("解析json文件错误！");
        return;
    }
    else
    {
    QJsonObject jsonObject = document.object();

    QJsonValue configValueList = jsonObject.value(QStringLiteral("config"));

    foreach(QString i, configValueList.toObject().keys()){
        QJsonArray array = configValueList.toObject().value(i).toArray();
        QStringList subSys;
        for(int k = 0;k<array.size();k++)
        {
            subSys<<array.at(k).toString();
        }
        sysMap.insert(i,subSys);
        subSysName<<i;
    }

    if(jsonObject.contains(QStringLiteral("parse")))
    {
        QJsonValue arrayValue = jsonObject.value(QStringLiteral("parse"));
        if(arrayValue.isArray())
        {
            QJsonArray parseArray = arrayValue.toArray();
            for (int i = 0; i<parseArray.size(); i++ ) {
                count++;
                QJsonObject parseItem = parseArray.at(i).toObject();
                QString dataName = parseItem.keys().at(0);
                QJsonObject item = parseItem.begin()->toObject();
                QString attribute = item.value(QStringLiteral("attribute")).toString();
                QStringList info;
                info<<attribute;
                info<<item.value(QStringLiteral("name")).toString();
                QJsonArray locationArray = item.value(QStringLiteral("location")).toArray();
                for(int k = 0;k<locationArray.size();k++)
                {
                    info<<QString::number(locationArray.at(k).toInt());
                }
//                qDebug()<<"attribute:"<< attribute;
                divisionMap.insert(dataName,info);
                switch (attribute.toInt()) {
                case 0:
                {
//                    QJsonObject flag = item.value(QStringLiteral("flag")).toObject();
//                    foreach(QString i, flag.keys())
//                    {
//                        qDebug()<<i<<flag.value(i).toString();
//                    }
                    QJsonValue flag = item.value(QStringLiteral("flag"));
                    jsonMap.insert(dataName,flag);
                    break;
                }
                case 1:
                {
//                    QJsonArray trans = item.value(QStringLiteral("trans")).toArray();
//                    for (int k = 0;k<trans.size();k++ ) {
//                        qDebug()<<trans.at(k).toString();
//                    }
                    QJsonValue trans = item.value(QStringLiteral("trans"));
                    jsonMap.insert(dataName,trans);
                    break;
                }
                case 3:
                {
                    break;
                }
                case 4:
                {
                    break;
                }
                default:break;
                }
            }
        }
    }
    }
}

void PacController::OpenRuleJson(QString jsonName)
{
    QString fileDir = "../"+jsonName;
    QFile file(fileDir);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString value = file.readAll();
    file.close();

//    int count = 0;
    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(),&parseJsonErr);
    if(!(parseJsonErr.error == QJsonParseError::NoError))
    {
        qDebug()<<tr("解析json文件错误！");
        return;
    }
    else
    {
        QJsonObject jsonObj = document.object();
        if(jsonObj.contains(QStringLiteral("0")))
        {
            QJsonValue rule0 = jsonObj.value(QStringLiteral("0"));
            ruleMap.insert("0",rule0);
        }
        if(jsonObj.contains(QStringLiteral("1")))
        {
            QJsonValue rule1 = jsonObj.value(QStringLiteral("1"));
            ruleMap.insert("1",rule1);
        }
        if(jsonObj.contains(QStringLiteral("2")))
        {
            QJsonValue rule2 = jsonObj.value(QStringLiteral("2"));
            ruleMap.insert("2",rule2);
        }
        if(jsonObj.contains(QStringLiteral("4")))
        {
            QJsonValue rule4 = jsonObj.value(QStringLiteral("4"));
            ruleMap.insert("4",rule4);
        }
        if(jsonObj.contains(QStringLiteral("5")))
        {
            QJsonValue rule5 = jsonObj.value(QStringLiteral("5"));
            ruleMap.insert("5",rule5);
        }
        if(jsonObj.contains(QStringLiteral("6")))
        {
            QJsonValue rule6 = jsonObj.value(QStringLiteral("6"));
            ruleMap.insert("6",rule6);
        }
//        qDebug()<<ruleMap;
    }
}

//对应波道号和序号
void PacController::buildMap()
{
    int i = 0;
    numMap.insert("TM-RDTTCA-01",i);i++;
    numMap.insert("TM-RDTTCA-02",i);i++;
    numMap.insert("TM-RDTTCA-03",i);i++;
    numMap.insert("TM-RDTTCA-04",i);i++;
    numMap.insert("TM-RDTTCA-05",i);i++;
    numMap.insert("TM-RDTTCA-06",i);i++;
    numMap.insert("TM-RDTTCA-07",i);i++;
    numMap.insert("TM-RDTTCA-08",i);i++;
    numMap.insert("TM-RDTTCA-09",i);i++;
    numMap.insert("TM-RDTTCA-10",i);i++;
    numMap.insert("TM-RDTTCA-11",i);i++;
    numMap.insert("TM-RDTTCA-12",i);i++;
    numMap.insert("TM-RDTTCA-13",i);i++;
    numMap.insert("TM-RDTTCA-14",i);i++;
    numMap.insert("TM-RDTTCA-15",i);i++;
    numMap.insert("TM-RDTTCA-16",i);i++;
    numMap.insert("TM-RDTTCA-17",i);i++;
    numMap.insert("TM-RDTTCA-18",i);i++;
    numMap.insert("TM-RDTTCA-19",i);i++;
    numMap.insert("TM-RDTTCA-20",i);i++;
    numMap.insert("TM-RDTTCA-21",i);i++;
    numMap.insert("TM-RDTTCA-22",i);i++;
    numMap.insert("TM-RDTTCA-23",i);i++;
    numMap.insert("TM-RDTTCA-24",i);i++;
    numMap.insert("TM-RDTTCA-25",i);i++;
    numMap.insert("TM-RDTTCA-26",i);i++;
    numMap.insert("TM-RDTTCA-27",i);i++;
    numMap.insert("TM-RDTTCA-28",i);i++;
    numMap.insert("TM-RDTTCA-29",i);i++;
    numMap.insert("TM-RDTTCA-30",i);i++;
    numMap.insert("TM-RDTTCA-31",i);i++;
    numMap.insert("TM-RDTTCA-32",i);i++;
    numMap.insert("TM-RDTTCA-33",i);i++;
    numMap.insert("TM-RDTTCA-34",i);i++;
    numMap.insert("TM-RDTTCA-35",i);i++;
    numMap.insert("TM-RDTTCA-36",i);i++;
    numMap.insert("TM-RDTTCA-37",i);i++;
    numMap.insert("TM-RDTTCA-38",i);i++;
    numMap.insert("TM-RDTTCA-39",i);i++;
    numMap.insert("TM-RDTTCA-40",i);i++;
    numMap.insert("TM-RDTTCA-41",i);i++;
    numMap.insert("TM-RDTTCA-42",i);i++;
    numMap.insert("TM-RDTTCA-43",i);i++;
    numMap.insert("TM-RDTTCA-44",i);i++;
    numMap.insert("TM-RDTTCA-45",i);i++;
    numMap.insert("TM-RDTTCA-46",i);i++;
    numMap.insert("TM-RDTTCA-47",i);i++;
    numMap.insert("TM-RDTTCA-48",i);i++;
    numMap.insert("TM-RDTTCA-49",i);i++;
    numMap.insert("TM-RDTTCA-50",i);i++;
    numMap.insert("TM-RDTTCA-51",i);i++;
    numMap.insert("TM-RDTTCA-52",i);i++;
    numMap.insert("TM-RDTTCA-53",i);i++;
    numMap.insert("TM-RDTTCA-54",i);i++;
    numMap.insert("TM-RDTTCA-55",i);i++;
    numMap.insert("TM-RDTTCB-01",i);i++;
    numMap.insert("TM-RDTTCB-02",i);i++;
    numMap.insert("TM-RDTTCB-03",i);i++;
    numMap.insert("TM-RDTTCB-04",i);i++;
    numMap.insert("TM-RDTTCB-05",i);i++;
    numMap.insert("TM-RDTTCB-06",i);i++;
    numMap.insert("TM-RDTTCB-07",i);i++;
    numMap.insert("TM-RDTTCB-08",i);i++;
    numMap.insert("TM-RDTTCB-09",i);i++;
    numMap.insert("TM-RDTTCB-10",i);i++;
    numMap.insert("TM-RDTTCB-11",i);i++;
    numMap.insert("TM-RDTTCB-12",i);i++;
    numMap.insert("TM-RDTTCB-13",i);i++;
    numMap.insert("TM-RDTTCB-14",i);i++;
    numMap.insert("TM-RDTTCB-15",i);i++;
    numMap.insert("TM-RDTTCB-16",i);i++;
    numMap.insert("TM-RDTTCB-17",i);i++;
    numMap.insert("TM-RDTTCB-18",i);i++;
    numMap.insert("TM-RDTTCB-19",i);i++;
    numMap.insert("TM-RDTTCB-20",i);i++;
    numMap.insert("TM-RDTTCB-21",i);i++;
    numMap.insert("TM-RDTTCB-22",i);i++;
    numMap.insert("TM-RDTTCB-23",i);i++;
    numMap.insert("TM-RDTTCB-24",i);i++;
    numMap.insert("TM-RDTTCB-25",i);i++;
    numMap.insert("TM-RDTTCB-26",i);i++;
    numMap.insert("TM-RDTTCB-27",i);i++;
    numMap.insert("TM-RDTTCB-28",i);i++;
    numMap.insert("TM-RDTTCB-29",i);i++;
    numMap.insert("TM-RDTTCB-30",i);i++;
    numMap.insert("TM-RDTTCB-31",i);i++;
    numMap.insert("TM-RDTTCB-32",i);i++;
    numMap.insert("TM-RDTTCB-33",i);i++;
    numMap.insert("TM-RDTTCB-34",i);i++;
    numMap.insert("TM-RDTTCB-35",i);i++;
    numMap.insert("TM-RDTTCB-36",i);i++;
    numMap.insert("TM-RDTTCB-37",i);i++;
    numMap.insert("TM-RDTTCB-38",i);i++;
    numMap.insert("TM-RDTTCB-39",i);i++;
    numMap.insert("TM-RDTTCB-40",i);i++;
    numMap.insert("TM-RDTTCB-41",i);i++;
    numMap.insert("TM-RDTTCB-42",i);i++;
    numMap.insert("TM-RDTTCB-43",i);i++;
    numMap.insert("TM-RDTTCB-44",i);i++;
    numMap.insert("TM-RDTTCB-45",i);i++;
    numMap.insert("TM-RDTTCB-46",i);i++;
    numMap.insert("TM-RDTTCB-47",i);i++;
    numMap.insert("TM-RDTTCB-48",i);i++;
    numMap.insert("TM-RDTTCB-49",i);i++;
    numMap.insert("TM-RDTTCB-50",i);i++;
    numMap.insert("TM-RDTTCB-51",i);i++;
    numMap.insert("TM-RDTTCB-52",i);i++;
    numMap.insert("TM-RDTTCB-53",i);i++;
    numMap.insert("TM-RDTTCB-54",i);i++;
    numMap.insert("TM-RDTTCB-55",i);i++;
    numMap.insert("TM-ROCS-01",i);i++;
    numMap.insert("TM-ROCS-02",i);i++;
    numMap.insert("TM-ROCS-03",i);i++;
    numMap.insert("TM-ROCS-04",i);i++;
    numMap.insert("TM-ROCS-05",i);i++;
    numMap.insert("TM-ROCS-06",i);i++;
    numMap.insert("TM-ROCS-07",i);i++;
    numMap.insert("TM-ROCS-08",i);i++;
    numMap.insert("TM-ROCS-09",i);i++;
    numMap.insert("TM-ROCS-10",i);i++;
    numMap.insert("TM-ROCS-11",i);i++;
    numMap.insert("TM-ROCS-12",i);i++;
    numMap.insert("TM-ROCS-13",i);i++;
    numMap.insert("TM-ROCS-14",i);i++;
    numMap.insert("TM-ROCS-15",i);i++;
    numMap.insert("TM-ROCS-16",i);i++;
    numMap.insert("TM-ROCS-17",i);i++;
    numMap.insert("TM-ROCS-18",i);i++;
    numMap.insert("TM-ROCS-19",i);i++;
    numMap.insert("TM-ROCS-20",i);i++;
    numMap.insert("TM-ROCS-21",i);i++;
    numMap.insert("TM-ROCS-22",i);i++;
    numMap.insert("TM-ROCS-23",i);i++;
    numMap.insert("TM-ROCS-24",i);i++;
    numMap.insert("TM-ROCS-25",i);i++;
    numMap.insert("TM-ROCS-26",i);i++;
    numMap.insert("TM-ROCS-27",i);i++;
    numMap.insert("TM-ROCS-28",i);i++;
    numMap.insert("TM-ROCS-29",i);i++;
    numMap.insert("TM-ROCS-30",i);i++;
    numMap.insert("TM-ROCS-31",i);i++;
    numMap.insert("TM-ROCS-32",i);i++;
    numMap.insert("TM-ROCS-33",i);i++;
    numMap.insert("TM-ROCS-34",i);i++;
    numMap.insert("TM-ROCS-35",i);i++;
    numMap.insert("TM-ROCS-36",i);i++;
    numMap.insert("TM-ROCS-37",i);i++;
    numMap.insert("TM-ROCS-38",i);i++;
    numMap.insert("TM-ROCS-39",i);i++;
    numMap.insert("TM-ROCS-40",i);i++;
    numMap.insert("TM-ROCS-41",i);i++;
    numMap.insert("TM-ROCS-42",i);i++;
    numMap.insert("TM-ROCS-43",i);i++;
    numMap.insert("TM-ROCS-44",i);i++;
    numMap.insert("TM-ROCS-45",i);i++;
    numMap.insert("TM-ROCS-46",i);i++;
    numMap.insert("TM-ROCS-47",i);i++;
    numMap.insert("TM-ROCS-48",i);i++;
    numMap.insert("TM-ROCS-49",i);i++;
    numMap.insert("TM-ROCS-50",i);i++;
    numMap.insert("TM-ROCS-51",i);i++;
    numMap.insert("TM-ROCS-52",i);i++;
    numMap.insert("TM-ROCS-53",i);i++;
    numMap.insert("TM-ROCS-54",i);i++;
    numMap.insert("TM-ROCS-55",i);i++;
    numMap.insert("TM-ROCS-56",i);i++;
    numMap.insert("TM-ROCS-57",i);i++;
    numMap.insert("TM-ROCS-58",i);i++;
    numMap.insert("TM-ROCS-59",i);i++;
    numMap.insert("TM-ROCS-60",i);i++;
    numMap.insert("TM-ROCS-61",i);i++;
    numMap.insert("TM-ROCS-62",i);i++;
    numMap.insert("TM-ROCS-63",i);i++;
    numMap.insert("TM-RADCS-01",i);i++;
    numMap.insert("TM-RADCS-02",i);i++;
    numMap.insert("TM-RADCS-03",i);i++;
    numMap.insert("TM-RADCS-04",i);i++;
    numMap.insert("TM-RADCS-05",i);i++;
    numMap.insert("TM-RADCS-06",i);i++;
    numMap.insert("TM-RADCS-07",i);i++;
    numMap.insert("TM-RADCS-08",i);i++;
    numMap.insert("TM-RADCS-09",i);i++;
    numMap.insert("TM-RADCS-10",i);i++;
    numMap.insert("TM-RADCS-11",i);i++;
    numMap.insert("TM-RADCS-12",i);i++;
    numMap.insert("TM-RADCS-13",i);i++;
    numMap.insert("TM-RADCS-14",i);i++;
    numMap.insert("TM-RADCS-15",i);i++;
    numMap.insert("TM-RADCS-16",i);i++;
    numMap.insert("TM-RADCS-17",i);i++;
    numMap.insert("TM-RADCS-18",i);i++;
    numMap.insert("TM-RADCS-19",i);i++;
    numMap.insert("TM-RADCS-20",i);i++;
    numMap.insert("TM-RADCS-21",i);i++;
    numMap.insert("TM-RADCS-22",i);i++;
    numMap.insert("TM-RADCS-23",i);i++;
    numMap.insert("TM-RADCS-24",i);i++;
    numMap.insert("TM-RADCS-25",i);i++;
    numMap.insert("TM-RADCS-26",i);i++;
    numMap.insert("TM-RADCS-27",i);i++;
    numMap.insert("TM-RADCS-28",i);i++;
    numMap.insert("TM-RADCS-29",i);i++;
    numMap.insert("TM-RADCS-30",i);i++;
    numMap.insert("TM-RADCS-31",i);i++;
    numMap.insert("TM-RADCS-32",i);i++;
    numMap.insert("TM-RADCS-33",i);i++;
    numMap.insert("TM-RADCS-34",i);i++;
    numMap.insert("TM-RADCS-35",i);i++;
    numMap.insert("TM-RADCS-36",i);i++;
    numMap.insert("TM-RADCS-37",i);i++;
    numMap.insert("TM-RADCS-38",i);i++;
    numMap.insert("TM-RADCS-39",i);i++;
    numMap.insert("TM-RADCS-40",i);i++;
    numMap.insert("TM-RADCS-41",i);i++;
    numMap.insert("TM-RADCS-42",i);i++;
    numMap.insert("TM-RADCS-43",i);i++;
    numMap.insert("TM-RADCS-44",i);i++;
    numMap.insert("TM-RADCS-45",i);i++;
    numMap.insert("TM-RADCS-46",i);i++;
    numMap.insert("TM-RADCS-47",i);i++;
    numMap.insert("TM-RADCS-48",i);i++;
    numMap.insert("TM-RADCS-49",i);i++;
    numMap.insert("TM-RADCS-50",i);i++;
    numMap.insert("TM-RADCS-51",i);i++;
    numMap.insert("TM-RADCS-52",i);i++;
    numMap.insert("TM-RADCS-53",i);i++;
    numMap.insert("TM-RADCS-54",i);i++;
    numMap.insert("TM-RADCS-55",i);i++;
    numMap.insert("TM-RADCS-56",i);i++;
    numMap.insert("TM-RADCS-57",i);i++;
    numMap.insert("TM-RADCS-58",i);i++;
    numMap.insert("TM-RADCS-59",i);i++;
    numMap.insert("TM-RADCS-60",i);i++;
    numMap.insert("TM-RADCS-61",i);i++;
    numMap.insert("TM-RADCS-62",i);i++;
    numMap.insert("TM-RADCS-63",i);i++;
    numMap.insert("TM-RADCS-64",i);i++;
    numMap.insert("TM-RADCS-65",i);i++;
    numMap.insert("TM-RADCS-66",i);i++;
    numMap.insert("TM-RADCS-67",i);i++;
    numMap.insert("TM-RADCS-68",i);i++;
    numMap.insert("TM-RADCS-69",i);i++;
    numMap.insert("TM-RADCS-70",i);i++;
    numMap.insert("TM-RADCS-71",i);i++;
    numMap.insert("TM-RADCS-72",i);i++;
    numMap.insert("TM-RADCS-73",i);i++;
    numMap.insert("TM-RADCS-74",i);i++;
    numMap.insert("TM-RADCS-75",i);i++;
    numMap.insert("TM-RADCS-76",i);i++;
    numMap.insert("TM-RADCS-77",i);i++;
    numMap.insert("TM-RADCS-78",i);i++;
    numMap.insert("TM-RADCS-79",i);i++;
    numMap.insert("TM-RADCS-80",i);i++;
    numMap.insert("TM-RADCS-81",i);i++;
    numMap.insert("TM-RADCS-82",i);i++;
    numMap.insert("TM-RADCS-83",i);i++;
    numMap.insert("TM-RADCS-84",i);i++;
    numMap.insert("TM-RADCS-85",i);i++;
    numMap.insert("TM-RADCS-86",i);i++;
    numMap.insert("TM-RADCS-87",i);i++;
    numMap.insert("TM-RADCS-88",i);i++;
    numMap.insert("TM-RADCS-89",i);i++;
    numMap.insert("TM-RADCS-90",i);i++;
    numMap.insert("TM-RADCS-91",i);i++;
    numMap.insert("TM-RADCS-92",i);i++;
    numMap.insert("TM-RADCS-93",i);i++;
    numMap.insert("TM-RADCS-94",i);i++;
    numMap.insert("TM-RADCS-95",i);i++;
    numMap.insert("TM-RADCS-96",i);i++;
    numMap.insert("TM-RADCS-97",i);i++;
    numMap.insert("TM-RADCS-98",i);i++;
    numMap.insert("TM-RADCS-99",i);i++;
    numMap.insert("TM-RADCS-100",i);i++;
    numMap.insert("TM-RADCS-101",i);i++;
    numMap.insert("TM-RADCS-102",i);i++;
    numMap.insert("TM-RADCS-103",i);i++;
    numMap.insert("TM-RADCS-104",i);i++;
    numMap.insert("TM-RADCS-105",i);i++;
    numMap.insert("TM-RADCS-106",i);i++;
    numMap.insert("TM-RADCS-107",i);i++;
    numMap.insert("TM-RADCS-108",i);i++;
    numMap.insert("TM-RADCS-109",i);i++;
    numMap.insert("TM-RADCS-110",i);i++;
    numMap.insert("TM-RADCS-111",i);i++;
    numMap.insert("TM-RADCS-112",i);i++;
    numMap.insert("TM-RADCS-113",i);i++;
    numMap.insert("TM-RADCS-114",i);i++;
    numMap.insert("TM-RADCS-115",i);i++;
    numMap.insert("TM-RADCS-116",i);i++;
    numMap.insert("TM-RADCS-117",i);i++;
    numMap.insert("TM-RADCS-118",i);i++;
    numMap.insert("TM-RADCS-119",i);i++;
    numMap.insert("TM-RADCS-120",i);i++;
    numMap.insert("TM-RADCS-121",i);i++;
    numMap.insert("TM-RADCS-122",i);i++;
    numMap.insert("TM-RADCS-123",i);i++;
    numMap.insert("TM-RADCS-124",i);i++;
    numMap.insert("TM-RADCS-125",i);i++;
    numMap.insert("TM-RADCS-126",i);i++;
    numMap.insert("TM-RADCS-127",i);i++;
    numMap.insert("TM-RADCS-128",i);i++;
    numMap.insert("TM-RADCS-129",i);i++;
    numMap.insert("TM-RADCS-130",i);i++;
    numMap.insert("TM-RADCS-131",i);i++;
    numMap.insert("TM-RADCS-132",i);i++;
    numMap.insert("TM-RADCS-133",i);i++;
    numMap.insert("TM-RADCS-134",i);i++;
    numMap.insert("TM-RADCS-135",i);i++;
    numMap.insert("TM-RADCS-136",i);i++;
    numMap.insert("TM-RADCS-137",i);i++;
    numMap.insert("TM-RADCS-138",i);i++;
    numMap.insert("TM-RADCS-139",i);i++;
    numMap.insert("TM-RADCS-140",i);i++;
    numMap.insert("TM-RADCS-141",i);i++;
    numMap.insert("TM-RADCS-142",i);i++;
    numMap.insert("TM-RADCS-143",i);i++;
    numMap.insert("TM-RADCS-144",i);i++;
    numMap.insert("TM-RADCS-145",i);i++;
    numMap.insert("TM-RADCS-146",i);i++;
    numMap.insert("TM-RADCS-147",i);i++;
    numMap.insert("TM-RADCS-148",i);i++;
    numMap.insert("TM-RADCS-149",i);i++;
    numMap.insert("TM-RADCS-150",i);i++;
    numMap.insert("TM-RADCS-151",i);i++;
    numMap.insert("TM-RADCS-152",i);i++;
    numMap.insert("TM-RADCS-153",i);i++;
    numMap.insert("TM-RADCS-154",i);i++;
    numMap.insert("TM-RADCS-155",i);i++;
    numMap.insert("TM-RADCS-156",i);i++;
    numMap.insert("TM-RADCS-157",i);i++;
    numMap.insert("TM-RADCS-158",i);i++;
    numMap.insert("TM-RADCS-159",i);i++;
    numMap.insert("TM-RADCS-160",i);i++;
    numMap.insert("TM-RADCS-161",i);i++;
    numMap.insert("TM-RADCS-162",i);i++;
    numMap.insert("TM-RADCS-163",i);i++;
    numMap.insert("TM-RADCS-164",i);i++;
    numMap.insert("TM-RADCS-165",i);i++;
    numMap.insert("TM-RADCS-166",i);i++;
    numMap.insert("TM-RADCS-167",i);i++;
    numMap.insert("TM-RADCS-168",i);i++;
    numMap.insert("TM-RADCS-169",i);i++;
    numMap.insert("TM-RADCS-170",i);i++;
    numMap.insert("TM-RADCS-171",i);i++;
    numMap.insert("TM-RADCS-172",i);i++;
    numMap.insert("TM-RADCS-173",i);i++;
    numMap.insert("TM-REPS-01",i);i++;
    numMap.insert("TM-REPS-02",i);i++;
    numMap.insert("TM-REPS-03",i);i++;
    numMap.insert("TM-REPS-04",i);i++;
    numMap.insert("TM-REPS-05",i);i++;
    numMap.insert("TM-REPS-06",i);i++;
    numMap.insert("TM-REPS-07",i);i++;
    numMap.insert("TM-REPS-08",i);i++;
    numMap.insert("TM-REPS-09",i);i++;
    numMap.insert("TM-REPS-10",i);i++;
    numMap.insert("TM-REPS-11",i);i++;
    numMap.insert("TM-REPS-12",i);i++;
    numMap.insert("TM-REPS-13",i);i++;
    numMap.insert("TM-REPS-14",i);i++;
    numMap.insert("TM-REPS-15",i);i++;
    numMap.insert("TM-REPS-16",i);i++;
    numMap.insert("TM-REPS-17",i);i++;
    numMap.insert("TM-REPS-18",i);i++;
    numMap.insert("TM-REPS-19",i);i++;
    numMap.insert("TM-REPS-20",i);i++;
    numMap.insert("TM-REPS-21",i);i++;
    numMap.insert("TM-REPS-22",i);i++;
    numMap.insert("TM-REPS-23",i);i++;
    numMap.insert("TM-REPS-24",i);i++;
    numMap.insert("TM-REPS-25",i);i++;
    numMap.insert("TM-REPS-26",i);i++;
    numMap.insert("TM-REPS-27",i);i++;
    numMap.insert("TM-REPS-28",i);i++;
    numMap.insert("TM-REPS-29",i);i++;
    numMap.insert("TM-REPS-30",i);i++;
    numMap.insert("TM-REPS-31",i);i++;
    numMap.insert("TM-REPS-32",i);i++;
    numMap.insert("TM-REPS-33",i);i++;
    numMap.insert("TM-REPS-34",i);i++;
    numMap.insert("TM-REPS-35",i);i++;
    numMap.insert("TM-REPS-36",i);i++;
    numMap.insert("TM-REPS-37",i);i++;
    numMap.insert("TM-REPS-38",i);i++;
    numMap.insert("TM-REPS-39",i);i++;
    numMap.insert("TM-REPS-40",i);i++;
    numMap.insert("TM-REPS-41",i);i++;
    numMap.insert("TM-REPS-42",i);i++;
    numMap.insert("TM-REPS-43",i);i++;
    numMap.insert("TM-REPS-44",i);i++;
    numMap.insert("TM-REPS-45",i);i++;
    numMap.insert("TM-REPS-46",i);i++;
    numMap.insert("TM-REPS-47",i);i++;
    numMap.insert("TM-REPS-48",i);i++;
    numMap.insert("TM-REPS-49",i);i++;
    numMap.insert("TM-REPS-50",i);i++;
    numMap.insert("TM-REPS-51",i);i++;
    numMap.insert("TM-REPS-52",i);i++;
    numMap.insert("TM-REPS-53",i);i++;
    numMap.insert("TM-REPS-54",i);i++;
    numMap.insert("TM-REPS-55",i);i++;
    numMap.insert("TM-REPS-56",i);i++;
    numMap.insert("TM-REPS-57",i);i++;
    numMap.insert("TM-REPS-58",i);i++;
    numMap.insert("TM-REPS-59",i);i++;
    numMap.insert("TM-REPS-60",i);i++;
    numMap.insert("TM-REPS-61",i);i++;
    numMap.insert("TM-REPS-62",i);i++;
    numMap.insert("TM-REPS-63",i);i++;
    numMap.insert("TM-REPS-64",i);i++;
    numMap.insert("TM-REPS-65",i);i++;
    numMap.insert("TM-REPS-66",i);i++;
    numMap.insert("TM-REPS-67",i);i++;
    numMap.insert("TM-REPS-68",i);i++;
    numMap.insert("TM-REPS-69",i);i++;
    numMap.insert("TM-REPS-70",i);i++;
    numMap.insert("TM-REPS-71",i);i++;
    numMap.insert("TM-REPS-72",i);i++;
    numMap.insert("TM-REPS-73",i);i++;
    numMap.insert("TM-REPS-74",i);i++;
    numMap.insert("TM-REPS-75",i);i++;
    numMap.insert("TM-REPS-76",i);i++;
    numMap.insert("TM-REPS-77",i);i++;
    numMap.insert("TM-REPS-78",i);i++;
    numMap.insert("TM-REPS-79",i);i++;
    numMap.insert("TM-REPS-80",i);i++;
    numMap.insert("TM-REPS-81",i);i++;
    numMap.insert("TM-REPS-82",i);i++;
    numMap.insert("TM-REPS-83",i);i++;
    numMap.insert("TM-REPS-84",i);i++;
    numMap.insert("TM-REPS-85",i);i++;
    numMap.insert("TM-REPS-86",i);i++;
    numMap.insert("TM-REPS-87",i);i++;
    numMap.insert("TM-REPS-88",i);i++;
    numMap.insert("TM-REPS-89",i);i++;
    numMap.insert("TM-REPS-90",i);i++;
    numMap.insert("TM-REPS-91",i);i++;
    numMap.insert("TM-REPS-92",i);i++;
    numMap.insert("TM-REPS-93",i);i++;
    numMap.insert("TM-REPS-94",i);i++;
    numMap.insert("TM-REPS-95",i);i++;
    numMap.insert("TM-REPS-96",i);i++;
    numMap.insert("TM-REPS-97",i);i++;
    numMap.insert("TM-REPS-98",i);i++;
    numMap.insert("TM-REPS-99",i);i++;
    numMap.insert("TM-REPS-100",i);i++;
    numMap.insert("TM-REPS-101",i);i++;
    numMap.insert("TM-REPS-102",i);i++;
    numMap.insert("TM-REPS-103",i);i++;
    numMap.insert("TM-REPS-104",i);i++;
    numMap.insert("TM-REPS-105",i);i++;
    numMap.insert("TM-REPS-106",i);i++;
    numMap.insert("TM-REPS-107",i);i++;
    numMap.insert("TM-REPS-108",i);i++;
    numMap.insert("TM-REPS-109",i);i++;
    numMap.insert("TM-REPS-110",i);i++;
    numMap.insert("TM-REPS-111",i);i++;
    numMap.insert("TM-REPS-112",i);i++;
    numMap.insert("TM-REPS-113",i);i++;
    numMap.insert("TM-REPS-114",i);i++;
    numMap.insert("TM-REPS-115",i);i++;
    numMap.insert("TM-REPS-116",i);i++;
    numMap.insert("TM-REPS-117",i);i++;
    numMap.insert("TM-REPS-118",i);i++;
    numMap.insert("TM-REPS-119",i);i++;
    numMap.insert("TM-REPS-120",i);i++;
    numMap.insert("TM-REPS-121",i);i++;
    numMap.insert("TM-REPS-122",i);i++;
    numMap.insert("TM-REPS-123",i);i++;
    numMap.insert("TM-REPS-124",i);i++;
    numMap.insert("TM-REPS-125",i);i++;
    numMap.insert("TM-REPS-126",i);i++;
    numMap.insert("TM-REPS-127",i);i++;
    numMap.insert("TM-REPS-128",i);i++;
    numMap.insert("TM-REPS-129",i);i++;
    numMap.insert("TM-REPS-130",i);i++;
    numMap.insert("TM-REPS-131",i);i++;
    numMap.insert("TM-REPS-132",i);i++;
    numMap.insert("TM-REPS-133",i);i++;
    numMap.insert("TM-REPS-134",i);i++;
    numMap.insert("TM-REPS-135",i);i++;
    numMap.insert("TM-REPS-136",i);i++;
    numMap.insert("TM-REPS-137",i);i++;
    numMap.insert("TM-REPS-138",i);i++;
    numMap.insert("TM-REPS-139",i);i++;
    numMap.insert("TM-REPS-140",i);i++;
    numMap.insert("TM-REPS-141",i);i++;
    numMap.insert("TM-RGNSS-01",i);i++;
    numMap.insert("TM-RGNSS-02",i);i++;
    numMap.insert("TM-RGNSS-03",i);i++;
    numMap.insert("TM-RGNSS-04",i);i++;
    numMap.insert("TM-RGNSS-05",i);i++;
    numMap.insert("TM-RGNSS-06",i);i++;
    numMap.insert("TM-RGNSS-07",i);i++;
    numMap.insert("TM-RGNSS-08",i);i++;
    numMap.insert("TM-RGNSS-09",i);i++;
    numMap.insert("TM-RGNSS-10",i);i++;
    numMap.insert("TM-RGNSS-11",i);i++;
    numMap.insert("TM-RGNSS-12",i);i++;
    numMap.insert("TM-RGNSS-13",i);i++;
    numMap.insert("TM-RGNSS-14",i);i++;
    numMap.insert("TM-RGNSS-15",i);i++;
    numMap.insert("TM-RGNSS-16",i);i++;
    numMap.insert("TM-RGNSS-17",i);i++;
    numMap.insert("TM-RGNSS-18",i);i++;
    numMap.insert("TM-RGNSS-19",i);i++;
    numMap.insert("TM-RGNSS-20",i);i++;
    numMap.insert("TM-RGNSS-21",i);i++;
    numMap.insert("TM-RGNSS-22",i);i++;
    numMap.insert("TM-RGNSS-23",i);i++;
    numMap.insert("TM-RGNSS-24",i);i++;
    numMap.insert("TM-RGNSS-25",i);i++;
    numMap.insert("TM-RGNSS-26",i);i++;
    numMap.insert("TM-RGNSS-27",i);i++;
    numMap.insert("TM-RGNSS-28",i);i++;
    numMap.insert("TM-RGNSS-29",i);i++;
    numMap.insert("TM-RGNSS-30",i);i++;
    numMap.insert("TM-RGNSS-31",i);i++;
    numMap.insert("TM-RGNSS-32",i);i++;
    numMap.insert("TM-RGNSS-33",i);i++;
    numMap.insert("TM-RGNSS-34",i);i++;
    numMap.insert("TM-RGNSS-35",i);i++;
    numMap.insert("TM-RGNSS-36",i);i++;
    numMap.insert("TM-RGNSS-37",i);i++;
    numMap.insert("TM-RGNSS-38",i);i++;
    numMap.insert("TM-RGNSS-39",i);i++;
    numMap.insert("TM-RGNSS-40",i);i++;
    numMap.insert("TM-RGNSS-41",i);i++;
    numMap.insert("TM-RGNSS-42",i);i++;
    numMap.insert("TM-RGNSS-43",i);i++;
    numMap.insert("TM-RGNSS-44",i);i++;
    numMap.insert("TM-RGNSS-45",i);i++;
    numMap.insert("TM-RGNSS-46",i);i++;
    numMap.insert("TM-RGNSS-47",i);i++;
    numMap.insert("TM-RGNSS-48",i);i++;
    numMap.insert("TM-RGNSS-49",i);i++;
    numMap.insert("TM-RGNSS-50",i);i++;
    numMap.insert("TM-RGNSS-51",i);i++;
    numMap.insert("TM-RGNSS-52",i);i++;
    numMap.insert("TM-RGNSS-53",i);i++;
    numMap.insert("TM-RGNSS-54",i);i++;
    numMap.insert("TM-RGNSS-55",i);i++;
    numMap.insert("TM-RGNSS-56",i);i++;
    numMap.insert("TM-RGNSS-57",i);i++;
    numMap.insert("TM-RGNSS-58",i);i++;
    numMap.insert("TM-RGNSS-59",i);i++;
    numMap.insert("TM-RGNSS-60",i);i++;
    numMap.insert("TM-RGNSS-61",i);i++;
    numMap.insert("TM-RGNSS-62",i);i++;
    numMap.insert("TM-RGNSS-63",i);i++;
    numMap.insert("TM-RGNSS-64",i);i++;
    numMap.insert("TM-RGNSS-65",i);i++;
    numMap.insert("TM-RGNSS-66",i);i++;
    numMap.insert("TM-RZH-01",i);i++;
    numMap.insert("TM-RZH-02",i);i++;
    numMap.insert("TM-RZH-03",i);i++;
    numMap.insert("TM-RZH-04",i);i++;
    numMap.insert("TM-RZH-05",i);i++;
    numMap.insert("TM-RZH-06",i);i++;
    numMap.insert("TM-RZH-07",i);i++;
    numMap.insert("TM-RZH-08",i);i++;
    numMap.insert("TM-RZH-09",i);i++;
    numMap.insert("TM-RZH-10",i);i++;
    numMap.insert("TM-RZH-11",i);i++;
    numMap.insert("TM-RZH-12",i);i++;
    numMap.insert("TM-RZH-13",i);i++;
    numMap.insert("TM-RZH-14",i);i++;
    numMap.insert("TM-RZH-15",i);i++;
    numMap.insert("TM-RZH-16",i);i++;
    numMap.insert("TM-RZH-17",i);i++;
    numMap.insert("TM-RZH-18",i);i++;
    numMap.insert("TM-RZH-19",i);i++;
    numMap.insert("TM-RZH-20",i);i++;
    numMap.insert("TM-RZH-21",i);i++;
    numMap.insert("TM-RZH-22",i);i++;
    numMap.insert("TM-RZH-23",i);i++;
    numMap.insert("TM-RZH-24",i);i++;
    numMap.insert("TM-RZH-25",i);i++;
    numMap.insert("TM-RZH-26",i);i++;
    numMap.insert("TM-RZH-27",i);i++;
    numMap.insert("TM-RZH-28",i);i++;
    numMap.insert("TM-RZH-29",i);i++;
    numMap.insert("TM-RZH-30",i);i++;
    numMap.insert("TM-RZH-31",i);i++;
    numMap.insert("TM-RZH-32",i);i++;
    numMap.insert("TM-RZH-33",i);i++;
    numMap.insert("TM-RZH-34",i);i++;
    numMap.insert("TM-RZH-35",i);i++;
    numMap.insert("TM-RZH-36",i);i++;
    numMap.insert("TM-RZH-37",i);i++;
    numMap.insert("TM-RZH-38",i);i++;
    numMap.insert("TM-RZH-39",i);i++;
    numMap.insert("TM-RZH-40",i);i++;
    numMap.insert("TM-RZH-41",i);i++;
    numMap.insert("TM-RZH-42",i);i++;
    numMap.insert("TM-RZH-43",i);i++;
    numMap.insert("TM-RZH-44",i);i++;
    numMap.insert("TM-RZH-45",i);i++;
    numMap.insert("TM-RZH-46",i);i++;
    numMap.insert("TM-RZH-47",i);i++;
    numMap.insert("TM-RZH-48",i);i++;
    numMap.insert("TM-RZH-49",i);i++;
    numMap.insert("TM-RZH-50",i);i++;
    numMap.insert("TM-RZH-51",i);i++;
    numMap.insert("TM-RZH-52",i);i++;
    numMap.insert("TM-RZH-53",i);i++;
    numMap.insert("TM-RZH-54",i);i++;
    numMap.insert("TM-RZH-55",i);i++;
    numMap.insert("TM-RZH-56",i);i++;
    numMap.insert("TM-RZH-57",i);i++;
    numMap.insert("TM-RZH-58",i);i++;
    numMap.insert("TM-RZH-59",i);i++;
    numMap.insert("TM-RZH-60",i);i++;
    numMap.insert("TM-RZH-61",i);i++;
    numMap.insert("TM-RZH-62",i);i++;
    numMap.insert("TM-RZH-63",i);i++;
    numMap.insert("TM-RZH-64",i);i++;
    numMap.insert("TM-RZH-65",i);i++;
    numMap.insert("TM-RZH-66",i);i++;
    numMap.insert("TM-RZH-67",i);i++;
    numMap.insert("TM-RZH-68",i);i++;
    numMap.insert("TM-RZH-69",i);i++;
    numMap.insert("TM-RZH-70",i);i++;
    numMap.insert("TM-RZH-71",i);i++;
    numMap.insert("TM-RZH-72",i);i++;
    numMap.insert("TM-RZH-73",i);i++;
    numMap.insert("TM-RZH-74",i);i++;
    numMap.insert("TM-RZH-75",i);i++;
    numMap.insert("TM-RZH-76",i);i++;
    numMap.insert("TM-RZH-77",i);i++;
    numMap.insert("TM-RZH-78",i);i++;
    numMap.insert("TM-RZH-79",i);i++;
    numMap.insert("TM-RZH-80",i);i++;
    numMap.insert("TM-RZH-81",i);i++;
    numMap.insert("TM-RZH-82",i);i++;
    numMap.insert("TM-RZH-83",i);i++;
    numMap.insert("TM-RZH-84",i);i++;
    numMap.insert("TM-RZH-85",i);i++;
    numMap.insert("TM-RZH-86",i);i++;
    numMap.insert("TM-RZH-87",i);i++;
    numMap.insert("TM-RZH-88",i);i++;
    numMap.insert("TM-RZH-89",i);i++;
    numMap.insert("TM-RZH-90",i);i++;
    numMap.insert("TM-RZH-91",i);i++;
    numMap.insert("TM-RZH-92",i);i++;
    numMap.insert("TM-RZH-93",i);i++;
    numMap.insert("TM-RZH-94",i);i++;
    numMap.insert("TM-RZH-95",i);i++;
    numMap.insert("TM-RZH-96",i);i++;
    numMap.insert("TM-RZH-97",i);i++;
    numMap.insert("TM-RZH-98",i);i++;
    numMap.insert("TM-RZH-99",i);i++;
    numMap.insert("TM-RZH-100",i);i++;
    numMap.insert("TM-RZH-101",i);i++;
    numMap.insert("TM-RCES-01",i);i++;
    numMap.insert("TM-RCES-02",i);i++;
    numMap.insert("TM-RCES-03",i);i++;
    numMap.insert("TM-RCES-04",i);i++;
    numMap.insert("TM-RCES-05",i);i++;
    numMap.insert("TM-RCES-06",i);i++;
    numMap.insert("TM-RCES-07",i);i++;
    numMap.insert("TM-RCES-08",i);i++;
    numMap.insert("TM-RCES-09",i);i++;
    numMap.insert("TM-RCES-10",i);i++;
    numMap.insert("TM-RCES-11",i);i++;
    numMap.insert("TM-RCES-12",i);i++;
    numMap.insert("TM-RCES-13",i);i++;
    numMap.insert("TM-RCES-14",i);i++;
    numMap.insert("TM-RCES-15",i);i++;
    numMap.insert("TM-RCES-16",i);i++;
    numMap.insert("TM-RCES-17",i);i++;
    numMap.insert("TM-RCES-18",i);i++;
    numMap.insert("TM-RCES-19",i);i++;
    numMap.insert("TM-RCES-20",i);i++;
    numMap.insert("TM-RCES-21",i);i++;
    numMap.insert("TM-RCES-22",i);i++;
    numMap.insert("TM-RCES-23",i);i++;
    numMap.insert("TM-RCES-24",i);i++;
    numMap.insert("TM-RCES-25",i);i++;
    numMap.insert("TM-RCES-26",i);i++;
    numMap.insert("TM-RCES-27",i);i++;
    numMap.insert("TM-RCES-28",i);i++;
    numMap.insert("TM-RCES-29",i);i++;
    numMap.insert("TM-RCES-30",i);i++;
    numMap.insert("TM-RCES-31",i);i++;
    numMap.insert("TM-RCES-32",i);i++;
    numMap.insert("TM-RCES-33",i);i++;
    numMap.insert("TM-RCES-34",i);i++;
    numMap.insert("TM-RCES-35",i);i++;
    numMap.insert("TM-RCES-36",i);i++;
    numMap.insert("TM-RCES-37",i);i++;
    numMap.insert("TM-RCES-38",i);i++;
    numMap.insert("TM-RCES-39",i);i++;
    numMap.insert("TM-RCES-40",i);i++;
    numMap.insert("TM-RCES-41",i);i++;
    numMap.insert("TM-RCES-42",i);i++;
    numMap.insert("TM-RCES-43",i);i++;
    numMap.insert("TM-RCES-44",i);i++;
    numMap.insert("TM-RCES-45",i);i++;
    numMap.insert("TM-RCES-46",i);i++;
    numMap.insert("TM-RCES-47",i);i++;
    numMap.insert("TM-RCES-48",i);i++;
    numMap.insert("TM-RCES-49",i);i++;
    numMap.insert("TM-RCES-50",i);i++;
    numMap.insert("TM-RCES-51",i);i++;
    numMap.insert("TM-RCES-52",i);i++;
    numMap.insert("TM-RCES-53",i);i++;
    numMap.insert("TM-RCES-54",i);i++;
    numMap.insert("TM-RCES-55",i);i++;
    numMap.insert("TM-RCES-56",i);i++;
    numMap.insert("TM-RCES-57",i);i++;
    numMap.insert("TM-RCES-58",i);i++;
    numMap.insert("TM-RCES-59",i);i++;
    numMap.insert("TM-RCES-60",i);i++;
    numMap.insert("TM-RCES-61",i);i++;
    numMap.insert("TM-RCES-62",i);i++;
    numMap.insert("TM-RCES-63",i);i++;
    numMap.insert("TM-RCES-64",i);i++;
    numMap.insert("TM-RCES-65",i);i++;
    numMap.insert("TM-RCES-66",i);i++;
    numMap.insert("TM-RCES-67",i);i++;
    numMap.insert("TM-RCES-68",i);i++;
    numMap.insert("TM-RCES-69",i);i++;
    numMap.insert("TM-RCES-70",i);i++;
    numMap.insert("TM-RCES-71",i);i++;
    numMap.insert("TM-RCES-72",i);i++;
    numMap.insert("TM-RCES-73",i);i++;
    numMap.insert("TM-RCES-74",i);i++;
    numMap.insert("TM-RCES-75",i);i++;
    numMap.insert("TM-RCES-76",i);i++;
    numMap.insert("TM-RCES-77",i);i++;
    numMap.insert("TM-RCES-78",i);i++;
    numMap.insert("TM-RCES-79",i);i++;
    numMap.insert("TM-RCES-80",i);i++;
    numMap.insert("TM-RCES-81",i);i++;
    numMap.insert("TM-RCES-82",i);i++;
    numMap.insert("TM-RCES-83",i);i++;
    numMap.insert("TM-RCES-84",i);i++;
    numMap.insert("TM-RCES-85",i);i++;
    numMap.insert("TM-RCES-86",i);i++;
    numMap.insert("TM-RCES-87",i);i++;
    numMap.insert("TM-RCES-88",i);i++;
    numMap.insert("TM-RCES-89",i);i++;
    numMap.insert("TM-RCES-90",i);i++;
    numMap.insert("TM-RCES-93",i);i++;
    numMap.insert("TM-RCES-94",i);i++;
    numMap.insert("TM-RCES-95",i);i++;
    numMap.insert("TM-RCES-96",i);i++;
    numMap.insert("TM-RCES-97",i);i++;
    numMap.insert("TM-RCES-98",i);i++;
    numMap.insert("TM-RCES-99",i);i++;
    numMap.insert("TM-RCES-100",i);i++;
    numMap.insert("TM-RCES-101",i);i++;
    numMap.insert("TM-RCES-102",i);i++;
    numMap.insert("TM-RCES-103",i);i++;
    numMap.insert("TM-RCES-104",i);i++;
    numMap.insert("TM-RCES-105",i);i++;
    numMap.insert("TM-RCES-106",i);i++;
    numMap.insert("TM-RCES-107",i);i++;
    numMap.insert("TM-RCES-108",i);i++;
    numMap.insert("TM-RCES-109",i);i++;
    numMap.insert("TM-RCES-110",i);i++;
    numMap.insert("TM-RCES-111",i);i++;
    numMap.insert("TM-RCES-112",i);i++;
    numMap.insert("TM-RCES-113",i);i++;
    numMap.insert("TM-RCES-114",i);i++;
    numMap.insert("TM-RCES-115",i);i++;
    numMap.insert("TM-RCES-116",i);i++;
    numMap.insert("TM-RCES-117",i);i++;
    numMap.insert("TM-RCES-118",i);i++;
    numMap.insert("TM-RCES-119",i);i++;
    numMap.insert("TM-RCES-120",i);i++;
    numMap.insert("TM-RCES-121",i);i++;
    numMap.insert("TM-RCES-122",i);i++;
    numMap.insert("TM-RCES-123",i);i++;
    numMap.insert("TM-RCES-124",i);i++;
    numMap.insert("TM-RCES-125",i);i++;
    numMap.insert("TM-RCES-126",i);i++;
    numMap.insert("TM-RCES-127",i);i++;
    numMap.insert("TM-RCES-128",i);i++;
    numMap.insert("TM-RCES-129",i);i++;
    numMap.insert("TM-RCES-130",i);i++;
    numMap.insert("TM-RCES-131",i);i++;
    numMap.insert("TM-RCES-132",i);i++;
    numMap.insert("TM-RCES-133",i);i++;
    numMap.insert("TM-RCES-134",i);i++;
    numMap.insert("TM-RCES-135",i);i++;
    numMap.insert("TM-RCES-136",i);i++;
    numMap.insert("TM-RCES-137",i);i++;
    numMap.insert("TM-RCES-138",i);i++;
    numMap.insert("TM-RCES-139",i);i++;
    numMap.insert("TM-RCES-140",i);i++;
    numMap.insert("TM-RCES-141",i);i++;
    numMap.insert("TM-RCES-142",i);i++;
    numMap.insert("TM-RCES-143",i);i++;
    numMap.insert("TM-RCES-144",i);i++;
    numMap.insert("TM-RCES-145",i);i++;
    numMap.insert("TM-RCES-146",i);i++;
    numMap.insert("TM-RCES-147",i);i++;
    numMap.insert("TM-RCES-148",i);i++;
    numMap.insert("TM-RCES-149",i);i++;
    numMap.insert("TM-RCES-150",i);i++;
    numMap.insert("TM-RCES-151",i);i++;
    numMap.insert("TM-RCES-152",i);i++;
    numMap.insert("TM-RCES-153",i);i++;
    numMap.insert("TM-RCES-154",i);i++;
    numMap.insert("TM-RCES-155",i);i++;
    numMap.insert("TM-RCES-156",i);i++;
    numMap.insert("TM-RCES-157",i);i++;
    numMap.insert("TM-RCES-158",i);i++;
    numMap.insert("TM-RCES-159",i);i++;
    numMap.insert("TM-RCES-160",i);i++;
    numMap.insert("TM-RCES-161",i);i++;
    numMap.insert("TM-RCES-162",i);i++;
    numMap.insert("TM-RCES-163",i);i++;
    numMap.insert("TM-RCES-164",i);i++;
    numMap.insert("TM-RCES-165",i);i++;
    numMap.insert("TM-RCES-166",i);i++;
    numMap.insert("TM-RCES-167",i);i++;
    numMap.insert("TM-RCES-168",i);i++;
    numMap.insert("TM-RCES-169",i);i++;
    numMap.insert("TM-RCES-170",i);i++;
    numMap.insert("TM-RCES-171",i);i++;
    numMap.insert("TM-RCES-172",i);i++;
    numMap.insert("TM-RCES-173",i);i++;
    numMap.insert("TM-RCES-174",i);i++;
    numMap.insert("TM-RCES-175",i);i++;
    numMap.insert("TM-RCES-176",i);i++;
    numMap.insert("TM-RCES-177",i);i++;
    numMap.insert("TM-RCES-178",i);i++;
    numMap.insert("TM-RCES-179",i);i++;
    numMap.insert("TM-RCES-180",i);i++;
    numMap.insert("TM-RCES-181",i);i++;
    numMap.insert("TM-RCES-182",i);i++;
    numMap.insert("TM-RCES-183",i);i++;
    numMap.insert("TM-RCES-184",i);i++;
    numMap.insert("TM-RCES-185",i);i++;
    numMap.insert("TM-RCES-186",i);i++;
    numMap.insert("TM-RCES-187",i);i++;
    numMap.insert("TM-RCES-188",i);i++;
    numMap.insert("TM-RCES-189",i);i++;
    numMap.insert("TM-RCES-190",i);i++;
    numMap.insert("TM-RCES-191",i);i++;
    numMap.insert("TM-RCES-192",i);i++;
    numMap.insert("TM-RCES-193",i);i++;
    numMap.insert("TM-RCES-194",i);i++;
    numMap.insert("TM-RCES-195",i);i++;
    numMap.insert("TM-RCES-196",i);i++;
    numMap.insert("TM-RCES-197",i);i++;
    numMap.insert("TM-RCES-198",i);i++;
    numMap.insert("TM-RCES-199",i);i++;
    numMap.insert("TM-RCES-200",i);i++;
    numMap.insert("TM-RCES-201",i);i++;
    numMap.insert("TM-RCES-202",i);i++;
    numMap.insert("TM-RCES-203",i);i++;
    numMap.insert("TM-RCES-204",i);i++;
    numMap.insert("TM-RCES-205",i);i++;
    numMap.insert("TM-RCES-206",i);i++;
    numMap.insert("TM-RCES-207",i);i++;
    numMap.insert("TM-RCES-208",i);i++;
    numMap.insert("TM-RCES-209",i);i++;
    numMap.insert("TM-RCES-210",i);i++;
    numMap.insert("TM-RCES-211",i);i++;
    numMap.insert("TM-RCES-212",i);i++;
    numMap.insert("TM-RCES-213",i);i++;
    numMap.insert("TM-RCES-214",i);i++;
    numMap.insert("TM-RCES-215",i);i++;
    numMap.insert("TM-RCES-216",i);i++;
    numMap.insert("TM-RCES-217",i);i++;
    numMap.insert("TM-RCES-218",i);i++;
    numMap.insert("TM-RCES-219",i);i++;
    numMap.insert("TM-RCES-220",i);i++;
    numMap.insert("TM-RCES-221",i);i++;
    numMap.insert("TM-RCES-222",i);i++;
    numMap.insert("TM-RCES-223",i);i++;
    numMap.insert("TM-RCES-224",i);i++;
    numMap.insert("TM-RCES-225",i);i++;
    numMap.insert("TM-RCES-226",i);i++;
    numMap.insert("TM-RCES-227",i);i++;
    numMap.insert("TM-RCES-228",i);i++;
    numMap.insert("TM-RCES-229",i);i++;
    numMap.insert("TM-RCES-230",i);i++;
    numMap.insert("TM-RCES-231",i);i++;
    numMap.insert("TM-RCES-232",i);i++;
    numMap.insert("TM-RCES-233",i);i++;
    numMap.insert("TM-RCES-234",i);i++;
    numMap.insert("TM-RCES-235",i);i++;
    numMap.insert("TM-RCES-236",i);i++;
    numMap.insert("TM-RCES-237",i);i++;
    numMap.insert("TM-RCES-238",i);i++;
    numMap.insert("TM-ROS-01",i);i++;
    numMap.insert("TM-ROS-02",i);i++;
    numMap.insert("TM-ROS-03",i);i++;
    numMap.insert("TM-ROS-04",i);i++;
    numMap.insert("TM-ROS-05",i);i++;
    numMap.insert("TM-ROS-06",i);i++;
}

void PacController::SavePacData(QByteArray byteArray)
{
    emit Send2Save(byteArray);
}

//收到检测指令，设置检测标志为true，设置检测时间
void PacController::GetStandardState(QStringList byteArray)
{
    detectFlag = true;
//    count = 6; //设置12帧的检测时间
    //检测时间更改
    count = byteArray.at(1).toInt();
    qDebug()<<"Delay:"<<count;
    cStringList = byteArray;
}
//指令检测完成，检测标志为false，count归零
void PacController::CommandOver()
{
    detectFlag = false;
    count = 0;
}

//检测完成状态
void PacController::DetectisOver(QString command, QStringList resultList)
{
    emit ReSendCommand(command, resultList);
}
//指令未匹配，检测状态
void PacController::CommandnotFind(QString command)
{
    CommandOver();
    emit DetectFailed(command);
}
//解析、检测结果传出
//void PacController::GetExplainInfo(int sysName, QVariantList valueList, QVariantList hexList,QStringList resultList)
//{
//    emit SendExplainInfo(sysName, valueList, hexList,resultList);
//}

void PacController::GetExplainInfo(QVariant map2Display,QStringList resultList)
{
    emit SendExplainInfo(map2Display, resultList);
}


#include "treewidgettelemetry.h"

treeWidgetTelemetry::treeWidgetTelemetry(QWidget *parent) : QWidget(parent)
{

}

treeWidgetTelemetry::~treeWidgetTelemetry()
{

}

QTreeWidgetItem * treeWidgetTelemetry::buildTree()
{
    //根节点
    QTreeWidgetItem * telemetryList = new QTreeWidgetItem(QStringList()<<"遥测项列表");

    //第二层节点
    QTreeWidgetItem * fixedTelemetry = new QTreeWidgetItem(QStringList()<<"固定遥测");
    QTreeWidgetItem * realTimeTelemetry = new QTreeWidgetItem(QStringList()<<"实时遥测");
    QTreeWidgetItem * delayTelemetry = new QTreeWidgetItem(QStringList()<<"延时遥测");
    QTreeWidgetItem * reservedTelemetry =new QTreeWidgetItem(QStringList()<<"预留");
    QTreeWidgetItem * projectTelemetry = new QTreeWidgetItem(QStringList()<<"工程遥测");
    QTreeWidgetItem * diyDataTable = new QTreeWidgetItem(QStringList()<<"自定义波道表格");
    QTreeWidgetItem * diyDataPlot = new QTreeWidgetItem(QStringList()<<"自定义数据波形图");
    QTreeWidgetItem * dataInterpret = new QTreeWidgetItem(QStringList()<<"数据判读");
    QTreeWidgetItem * testTelemetry = new QTreeWidgetItem(QStringList()<<"测试用");

    //第二层节点插入根节点
    telemetryList->addChildren(QList<QTreeWidgetItem *>() << fixedTelemetry << realTimeTelemetry << delayTelemetry << reservedTelemetry
                               <<projectTelemetry << diyDataTable << diyDataPlot << dataInterpret<<testTelemetry);

    //叶节点
    QTreeWidgetItem * r1RTime0_PKG = new QTreeWidgetItem(QStringList()<<"R1 实时遥测0_卫星实时遥测数据");
    QTreeWidgetItem * r2Delay1_OrbitalTestModel = new QTreeWidgetItem(QStringList()<<"R2 延时遥测1_轨道试验模式");
    QTreeWidgetItem * r3Delay2_OrbitalNnTestModel = new QTreeWidgetItem(QStringList()<<"R3 延时遥测2_轨道非试验模式");
    QTreeWidgetItem * r4Delay3_OS = new QTreeWidgetItem(QStringList()<<"R4 延时遥测3_OS操作系统");
    QTreeWidgetItem * r5Delay4_ADCS = new QTreeWidgetItem(QStringList()<<"R5 延时遥测4_ADCS姿控");
    QTreeWidgetItem * r6Delay5_EPS = new QTreeWidgetItem(QStringList()<<"R6 延时遥测5_EPS电源");
    QTreeWidgetItem * r7Delay6_ISRS = new QTreeWidgetItem(QStringList()<<"R7 延时遥测6_ISRS星间测距");
    QTreeWidgetItem * r8Delay7_GNSS1 = new QTreeWidgetItem(QStringList()<<"R8 延时遥测7_GNSS1");
    QTreeWidgetItem * r9Delay8_CES = new QTreeWidgetItem(QStringList()<<"R9 延时遥测8_CES综合电子");
    QTreeWidgetItem * r10Reserved = new QTreeWidgetItem(QStringList()<<"R10 预留");
    QTreeWidgetItem * r11Delay9_Load = new QTreeWidgetItem(QStringList()<<"R11 延时遥测9_载荷");
    QTreeWidgetItem * r12Delay10_ADCState = new QTreeWidgetItem(QStringList()<<"R12 延时遥测10_姿控状态量");
    QTreeWidgetItem * r13Delay11_HistoryRTime = new QTreeWidgetItem(QStringList()<<"R13 延时遥测11_历史实时遥测");
    QTreeWidgetItem * r14FillFrame = new QTreeWidgetItem(QStringList()<<"R14 填充帧");
    QTreeWidgetItem * r15SelfTelemetry = new QTreeWidgetItem(QStringList()<<"R15 自遥测");
    QTreeWidgetItem * r16Delay12_GNSS3 = new QTreeWidgetItem(QStringList()<<"R16 延时遥测12_GNSS3");
    QTreeWidgetItem * r17Delay13_GNSS4 = new QTreeWidgetItem(QStringList()<<"R17 延时遥测13_GNSS4");
    QTreeWidgetItem * r18Delay14_RTOD = new QTreeWidgetItem(QStringList()<<"R18 延时遥测14_RTOD");
    QTreeWidgetItem * r19RTime1_MCS_A = new QTreeWidgetItem(QStringList()<<"R19 实时遥测1_测控系统A机");
    QTreeWidgetItem * r20RTime2_MCS_B = new QTreeWidgetItem(QStringList()<<"R20 实时遥测2_测控系统B机");
    QTreeWidgetItem * r21RTime3_OrbitalCtrl = new QTreeWidgetItem(QStringList()<<"R21 实时遥测3_轨控系统");
    QTreeWidgetItem * r22RTime4_ADCS = new QTreeWidgetItem(QStringList()<<"R22 实时遥测4_姿控系统");
    QTreeWidgetItem * r23RTime5_EPS = new QTreeWidgetItem(QStringList()<<"R23 实时遥测5_电源系统");
    QTreeWidgetItem * r24RTime6_GPS = new QTreeWidgetItem(QStringList()<<"R24 实时遥测6_GPS系统");
    QTreeWidgetItem * r25RTime7_Load = new QTreeWidgetItem(QStringList()<<"R25 实时遥测7_载荷");
    QTreeWidgetItem * r26RTime8_CES = new QTreeWidgetItem(QStringList()<<"R26 实时遥测8_综合电子系统");
    QTreeWidgetItem * r27RTime9_OS = new QTreeWidgetItem(QStringList()<<"R27 实时遥测9_操作系统");

    //实时遥测
    realTimeTelemetry->addChildren(QList<QTreeWidgetItem *>() << r1RTime0_PKG << r13Delay11_HistoryRTime
                                   << r19RTime1_MCS_A << r20RTime2_MCS_B << r21RTime3_OrbitalCtrl << r22RTime4_ADCS
                                   << r23RTime5_EPS << r24RTime6_GPS << r25RTime7_Load << r26RTime8_CES << r27RTime9_OS);

    //延时遥测
    delayTelemetry->addChildren(QList<QTreeWidgetItem *>() << r2Delay1_OrbitalTestModel << r3Delay2_OrbitalNnTestModel
                                << r4Delay3_OS << r5Delay4_ADCS << r6Delay5_EPS << r7Delay6_ISRS << r8Delay7_GNSS1
                                << r9Delay8_CES << r11Delay9_Load << r12Delay10_ADCState << r13Delay11_HistoryRTime
                                << r16Delay12_GNSS3 << r17Delay13_GNSS4 << r18Delay14_RTOD);

    //预留
    reservedTelemetry->addChild(r10Reserved);

    testTelemetry->addChildren(QList<QTreeWidgetItem *>() << r14FillFrame << r15SelfTelemetry);

    //设置初始为收拢状态
    r1RTime0_PKG->setCheckState(0,Qt::Unchecked);
    r2Delay1_OrbitalTestModel->setCheckState(0,Qt::Unchecked);
    r3Delay2_OrbitalNnTestModel->setCheckState(0,Qt::Unchecked);
    r4Delay3_OS->setCheckState(0,Qt::Unchecked);
    r5Delay4_ADCS->setCheckState(0,Qt::Unchecked);
    r6Delay5_EPS->setCheckState(0,Qt::Unchecked);
    r7Delay6_ISRS->setCheckState(0,Qt::Unchecked);
    r8Delay7_GNSS1->setCheckState(0,Qt::Unchecked);
    r9Delay8_CES->setCheckState(0,Qt::Unchecked);
    r10Reserved->setCheckState(0,Qt::Unchecked);
    r11Delay9_Load->setCheckState(0,Qt::Unchecked);
    r12Delay10_ADCState->setCheckState(0,Qt::Unchecked);
    r13Delay11_HistoryRTime->setCheckState(0,Qt::Unchecked);
    r14FillFrame->setCheckState(0,Qt::Unchecked);
    r15SelfTelemetry->setCheckState(0,Qt::Unchecked);
    r16Delay12_GNSS3->setCheckState(0,Qt::Unchecked);
    r17Delay13_GNSS4->setCheckState(0,Qt::Unchecked);
    r18Delay14_RTOD->setCheckState(0,Qt::Unchecked);
    r19RTime1_MCS_A->setCheckState(0,Qt::Unchecked);
    r20RTime2_MCS_B->setCheckState(0,Qt::Unchecked);
    r21RTime3_OrbitalCtrl->setCheckState(0,Qt::Unchecked);
    r22RTime4_ADCS->setCheckState(0,Qt::Unchecked);
    r23RTime5_EPS->setCheckState(0,Qt::Unchecked);
    r24RTime6_GPS->setCheckState(0,Qt::Unchecked);
    r25RTime7_Load->setCheckState(0,Qt::Unchecked);
    r26RTime8_CES->setCheckState(0,Qt::Unchecked);
    r27RTime9_OS->setCheckState(0,Qt::Unchecked);
    return telemetryList;
}

#include "telemetryform.h"
#include "ui_telemetryform.h"
#include <QTableWidget>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include <QString>
//#include <QVariantList>

QMap<QString,QStringList> teleSysMap; //分系统对应的数据编号
QMap<QString,QString> findNameMap;    //数据编号对应的解析（此处只使用数据名）
QStringList teleSysName;     //分系统名，表名 数字

TelemetryForm::TelemetryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TelemetryForm)
{
    ui->setupUi(this);

    QString fileName = "dataParse_v1.json";
    OpenJsonFile(fileName);

    /*******************************************************************************************/
    /*******************************************************************************************/
    //treeWidget 遥测数据显示选择树

    topItem = telemetryList->buildTree();
    ui->treeWidgetTelemetry->addTopLevelItem(topItem);
    ui->treeWidgetTelemetry->expandItem(topItem);


    //单击一行选中，选中父节点选中，联动tableWidget.
    //显示分系统状态，使用icon即可



    //tabWidgetDisplay 遥测数据展示tab(双击树控件Item打开tab，显示表格)
    ui->tabWidgetDisplay->setTabsClosable(true);
    //显示标签页关闭按钮
    connect(ui->tabWidgetDisplay,&QTabWidget::tabCloseRequested,ui->tabWidgetDisplay,&QTabWidget::removeTab);



    ui->tabWidgetDisplay->removeTab(1);
    ui->tabWidgetDisplay->removeTab(0);
    ui->tabWidgetDisplay->clear();
    ////////////////////////////////////////////////////////////////////////////////////////////


    /*******************************************************************************************/
    /*******************************************************************************************/
    //插入显示页面表格（以分系统显示）

    R1_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R1_tableForm,"R1 实时遥测0_卫星实时遥测数据");
    connect(this,&TelemetryForm::R1_Display,R1_tableForm,&TableForm::UpdataUI);

    R2_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R2_tableForm,"R2 延时遥测1_轨道试验模式");

    R3_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R3_tableForm,"R3 延时遥测2_轨道非试验模式");

     R4_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R4_tableForm,"R4 延时遥测3_OS操作系统");

     R5_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R5_tableForm,"R5 延时遥测4_ADCS姿控");

     R6_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R6_tableForm,"R6 延时遥测5_EPS电源");

     R7_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R7_tableForm,"R7 延时遥测6_ISRS星间测距");

     R8_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R8_tableForm,"R8 延时遥测7_GNSS1");

     R9_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R9_tableForm,"R9 延时遥测8_CES综合电子");

     R10_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R10_tableForm,"R10 预留");

     R11_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R11_tableForm,"R11 延时遥测9_载荷");

     R12_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R12_tableForm,"R12 延时遥测10_姿控状态量");

     R13_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R13_tableForm,"R13 延时遥测11_历史实时遥测");

     R14_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R14_tableForm,"R14 填充帧");

     R15_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R15_tableForm,"R15 自遥测");

     R16_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R16_tableForm,"R16 延时遥测12_GNSS3");

     R17_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R17_tableForm,"R17 延时遥测13_GNSS4");

     R18_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R18_tableForm,"R18 延时遥测14_RTOD");

    R19_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R19_tableForm,"R19_延时遥测11_测控系统A机");
    //初始化R19表
    connect(this,&TelemetryForm::R19_Init,R19_tableForm,&TableForm::InitTable);
//    emit R19_Init(R19_Name(),R19_Num());
    emit R19_Init(GetNameFromMap("19"),teleSysMap.value("19"));
    //设置R19表的更新信号槽
    connect(this,&TelemetryForm::R19_Display,R19_tableForm,&TableForm::UpdataUI);

    R20_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R20_tableForm,"R20 实时遥测2_测控系统B机");
    connect(this,&TelemetryForm::R20_Init,R20_tableForm,&TableForm::InitTable);
    emit R20_Init(R20_Name(),R20_Num());
//    emit R26_Init(GetNameFromMap("20"),teleSysMap.value("20"));
    connect(this,&TelemetryForm::R20_Display,R20_tableForm,&TableForm::UpdataUI);

    R21_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R21_tableForm,"R21 实时遥测3_轨控系统");
    connect(this,&TelemetryForm::R21_Init,R21_tableForm,&TableForm::InitTable);
//    emit R21_Init(R21_Name(),R21_Num());
    emit R21_Init(GetNameFromMap("21"),teleSysMap.value("21"));
    connect(this,&TelemetryForm::R21_Display,R21_tableForm,&TableForm::UpdataUI);

    R22_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R22_tableForm,"R22 实时遥测4_姿控系统");
    connect(this,&TelemetryForm::R22_Init,R22_tableForm,&TableForm::InitTable);
//    emit R22_Init(R22_Name(),R22_Num());
    emit R22_Init(GetNameFromMap("22"),teleSysMap.value("22"));
    connect(this,&TelemetryForm::R22_Display,R22_tableForm,&TableForm::UpdataUI);

    R23_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R23_tableForm,"R23 实时遥测5_电源系统");
    connect(this,&TelemetryForm::R23_Init,R23_tableForm,&TableForm::InitTable);
//    emit R23_Init(R23_Name(),R23_Num());
    emit R23_Init(GetNameFromMap("23"),teleSysMap.value("23"));
    connect(this,&TelemetryForm::R23_Display,R23_tableForm,&TableForm::UpdataUI);

    R24_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R24_tableForm,"R24 实时遥测6_GPS系统");
    connect(this,&TelemetryForm::R24_Init,R24_tableForm,&TableForm::InitTable);
//    emit R24_Init(R24_Name(),R24_Num());
    emit R24_Init(GetNameFromMap("24"),teleSysMap.value("24"));
    connect(this,&TelemetryForm::R24_Display,R24_tableForm,&TableForm::UpdataUI);

    R25_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R25_tableForm,"R25 实时遥测7_载荷");
    connect(this,&TelemetryForm::R25_Init,R25_tableForm,&TableForm::InitTable);
//    emit R25_Init(R25_Name(),R25_Num());
    emit R25_Init(GetNameFromMap("25"),teleSysMap.value("25"));
    connect(this,&TelemetryForm::R25_Display,R25_tableForm,&TableForm::UpdataUI);

    R26_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R26_tableForm,"R26 实时遥测8_综合电子系统");
    connect(this,&TelemetryForm::R26_Init,R26_tableForm,&TableForm::InitTable);
//    emit R26_Init(R26_Name(),R26_Num());
    emit R26_Init(GetNameFromMap("26"),teleSysMap.value("26"));
    connect(this,&TelemetryForm::R26_Display,R26_tableForm,&TableForm::UpdataUI);

    R27_tableForm = new TableForm(this);
    ui->tabWidgetDisplay->insertTab(0,R27_tableForm,"R27 实时遥测9_操作系统");
    connect(this,&TelemetryForm::R27_Init,R27_tableForm,&TableForm::InitTable);
//    emit R27_Init(R27_Name(),R27_Num());
    emit R27_Init(GetNameFromMap("27"),teleSysMap.value("27"));
    connect(this,&TelemetryForm::R27_Display,R27_tableForm,&TableForm::UpdataUI);

    for (int i = 0; i<27; i++ ) {
        ui->tabWidgetDisplay->removeTab(0);
    }

    //双击树的最小项，打开对应的表格
    connect(ui->treeWidgetTelemetry,&QTreeWidget::itemDoubleClicked,[=](){
        //通过判断是否是子节点,决定是否插入新的tab窗口
        if(ui->treeWidgetTelemetry->currentItem()->childCount() == 0){
            QString tmp = ui->treeWidgetTelemetry->currentItem()->text(ui->treeWidgetTelemetry->currentColumn());
            int pacName = tmp.mid(1,2).toInt();
            //            qDebug()<<pacName;
            switch (pacName) {   //设置打开标签页的标题
            case 1: ui->tabWidgetDisplay->insertTab(0,R1_tableForm,"R1 实时遥测0_卫星实时遥测数据");break;
            case 2: ui->tabWidgetDisplay->insertTab(0,R2_tableForm,"R2 延时遥测1_轨道试验模式");break;
            case 3: ui->tabWidgetDisplay->insertTab(0,R3_tableForm,"R3 延时遥测2_轨道非试验模式");break;
            case 4: ui->tabWidgetDisplay->insertTab(0,R4_tableForm,"R4 延时遥测3_OS操作系统");break;
            case 5: ui->tabWidgetDisplay->insertTab(0,R5_tableForm,"R5 延时遥测4_ADCS姿控");break;
            case 6: ui->tabWidgetDisplay->insertTab(0,R6_tableForm,"R6 延时遥测5_EPS电源");break;
            case 7: ui->tabWidgetDisplay->insertTab(0,R7_tableForm,"R7 延时遥测6_ISRS星间测距");break;
            case 8: ui->tabWidgetDisplay->insertTab(0,R8_tableForm,"R8 延时遥测7_GNSS1");break;
            case 9: ui->tabWidgetDisplay->insertTab(0,R9_tableForm,"R9 延时遥测8_CES综合电子");break;
            case 10: ui->tabWidgetDisplay->insertTab(0,R10_tableForm,"R10 预留");break;
            case 11: ui->tabWidgetDisplay->insertTab(0,R11_tableForm,"R11 延时遥测9_载荷");break;
            case 12: ui->tabWidgetDisplay->insertTab(0,R12_tableForm,"R12 延时遥测10_姿控状态量");break;
            case 13: ui->tabWidgetDisplay->insertTab(0,R13_tableForm,"R13 延时遥测11_历史实时遥测");break;
            case 14: ui->tabWidgetDisplay->insertTab(0,R14_tableForm,"R14 填充帧");break;
            case 15: ui->tabWidgetDisplay->insertTab(0,R15_tableForm,"R15 自遥测");break;
            case 16: ui->tabWidgetDisplay->insertTab(0,R16_tableForm,"R16 延时遥测12_GNSS3");break;
            case 17: ui->tabWidgetDisplay->insertTab(0,R17_tableForm,"R17 延时遥测13_GNSS4");break;
            case 18: ui->tabWidgetDisplay->insertTab(0,R18_tableForm,"R18 延时遥测14_RTOD");break;
            case 19: ui->tabWidgetDisplay->insertTab(0,R19_tableForm,"R19 实时遥测1_测控系统A机");break;
            case 20: ui->tabWidgetDisplay->insertTab(0,R20_tableForm,"R20 实时遥测2_测控系统B机");break;
            case 21: ui->tabWidgetDisplay->insertTab(0,R21_tableForm,"R21 实时遥测3_轨控系统");break;
            case 22: ui->tabWidgetDisplay->insertTab(0,R22_tableForm,"R22 实时遥测4_姿控系统");break;
            case 23: ui->tabWidgetDisplay->insertTab(0,R23_tableForm,"R23 实时遥测5_电源系统");break;
            case 24: ui->tabWidgetDisplay->insertTab(0,R24_tableForm,"R24 实时遥测6_GPS系统");break;
            case 25: ui->tabWidgetDisplay->insertTab(0,R25_tableForm,"R25 实时遥测7_载荷");break;
            case 26: ui->tabWidgetDisplay->insertTab(0,R26_tableForm,"R26 实时遥测8_综合电子系统");break;
            case 27: ui->tabWidgetDisplay->insertTab(0,R27_tableForm,"R27 实时遥测9_操作系统");break;
            default:break;
            }
            qDebug()<<ui->treeWidgetTelemetry->currentItem()->text(ui->treeWidgetTelemetry->currentColumn());
            ui->tabWidgetDisplay->setCurrentIndex(0);
        }
    });


}

TelemetryForm::~TelemetryForm()
{
    delete R1_tableForm;
    delete R2_tableForm;
    delete R3_tableForm;
    delete R4_tableForm;
    delete R5_tableForm;
    delete R6_tableForm;
    delete R7_tableForm;
    delete R8_tableForm;
    delete R9_tableForm;
    delete R10_tableForm;
    delete R11_tableForm;
    delete R12_tableForm;
    delete R13_tableForm;
    delete R14_tableForm;
    delete R15_tableForm;
    delete R16_tableForm;
    delete R17_tableForm;
    delete R18_tableForm;
    delete R19_tableForm;
    delete R20_tableForm;
    delete R21_tableForm;
    delete R22_tableForm;
    delete R23_tableForm;
    delete R24_tableForm;
    delete R25_tableForm;
    delete R26_tableForm;
    delete R27_tableForm;
//    delete telemetryList;
    delete topItem;
    delete ui;
    qDebug()<<"析构 TelemetryForm";
}

void TelemetryForm::OpenJsonFile(QString fileName)
{
    QString fileDir = "../"+fileName;
    QFile file(fileDir);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString value = file.readAll();
    file.close();

    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(),&parseJsonErr);
    if(!(parseJsonErr.error == QJsonParseError::NoError))
    {
        qDebug()<<tr("解析json文件错误！");
        return;
    }
    QJsonObject jsonObject = document.object();

    QJsonValue configValueList = jsonObject.value(QStringLiteral("config"));

    foreach(QString i, configValueList.toObject().keys()){
        QJsonArray array = configValueList.toObject().value(i).toArray();
        QStringList subSys;
        for(int k = 0;k<array.size();k++)
        {
            subSys<<array.at(k).toString();
        }
        teleSysMap.insert(i,subSys);
        teleSysName<<i;
    }

    if(jsonObject.contains(QStringLiteral("parse")))
    {
        QJsonValue arrayValue = jsonObject.value(QStringLiteral("parse"));
        if(arrayValue.isArray())
        {
            QJsonArray parseArray = arrayValue.toArray();
            for (int i = 0; i<parseArray.size(); i++ ) {
                QJsonObject parseItem = parseArray.at(i).toObject();
                QString dataName = parseItem.keys().at(0);
                QJsonObject item = parseItem.begin()->toObject();
                QString infoName = item.value(QStringLiteral("name")).toString();
                findNameMap.insert(dataName,infoName);
            }
        }
    }
//    qDebug()<<teleSysMap;
//    qDebug()<<findNameMap;
}

QStringList TelemetryForm::GetNameFromMap(QString sysName)
{
    QStringList nameList;
    QStringList numList;
    numList = teleSysMap.value(sysName);
    for (int i = 0;i<numList.size(); i++ ) {
        nameList<<findNameMap.value(numList.at(i));
    }
    return nameList;

}

void TelemetryForm::RecvExplainInfo(QVariant map2Display, QStringList resultList)
{
    QMap<QString,QStringList> displayMap = map2Display.value<QMap<QString,QStringList>>();
    qDebug()<<"显示结果："<<displayMap.size();
    for (int i=0; i<teleSysName.size() ; i++ ) {
        QString tableName = teleSysName.at(i);
        QStringList sysNumList = teleSysMap.value(tableName);
        QVariantList valueList;
        QVariantList hexList;
        for (int j=0;j<sysNumList.size() ; j++ ) {
            hexList<<displayMap.value(sysNumList.at(j)).at(1);
            valueList<<displayMap.value(sysNumList.at(j)).at(2);
//            flagList<<displayMap.value(sysNumList.at(j)).at(2)
        }
        switch (tableName.toInt()) {
        case 19:
            emit R19_Display(valueList,hexList,resultList.mid(0,valueList.size()));
            break;
        case 21:
            emit R21_Display(valueList,hexList,resultList.mid(0,valueList.size()));
            break;
        case 22:
            emit R22_Display(valueList,hexList,resultList.mid(0,valueList.size()));
            break;
        case 23:
            emit R23_Display(valueList,hexList,resultList.mid(0,valueList.size()));
            break;
        case 24:
            emit R24_Display(valueList,hexList,resultList.mid(0,valueList.size()));
            break;
        case 25:
            emit R25_Display(valueList,hexList,resultList.mid(0,valueList.size()));
            break;
        case 26:
            emit R26_Display(valueList,hexList,resultList.mid(0,valueList.size()));
            break;
        case 27:
            emit R27_Display(valueList,hexList,resultList.mid(0,valueList.size()));
            break;
        default:
            break;
        }
    }



    //检测结果在遥测界面显示
    ui->errorText->append(resultList.at(0));
}

































//显示遥测数据解析与检测的结构
//void TelemetryForm::RecvExplainInfo(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList)
//{
//    switch (sysName) {
//    case 1:
//        emit R19_Display(valueList.mid(0,55),hexList.mid(0,55),resultList.mid(0,55));   //R19表
//        emit R20_Display(valueList.mid(55,55),hexList.mid(55,55),resultList.mid(55,55));//R20表
//        emit R21_Display(valueList.mid(110,63),hexList.mid(110,63),resultList.mid(110,63));//R21表
//        emit R22_Display(valueList.mid(173,173),hexList.mid(173,173),resultList.mid(173,173));//R22表
//        emit R23_Display(valueList.mid(346,141),hexList.mid(346,141),resultList.mid(346,141));//R23表
//        emit R24_Display(valueList.mid(487,66),hexList.mid(487,66),resultList.mid(487,66));//R24表
//        emit R25_Display(valueList.mid(553,101),hexList.mid(553,101),resultList.mid(553,101));//R25表
//        emit R26_Display(valueList.mid(654,236),hexList.mid(654,236),resultList.mid(654,236));//R26表
//        emit R27_Display(valueList.mid(890,6),hexList.mid(890,6),resultList.mid(890,6));//R27表
//        break;
//    case 2:break;
//    case 3:break;
//    case 4:break;
//    case 5:break;
//    case 6:break;
//    case 7:break;
//    case 8:break;
//    case 9:break;
//    case 10:break;
//    case 11:break;
//    case 12:break;
//    case 13:break;
//    case 14:break;
//    case 15:break;
//    case 16:break;
//    case 17:break;
//    case 18:break;
//    default:break;
//    }
//}










#include "rcform.h"
#include "ui_rcform.h"
#include <QDebug>
#include <QMap>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

//QMap<int,QString> nameMap;

//<分系统名，指令名List>
QMap<QString,QStringList> sysOrderNameMap;

//<指令名，规定格式指令内容（指令类型，指令，延时，对应标准状态）>
QMap<QString,QStringList> orderContentMap;


RCForm::RCForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RCForm)
{
    ui->setupUi(this);

    /*******************************************************************************************/
    /*******************************************************************************************/
    //comboBox  开关指令类型

    ui->comboBoxSwitchType->addItems(QStringList()<<"明指令"<<"密指令"<<"加解密内部指令"<<"间接指令");

    //默认没有内容
    ui->comboBoxSwitchType->setCurrentIndex(-1);

    //明指令 不能使用  “开关指令加密”
    //创建函数指针(判断comboBox选择的哪一个)
    void(QComboBox:: * changeIndexCBox)(int)=&QComboBox::currentIndexChanged;

    connect(ui->comboBoxSwitchType,changeIndexCBox,[=](){
        switch(ui->comboBoxSwitchType->currentIndex())
        {
        case 0:
            ui->checkBoxSwitch->setCheckState(Qt::Unchecked);
            ui->checkBoxSwitch->setEnabled(false);
            break;
        case 1:
            ui->checkBoxSwitch->setCheckState(Qt::Unchecked);
            ui->checkBoxSwitch->setEnabled(true);
            break;
        case 2:
            ui->checkBoxSwitch->setCheckState(Qt::Checked);
            ui->checkBoxSwitch->setEnabled(false);
            break;
        case 3:
            ui->checkBoxSwitch->setCheckState(Qt::Unchecked);
            ui->checkBoxSwitch->setEnabled(true);
            break;
        default:
            break;
        }
    });

    ///////////////////////////////////////////////////////////////////////////////////


    /*********************************************************************************/
    /*********************************************************************************/
    //comboBox 分系统

    ui->comboBoxSubSys->addItems(QStringList()<<"DTTC测控系统应答机"<<"CES综合电子系统"
                                 <<"OCS轨控系统"<<"ADCS姿控系统"<<"OS操作系统"<<"EPS电源系统"
                                 <<"ZH载荷系统"<<"GNSS系统");

    //默认没有内容
    ui->comboBoxSubSys->setCurrentIndex(-1);

    ///////////////////////////////////////////////////////////////////////////////////


    /*********************************************************************************/
    /*********************************************************************************/
    //comboBox 发送类型

    ui->comboBoxSendType->addItem("立即发送");

    ///////////////////////////////////////////////////////////////////////////////////


    /*********************************************************************************/
    /*********************************************************************************/
    //comboBox 数据长度

    ui->comboBoxDataLength->addItems(QStringList()<<"256"<<"128"<<"32"<<"16");

    ///////////////////////////////////////////////////////////////////////////////////


    /*********************************************************************************/
    /*********************************************************************************/
    //radioButton 注数发送类型（radioButton和pushButton一一对应）

    connect(ui->radioButtonSetData,&QRadioButton::clicked,[=](){
        ui->btnSendDIY->setEnabled(false);
        ui->pushButtonSetData->setEnabled(true);
    });

    connect(ui->radioButtonDIYData,&QRadioButton::clicked,[=](){
        ui->pushButtonSetData->setEnabled(false);
        ui->btnSendDIY->setEnabled(true);
    });

    ///////////////////////////////////////////////////////////////////////////////////


    //读取指令的配置文件
    QString jsonName = "TClib.json";
//    connect(ui->btnSearch,&QPushButton::clicked,[=](){
//        OpenOrderFile(jsonName);
//    });

    OpenOrderFile(jsonName);


    connect(ui->btnOpenTxt,&QPushButton::clicked,[=](){
        //打开文件选择对话框，选择文件，获取文件路径
        QString fileName = QFileDialog::getOpenFileName(
                    this, tr("open image file"),
                    "./", tr("List files(*.txt *.json *.php *.dpl *.m3u *.m3u8 *.xspf );;All files (*.*)"));
        if(fileName.isEmpty()){
            ui->hisTextBrowser->append("用户取消操作！！");
        }
        else {
            ui->hisTextBrowser->setText(fileName);//显示文件路径

            QFile f(fileName);
            //if打开失败
            if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                ui->hisTextBrowser->append("Fail！！");
                return;
            }
            ui->hisTextBrowser->append("打开成功！");

            QFileInfo fileInfo = QFileInfo(fileName);

            if(fileInfo.suffix()!="json")
            {
                QTextStream txtInput(&f);
                txtInput.setCodec("utf-8");
                QString lineStr;
                //读取文件所有内容
//                while(!txtInput.atEnd())
//                {
//                    commandList << txtInput.readLine();
//                }
//                foreach(auto item,commandList)
//                    lineStr=lineStr + item + "\n";

                lineStr = txtInput.readLine();
                diyList = lineStr.split(",");
                qDebug()<<diyList;
                ui->showTextEdit->setText(lineStr);//显示txt文件内容
            }
            else
            {
                QString value = f.readAll();
//                ui->showTextEdit->setText(value); //显示读取内容
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
                    //                qDebug()<<jsonObject;
                    foreach(QString i, jsonObject.keys())
                    {
                        QJsonArray array = jsonObject.value(i).toArray();
                        for (int j = 0;j<array.size() ;j++ ) {
                            QJsonObject orderItem = array.at(j).toObject();
                            QString orderName = orderItem.value("name").toString();
                            QString order = orderItem.value("order").toString();
                            QString orderDelay = orderItem.value("delay").toString();
                            QJsonObject target = orderItem.value("target").toObject();
                            qDebug()<<orderName<<"\n"<<order<<"\n"<<orderDelay<<"\n"<<target;
                        }
                    }
                }
            }
            f.close();
        }
    });

    ui->btnOrderSend->setEnabled(false);

    connect(ui->btnSetOrder,&QPushButton::clicked,[=](){
       dOrderHead = ui->headLineEdit->text();
       dOrderTail = ui->tailLineEdit->text();
       indOrderHead = ui->head2LineEdit->text();
       indOrderTail = ui->tail2LineEdit->text();
//       qDebug()<<orderHead<<orderTail;
       ui->btnOrderSend->setEnabled(true);
    });

    //顺序发送按钮
    connect(ui->btnOrderSend,&QPushButton::clicked,[=](){
        BuildCommandList();
        emit TxtSend(commandList);
        qDebug()<<commandList;
        for(int i=0;i<commandList.size();i++)
            ui->showTextEdit->append(commandList.at(i));
        ui->hisTextBrowser->append("发送成功");
        ui->textBrowser->append("///////////////");
        ui->comboBoxSubSys->setCurrentIndex(-1);
    });

    //发送按钮
    connect(ui->btnSend,&QPushButton::clicked,[=](){
        ui->hisTextBrowser->append("发送成功");
    });

    //发送按钮
    connect(ui->btnSendDIY,&QPushButton::clicked,[=](){
        ui->hisTextBrowser->append("发送成功");
    });

//    //建立序号和波道名的Map
//    BuildMap();
}

RCForm::~RCForm()
{
    delete ui;
}

//QString转换为QByteArray
QByteArray RCForm::QString2QByteArray(QString str)
{
    QByteArray byteArray;
    QString temp;
    if(str.isEmpty()){
        byteArray="\x00";
        return byteArray;
    }
    //补零
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
    //每八位2进制转换为int
    for (int i = 0; i < str.length()/8; i++ ) {
          temp = str.mid(i*8,8);
          byteArray.append(temp.toInt(nullptr,2));
    }
    return byteArray;
}

//显示对应检测指令清单的检测结果
void RCForm::DisplayDetectResult(QString command, QStringList resultList)
{
    QString index;
//    bool flag = true; //是否有错误标志
    if(resultList.size()==1) //检测结束
    {
        ui->textBrowser->append("///////////////");
    }
//    else if(resultList.size()==2) //未匹配
//    {
//        ui->textBrowser->append(command);
//        index = resultList.at(0) + resultList.at(1);
//        ui->textBrowser->append(index);
//    }
//    else
//    {
//        ui->textBrowser->append(command);
//        ui->textBrowser->append("Result:");
//        for (int i = 0; i<resultList.size(); i++ ) {
//            if(resultList.at(i)=="false")  //检测到错误
//            {
//                flag = false;
////                index = nameMap.find(i).value();
////                index = index + " : error occurred;";
////                ui->textBrowser->append(index);
//                ui->textBrowser->append("error occurred!");
//            }
//        }
//        if(flag)   //未检测到错误
//        {
//            ui->textBrowser->append("No error!");
//            ui->textBrowser->append(" ");
//        }
//        else
//             ui->textBrowser->append(" ");
//    }
    else
    {
        ui->textBrowser->append(command);
        ui->textBrowser->append("Result:");
        for(int i = 0;i<resultList.size();i++)
            ui->textBrowser->append(resultList.at(i));
    }

}

/*
//建立序号和波道名的Map
void RCForm::BuildMap()
{
    int i = 0;
    nameMap.insert(i,"TM-RDTTCA-01");i++;
    nameMap.insert(i,"TM-RDTTCA-02");i++;
    nameMap.insert(i,"TM-RDTTCA-03");i++;
    nameMap.insert(i,"TM-RDTTCA-04");i++;
    nameMap.insert(i,"TM-RDTTCA-05");i++;
    nameMap.insert(i,"TM-RDTTCA-06");i++;
    nameMap.insert(i,"TM-RDTTCA-07");i++;
    nameMap.insert(i,"TM-RDTTCA-08");i++;
    nameMap.insert(i,"TM-RDTTCA-09");i++;
    nameMap.insert(i,"TM-RDTTCA-10");i++;
    nameMap.insert(i,"TM-RDTTCA-11");i++;
    nameMap.insert(i,"TM-RDTTCA-12");i++;
    nameMap.insert(i,"TM-RDTTCA-13");i++;
    nameMap.insert(i,"TM-RDTTCA-14");i++;
    nameMap.insert(i,"TM-RDTTCA-15");i++;
    nameMap.insert(i,"TM-RDTTCA-16");i++;
    nameMap.insert(i,"TM-RDTTCA-17");i++;
    nameMap.insert(i,"TM-RDTTCA-18");i++;
    nameMap.insert(i,"TM-RDTTCA-19");i++;
    nameMap.insert(i,"TM-RDTTCA-20");i++;
    nameMap.insert(i,"TM-RDTTCA-21");i++;
    nameMap.insert(i,"TM-RDTTCA-22");i++;
    nameMap.insert(i,"TM-RDTTCA-23");i++;
    nameMap.insert(i,"TM-RDTTCA-24");i++;
    nameMap.insert(i,"TM-RDTTCA-25");i++;
    nameMap.insert(i,"TM-RDTTCA-26");i++;
    nameMap.insert(i,"TM-RDTTCA-27");i++;
    nameMap.insert(i,"TM-RDTTCA-28");i++;
    nameMap.insert(i,"TM-RDTTCA-29");i++;
    nameMap.insert(i,"TM-RDTTCA-30");i++;
    nameMap.insert(i,"TM-RDTTCA-31");i++;
    nameMap.insert(i,"TM-RDTTCA-32");i++;
    nameMap.insert(i,"TM-RDTTCA-33");i++;
    nameMap.insert(i,"TM-RDTTCA-34");i++;
    nameMap.insert(i,"TM-RDTTCA-35");i++;
    nameMap.insert(i,"TM-RDTTCA-36");i++;
    nameMap.insert(i,"TM-RDTTCA-37");i++;
    nameMap.insert(i,"TM-RDTTCA-38");i++;
    nameMap.insert(i,"TM-RDTTCA-39");i++;
    nameMap.insert(i,"TM-RDTTCA-40");i++;
    nameMap.insert(i,"TM-RDTTCA-41");i++;
    nameMap.insert(i,"TM-RDTTCA-42");i++;
    nameMap.insert(i,"TM-RDTTCA-43");i++;
    nameMap.insert(i,"TM-RDTTCA-44");i++;
    nameMap.insert(i,"TM-RDTTCA-45");i++;
    nameMap.insert(i,"TM-RDTTCA-46");i++;
    nameMap.insert(i,"TM-RDTTCA-47");i++;
    nameMap.insert(i,"TM-RDTTCA-48");i++;
    nameMap.insert(i,"TM-RDTTCA-49");i++;
    nameMap.insert(i,"TM-RDTTCA-50");i++;
    nameMap.insert(i,"TM-RDTTCA-51");i++;
    nameMap.insert(i,"TM-RDTTCA-52");i++;
    nameMap.insert(i,"TM-RDTTCA-53");i++;
    nameMap.insert(i,"TM-RDTTCA-54");i++;
    nameMap.insert(i,"TM-RDTTCA-55");i++;
    nameMap.insert(i,"TM-RDTTCB-01");i++;
    nameMap.insert(i,"TM-RDTTCB-02");i++;
    nameMap.insert(i,"TM-RDTTCB-03");i++;
    nameMap.insert(i,"TM-RDTTCB-04");i++;
    nameMap.insert(i,"TM-RDTTCB-05");i++;
    nameMap.insert(i,"TM-RDTTCB-06");i++;
    nameMap.insert(i,"TM-RDTTCB-07");i++;
    nameMap.insert(i,"TM-RDTTCB-08");i++;
    nameMap.insert(i,"TM-RDTTCB-09");i++;
    nameMap.insert(i,"TM-RDTTCB-10");i++;
    nameMap.insert(i,"TM-RDTTCB-11");i++;
    nameMap.insert(i,"TM-RDTTCB-12");i++;
    nameMap.insert(i,"TM-RDTTCB-13");i++;
    nameMap.insert(i,"TM-RDTTCB-14");i++;
    nameMap.insert(i,"TM-RDTTCB-15");i++;
    nameMap.insert(i,"TM-RDTTCB-16");i++;
    nameMap.insert(i,"TM-RDTTCB-17");i++;
    nameMap.insert(i,"TM-RDTTCB-18");i++;
    nameMap.insert(i,"TM-RDTTCB-19");i++;
    nameMap.insert(i,"TM-RDTTCB-20");i++;
    nameMap.insert(i,"TM-RDTTCB-21");i++;
    nameMap.insert(i,"TM-RDTTCB-22");i++;
    nameMap.insert(i,"TM-RDTTCB-23");i++;
    nameMap.insert(i,"TM-RDTTCB-24");i++;
    nameMap.insert(i,"TM-RDTTCB-25");i++;
    nameMap.insert(i,"TM-RDTTCB-26");i++;
    nameMap.insert(i,"TM-RDTTCB-27");i++;
    nameMap.insert(i,"TM-RDTTCB-28");i++;
    nameMap.insert(i,"TM-RDTTCB-29");i++;
    nameMap.insert(i,"TM-RDTTCB-30");i++;
    nameMap.insert(i,"TM-RDTTCB-31");i++;
    nameMap.insert(i,"TM-RDTTCB-32");i++;
    nameMap.insert(i,"TM-RDTTCB-33");i++;
    nameMap.insert(i,"TM-RDTTCB-34");i++;
    nameMap.insert(i,"TM-RDTTCB-35");i++;
    nameMap.insert(i,"TM-RDTTCB-36");i++;
    nameMap.insert(i,"TM-RDTTCB-37");i++;
    nameMap.insert(i,"TM-RDTTCB-38");i++;
    nameMap.insert(i,"TM-RDTTCB-39");i++;
    nameMap.insert(i,"TM-RDTTCB-40");i++;
    nameMap.insert(i,"TM-RDTTCB-41");i++;
    nameMap.insert(i,"TM-RDTTCB-42");i++;
    nameMap.insert(i,"TM-RDTTCB-43");i++;
    nameMap.insert(i,"TM-RDTTCB-44");i++;
    nameMap.insert(i,"TM-RDTTCB-45");i++;
    nameMap.insert(i,"TM-RDTTCB-46");i++;
    nameMap.insert(i,"TM-RDTTCB-47");i++;
    nameMap.insert(i,"TM-RDTTCB-48");i++;
    nameMap.insert(i,"TM-RDTTCB-49");i++;
    nameMap.insert(i,"TM-RDTTCB-50");i++;
    nameMap.insert(i,"TM-RDTTCB-51");i++;
    nameMap.insert(i,"TM-RDTTCB-52");i++;
    nameMap.insert(i,"TM-RDTTCB-53");i++;
    nameMap.insert(i,"TM-RDTTCB-54");i++;
    nameMap.insert(i,"TM-RDTTCB-55");i++;
    nameMap.insert(i,"TM-ROCS-01");i++;
    nameMap.insert(i,"TM-ROCS-02");i++;
    nameMap.insert(i,"TM-ROCS-03");i++;
    nameMap.insert(i,"TM-ROCS-04");i++;
    nameMap.insert(i,"TM-ROCS-05");i++;
    nameMap.insert(i,"TM-ROCS-06");i++;
    nameMap.insert(i,"TM-ROCS-07");i++;
    nameMap.insert(i,"TM-ROCS-08");i++;
    nameMap.insert(i,"TM-ROCS-09");i++;
    nameMap.insert(i,"TM-ROCS-10");i++;
    nameMap.insert(i,"TM-ROCS-11");i++;
    nameMap.insert(i,"TM-ROCS-12");i++;
    nameMap.insert(i,"TM-ROCS-13");i++;
    nameMap.insert(i,"TM-ROCS-14");i++;
    nameMap.insert(i,"TM-ROCS-15");i++;
    nameMap.insert(i,"TM-ROCS-16");i++;
    nameMap.insert(i,"TM-ROCS-17");i++;
    nameMap.insert(i,"TM-ROCS-18");i++;
    nameMap.insert(i,"TM-ROCS-19");i++;
    nameMap.insert(i,"TM-ROCS-20");i++;
    nameMap.insert(i,"TM-ROCS-21");i++;
    nameMap.insert(i,"TM-ROCS-22");i++;
    nameMap.insert(i,"TM-ROCS-23");i++;
    nameMap.insert(i,"TM-ROCS-24");i++;
    nameMap.insert(i,"TM-ROCS-25");i++;
    nameMap.insert(i,"TM-ROCS-26");i++;
    nameMap.insert(i,"TM-ROCS-27");i++;
    nameMap.insert(i,"TM-ROCS-28");i++;
    nameMap.insert(i,"TM-ROCS-29");i++;
    nameMap.insert(i,"TM-ROCS-30");i++;
    nameMap.insert(i,"TM-ROCS-31");i++;
    nameMap.insert(i,"TM-ROCS-32");i++;
    nameMap.insert(i,"TM-ROCS-33");i++;
    nameMap.insert(i,"TM-ROCS-34");i++;
    nameMap.insert(i,"TM-ROCS-35");i++;
    nameMap.insert(i,"TM-ROCS-36");i++;
    nameMap.insert(i,"TM-ROCS-37");i++;
    nameMap.insert(i,"TM-ROCS-38");i++;
    nameMap.insert(i,"TM-ROCS-39");i++;
    nameMap.insert(i,"TM-ROCS-40");i++;
    nameMap.insert(i,"TM-ROCS-41");i++;
    nameMap.insert(i,"TM-ROCS-42");i++;
    nameMap.insert(i,"TM-ROCS-43");i++;
    nameMap.insert(i,"TM-ROCS-44");i++;
    nameMap.insert(i,"TM-ROCS-45");i++;
    nameMap.insert(i,"TM-ROCS-46");i++;
    nameMap.insert(i,"TM-ROCS-47");i++;
    nameMap.insert(i,"TM-ROCS-48");i++;
    nameMap.insert(i,"TM-ROCS-49");i++;
    nameMap.insert(i,"TM-ROCS-50");i++;
    nameMap.insert(i,"TM-ROCS-51");i++;
    nameMap.insert(i,"TM-ROCS-52");i++;
    nameMap.insert(i,"TM-ROCS-53");i++;
    nameMap.insert(i,"TM-ROCS-54");i++;
    nameMap.insert(i,"TM-ROCS-55");i++;
    nameMap.insert(i,"TM-ROCS-56");i++;
    nameMap.insert(i,"TM-ROCS-57");i++;
    nameMap.insert(i,"TM-ROCS-58");i++;
    nameMap.insert(i,"TM-ROCS-59");i++;
    nameMap.insert(i,"TM-ROCS-60");i++;
    nameMap.insert(i,"TM-ROCS-61");i++;
    nameMap.insert(i,"TM-ROCS-62");i++;
    nameMap.insert(i,"TM-ROCS-63");i++;
    nameMap.insert(i,"TM-RADCS-01");i++;
    nameMap.insert(i,"TM-RADCS-02");i++;
    nameMap.insert(i,"TM-RADCS-03");i++;
    nameMap.insert(i,"TM-RADCS-04");i++;
    nameMap.insert(i,"TM-RADCS-05");i++;
    nameMap.insert(i,"TM-RADCS-06");i++;
    nameMap.insert(i,"TM-RADCS-07");i++;
    nameMap.insert(i,"TM-RADCS-08");i++;
    nameMap.insert(i,"TM-RADCS-09");i++;
    nameMap.insert(i,"TM-RADCS-10");i++;
    nameMap.insert(i,"TM-RADCS-11");i++;
    nameMap.insert(i,"TM-RADCS-12");i++;
    nameMap.insert(i,"TM-RADCS-13");i++;
    nameMap.insert(i,"TM-RADCS-14");i++;
    nameMap.insert(i,"TM-RADCS-15");i++;
    nameMap.insert(i,"TM-RADCS-16");i++;
    nameMap.insert(i,"TM-RADCS-17");i++;
    nameMap.insert(i,"TM-RADCS-18");i++;
    nameMap.insert(i,"TM-RADCS-19");i++;
    nameMap.insert(i,"TM-RADCS-20");i++;
    nameMap.insert(i,"TM-RADCS-21");i++;
    nameMap.insert(i,"TM-RADCS-22");i++;
    nameMap.insert(i,"TM-RADCS-23");i++;
    nameMap.insert(i,"TM-RADCS-24");i++;
    nameMap.insert(i,"TM-RADCS-25");i++;
    nameMap.insert(i,"TM-RADCS-26");i++;
    nameMap.insert(i,"TM-RADCS-27");i++;
    nameMap.insert(i,"TM-RADCS-28");i++;
    nameMap.insert(i,"TM-RADCS-29");i++;
    nameMap.insert(i,"TM-RADCS-30");i++;
    nameMap.insert(i,"TM-RADCS-31");i++;
    nameMap.insert(i,"TM-RADCS-32");i++;
    nameMap.insert(i,"TM-RADCS-33");i++;
    nameMap.insert(i,"TM-RADCS-34");i++;
    nameMap.insert(i,"TM-RADCS-35");i++;
    nameMap.insert(i,"TM-RADCS-36");i++;
    nameMap.insert(i,"TM-RADCS-37");i++;
    nameMap.insert(i,"TM-RADCS-38");i++;
    nameMap.insert(i,"TM-RADCS-39");i++;
    nameMap.insert(i,"TM-RADCS-40");i++;
    nameMap.insert(i,"TM-RADCS-41");i++;
    nameMap.insert(i,"TM-RADCS-42");i++;
    nameMap.insert(i,"TM-RADCS-43");i++;
    nameMap.insert(i,"TM-RADCS-44");i++;
    nameMap.insert(i,"TM-RADCS-45");i++;
    nameMap.insert(i,"TM-RADCS-46");i++;
    nameMap.insert(i,"TM-RADCS-47");i++;
    nameMap.insert(i,"TM-RADCS-48");i++;
    nameMap.insert(i,"TM-RADCS-49");i++;
    nameMap.insert(i,"TM-RADCS-50");i++;
    nameMap.insert(i,"TM-RADCS-51");i++;
    nameMap.insert(i,"TM-RADCS-52");i++;
    nameMap.insert(i,"TM-RADCS-53");i++;
    nameMap.insert(i,"TM-RADCS-54");i++;
    nameMap.insert(i,"TM-RADCS-55");i++;
    nameMap.insert(i,"TM-RADCS-56");i++;
    nameMap.insert(i,"TM-RADCS-57");i++;
    nameMap.insert(i,"TM-RADCS-58");i++;
    nameMap.insert(i,"TM-RADCS-59");i++;
    nameMap.insert(i,"TM-RADCS-60");i++;
    nameMap.insert(i,"TM-RADCS-61");i++;
    nameMap.insert(i,"TM-RADCS-62");i++;
    nameMap.insert(i,"TM-RADCS-63");i++;
    nameMap.insert(i,"TM-RADCS-64");i++;
    nameMap.insert(i,"TM-RADCS-65");i++;
    nameMap.insert(i,"TM-RADCS-66");i++;
    nameMap.insert(i,"TM-RADCS-67");i++;
    nameMap.insert(i,"TM-RADCS-68");i++;
    nameMap.insert(i,"TM-RADCS-69");i++;
    nameMap.insert(i,"TM-RADCS-70");i++;
    nameMap.insert(i,"TM-RADCS-71");i++;
    nameMap.insert(i,"TM-RADCS-72");i++;
    nameMap.insert(i,"TM-RADCS-73");i++;
    nameMap.insert(i,"TM-RADCS-74");i++;
    nameMap.insert(i,"TM-RADCS-75");i++;
    nameMap.insert(i,"TM-RADCS-76");i++;
    nameMap.insert(i,"TM-RADCS-77");i++;
    nameMap.insert(i,"TM-RADCS-78");i++;
    nameMap.insert(i,"TM-RADCS-79");i++;
    nameMap.insert(i,"TM-RADCS-80");i++;
    nameMap.insert(i,"TM-RADCS-81");i++;
    nameMap.insert(i,"TM-RADCS-82");i++;
    nameMap.insert(i,"TM-RADCS-83");i++;
    nameMap.insert(i,"TM-RADCS-84");i++;
    nameMap.insert(i,"TM-RADCS-85");i++;
    nameMap.insert(i,"TM-RADCS-86");i++;
    nameMap.insert(i,"TM-RADCS-87");i++;
    nameMap.insert(i,"TM-RADCS-88");i++;
    nameMap.insert(i,"TM-RADCS-89");i++;
    nameMap.insert(i,"TM-RADCS-90");i++;
    nameMap.insert(i,"TM-RADCS-91");i++;
    nameMap.insert(i,"TM-RADCS-92");i++;
    nameMap.insert(i,"TM-RADCS-93");i++;
    nameMap.insert(i,"TM-RADCS-94");i++;
    nameMap.insert(i,"TM-RADCS-95");i++;
    nameMap.insert(i,"TM-RADCS-96");i++;
    nameMap.insert(i,"TM-RADCS-97");i++;
    nameMap.insert(i,"TM-RADCS-98");i++;
    nameMap.insert(i,"TM-RADCS-99");i++;
    nameMap.insert(i,"TM-RADCS-100");i++;
    nameMap.insert(i,"TM-RADCS-101");i++;
    nameMap.insert(i,"TM-RADCS-102");i++;
    nameMap.insert(i,"TM-RADCS-103");i++;
    nameMap.insert(i,"TM-RADCS-104");i++;
    nameMap.insert(i,"TM-RADCS-105");i++;
    nameMap.insert(i,"TM-RADCS-106");i++;
    nameMap.insert(i,"TM-RADCS-107");i++;
    nameMap.insert(i,"TM-RADCS-108");i++;
    nameMap.insert(i,"TM-RADCS-109");i++;
    nameMap.insert(i,"TM-RADCS-110");i++;
    nameMap.insert(i,"TM-RADCS-111");i++;
    nameMap.insert(i,"TM-RADCS-112");i++;
    nameMap.insert(i,"TM-RADCS-113");i++;
    nameMap.insert(i,"TM-RADCS-114");i++;
    nameMap.insert(i,"TM-RADCS-115");i++;
    nameMap.insert(i,"TM-RADCS-116");i++;
    nameMap.insert(i,"TM-RADCS-117");i++;
    nameMap.insert(i,"TM-RADCS-118");i++;
    nameMap.insert(i,"TM-RADCS-119");i++;
    nameMap.insert(i,"TM-RADCS-120");i++;
    nameMap.insert(i,"TM-RADCS-121");i++;
    nameMap.insert(i,"TM-RADCS-122");i++;
    nameMap.insert(i,"TM-RADCS-123");i++;
    nameMap.insert(i,"TM-RADCS-124");i++;
    nameMap.insert(i,"TM-RADCS-125");i++;
    nameMap.insert(i,"TM-RADCS-126");i++;
    nameMap.insert(i,"TM-RADCS-127");i++;
    nameMap.insert(i,"TM-RADCS-128");i++;
    nameMap.insert(i,"TM-RADCS-129");i++;
    nameMap.insert(i,"TM-RADCS-130");i++;
    nameMap.insert(i,"TM-RADCS-131");i++;
    nameMap.insert(i,"TM-RADCS-132");i++;
    nameMap.insert(i,"TM-RADCS-133");i++;
    nameMap.insert(i,"TM-RADCS-134");i++;
    nameMap.insert(i,"TM-RADCS-135");i++;
    nameMap.insert(i,"TM-RADCS-136");i++;
    nameMap.insert(i,"TM-RADCS-137");i++;
    nameMap.insert(i,"TM-RADCS-138");i++;
    nameMap.insert(i,"TM-RADCS-139");i++;
    nameMap.insert(i,"TM-RADCS-140");i++;
    nameMap.insert(i,"TM-RADCS-141");i++;
    nameMap.insert(i,"TM-RADCS-142");i++;
    nameMap.insert(i,"TM-RADCS-143");i++;
    nameMap.insert(i,"TM-RADCS-144");i++;
    nameMap.insert(i,"TM-RADCS-145");i++;
    nameMap.insert(i,"TM-RADCS-146");i++;
    nameMap.insert(i,"TM-RADCS-147");i++;
    nameMap.insert(i,"TM-RADCS-148");i++;
    nameMap.insert(i,"TM-RADCS-149");i++;
    nameMap.insert(i,"TM-RADCS-150");i++;
    nameMap.insert(i,"TM-RADCS-151");i++;
    nameMap.insert(i,"TM-RADCS-152");i++;
    nameMap.insert(i,"TM-RADCS-153");i++;
    nameMap.insert(i,"TM-RADCS-154");i++;
    nameMap.insert(i,"TM-RADCS-155");i++;
    nameMap.insert(i,"TM-RADCS-156");i++;
    nameMap.insert(i,"TM-RADCS-157");i++;
    nameMap.insert(i,"TM-RADCS-158");i++;
    nameMap.insert(i,"TM-RADCS-159");i++;
    nameMap.insert(i,"TM-RADCS-160");i++;
    nameMap.insert(i,"TM-RADCS-161");i++;
    nameMap.insert(i,"TM-RADCS-162");i++;
    nameMap.insert(i,"TM-RADCS-163");i++;
    nameMap.insert(i,"TM-RADCS-164");i++;
    nameMap.insert(i,"TM-RADCS-165");i++;
    nameMap.insert(i,"TM-RADCS-166");i++;
    nameMap.insert(i,"TM-RADCS-167");i++;
    nameMap.insert(i,"TM-RADCS-168");i++;
    nameMap.insert(i,"TM-RADCS-169");i++;
    nameMap.insert(i,"TM-RADCS-170");i++;
    nameMap.insert(i,"TM-RADCS-171");i++;
    nameMap.insert(i,"TM-RADCS-172");i++;
    nameMap.insert(i,"TM-RADCS-173");i++;
    nameMap.insert(i,"TM-REPS-01");i++;
    nameMap.insert(i,"TM-REPS-02");i++;
    nameMap.insert(i,"TM-REPS-03");i++;
    nameMap.insert(i,"TM-REPS-04");i++;
    nameMap.insert(i,"TM-REPS-05");i++;
    nameMap.insert(i,"TM-REPS-06");i++;
    nameMap.insert(i,"TM-REPS-07");i++;
    nameMap.insert(i,"TM-REPS-08");i++;
    nameMap.insert(i,"TM-REPS-09");i++;
    nameMap.insert(i,"TM-REPS-10");i++;
    nameMap.insert(i,"TM-REPS-11");i++;
    nameMap.insert(i,"TM-REPS-12");i++;
    nameMap.insert(i,"TM-REPS-13");i++;
    nameMap.insert(i,"TM-REPS-14");i++;
    nameMap.insert(i,"TM-REPS-15");i++;
    nameMap.insert(i,"TM-REPS-16");i++;
    nameMap.insert(i,"TM-REPS-17");i++;
    nameMap.insert(i,"TM-REPS-18");i++;
    nameMap.insert(i,"TM-REPS-19");i++;
    nameMap.insert(i,"TM-REPS-20");i++;
    nameMap.insert(i,"TM-REPS-21");i++;
    nameMap.insert(i,"TM-REPS-22");i++;
    nameMap.insert(i,"TM-REPS-23");i++;
    nameMap.insert(i,"TM-REPS-24");i++;
    nameMap.insert(i,"TM-REPS-25");i++;
    nameMap.insert(i,"TM-REPS-26");i++;
    nameMap.insert(i,"TM-REPS-27");i++;
    nameMap.insert(i,"TM-REPS-28");i++;
    nameMap.insert(i,"TM-REPS-29");i++;
    nameMap.insert(i,"TM-REPS-30");i++;
    nameMap.insert(i,"TM-REPS-31");i++;
    nameMap.insert(i,"TM-REPS-32");i++;
    nameMap.insert(i,"TM-REPS-33");i++;
    nameMap.insert(i,"TM-REPS-34");i++;
    nameMap.insert(i,"TM-REPS-35");i++;
    nameMap.insert(i,"TM-REPS-36");i++;
    nameMap.insert(i,"TM-REPS-37");i++;
    nameMap.insert(i,"TM-REPS-38");i++;
    nameMap.insert(i,"TM-REPS-39");i++;
    nameMap.insert(i,"TM-REPS-40");i++;
    nameMap.insert(i,"TM-REPS-41");i++;
    nameMap.insert(i,"TM-REPS-42");i++;
    nameMap.insert(i,"TM-REPS-43");i++;
    nameMap.insert(i,"TM-REPS-44");i++;
    nameMap.insert(i,"TM-REPS-45");i++;
    nameMap.insert(i,"TM-REPS-46");i++;
    nameMap.insert(i,"TM-REPS-47");i++;
    nameMap.insert(i,"TM-REPS-48");i++;
    nameMap.insert(i,"TM-REPS-49");i++;
    nameMap.insert(i,"TM-REPS-50");i++;
    nameMap.insert(i,"TM-REPS-51");i++;
    nameMap.insert(i,"TM-REPS-52");i++;
    nameMap.insert(i,"TM-REPS-53");i++;
    nameMap.insert(i,"TM-REPS-54");i++;
    nameMap.insert(i,"TM-REPS-55");i++;
    nameMap.insert(i,"TM-REPS-56");i++;
    nameMap.insert(i,"TM-REPS-57");i++;
    nameMap.insert(i,"TM-REPS-58");i++;
    nameMap.insert(i,"TM-REPS-59");i++;
    nameMap.insert(i,"TM-REPS-60");i++;
    nameMap.insert(i,"TM-REPS-61");i++;
    nameMap.insert(i,"TM-REPS-62");i++;
    nameMap.insert(i,"TM-REPS-63");i++;
    nameMap.insert(i,"TM-REPS-64");i++;
    nameMap.insert(i,"TM-REPS-65");i++;
    nameMap.insert(i,"TM-REPS-66");i++;
    nameMap.insert(i,"TM-REPS-67");i++;
    nameMap.insert(i,"TM-REPS-68");i++;
    nameMap.insert(i,"TM-REPS-69");i++;
    nameMap.insert(i,"TM-REPS-70");i++;
    nameMap.insert(i,"TM-REPS-71");i++;
    nameMap.insert(i,"TM-REPS-72");i++;
    nameMap.insert(i,"TM-REPS-73");i++;
    nameMap.insert(i,"TM-REPS-74");i++;
    nameMap.insert(i,"TM-REPS-75");i++;
    nameMap.insert(i,"TM-REPS-76");i++;
    nameMap.insert(i,"TM-REPS-77");i++;
    nameMap.insert(i,"TM-REPS-78");i++;
    nameMap.insert(i,"TM-REPS-79");i++;
    nameMap.insert(i,"TM-REPS-80");i++;
    nameMap.insert(i,"TM-REPS-81");i++;
    nameMap.insert(i,"TM-REPS-82");i++;
    nameMap.insert(i,"TM-REPS-83");i++;
    nameMap.insert(i,"TM-REPS-84");i++;
    nameMap.insert(i,"TM-REPS-85");i++;
    nameMap.insert(i,"TM-REPS-86");i++;
    nameMap.insert(i,"TM-REPS-87");i++;
    nameMap.insert(i,"TM-REPS-88");i++;
    nameMap.insert(i,"TM-REPS-89");i++;
    nameMap.insert(i,"TM-REPS-90");i++;
    nameMap.insert(i,"TM-REPS-91");i++;
    nameMap.insert(i,"TM-REPS-92");i++;
    nameMap.insert(i,"TM-REPS-93");i++;
    nameMap.insert(i,"TM-REPS-94");i++;
    nameMap.insert(i,"TM-REPS-95");i++;
    nameMap.insert(i,"TM-REPS-96");i++;
    nameMap.insert(i,"TM-REPS-97");i++;
    nameMap.insert(i,"TM-REPS-98");i++;
    nameMap.insert(i,"TM-REPS-99");i++;
    nameMap.insert(i,"TM-REPS-100");i++;
    nameMap.insert(i,"TM-REPS-101");i++;
    nameMap.insert(i,"TM-REPS-102");i++;
    nameMap.insert(i,"TM-REPS-103");i++;
    nameMap.insert(i,"TM-REPS-104");i++;
    nameMap.insert(i,"TM-REPS-105");i++;
    nameMap.insert(i,"TM-REPS-106");i++;
    nameMap.insert(i,"TM-REPS-107");i++;
    nameMap.insert(i,"TM-REPS-108");i++;
    nameMap.insert(i,"TM-REPS-109");i++;
    nameMap.insert(i,"TM-REPS-110");i++;
    nameMap.insert(i,"TM-REPS-111");i++;
    nameMap.insert(i,"TM-REPS-112");i++;
    nameMap.insert(i,"TM-REPS-113");i++;
    nameMap.insert(i,"TM-REPS-114");i++;
    nameMap.insert(i,"TM-REPS-115");i++;
    nameMap.insert(i,"TM-REPS-116");i++;
    nameMap.insert(i,"TM-REPS-117");i++;
    nameMap.insert(i,"TM-REPS-118");i++;
    nameMap.insert(i,"TM-REPS-119");i++;
    nameMap.insert(i,"TM-REPS-120");i++;
    nameMap.insert(i,"TM-REPS-121");i++;
    nameMap.insert(i,"TM-REPS-122");i++;
    nameMap.insert(i,"TM-REPS-123");i++;
    nameMap.insert(i,"TM-REPS-124");i++;
    nameMap.insert(i,"TM-REPS-125");i++;
    nameMap.insert(i,"TM-REPS-126");i++;
    nameMap.insert(i,"TM-REPS-127");i++;
    nameMap.insert(i,"TM-REPS-128");i++;
    nameMap.insert(i,"TM-REPS-129");i++;
    nameMap.insert(i,"TM-REPS-130");i++;
    nameMap.insert(i,"TM-REPS-131");i++;
    nameMap.insert(i,"TM-REPS-132");i++;
    nameMap.insert(i,"TM-REPS-133");i++;
    nameMap.insert(i,"TM-REPS-134");i++;
    nameMap.insert(i,"TM-REPS-135");i++;
    nameMap.insert(i,"TM-REPS-136");i++;
    nameMap.insert(i,"TM-REPS-137");i++;
    nameMap.insert(i,"TM-REPS-138");i++;
    nameMap.insert(i,"TM-REPS-139");i++;
    nameMap.insert(i,"TM-REPS-140");i++;
    nameMap.insert(i,"TM-REPS-141");i++;
    nameMap.insert(i,"TM-RGNSS-01");i++;
    nameMap.insert(i,"TM-RGNSS-02");i++;
    nameMap.insert(i,"TM-RGNSS-03");i++;
    nameMap.insert(i,"TM-RGNSS-04");i++;
    nameMap.insert(i,"TM-RGNSS-05");i++;
    nameMap.insert(i,"TM-RGNSS-06");i++;
    nameMap.insert(i,"TM-RGNSS-07");i++;
    nameMap.insert(i,"TM-RGNSS-08");i++;
    nameMap.insert(i,"TM-RGNSS-09");i++;
    nameMap.insert(i,"TM-RGNSS-10");i++;
    nameMap.insert(i,"TM-RGNSS-11");i++;
    nameMap.insert(i,"TM-RGNSS-12");i++;
    nameMap.insert(i,"TM-RGNSS-13");i++;
    nameMap.insert(i,"TM-RGNSS-14");i++;
    nameMap.insert(i,"TM-RGNSS-15");i++;
    nameMap.insert(i,"TM-RGNSS-16");i++;
    nameMap.insert(i,"TM-RGNSS-17");i++;
    nameMap.insert(i,"TM-RGNSS-18");i++;
    nameMap.insert(i,"TM-RGNSS-19");i++;
    nameMap.insert(i,"TM-RGNSS-20");i++;
    nameMap.insert(i,"TM-RGNSS-21");i++;
    nameMap.insert(i,"TM-RGNSS-22");i++;
    nameMap.insert(i,"TM-RGNSS-23");i++;
    nameMap.insert(i,"TM-RGNSS-24");i++;
    nameMap.insert(i,"TM-RGNSS-25");i++;
    nameMap.insert(i,"TM-RGNSS-26");i++;
    nameMap.insert(i,"TM-RGNSS-27");i++;
    nameMap.insert(i,"TM-RGNSS-28");i++;
    nameMap.insert(i,"TM-RGNSS-29");i++;
    nameMap.insert(i,"TM-RGNSS-30");i++;
    nameMap.insert(i,"TM-RGNSS-31");i++;
    nameMap.insert(i,"TM-RGNSS-32");i++;
    nameMap.insert(i,"TM-RGNSS-33");i++;
    nameMap.insert(i,"TM-RGNSS-34");i++;
    nameMap.insert(i,"TM-RGNSS-35");i++;
    nameMap.insert(i,"TM-RGNSS-36");i++;
    nameMap.insert(i,"TM-RGNSS-37");i++;
    nameMap.insert(i,"TM-RGNSS-38");i++;
    nameMap.insert(i,"TM-RGNSS-39");i++;
    nameMap.insert(i,"TM-RGNSS-40");i++;
    nameMap.insert(i,"TM-RGNSS-41");i++;
    nameMap.insert(i,"TM-RGNSS-42");i++;
    nameMap.insert(i,"TM-RGNSS-43");i++;
    nameMap.insert(i,"TM-RGNSS-44");i++;
    nameMap.insert(i,"TM-RGNSS-45");i++;
    nameMap.insert(i,"TM-RGNSS-46");i++;
    nameMap.insert(i,"TM-RGNSS-47");i++;
    nameMap.insert(i,"TM-RGNSS-48");i++;
    nameMap.insert(i,"TM-RGNSS-49");i++;
    nameMap.insert(i,"TM-RGNSS-50");i++;
    nameMap.insert(i,"TM-RGNSS-51");i++;
    nameMap.insert(i,"TM-RGNSS-52");i++;
    nameMap.insert(i,"TM-RGNSS-53");i++;
    nameMap.insert(i,"TM-RGNSS-54");i++;
    nameMap.insert(i,"TM-RGNSS-55");i++;
    nameMap.insert(i,"TM-RGNSS-56");i++;
    nameMap.insert(i,"TM-RGNSS-57");i++;
    nameMap.insert(i,"TM-RGNSS-58");i++;
    nameMap.insert(i,"TM-RGNSS-59");i++;
    nameMap.insert(i,"TM-RGNSS-60");i++;
    nameMap.insert(i,"TM-RGNSS-61");i++;
    nameMap.insert(i,"TM-RGNSS-62");i++;
    nameMap.insert(i,"TM-RGNSS-63");i++;
    nameMap.insert(i,"TM-RGNSS-64");i++;
    nameMap.insert(i,"TM-RGNSS-65");i++;
    nameMap.insert(i,"TM-RGNSS-66");i++;
    nameMap.insert(i,"TM-RZH-01");i++;
    nameMap.insert(i,"TM-RZH-02");i++;
    nameMap.insert(i,"TM-RZH-03");i++;
    nameMap.insert(i,"TM-RZH-04");i++;
    nameMap.insert(i,"TM-RZH-05");i++;
    nameMap.insert(i,"TM-RZH-06");i++;
    nameMap.insert(i,"TM-RZH-07");i++;
    nameMap.insert(i,"TM-RZH-08");i++;
    nameMap.insert(i,"TM-RZH-09");i++;
    nameMap.insert(i,"TM-RZH-10");i++;
    nameMap.insert(i,"TM-RZH-11");i++;
    nameMap.insert(i,"TM-RZH-12");i++;
    nameMap.insert(i,"TM-RZH-13");i++;
    nameMap.insert(i,"TM-RZH-14");i++;
    nameMap.insert(i,"TM-RZH-15");i++;
    nameMap.insert(i,"TM-RZH-16");i++;
    nameMap.insert(i,"TM-RZH-17");i++;
    nameMap.insert(i,"TM-RZH-18");i++;
    nameMap.insert(i,"TM-RZH-19");i++;
    nameMap.insert(i,"TM-RZH-20");i++;
    nameMap.insert(i,"TM-RZH-21");i++;
    nameMap.insert(i,"TM-RZH-22");i++;
    nameMap.insert(i,"TM-RZH-23");i++;
    nameMap.insert(i,"TM-RZH-24");i++;
    nameMap.insert(i,"TM-RZH-25");i++;
    nameMap.insert(i,"TM-RZH-26");i++;
    nameMap.insert(i,"TM-RZH-27");i++;
    nameMap.insert(i,"TM-RZH-28");i++;
    nameMap.insert(i,"TM-RZH-29");i++;
    nameMap.insert(i,"TM-RZH-30");i++;
    nameMap.insert(i,"TM-RZH-31");i++;
    nameMap.insert(i,"TM-RZH-32");i++;
    nameMap.insert(i,"TM-RZH-33");i++;
    nameMap.insert(i,"TM-RZH-34");i++;
    nameMap.insert(i,"TM-RZH-35");i++;
    nameMap.insert(i,"TM-RZH-36");i++;
    nameMap.insert(i,"TM-RZH-37");i++;
    nameMap.insert(i,"TM-RZH-38");i++;
    nameMap.insert(i,"TM-RZH-39");i++;
    nameMap.insert(i,"TM-RZH-40");i++;
    nameMap.insert(i,"TM-RZH-41");i++;
    nameMap.insert(i,"TM-RZH-42");i++;
    nameMap.insert(i,"TM-RZH-43");i++;
    nameMap.insert(i,"TM-RZH-44");i++;
    nameMap.insert(i,"TM-RZH-45");i++;
    nameMap.insert(i,"TM-RZH-46");i++;
    nameMap.insert(i,"TM-RZH-47");i++;
    nameMap.insert(i,"TM-RZH-48");i++;
    nameMap.insert(i,"TM-RZH-49");i++;
    nameMap.insert(i,"TM-RZH-50");i++;
    nameMap.insert(i,"TM-RZH-51");i++;
    nameMap.insert(i,"TM-RZH-52");i++;
    nameMap.insert(i,"TM-RZH-53");i++;
    nameMap.insert(i,"TM-RZH-54");i++;
    nameMap.insert(i,"TM-RZH-55");i++;
    nameMap.insert(i,"TM-RZH-56");i++;
    nameMap.insert(i,"TM-RZH-57");i++;
    nameMap.insert(i,"TM-RZH-58");i++;
    nameMap.insert(i,"TM-RZH-59");i++;
    nameMap.insert(i,"TM-RZH-60");i++;
    nameMap.insert(i,"TM-RZH-61");i++;
    nameMap.insert(i,"TM-RZH-62");i++;
    nameMap.insert(i,"TM-RZH-63");i++;
    nameMap.insert(i,"TM-RZH-64");i++;
    nameMap.insert(i,"TM-RZH-65");i++;
    nameMap.insert(i,"TM-RZH-66");i++;
    nameMap.insert(i,"TM-RZH-67");i++;
    nameMap.insert(i,"TM-RZH-68");i++;
    nameMap.insert(i,"TM-RZH-69");i++;
    nameMap.insert(i,"TM-RZH-70");i++;
    nameMap.insert(i,"TM-RZH-71");i++;
    nameMap.insert(i,"TM-RZH-72");i++;
    nameMap.insert(i,"TM-RZH-73");i++;
    nameMap.insert(i,"TM-RZH-74");i++;
    nameMap.insert(i,"TM-RZH-75");i++;
    nameMap.insert(i,"TM-RZH-76");i++;
    nameMap.insert(i,"TM-RZH-77");i++;
    nameMap.insert(i,"TM-RZH-78");i++;
    nameMap.insert(i,"TM-RZH-79");i++;
    nameMap.insert(i,"TM-RZH-80");i++;
    nameMap.insert(i,"TM-RZH-81");i++;
    nameMap.insert(i,"TM-RZH-82");i++;
    nameMap.insert(i,"TM-RZH-83");i++;
    nameMap.insert(i,"TM-RZH-84");i++;
    nameMap.insert(i,"TM-RZH-85");i++;
    nameMap.insert(i,"TM-RZH-86");i++;
    nameMap.insert(i,"TM-RZH-87");i++;
    nameMap.insert(i,"TM-RZH-88");i++;
    nameMap.insert(i,"TM-RZH-89");i++;
    nameMap.insert(i,"TM-RZH-90");i++;
    nameMap.insert(i,"TM-RZH-91");i++;
    nameMap.insert(i,"TM-RZH-92");i++;
    nameMap.insert(i,"TM-RZH-93");i++;
    nameMap.insert(i,"TM-RZH-94");i++;
    nameMap.insert(i,"TM-RZH-95");i++;
    nameMap.insert(i,"TM-RZH-96");i++;
    nameMap.insert(i,"TM-RZH-97");i++;
    nameMap.insert(i,"TM-RZH-98");i++;
    nameMap.insert(i,"TM-RZH-99");i++;
    nameMap.insert(i,"TM-RZH-100");i++;
    nameMap.insert(i,"TM-RZH-101");i++;
    nameMap.insert(i,"TM-RCES-01");i++;
    nameMap.insert(i,"TM-RCES-02");i++;
    nameMap.insert(i,"TM-RCES-03");i++;
    nameMap.insert(i,"TM-RCES-04");i++;
    nameMap.insert(i,"TM-RCES-05");i++;
    nameMap.insert(i,"TM-RCES-06");i++;
    nameMap.insert(i,"TM-RCES-07");i++;
    nameMap.insert(i,"TM-RCES-08");i++;
    nameMap.insert(i,"TM-RCES-09");i++;
    nameMap.insert(i,"TM-RCES-10");i++;
    nameMap.insert(i,"TM-RCES-11");i++;
    nameMap.insert(i,"TM-RCES-12");i++;
    nameMap.insert(i,"TM-RCES-13");i++;
    nameMap.insert(i,"TM-RCES-14");i++;
    nameMap.insert(i,"TM-RCES-15");i++;
    nameMap.insert(i,"TM-RCES-16");i++;
    nameMap.insert(i,"TM-RCES-17");i++;
    nameMap.insert(i,"TM-RCES-18");i++;
    nameMap.insert(i,"TM-RCES-19");i++;
    nameMap.insert(i,"TM-RCES-20");i++;
    nameMap.insert(i,"TM-RCES-21");i++;
    nameMap.insert(i,"TM-RCES-22");i++;
    nameMap.insert(i,"TM-RCES-23");i++;
    nameMap.insert(i,"TM-RCES-24");i++;
    nameMap.insert(i,"TM-RCES-25");i++;
    nameMap.insert(i,"TM-RCES-26");i++;
    nameMap.insert(i,"TM-RCES-27");i++;
    nameMap.insert(i,"TM-RCES-28");i++;
    nameMap.insert(i,"TM-RCES-29");i++;
    nameMap.insert(i,"TM-RCES-30");i++;
    nameMap.insert(i,"TM-RCES-31");i++;
    nameMap.insert(i,"TM-RCES-32");i++;
    nameMap.insert(i,"TM-RCES-33");i++;
    nameMap.insert(i,"TM-RCES-34");i++;
    nameMap.insert(i,"TM-RCES-35");i++;
    nameMap.insert(i,"TM-RCES-36");i++;
    nameMap.insert(i,"TM-RCES-37");i++;
    nameMap.insert(i,"TM-RCES-38");i++;
    nameMap.insert(i,"TM-RCES-39");i++;
    nameMap.insert(i,"TM-RCES-40");i++;
    nameMap.insert(i,"TM-RCES-41");i++;
    nameMap.insert(i,"TM-RCES-42");i++;
    nameMap.insert(i,"TM-RCES-43");i++;
    nameMap.insert(i,"TM-RCES-44");i++;
    nameMap.insert(i,"TM-RCES-45");i++;
    nameMap.insert(i,"TM-RCES-46");i++;
    nameMap.insert(i,"TM-RCES-47");i++;
    nameMap.insert(i,"TM-RCES-48");i++;
    nameMap.insert(i,"TM-RCES-49");i++;
    nameMap.insert(i,"TM-RCES-50");i++;
    nameMap.insert(i,"TM-RCES-51");i++;
    nameMap.insert(i,"TM-RCES-52");i++;
    nameMap.insert(i,"TM-RCES-53");i++;
    nameMap.insert(i,"TM-RCES-54");i++;
    nameMap.insert(i,"TM-RCES-55");i++;
    nameMap.insert(i,"TM-RCES-56");i++;
    nameMap.insert(i,"TM-RCES-57");i++;
    nameMap.insert(i,"TM-RCES-58");i++;
    nameMap.insert(i,"TM-RCES-59");i++;
    nameMap.insert(i,"TM-RCES-60");i++;
    nameMap.insert(i,"TM-RCES-61");i++;
    nameMap.insert(i,"TM-RCES-62");i++;
    nameMap.insert(i,"TM-RCES-63");i++;
    nameMap.insert(i,"TM-RCES-64");i++;
    nameMap.insert(i,"TM-RCES-65");i++;
    nameMap.insert(i,"TM-RCES-66");i++;
    nameMap.insert(i,"TM-RCES-67");i++;
    nameMap.insert(i,"TM-RCES-68");i++;
    nameMap.insert(i,"TM-RCES-69");i++;
    nameMap.insert(i,"TM-RCES-70");i++;
    nameMap.insert(i,"TM-RCES-71");i++;
    nameMap.insert(i,"TM-RCES-72");i++;
    nameMap.insert(i,"TM-RCES-73");i++;
    nameMap.insert(i,"TM-RCES-74");i++;
    nameMap.insert(i,"TM-RCES-75");i++;
    nameMap.insert(i,"TM-RCES-76");i++;
    nameMap.insert(i,"TM-RCES-77");i++;
    nameMap.insert(i,"TM-RCES-78");i++;
    nameMap.insert(i,"TM-RCES-79");i++;
    nameMap.insert(i,"TM-RCES-80");i++;
    nameMap.insert(i,"TM-RCES-81");i++;
    nameMap.insert(i,"TM-RCES-82");i++;
    nameMap.insert(i,"TM-RCES-83");i++;
    nameMap.insert(i,"TM-RCES-84");i++;
    nameMap.insert(i,"TM-RCES-85");i++;
    nameMap.insert(i,"TM-RCES-86");i++;
    nameMap.insert(i,"TM-RCES-87");i++;
    nameMap.insert(i,"TM-RCES-88");i++;
    nameMap.insert(i,"TM-RCES-89");i++;
    nameMap.insert(i,"TM-RCES-90");i++;
    nameMap.insert(i,"TM-RCES-93");i++;
    nameMap.insert(i,"TM-RCES-94");i++;
    nameMap.insert(i,"TM-RCES-95");i++;
    nameMap.insert(i,"TM-RCES-96");i++;
    nameMap.insert(i,"TM-RCES-97");i++;
    nameMap.insert(i,"TM-RCES-98");i++;
    nameMap.insert(i,"TM-RCES-99");i++;
    nameMap.insert(i,"TM-RCES-100");i++;
    nameMap.insert(i,"TM-RCES-101");i++;
    nameMap.insert(i,"TM-RCES-102");i++;
    nameMap.insert(i,"TM-RCES-103");i++;
    nameMap.insert(i,"TM-RCES-104");i++;
    nameMap.insert(i,"TM-RCES-105");i++;
    nameMap.insert(i,"TM-RCES-106");i++;
    nameMap.insert(i,"TM-RCES-107");i++;
    nameMap.insert(i,"TM-RCES-108");i++;
    nameMap.insert(i,"TM-RCES-109");i++;
    nameMap.insert(i,"TM-RCES-110");i++;
    nameMap.insert(i,"TM-RCES-111");i++;
    nameMap.insert(i,"TM-RCES-112");i++;
    nameMap.insert(i,"TM-RCES-113");i++;
    nameMap.insert(i,"TM-RCES-114");i++;
    nameMap.insert(i,"TM-RCES-115");i++;
    nameMap.insert(i,"TM-RCES-116");i++;
    nameMap.insert(i,"TM-RCES-117");i++;
    nameMap.insert(i,"TM-RCES-118");i++;
    nameMap.insert(i,"TM-RCES-119");i++;
    nameMap.insert(i,"TM-RCES-120");i++;
    nameMap.insert(i,"TM-RCES-121");i++;
    nameMap.insert(i,"TM-RCES-122");i++;
    nameMap.insert(i,"TM-RCES-123");i++;
    nameMap.insert(i,"TM-RCES-124");i++;
    nameMap.insert(i,"TM-RCES-125");i++;
    nameMap.insert(i,"TM-RCES-126");i++;
    nameMap.insert(i,"TM-RCES-127");i++;
    nameMap.insert(i,"TM-RCES-128");i++;
    nameMap.insert(i,"TM-RCES-129");i++;
    nameMap.insert(i,"TM-RCES-130");i++;
    nameMap.insert(i,"TM-RCES-131");i++;
    nameMap.insert(i,"TM-RCES-132");i++;
    nameMap.insert(i,"TM-RCES-133");i++;
    nameMap.insert(i,"TM-RCES-134");i++;
    nameMap.insert(i,"TM-RCES-135");i++;
    nameMap.insert(i,"TM-RCES-136");i++;
    nameMap.insert(i,"TM-RCES-137");i++;
    nameMap.insert(i,"TM-RCES-138");i++;
    nameMap.insert(i,"TM-RCES-139");i++;
    nameMap.insert(i,"TM-RCES-140");i++;
    nameMap.insert(i,"TM-RCES-141");i++;
    nameMap.insert(i,"TM-RCES-142");i++;
    nameMap.insert(i,"TM-RCES-143");i++;
    nameMap.insert(i,"TM-RCES-144");i++;
    nameMap.insert(i,"TM-RCES-145");i++;
    nameMap.insert(i,"TM-RCES-146");i++;
    nameMap.insert(i,"TM-RCES-147");i++;
    nameMap.insert(i,"TM-RCES-148");i++;
    nameMap.insert(i,"TM-RCES-149");i++;
    nameMap.insert(i,"TM-RCES-150");i++;
    nameMap.insert(i,"TM-RCES-151");i++;
    nameMap.insert(i,"TM-RCES-152");i++;
    nameMap.insert(i,"TM-RCES-153");i++;
    nameMap.insert(i,"TM-RCES-154");i++;
    nameMap.insert(i,"TM-RCES-155");i++;
    nameMap.insert(i,"TM-RCES-156");i++;
    nameMap.insert(i,"TM-RCES-157");i++;
    nameMap.insert(i,"TM-RCES-158");i++;
    nameMap.insert(i,"TM-RCES-159");i++;
    nameMap.insert(i,"TM-RCES-160");i++;
    nameMap.insert(i,"TM-RCES-161");i++;
    nameMap.insert(i,"TM-RCES-162");i++;
    nameMap.insert(i,"TM-RCES-163");i++;
    nameMap.insert(i,"TM-RCES-164");i++;
    nameMap.insert(i,"TM-RCES-165");i++;
    nameMap.insert(i,"TM-RCES-166");i++;
    nameMap.insert(i,"TM-RCES-167");i++;
    nameMap.insert(i,"TM-RCES-168");i++;
    nameMap.insert(i,"TM-RCES-169");i++;
    nameMap.insert(i,"TM-RCES-170");i++;
    nameMap.insert(i,"TM-RCES-171");i++;
    nameMap.insert(i,"TM-RCES-172");i++;
    nameMap.insert(i,"TM-RCES-173");i++;
    nameMap.insert(i,"TM-RCES-174");i++;
    nameMap.insert(i,"TM-RCES-175");i++;
    nameMap.insert(i,"TM-RCES-176");i++;
    nameMap.insert(i,"TM-RCES-177");i++;
    nameMap.insert(i,"TM-RCES-178");i++;
    nameMap.insert(i,"TM-RCES-179");i++;
    nameMap.insert(i,"TM-RCES-180");i++;
    nameMap.insert(i,"TM-RCES-181");i++;
    nameMap.insert(i,"TM-RCES-182");i++;
    nameMap.insert(i,"TM-RCES-183");i++;
    nameMap.insert(i,"TM-RCES-184");i++;
    nameMap.insert(i,"TM-RCES-185");i++;
    nameMap.insert(i,"TM-RCES-186");i++;
    nameMap.insert(i,"TM-RCES-187");i++;
    nameMap.insert(i,"TM-RCES-188");i++;
    nameMap.insert(i,"TM-RCES-189");i++;
    nameMap.insert(i,"TM-RCES-190");i++;
    nameMap.insert(i,"TM-RCES-191");i++;
    nameMap.insert(i,"TM-RCES-192");i++;
    nameMap.insert(i,"TM-RCES-193");i++;
    nameMap.insert(i,"TM-RCES-194");i++;
    nameMap.insert(i,"TM-RCES-195");i++;
    nameMap.insert(i,"TM-RCES-196");i++;
    nameMap.insert(i,"TM-RCES-197");i++;
    nameMap.insert(i,"TM-RCES-198");i++;
    nameMap.insert(i,"TM-RCES-199");i++;
    nameMap.insert(i,"TM-RCES-200");i++;
    nameMap.insert(i,"TM-RCES-201");i++;
    nameMap.insert(i,"TM-RCES-202");i++;
    nameMap.insert(i,"TM-RCES-203");i++;
    nameMap.insert(i,"TM-RCES-204");i++;
    nameMap.insert(i,"TM-RCES-205");i++;
    nameMap.insert(i,"TM-RCES-206");i++;
    nameMap.insert(i,"TM-RCES-207");i++;
    nameMap.insert(i,"TM-RCES-208");i++;
    nameMap.insert(i,"TM-RCES-209");i++;
    nameMap.insert(i,"TM-RCES-210");i++;
    nameMap.insert(i,"TM-RCES-211");i++;
    nameMap.insert(i,"TM-RCES-212");i++;
    nameMap.insert(i,"TM-RCES-213");i++;
    nameMap.insert(i,"TM-RCES-214");i++;
    nameMap.insert(i,"TM-RCES-215");i++;
    nameMap.insert(i,"TM-RCES-216");i++;
    nameMap.insert(i,"TM-RCES-217");i++;
    nameMap.insert(i,"TM-RCES-218");i++;
    nameMap.insert(i,"TM-RCES-219");i++;
    nameMap.insert(i,"TM-RCES-220");i++;
    nameMap.insert(i,"TM-RCES-221");i++;
    nameMap.insert(i,"TM-RCES-222");i++;
    nameMap.insert(i,"TM-RCES-223");i++;
    nameMap.insert(i,"TM-RCES-224");i++;
    nameMap.insert(i,"TM-RCES-225");i++;
    nameMap.insert(i,"TM-RCES-226");i++;
    nameMap.insert(i,"TM-RCES-227");i++;
    nameMap.insert(i,"TM-RCES-228");i++;
    nameMap.insert(i,"TM-RCES-229");i++;
    nameMap.insert(i,"TM-RCES-230");i++;
    nameMap.insert(i,"TM-RCES-231");i++;
    nameMap.insert(i,"TM-RCES-232");i++;
    nameMap.insert(i,"TM-RCES-233");i++;
    nameMap.insert(i,"TM-RCES-234");i++;
    nameMap.insert(i,"TM-RCES-235");i++;
    nameMap.insert(i,"TM-RCES-236");i++;
    nameMap.insert(i,"TM-RCES-237");i++;
    nameMap.insert(i,"TM-RCES-238");i++;
    nameMap.insert(i,"TM-ROS-01");i++;
    nameMap.insert(i,"TM-ROS-02");i++;
    nameMap.insert(i,"TM-ROS-03");i++;
    nameMap.insert(i,"TM-ROS-04");i++;
    nameMap.insert(i,"TM-ROS-05");i++;
    nameMap.insert(i,"TM-ROS-06");i++;
}
*/

void RCForm::OpenOrderFile(QString fileName)
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

    /****************************************************************************************************************************/

    QJsonObject jsonObject = document.object();
    foreach(QString i, jsonObject.keys())
    {
        QJsonObject obj = jsonObject.value(i).toObject();
        QStringList orderList;
        orderList<<obj.value(QStringLiteral("type")).toString();
        orderList<<obj.value(QStringLiteral("name")).toString();
        orderList<<obj.value(QStringLiteral("order")).toString();
        orderList<<obj.value(QStringLiteral("delay")).toString();
        QJsonObject target = obj.value(QStringLiteral("target")).toObject();

        if(target.isEmpty())
        {
            orderList<<" ";
        }
        else
        {
            QString sdStatus;
            foreach(QString k, target.keys())
            {
                sdStatus.clear();
                QJsonObject targetItem = target.value(k).toObject();
                if(targetItem.value(QStringLiteral("attribute")).toString() == "0")
                {
                    sdStatus = k + " " + "0" + " " + targetItem.value(QStringLiteral("content")).toString();
                    orderList<<sdStatus;
                    continue;
                }
                if(targetItem.value(QStringLiteral("attribute")).toString() == "1")
                {
                    QString tmp = targetItem.value(QStringLiteral("content")).toString();
                    QStringList temp = tmp.split("-");
                    if(temp.length()==2)
                    {
                        sdStatus = k + " " + "1" + " " + temp.at(0) + " " + temp.at(1);
                    }
                    else
                    {
                        sdStatus = " ";
                    }
                    orderList<<sdStatus;
                    continue;
                }
            }
        }

        orderContentMap.insert(i,orderList);
    }

    /*******************************************************************************************************************************************/
}

void RCForm::BuildCommandList()
{
    commandList.clear();
    int index = ui->comboBoxSubSys->currentIndex();
    QStringList cList;
    QString order;
    QString temp;
    QString head;
    QString tail;
    switch (index) {
    case -1:{
        for (int i=0; i<diyList.size();i++ ) {
            commandList<<"######";
            qDebug()<<diyList;
            if(!orderContentMap.contains(diyList.at(i)))
            {
                //需要设置不存在该指令的提示，在后续发送之中也要处理这个特殊情况
                continue;
            }
            cList = orderContentMap.value(diyList.at(i));
            qDebug()<<cList;
            if(cList.at(0)=="0")
            {
                head = dOrderHead;
                tail = dOrderTail;
            }
            else
            {
                head = indOrderHead;
                tail = indOrderTail;
            }
            temp = cList.at(2);
            order = head + temp + temp + temp + tail;
            commandList<<order;
            commandList<<cList.at(3);
            for (int j=4;j<cList.size();j++) {
                commandList<<cList.at(j);
            }
        }
        break;
    }
    case 0:{//DTTC测控系统应答机
        break;
    }
    case 1:{//CES综合电子系统
//        QStringList tmpList = sysOrderNameMap.value("RCES");
//        for (int i=0; i<tmpList.size() ;i++ ) {
//            commandList<<"######";
//            cList = orderContentMap.value(tmpList.at(i));
//            if(cList.at(0)=="0")
//            {
//                head = dOrderHead;
//                tail = dOrderTail;
//            }
//            else
//            {
//                head = indOrderHead;
//                tail = indOrderTail;
//            }
//            temp = cList.at(1);
//            order = head + temp + temp + temp + tail;
//            commandList<<order;
//            commandList<<cList.at(2);
//            for (int j=3;j<cList.size();j++) {
//                commandList<<cList.at(j);
//            }
//        }
//        break;
    }
    case 2:{//OCS轨控系统
        break;
    }
    case 3:{//ADCS姿控系统
//        QStringList tmpList = sysOrderNameMap.value("RADCS");
//        for (int i=0; i<tmpList.size() ;i++ ) {
//            commandList<<"######";
//            cList = orderContentMap.value(tmpList.at(i));
//            if(cList.at(0)=="0")
//            {
//                head = dOrderHead;
//                tail = dOrderTail;
//            }
//            else
//            {
//                head = indOrderHead;
//                tail = indOrderTail;
//            }
//            temp = cList.at(1);
//            order = head + temp + temp + temp + tail;
//            commandList<<order;
//            commandList<<cList.at(2);
//            for (int j=3;j<cList.size();j++) {
//                commandList<<cList.at(j);
//            }
//        }
//        break;
    }
    case 4:{//OS操作系统
        break;
    }
    case 5:{//EPS电源系统
        break;
    }
    case 6:{//ZH载荷系统
        break;
    }
    case 7:{//GNSS系统
        break;
    }
    default:break;
    }
}

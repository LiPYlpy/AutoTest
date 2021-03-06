#include "widget.h"
#include "ui_widget.h"
#include <QDebug>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tabWidget->removeTab(1);
    ui->tabWidget->removeTab(2);

    ui->tabWidget->clear();

    serialForm = new SerialForm(this);
    ui->tabWidget->insertTab(0,serialForm,tr("数据中心"));

    telemetryForm = new TelemetryForm(this);
    ui->tabWidget->insertTab(1,telemetryForm,tr("遥测系统"));


    rcForm = new RCForm(this);
    ui->tabWidget->insertTab(2,rcForm,tr("遥控系统"));


    //接收检测配置文件中的检测指令和卫星标准状态
    connect(rcForm,&RCForm::TxtSend,this,&Widget::TxtRecv);

    connect(this,&Widget::TxtSend,serialForm,&SerialForm::TxtRecv);

    //显示检测结果
    connect(serialForm,&SerialForm::SendExplainInfo,this,&Widget::RecvExplainInfo);

    connect(serialForm,&SerialForm::Send2RCForm,this,&Widget::FromSerialForm);

    //检测对应指令的检测结果
    connect(this,&Widget::Send2RCForm,rcForm,&RCForm::DisplayDetectResult);

    connect(this,&Widget::SendExplainInfo,telemetryForm,&TelemetryForm::RecvExplainInfo);
}

Widget::~Widget()
{

    delete telemetryForm;
    delete rcForm;
    delete serialForm;
    delete ui;
    qDebug()<<"析构 Widget";
}

void Widget::TxtRecv(QStringList lineStr)
{
    emit TxtSend(lineStr);
}

void Widget::FromSerialForm(QString command, QStringList resultList)
{
    emit Send2RCForm(command,resultList);
}

void Widget::RecvExplainInfo(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList)
{
    emit SendExplainInfo(sysName, valueList, hexList, resultList);
}


#include "tableform.h"
#include "ui_tableform.h"
#include <QColor>

TableForm::TableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableForm)
{
    ui->setupUi(this);

    //tabWidget初始化，设置行数、列数
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(55);
    //设置表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"波道代号"<<"值"<<"源码HEX"<<"数据保存时间"<<"星上时间"<<"CRC校验"<<"");

}

TableForm::~TableForm()
{
    delete ui;
}

//表格更新函数
void TableForm::UpdataUI(QVariantList valueList, QVariantList hexList, QStringList resultList)
{
    for (int i = 0; i<valueList.size(); i++ ) {   //更新value和hex
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(valueList.at(i).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(hexList.at(i).toString()));
        if(resultList.at(i)=="true")   //数据无错，设置背景为白色
        {
            ui->tableWidget->item(i,1)->setBackgroundColor(QColor(255,255,255));
            ui->tableWidget->item(i,2)->setBackgroundColor(QColor(255,255,255));
        }
        else   //数据有错设置背景为红色
        {
            ui->tableWidget->item(i,1)->setBackgroundColor(QColor(255,128,128));
            ui->tableWidget->item(i,2)->setBackgroundColor(QColor(255,128,128));
        }
    }
}

//初始化表格前两列（波道名、波道号）
void TableForm::InitTable(QStringList nameList, QStringList numList)
{
    ui->tableWidget->setRowCount(numList.size());
    for (int i = 0; i < numList.size(); i++) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(numList.at(i)));
    }
}


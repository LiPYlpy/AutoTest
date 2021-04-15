#ifndef TELEMETRYFORM_H
#define TELEMETRYFORM_H

#include <QWidget>
#include "treewidgettelemetry.h"
//#include "tabform.h"
#include "tableform.h"
#include "inittelemetrytable.h"
#include <QMap>
#include <QVariant>
#include "drawform.h"


namespace Ui {
class TelemetryForm;
}

class TelemetryForm : public QWidget
{
    Q_OBJECT

public:
    explicit TelemetryForm(QWidget *parent = nullptr);
    ~TelemetryForm();

    void OpenJsonFile(QString fileName);

    QStringList GetNameFromMap(QString sysName);

    //SLOT

//    void RecvExplainInfo(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList);

    void RecvExplainInfo(QVariant map2Display,QStringList resultList);

    void StartDrawPic(DrawForm * plotForm, QStringList chosenList);

signals:

    void Send2Plot(QList<float> chosenValueF, QStringList chosenList);

    void R1_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R2_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R3_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R4_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R5_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R6_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R7_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R8_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R9_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R10_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);

    void R19_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R20_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R21_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R22_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R23_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R24_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R25_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R26_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);
    void R27_Display(QVariantList valueList, QVariantList hexList, QStringList resultList);


    void R19_Init(QStringList nameList, QStringList numList);
    void R20_Init(QStringList nameList, QStringList numList);
    void R21_Init(QStringList nameList, QStringList numList);
    void R22_Init(QStringList nameList, QStringList numList);
    void R23_Init(QStringList nameList, QStringList numList);
    void R24_Init(QStringList nameList, QStringList numList);
    void R25_Init(QStringList nameList, QStringList numList);
    void R26_Init(QStringList nameList, QStringList numList);
    void R27_Init(QStringList nameList, QStringList numList);

private:
    Ui::TelemetryForm *ui;
    treeWidgetTelemetry * telemetryList;   //遥测数据树建立返回的treeWidgetItem
    QTreeWidgetItem * topItem;             //ui中的树的顶层节点

    TableForm * R1_tableForm;
    TableForm * R2_tableForm;
    TableForm * R3_tableForm;
    TableForm * R4_tableForm;
    TableForm * R5_tableForm;
    TableForm * R6_tableForm;
    TableForm * R7_tableForm;
    TableForm * R8_tableForm;
    TableForm * R9_tableForm;
    TableForm * R10_tableForm;
    TableForm * R11_tableForm;
    TableForm * R12_tableForm;
    TableForm * R13_tableForm;
    TableForm * R14_tableForm;
    TableForm * R15_tableForm;
    TableForm * R16_tableForm;
    TableForm * R17_tableForm;
    TableForm * R18_tableForm;
    TableForm * R19_tableForm;
    TableForm * R20_tableForm;
    TableForm * R21_tableForm;
    TableForm * R22_tableForm;
    TableForm * R23_tableForm;
    TableForm * R24_tableForm;
    TableForm * R25_tableForm;
    TableForm * R26_tableForm;
    TableForm * R27_tableForm;

    DrawForm * curvePic;
};



#endif // TELEMETRYFORM_H

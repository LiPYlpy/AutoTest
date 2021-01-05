#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "rcform.h"
#include "telemetryform.h"
#include "serialform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //SLOT

    void TxtRecv(QStringList lineStr);

    void FromSerialForm(QString command, QStringList resultList);

    //tableWidget
    void RecvExplainInfo(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList);

signals:

    void TxtSend(QStringList lineStr);

    void Send2RCForm(QString command, QStringList resultList);

    //tableWidget
    void SendExplainInfo(int sysName, QVariantList valueList, QVariantList hexList, QStringList resultList);


private:
    Ui::Widget *ui;
    RCForm *rcForm;
    TelemetryForm *telemetryForm;
    SerialForm *serialForm;

};
#endif // WIDGET_H

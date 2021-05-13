#ifndef RCFORM_H
#define RCFORM_H

#include <QWidget>
#include <QFileDialog>
#include <QTextStream>
#include "drawform.h"


namespace Ui {
class RCForm;
}

class RCForm : public QWidget
{
    Q_OBJECT

public:
    explicit RCForm(QWidget *parent = nullptr);
    ~RCForm();

    QByteArray QString2QByteArray(QString str);

    void DisplayDetectResult(QString command, QStringList resultList);

    void BuildMap();

    void OpenOrderFile(QString fileName);

    void BuildCommandList();

    void RecvBeforeTest(QStringList startTest);

    void RecvStatePerPac(QVariant map2Display);

signals:

    void TxtSend(QStringList lineStr);

    void Send2Plot(QList<float> chosenValueF, QStringList chosenList);

    void cleanPic();

private:
    Ui::RCForm *ui;
    QStringList commandList;
    QStringList diyList;
    QString dOrderHead;
    QString dOrderTail;
    QString indOrderHead;
    QString indOrderTail;

    QStringList tclibinf;
    QString tcnum;
    QString tcname;

    QStringList storeStateList; //存储检测之前的对应波道的状态
    QStringList drawList;

    DrawForm * curvePic;
};

#endif // RCFORM_H

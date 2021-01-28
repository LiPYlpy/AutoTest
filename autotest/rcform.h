#ifndef RCFORM_H
#define RCFORM_H

#include <QWidget>
#include <QFileDialog>
#include <QTextStream>


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

signals:

    void TxtSend(QStringList lineStr);

private:
    Ui::RCForm *ui;
    QStringList commandList;
    QStringList diyList;
    QString dOrderHead;
    QString dOrderTail;
    QString indOrderHead;
    QString indOrderTail;
};

#endif // RCFORM_H

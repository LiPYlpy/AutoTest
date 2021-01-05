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

signals:

    void TxtSend(QStringList lineStr);

private:
    Ui::RCForm *ui;
    QStringList commandList;
};

#endif // RCFORM_H

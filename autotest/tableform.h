#ifndef TABLEFORM_H
#define TABLEFORM_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class TableForm;
}

class TableForm : public QWidget
{
    Q_OBJECT

public:
    explicit TableForm(QWidget *parent = nullptr);
    ~TableForm();

    //SLOT
    void UpdataUI(QVariantList valueList, QVariantList hexList, QStringList resultList);

    void InitTable(QStringList nameList, QStringList numList);

private:
    Ui::TableForm *ui;
};

#endif // TABLEFORM_H

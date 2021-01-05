/********************************************************************************
** Form generated from reading UI file 'tableform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEFORM_H
#define UI_TABLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableForm
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *TableForm)
    {
        if (TableForm->objectName().isEmpty())
            TableForm->setObjectName(QStringLiteral("TableForm"));
        TableForm->resize(986, 620);
        horizontalLayout = new QHBoxLayout(TableForm);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(TableForm);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout->addWidget(tableWidget);


        retranslateUi(TableForm);

        QMetaObject::connectSlotsByName(TableForm);
    } // setupUi

    void retranslateUi(QWidget *TableForm)
    {
        TableForm->setWindowTitle(QApplication::translate("TableForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TableForm: public Ui_TableForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEFORM_H

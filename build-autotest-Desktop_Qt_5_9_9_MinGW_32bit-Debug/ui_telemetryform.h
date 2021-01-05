/********************************************************************************
** Form generated from reading UI file 'telemetryform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELEMETRYFORM_H
#define UI_TELEMETRYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelemetryForm
{
public:
    QGridLayout *gridLayout;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidgetTelemetry;
    QTabWidget *tabWidgetDisplay;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QWidget *tab_2;

    void setupUi(QWidget *TelemetryForm)
    {
        if (TelemetryForm->objectName().isEmpty())
            TelemetryForm->setObjectName(QStringLiteral("TelemetryForm"));
        TelemetryForm->resize(1060, 618);
        gridLayout = new QGridLayout(TelemetryForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dockWidget = new QDockWidget(TelemetryForm);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMaximumSize(QSize(571, 524287));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidgetTelemetry = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidgetTelemetry->setHeaderItem(__qtreewidgetitem);
        treeWidgetTelemetry->setObjectName(QStringLiteral("treeWidgetTelemetry"));
        treeWidgetTelemetry->setHeaderHidden(true);

        verticalLayout->addWidget(treeWidgetTelemetry);

        dockWidget->setWidget(dockWidgetContents);

        gridLayout->addWidget(dockWidget, 0, 0, 1, 1);

        tabWidgetDisplay = new QTabWidget(TelemetryForm);
        tabWidgetDisplay->setObjectName(QStringLiteral("tabWidgetDisplay"));
        tabWidgetDisplay->setElideMode(Qt::ElideNone);
        tabWidgetDisplay->setTabsClosable(false);
        tabWidgetDisplay->setMovable(true);
        tabWidgetDisplay->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tabWidgetDisplay->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidgetDisplay->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidgetDisplay, 0, 1, 1, 1);


        retranslateUi(TelemetryForm);

        tabWidgetDisplay->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TelemetryForm);
    } // setupUi

    void retranslateUi(QWidget *TelemetryForm)
    {
        TelemetryForm->setWindowTitle(QApplication::translate("TelemetryForm", "Form", Q_NULLPTR));
        tabWidgetDisplay->setTabText(tabWidgetDisplay->indexOf(tab), QApplication::translate("TelemetryForm", "Tab 1", Q_NULLPTR));
        tabWidgetDisplay->setTabText(tabWidgetDisplay->indexOf(tab_2), QApplication::translate("TelemetryForm", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TelemetryForm: public Ui_TelemetryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELEMETRYFORM_H

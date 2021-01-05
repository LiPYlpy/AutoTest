/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab0;
    QWidget *tab1;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *treeWidgetTelemetry;
    QTabWidget *tabWidgetDisplay;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QWidget *tab_2;
    QWidget *tab2;
    QTabWidget *tabWidget_2;
    QWidget *tab20;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxSwitchType;
    QLabel *label_2;
    QComboBox *comboBoxSubSys;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxSwitch;
    QCheckBox *checkBoxReturn;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QPushButton *btnSearch;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *comboBoxSendType;
    QPushButton *btnSend;
    QWidget *tab21;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QComboBox *comboBoxDataLength;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkBoxDisturb;
    QCheckBox *checkBoxEncrypt;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioButtonSetData;
    QRadioButton *radioButtonDIYData;
    QTextEdit *textEdit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonSetData;
    QPushButton *pushButtonDIYData;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QTableView *tableView;
    QPushButton *btnOrderSend;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1253, 681);
        horizontalLayout_4 = new QHBoxLayout(Widget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab0 = new QWidget();
        tab0->setObjectName(QStringLiteral("tab0"));
        tabWidget->addTab(tab0, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        dockWidget = new QDockWidget(tab1);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setGeometry(QRect(20, 20, 361, 561));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        treeWidgetTelemetry = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidgetTelemetry->setHeaderItem(__qtreewidgetitem);
        treeWidgetTelemetry->setObjectName(QStringLiteral("treeWidgetTelemetry"));
        treeWidgetTelemetry->setHeaderHidden(true);

        verticalLayout_4->addWidget(treeWidgetTelemetry);

        dockWidget->setWidget(dockWidgetContents);
        tabWidgetDisplay = new QTabWidget(tab1);
        tabWidgetDisplay->setObjectName(QStringLiteral("tabWidgetDisplay"));
        tabWidgetDisplay->setGeometry(QRect(430, 20, 771, 551));
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
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        tabWidget_2 = new QTabWidget(tab2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(40, 30, 371, 451));
        tab20 = new QWidget();
        tab20->setObjectName(QStringLiteral("tab20"));
        verticalLayout = new QVBoxLayout(tab20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(tab20);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBoxSwitchType = new QComboBox(widget);
        comboBoxSwitchType->setObjectName(QStringLiteral("comboBoxSwitchType"));
        comboBoxSwitchType->setEditable(false);

        horizontalLayout->addWidget(comboBoxSwitchType);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBoxSubSys = new QComboBox(widget);
        comboBoxSubSys->setObjectName(QStringLiteral("comboBoxSubSys"));

        horizontalLayout->addWidget(comboBoxSubSys);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(tab20);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxSwitch = new QCheckBox(widget_2);
        checkBoxSwitch->setObjectName(QStringLiteral("checkBoxSwitch"));

        horizontalLayout_2->addWidget(checkBoxSwitch);

        checkBoxReturn = new QCheckBox(widget_2);
        checkBoxReturn->setObjectName(QStringLiteral("checkBoxReturn"));

        horizontalLayout_2->addWidget(checkBoxReturn);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(tab20);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        btnSearch = new QPushButton(widget_3);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));

        horizontalLayout_3->addWidget(btnSearch);


        verticalLayout->addWidget(widget_3);

        scrollArea = new QScrollArea(tab20);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 341, 187));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        widget_4 = new QWidget(tab20);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        comboBoxSendType = new QComboBox(widget_4);
        comboBoxSendType->setObjectName(QStringLiteral("comboBoxSendType"));

        horizontalLayout_5->addWidget(comboBoxSendType);

        btnSend = new QPushButton(widget_4);
        btnSend->setObjectName(QStringLiteral("btnSend"));

        horizontalLayout_5->addWidget(btnSend);


        verticalLayout->addWidget(widget_4);

        tabWidget_2->addTab(tab20, QString());
        tab21 = new QWidget();
        tab21->setObjectName(QStringLiteral("tab21"));
        verticalLayout_2 = new QVBoxLayout(tab21);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_7 = new QWidget(tab21);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_9 = new QHBoxLayout(widget_7);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_9->addWidget(label_4);

        comboBoxDataLength = new QComboBox(widget_7);
        comboBoxDataLength->setObjectName(QStringLiteral("comboBoxDataLength"));

        horizontalLayout_9->addWidget(comboBoxDataLength);


        verticalLayout_2->addWidget(widget_7);

        widget_6 = new QWidget(tab21);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_8 = new QHBoxLayout(widget_6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        checkBoxDisturb = new QCheckBox(widget_6);
        checkBoxDisturb->setObjectName(QStringLiteral("checkBoxDisturb"));

        horizontalLayout_8->addWidget(checkBoxDisturb);

        checkBoxEncrypt = new QCheckBox(widget_6);
        checkBoxEncrypt->setObjectName(QStringLiteral("checkBoxEncrypt"));

        horizontalLayout_8->addWidget(checkBoxEncrypt);


        verticalLayout_2->addWidget(widget_6);

        groupBox = new QGroupBox(tab21);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        radioButtonSetData = new QRadioButton(groupBox);
        radioButtonSetData->setObjectName(QStringLiteral("radioButtonSetData"));

        horizontalLayout_6->addWidget(radioButtonSetData);

        radioButtonDIYData = new QRadioButton(groupBox);
        radioButtonDIYData->setObjectName(QStringLiteral("radioButtonDIYData"));

        horizontalLayout_6->addWidget(radioButtonDIYData);


        verticalLayout_2->addWidget(groupBox);

        textEdit = new QTextEdit(tab21);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        widget_5 = new QWidget(tab21);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButtonSetData = new QPushButton(widget_5);
        pushButtonSetData->setObjectName(QStringLiteral("pushButtonSetData"));

        horizontalLayout_7->addWidget(pushButtonSetData);

        pushButtonDIYData = new QPushButton(widget_5);
        pushButtonDIYData->setObjectName(QStringLiteral("pushButtonDIYData"));

        horizontalLayout_7->addWidget(pushButtonDIYData);


        verticalLayout_2->addWidget(widget_5);

        tabWidget_2->addTab(tab21, QString());
        widget_8 = new QWidget(tab2);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(450, 50, 511, 431));
        verticalLayout_3 = new QVBoxLayout(widget_8);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(widget_8);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        tableView = new QTableView(widget_8);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_3->addWidget(tableView);

        btnOrderSend = new QPushButton(tab2);
        btnOrderSend->setObjectName(QStringLiteral("btnOrderSend"));
        btnOrderSend->setGeometry(QRect(800, 490, 131, 41));
        textBrowser = new QTextBrowser(tab2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(40, 500, 711, 31));
        tabWidget->addTab(tab2, QString());

        horizontalLayout_4->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);
        tabWidgetDisplay->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\344\270\200\351\224\256\346\265\213\350\257\225", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab0), QApplication::translate("Widget", "\346\225\260\346\215\256\344\270\255\345\277\203 ", Q_NULLPTR));
        tabWidgetDisplay->setTabText(tabWidgetDisplay->indexOf(tab), QApplication::translate("Widget", "Tab 1", Q_NULLPTR));
        tabWidgetDisplay->setTabText(tabWidgetDisplay->indexOf(tab_2), QApplication::translate("Widget", "Tab 2", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("Widget", "\351\201\245\346\265\213\347\263\273\347\273\237", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\345\274\200\345\205\263\346\214\207\344\273\244\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\345\210\206\347\263\273\347\273\237\357\274\232", Q_NULLPTR));
        checkBoxSwitch->setText(QApplication::translate("Widget", "\345\274\200\345\205\263\346\214\207\344\273\244\345\212\240\345\257\206", Q_NULLPTR));
        checkBoxReturn->setText(QApplication::translate("Widget", "\350\277\224\345\233\236\345\260\217\347\216\257\346\257\224\345\257\271", Q_NULLPTR));
        lineEdit->setText(QString());
        btnSearch->setText(QApplication::translate("Widget", "\346\220\234\347\264\242", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        btnSend->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab20), QApplication::translate("Widget", "\346\214\207\344\273\244", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\351\225\277\345\272\246", Q_NULLPTR));
        checkBoxDisturb->setText(QApplication::translate("Widget", "\346\263\250\345\205\245\346\225\260\346\215\256\345\212\240\346\211\260", Q_NULLPTR));
        checkBoxEncrypt->setText(QApplication::translate("Widget", "\346\263\250\345\205\245\346\225\260\346\215\256\345\212\240\345\257\206", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "\345\217\221\351\200\201\347\261\273\345\236\213", Q_NULLPTR));
        radioButtonSetData->setText(QApplication::translate("Widget", "\346\263\250\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        radioButtonDIYData->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\350\207\252\345\256\232\344\271\211\346\225\260\346\215\256", Q_NULLPTR));
        pushButtonSetData->setText(QApplication::translate("Widget", "\346\263\250\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        pushButtonDIYData->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\350\207\252\345\256\232\344\271\211\346\225\260\346\215\256", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab21), QApplication::translate("Widget", "\346\263\250\346\225\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\345\217\221\351\200\201\345\216\206\345\217\262\350\256\260\345\275\225", Q_NULLPTR));
        btnOrderSend->setText(QApplication::translate("Widget", "\350\207\252\345\212\250\351\241\272\345\272\217\345\217\221\351\200\201", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("Widget", "\351\201\245\346\216\247\347\263\273\347\273\237 ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

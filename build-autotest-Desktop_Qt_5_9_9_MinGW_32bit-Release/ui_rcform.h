/********************************************************************************
** Form generated from reading UI file 'rcform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RCFORM_H
#define UI_RCFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RCForm
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget_2;
    QWidget *tab20;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QComboBox *comboBoxSwitchType;
    QLabel *label_2;
    QComboBox *comboBoxSubSys;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxSwitch;
    QCheckBox *checkBoxReturn;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *btnSearch;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBoxSendType;
    QPushButton *btnSend;
    QWidget *tab21;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QComboBox *comboBoxDataLength;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBoxDisturb;
    QCheckBox *checkBoxEncrypt;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioButtonSetData;
    QRadioButton *radioButtonDIYData;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonSetData;
    QPushButton *btnSendDIY;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QTextBrowser *hisTextBrowser;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *showTextEdit;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btnOpenTxt;
    QPushButton *btnOrderSend;

    void setupUi(QWidget *RCForm)
    {
        if (RCForm->objectName().isEmpty())
            RCForm->setObjectName(QStringLiteral("RCForm"));
        RCForm->resize(1194, 499);
        gridLayout = new QGridLayout(RCForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget_2 = new QTabWidget(RCForm);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab20 = new QWidget();
        tab20->setObjectName(QStringLiteral("tab20"));
        verticalLayout = new QVBoxLayout(tab20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label = new QLabel(tab20);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_9->addWidget(label);

        comboBoxSwitchType = new QComboBox(tab20);
        comboBoxSwitchType->setObjectName(QStringLiteral("comboBoxSwitchType"));
        comboBoxSwitchType->setEditable(false);

        horizontalLayout_9->addWidget(comboBoxSwitchType);

        label_2 = new QLabel(tab20);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_9->addWidget(label_2);

        comboBoxSubSys = new QComboBox(tab20);
        comboBoxSubSys->setObjectName(QStringLiteral("comboBoxSubSys"));

        horizontalLayout_9->addWidget(comboBoxSubSys);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxSwitch = new QCheckBox(tab20);
        checkBoxSwitch->setObjectName(QStringLiteral("checkBoxSwitch"));

        horizontalLayout->addWidget(checkBoxSwitch);

        checkBoxReturn = new QCheckBox(tab20);
        checkBoxReturn->setObjectName(QStringLiteral("checkBoxReturn"));

        horizontalLayout->addWidget(checkBoxReturn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(tab20);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        btnSearch = new QPushButton(tab20);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));

        horizontalLayout_2->addWidget(btnSearch);


        verticalLayout->addLayout(horizontalLayout_2);

        scrollArea = new QScrollArea(tab20);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 360, 293));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(tab20);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBoxSendType = new QComboBox(tab20);
        comboBoxSendType->setObjectName(QStringLiteral("comboBoxSendType"));

        horizontalLayout_3->addWidget(comboBoxSendType);

        btnSend = new QPushButton(tab20);
        btnSend->setObjectName(QStringLiteral("btnSend"));

        horizontalLayout_3->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout_3);

        tabWidget_2->addTab(tab20, QString());
        tab21 = new QWidget();
        tab21->setObjectName(QStringLiteral("tab21"));
        verticalLayout_2 = new QVBoxLayout(tab21);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_4 = new QLabel(tab21);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_8->addWidget(label_4);

        comboBoxDataLength = new QComboBox(tab21);
        comboBoxDataLength->setObjectName(QStringLiteral("comboBoxDataLength"));

        horizontalLayout_8->addWidget(comboBoxDataLength);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        checkBoxDisturb = new QCheckBox(tab21);
        checkBoxDisturb->setObjectName(QStringLiteral("checkBoxDisturb"));

        horizontalLayout_7->addWidget(checkBoxDisturb);

        checkBoxEncrypt = new QCheckBox(tab21);
        checkBoxEncrypt->setObjectName(QStringLiteral("checkBoxEncrypt"));

        horizontalLayout_7->addWidget(checkBoxEncrypt);


        verticalLayout_2->addLayout(horizontalLayout_7);

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

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonSetData = new QPushButton(tab21);
        pushButtonSetData->setObjectName(QStringLiteral("pushButtonSetData"));

        horizontalLayout_4->addWidget(pushButtonSetData);

        btnSendDIY = new QPushButton(tab21);
        btnSendDIY->setObjectName(QStringLiteral("btnSendDIY"));

        horizontalLayout_4->addWidget(btnSendDIY);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tabWidget_2->addTab(tab21, QString());

        gridLayout->addWidget(tabWidget_2, 0, 0, 3, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(RCForm);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        hisTextBrowser = new QTextBrowser(RCForm);
        hisTextBrowser->setObjectName(QStringLiteral("hisTextBrowser"));

        verticalLayout_3->addWidget(hisTextBrowser);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_6 = new QLabel(RCForm);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);

        textBrowser = new QTextBrowser(RCForm);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_4->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout_4, 0, 2, 2, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        showTextEdit = new QTextEdit(RCForm);
        showTextEdit->setObjectName(QStringLiteral("showTextEdit"));

        verticalLayout_5->addWidget(showTextEdit);


        gridLayout->addLayout(verticalLayout_5, 1, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        btnOpenTxt = new QPushButton(RCForm);
        btnOpenTxt->setObjectName(QStringLiteral("btnOpenTxt"));

        horizontalLayout_10->addWidget(btnOpenTxt);

        btnOrderSend = new QPushButton(RCForm);
        btnOrderSend->setObjectName(QStringLiteral("btnOrderSend"));

        horizontalLayout_10->addWidget(btnOrderSend);


        gridLayout->addLayout(horizontalLayout_10, 2, 1, 1, 1);


        retranslateUi(RCForm);

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RCForm);
    } // setupUi

    void retranslateUi(QWidget *RCForm)
    {
        RCForm->setWindowTitle(QApplication::translate("RCForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("RCForm", "\345\274\200\345\205\263\346\214\207\344\273\244\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("RCForm", "\345\210\206\347\263\273\347\273\237\357\274\232", Q_NULLPTR));
        checkBoxSwitch->setText(QApplication::translate("RCForm", "\345\274\200\345\205\263\346\214\207\344\273\244\345\212\240\345\257\206", Q_NULLPTR));
        checkBoxReturn->setText(QApplication::translate("RCForm", "\350\277\224\345\233\236\345\260\217\347\216\257\346\257\224\345\257\271", Q_NULLPTR));
        lineEdit->setText(QString());
        btnSearch->setText(QApplication::translate("RCForm", "\346\220\234\347\264\242", Q_NULLPTR));
        label_3->setText(QApplication::translate("RCForm", "\345\217\221\351\200\201\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        btnSend->setText(QApplication::translate("RCForm", "\345\217\221\351\200\201", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab20), QApplication::translate("RCForm", "\346\214\207\344\273\244", Q_NULLPTR));
        label_4->setText(QApplication::translate("RCForm", "\346\225\260\346\215\256\351\225\277\345\272\246", Q_NULLPTR));
        checkBoxDisturb->setText(QApplication::translate("RCForm", "\346\263\250\345\205\245\346\225\260\346\215\256\345\212\240\346\211\260", Q_NULLPTR));
        checkBoxEncrypt->setText(QApplication::translate("RCForm", "\346\263\250\345\205\245\346\225\260\346\215\256\345\212\240\345\257\206", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("RCForm", "\345\217\221\351\200\201\347\261\273\345\236\213", Q_NULLPTR));
        radioButtonSetData->setText(QApplication::translate("RCForm", "\346\263\250\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        radioButtonDIYData->setText(QApplication::translate("RCForm", "\347\224\250\346\210\267\350\207\252\345\256\232\344\271\211\346\225\260\346\215\256", Q_NULLPTR));
        pushButtonSetData->setText(QApplication::translate("RCForm", "\346\263\250\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        btnSendDIY->setText(QApplication::translate("RCForm", "\345\217\221\351\200\201\350\207\252\345\256\232\344\271\211\346\225\260\346\215\256", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab21), QApplication::translate("RCForm", "\346\263\250\346\225\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("RCForm", "\346\225\260\346\215\256\345\217\221\351\200\201\345\216\206\345\217\262\350\256\260\345\275\225", Q_NULLPTR));
        label_6->setText(QApplication::translate("RCForm", "\346\243\200\346\265\213\347\273\223\346\236\234", Q_NULLPTR));
        btnOpenTxt->setText(QApplication::translate("RCForm", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        btnOrderSend->setText(QApplication::translate("RCForm", "\350\207\252\345\212\250\346\265\213\350\257\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RCForm: public Ui_RCForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCFORM_H

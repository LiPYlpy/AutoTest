/********************************************************************************
** Form generated from reading UI file 'serialform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALFORM_H
#define UI_SERIALFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_8;
    QComboBox *portNameBox;
    QSpacerItem *verticalSpacer;
    QComboBox *baudrateBox;
    QSpacerItem *verticalSpacer_2;
    QComboBox *stopBitsBox;
    QSpacerItem *verticalSpacer_3;
    QComboBox *dataBitsBox;
    QSpacerItem *verticalSpacer_4;
    QComboBox *ParityBox;
    QSpacerItem *verticalSpacer_5;
    QPushButton *searchButton;
    QSpacerItem *verticalSpacer_7;
    QPushButton *openButton;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioBtnSerial;
    QRadioButton *radioBtnUDP;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *recvTextEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QSpinBox *spinBox_server_port;
    QLabel *label_9;
    QComboBox *comboTargetIP;
    QLabel *label_10;
    QSpinBox *spinTargetPort;
    QPushButton *pushButton_server_bind;
    QPushButton *pushButton_server_bind_stop;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *clearButton;
    QPushButton *sendButton;
    QHBoxLayout *horizontalLayout;
    QTextEdit *sendTextEdit;

    void setupUi(QWidget *SerialForm)
    {
        if (SerialForm->objectName().isEmpty())
            SerialForm->setObjectName(QStringLiteral("SerialForm"));
        SerialForm->resize(728, 560);
        gridLayout = new QGridLayout(SerialForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_8);

        portNameBox = new QComboBox(SerialForm);
        portNameBox->setObjectName(QStringLiteral("portNameBox"));

        verticalLayout_3->addWidget(portNameBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        baudrateBox = new QComboBox(SerialForm);
        baudrateBox->setObjectName(QStringLiteral("baudrateBox"));

        verticalLayout_3->addWidget(baudrateBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stopBitsBox = new QComboBox(SerialForm);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));

        verticalLayout_3->addWidget(stopBitsBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        dataBitsBox = new QComboBox(SerialForm);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));

        verticalLayout_3->addWidget(dataBitsBox);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        ParityBox = new QComboBox(SerialForm);
        ParityBox->setObjectName(QStringLiteral("ParityBox"));

        verticalLayout_3->addWidget(ParityBox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        searchButton = new QPushButton(SerialForm);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        verticalLayout_3->addWidget(searchButton);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        openButton = new QPushButton(SerialForm);
        openButton->setObjectName(QStringLiteral("openButton"));

        verticalLayout_3->addWidget(openButton);


        gridLayout->addLayout(verticalLayout_3, 1, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioBtnSerial = new QRadioButton(SerialForm);
        radioBtnSerial->setObjectName(QStringLiteral("radioBtnSerial"));

        horizontalLayout_3->addWidget(radioBtnSerial);

        radioBtnUDP = new QRadioButton(SerialForm);
        radioBtnUDP->setObjectName(QStringLiteral("radioBtnUDP"));

        horizontalLayout_3->addWidget(radioBtnUDP);


        gridLayout->addLayout(horizontalLayout_3, 0, 2, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        recvTextEdit = new QTextEdit(SerialForm);
        recvTextEdit->setObjectName(QStringLiteral("recvTextEdit"));

        horizontalLayout_4->addWidget(recvTextEdit);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 2, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_11 = new QLabel(SerialForm);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_2->addWidget(label_11);

        spinBox_server_port = new QSpinBox(SerialForm);
        spinBox_server_port->setObjectName(QStringLiteral("spinBox_server_port"));
        spinBox_server_port->setMaximum(65535);

        verticalLayout_2->addWidget(spinBox_server_port);

        label_9 = new QLabel(SerialForm);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_2->addWidget(label_9);

        comboTargetIP = new QComboBox(SerialForm);
        comboTargetIP->setObjectName(QStringLiteral("comboTargetIP"));
        comboTargetIP->setCursor(QCursor(Qt::IBeamCursor));
        comboTargetIP->setFocusPolicy(Qt::StrongFocus);
        comboTargetIP->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboTargetIP->setEditable(true);

        verticalLayout_2->addWidget(comboTargetIP);

        label_10 = new QLabel(SerialForm);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_2->addWidget(label_10);

        spinTargetPort = new QSpinBox(SerialForm);
        spinTargetPort->setObjectName(QStringLiteral("spinTargetPort"));
        spinTargetPort->setMaximum(65535);

        verticalLayout_2->addWidget(spinTargetPort);

        pushButton_server_bind = new QPushButton(SerialForm);
        pushButton_server_bind->setObjectName(QStringLiteral("pushButton_server_bind"));

        verticalLayout_2->addWidget(pushButton_server_bind);

        pushButton_server_bind_stop = new QPushButton(SerialForm);
        pushButton_server_bind_stop->setObjectName(QStringLiteral("pushButton_server_bind_stop"));

        verticalLayout_2->addWidget(pushButton_server_bind_stop);


        gridLayout->addLayout(verticalLayout_2, 1, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        clearButton = new QPushButton(SerialForm);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout_2->addWidget(clearButton);

        sendButton = new QPushButton(SerialForm);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout_2->addWidget(sendButton);


        gridLayout->addLayout(horizontalLayout_2, 2, 2, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sendTextEdit = new QTextEdit(SerialForm);
        sendTextEdit->setObjectName(QStringLiteral("sendTextEdit"));

        horizontalLayout->addWidget(sendTextEdit);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);


        retranslateUi(SerialForm);

        QMetaObject::connectSlotsByName(SerialForm);
    } // setupUi

    void retranslateUi(QWidget *SerialForm)
    {
        SerialForm->setWindowTitle(QApplication::translate("SerialForm", "Form", Q_NULLPTR));
        searchButton->setText(QApplication::translate("SerialForm", "\346\243\200\346\265\213\344\270\262\345\217\243", Q_NULLPTR));
        openButton->setText(QApplication::translate("SerialForm", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        radioBtnSerial->setText(QApplication::translate("SerialForm", "\344\270\262\345\217\243\351\200\232\344\277\241", Q_NULLPTR));
        radioBtnUDP->setText(QApplication::translate("SerialForm", "\347\275\221\347\273\234\351\200\232\344\277\241", Q_NULLPTR));
        label_11->setText(QApplication::translate("SerialForm", "\346\234\254\345\234\260\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("SerialForm", "\347\233\256\346\240\207\345\234\260\345\235\200IP\357\274\232", Q_NULLPTR));
        comboTargetIP->clear();
        comboTargetIP->insertItems(0, QStringList()
         << QApplication::translate("SerialForm", "192.168.0.1", Q_NULLPTR)
        );
        comboTargetIP->setCurrentText(QApplication::translate("SerialForm", "192.168.0.1", Q_NULLPTR));
        label_10->setText(QApplication::translate("SerialForm", "  \347\233\256\346\240\207\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        pushButton_server_bind->setText(QApplication::translate("SerialForm", "\347\273\221\345\256\232\347\253\257\345\217\243", Q_NULLPTR));
        pushButton_server_bind_stop->setText(QApplication::translate("SerialForm", "\350\247\243\351\231\244\347\273\221\345\256\232", Q_NULLPTR));
        clearButton->setText(QApplication::translate("SerialForm", "\346\270\205\347\251\272\346\216\245\346\224\266", Q_NULLPTR));
        sendButton->setText(QApplication::translate("SerialForm", "\345\217\221\351\200\201\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialForm: public Ui_SerialForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALFORM_H

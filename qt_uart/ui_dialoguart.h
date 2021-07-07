/********************************************************************************
** Form generated from reading UI file 'dialoguart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUART_H
#define UI_DIALOGUART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DialogUart
{
public:
    QPushButton *btnUartOpen;
    QPushButton *btnUartClose;
    QPushButton *btnConnect;
    QPushButton *btnDisConnect;
    QPushButton *readAll;
    QPushButton *writeAll;
    QTextBrowser *readText;
    QLineEdit *writeText;

    void setupUi(QDialog *DialogUart)
    {
        if (DialogUart->objectName().isEmpty())
            DialogUart->setObjectName(QString::fromUtf8("DialogUart"));
        DialogUart->resize(605, 457);
        btnUartOpen = new QPushButton(DialogUart);
        btnUartOpen->setObjectName(QString::fromUtf8("btnUartOpen"));
        btnUartOpen->setGeometry(QRect(30, 50, 93, 28));
        btnUartClose = new QPushButton(DialogUart);
        btnUartClose->setObjectName(QString::fromUtf8("btnUartClose"));
        btnUartClose->setGeometry(QRect(30, 100, 93, 28));
        btnConnect = new QPushButton(DialogUart);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(190, 50, 93, 28));
        btnDisConnect = new QPushButton(DialogUart);
        btnDisConnect->setObjectName(QString::fromUtf8("btnDisConnect"));
        btnDisConnect->setGeometry(QRect(190, 110, 93, 28));
        readAll = new QPushButton(DialogUart);
        readAll->setObjectName(QString::fromUtf8("readAll"));
        readAll->setGeometry(QRect(30, 210, 93, 28));
        writeAll = new QPushButton(DialogUart);
        writeAll->setObjectName(QString::fromUtf8("writeAll"));
        writeAll->setGeometry(QRect(30, 290, 93, 28));
        readText = new QTextBrowser(DialogUart);
        readText->setObjectName(QString::fromUtf8("readText"));
        readText->setGeometry(QRect(180, 170, 351, 111));
        writeText = new QLineEdit(DialogUart);
        writeText->setObjectName(QString::fromUtf8("writeText"));
        writeText->setGeometry(QRect(180, 300, 351, 21));

        retranslateUi(DialogUart);

        QMetaObject::connectSlotsByName(DialogUart);
    } // setupUi

    void retranslateUi(QDialog *DialogUart)
    {
        DialogUart->setWindowTitle(QApplication::translate("DialogUart", "Dialog", nullptr));
        btnUartOpen->setText(QApplication::translate("DialogUart", "openUart", nullptr));
        btnUartClose->setText(QApplication::translate("DialogUart", "closeUart", nullptr));
        btnConnect->setText(QApplication::translate("DialogUart", "connect", nullptr));
        btnDisConnect->setText(QApplication::translate("DialogUart", "disconnect", nullptr));
        readAll->setText(QApplication::translate("DialogUart", "readAll", nullptr));
        writeAll->setText(QApplication::translate("DialogUart", "writeAll", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogUart: public Ui_DialogUart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUART_H

/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *mapGroupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *mapGridLayout;
    QPushButton *pushButton_New;
    QPushButton *pushButton_Solve;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(593, 669);
        mapGroupBox = new QGroupBox(Dialog);
        mapGroupBox->setObjectName(QString::fromUtf8("mapGroupBox"));
        mapGroupBox->setGeometry(QRect(20, 20, 551, 581));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        mapGroupBox->setFont(font);
        mapGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"\n"
"border: 3px solid blue;\n"
"border-radius: 6px;\n"
"padding: 0 8px;\n"
"background : lightyellow;\n"
"\n"
"}"));
        gridLayoutWidget = new QWidget(mapGroupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 30, 511, 521));
        mapGridLayout = new QGridLayout(gridLayoutWidget);
        mapGridLayout->setSpacing(0);
        mapGridLayout->setObjectName(QString::fromUtf8("mapGridLayout"));
        mapGridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        mapGridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_New = new QPushButton(Dialog);
        pushButton_New->setObjectName(QString::fromUtf8("pushButton_New"));
        pushButton_New->setGeometry(QRect(80, 620, 171, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setItalic(false);
        pushButton_New->setFont(font1);
        pushButton_New->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"border: 2px solid gray;\n"
"border-radius: 6px;\n"
"padding: 0 8px;\n"
"background : green;\n"
"color: white;\n"
"\n"
"}"));
        pushButton_Solve = new QPushButton(Dialog);
        pushButton_Solve->setObjectName(QString::fromUtf8("pushButton_Solve"));
        pushButton_Solve->setGeometry(QRect(310, 620, 171, 31));
        pushButton_Solve->setFont(font1);
        pushButton_Solve->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"border: 2px solid gray;\n"
"border-radius: 6px;\n"
"padding: 0 8px;\n"
"background : red;\n"
"color: white;\n"
"\n"
"}"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        mapGroupBox->setTitle(QCoreApplication::translate("Dialog", "Sudoku map", nullptr));
        pushButton_New->setText(QCoreApplication::translate("Dialog", "New", nullptr));
        pushButton_Solve->setText(QCoreApplication::translate("Dialog", "Solve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

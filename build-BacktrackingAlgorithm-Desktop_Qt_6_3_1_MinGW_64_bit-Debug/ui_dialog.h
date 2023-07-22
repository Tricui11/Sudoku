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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *mapGroupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *mapGridLayout;
    QGroupBox *inputGroupBox;
    QPushButton *pushButton_GenMap;
    QLineEdit *lineEdit_N;
    QLabel *labelN;
    QPushButton *pushButton_Solve;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(739, 633);
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
        inputGroupBox = new QGroupBox(Dialog);
        inputGroupBox->setObjectName(QString::fromUtf8("inputGroupBox"));
        inputGroupBox->setGeometry(QRect(590, 250, 131, 141));
        QFont font1;
        font1.setPointSize(12);
        font1.setItalic(true);
        inputGroupBox->setFont(font1);
        inputGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"\n"
"border: 1px solid blue;\n"
"border-radius: 6px;\n"
"padding: 0 8px;\n"
"background : lightgreen;\n"
"\n"
"}"));
        pushButton_GenMap = new QPushButton(inputGroupBox);
        pushButton_GenMap->setObjectName(QString::fromUtf8("pushButton_GenMap"));
        pushButton_GenMap->setGeometry(QRect(10, 60, 111, 24));
        QFont font2;
        font2.setPointSize(9);
        font2.setItalic(false);
        pushButton_GenMap->setFont(font2);
        pushButton_GenMap->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"border: 2px solid gray;\n"
"border-radius: 6px;\n"
"padding: 0 8px;\n"
"background : blue;\n"
"color: white;\n"
"\n"
"}"));
        lineEdit_N = new QLineEdit(inputGroupBox);
        lineEdit_N->setObjectName(QString::fromUtf8("lineEdit_N"));
        lineEdit_N->setGeometry(QRect(70, 30, 28, 18));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(false);
        lineEdit_N->setFont(font3);
        lineEdit_N->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"\n"
"color : blue;\n"
"\n"
"}"));
        labelN = new QLabel(inputGroupBox);
        labelN->setObjectName(QString::fromUtf8("labelN"));
        labelN->setGeometry(QRect(40, 31, 16, 18));
        labelN->setFont(font2);
        pushButton_Solve = new QPushButton(inputGroupBox);
        pushButton_Solve->setObjectName(QString::fromUtf8("pushButton_Solve"));
        pushButton_Solve->setGeometry(QRect(30, 100, 71, 24));
        pushButton_Solve->setFont(font2);
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
        inputGroupBox->setTitle(QString());
        pushButton_GenMap->setText(QCoreApplication::translate("Dialog", "Generate map", nullptr));
        labelN->setText(QCoreApplication::translate("Dialog", "N:", nullptr));
        pushButton_Solve->setText(QCoreApplication::translate("Dialog", "Solve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

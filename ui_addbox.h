/********************************************************************************
** Form generated from reading UI file 'addbox.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOX_H
#define UI_ADDBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addBox
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;

    void setupUi(QDialog *addBox)
    {
        if (addBox->objectName().isEmpty())
            addBox->setObjectName("addBox");
        addBox->resize(426, 408);
        gridLayout = new QGridLayout(addBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(addBox);
        label->setObjectName("label");
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("QLabel{background:light gray;\n"
"font-size:30px;\n"
"color:white;\n"
"}"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(addBox);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:15px;\n"
"color:blue;\n"
"}"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(addBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15px;\n"
"}"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(addBox);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:15px;\n"
"color:blue;\n"
"}"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(addBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15px;\n"
"}"));

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        label_4 = new QLabel(addBox);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:15px;\n"
"color:blue;\n"
"}"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(addBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15px;\n"
"}"));

        gridLayout->addWidget(lineEdit_3, 3, 1, 1, 1);

        pushButton = new QPushButton(addBox);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15px;\n"
"color:blue;\n"
"}"));

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);


        retranslateUi(addBox);

        QMetaObject::connectSlotsByName(addBox);
    } // setupUi

    void retranslateUi(QDialog *addBox)
    {
        addBox->setWindowTitle(QCoreApplication::translate("addBox", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addBox", "Enter Information", nullptr));
        label_2->setText(QCoreApplication::translate("addBox", "RollNo:", nullptr));
        label_3->setText(QCoreApplication::translate("addBox", "Name:", nullptr));
        label_4->setText(QCoreApplication::translate("addBox", "Subject:", nullptr));
        pushButton->setText(QCoreApplication::translate("addBox", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addBox: public Ui_addBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOX_H

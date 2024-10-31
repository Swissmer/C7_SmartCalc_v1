/********************************************************************************
** Form generated from reading UI file 'graphics.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICS_H
#define UI_GRAPHICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graphics
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_calc;
    QCustomPlot *widget;
    QLineEdit *max_y;
    QPushButton *update;
    QLineEdit *min_x;
    QLineEdit *min_y;
    QLineEdit *max_x;

    void setupUi(QMainWindow *graphics)
    {
        if (graphics->objectName().isEmpty())
            graphics->setObjectName("graphics");
        graphics->resize(640, 540);
        centralwidget = new QWidget(graphics);
        centralwidget->setObjectName("centralwidget");
        pushButton_calc = new QPushButton(centralwidget);
        pushButton_calc->setObjectName("pushButton_calc");
        pushButton_calc->setGeometry(QRect(80, 480, 481, 21));
        pushButton_calc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                             background-color: #FF8200;\n"
"                             color: black;\n"
"                             border: none;\n"
"                             border-radius: 10px;\n"
"\n"
"                         }"));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 40, 481, 331));
        widget->setStyleSheet(QString::fromUtf8("background-color: black;"));
        max_y = new QLineEdit(centralwidget);
        max_y->setObjectName("max_y");
        max_y->setGeometry(QRect(410, 420, 81, 21));
        max_y->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"   background-color: #FAFAFF;\n"
"   color: black;\n"
"   border: none;\n"
"   border-radius: 10px;\n"
"   padding: 0px 20px;\n"
"}\n"
"\n"
"QLineEdit:!placeholder {\n"
"    color: black; /* \320\246\320\262\320\265\321\202 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    font-style: normal; /* \320\243\320\261\321\200\320\260\321\202\321\214 \320\272\321\203\321\200\321\201\320\270\320\262 \320\264\320\273\321\217 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}"));
        update = new QPushButton(centralwidget);
        update->setObjectName("update");
        update->setGeometry(QRect(520, 420, 41, 21));
        update->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                             background-color: #FF8200;\n"
"                             color: black;\n"
"                             border: none;\n"
"                             border-radius: 10px;\n"
"\n"
"                         }"));
        min_x = new QLineEdit(centralwidget);
        min_x->setObjectName("min_x");
        min_x->setGeometry(QRect(80, 420, 81, 21));
        min_x->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"   background-color: #FAFAFF;\n"
"   color: black;\n"
"   border: none;\n"
"   border-radius: 10px;\n"
"   padding: 0px 20px;\n"
"}\n"
"\n"
"QLineEdit:!placeholder {\n"
"    color: black; /* \320\246\320\262\320\265\321\202 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    font-style: normal; /* \320\243\320\261\321\200\320\260\321\202\321\214 \320\272\321\203\321\200\321\201\320\270\320\262 \320\264\320\273\321\217 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}"));
        min_y = new QLineEdit(centralwidget);
        min_y->setObjectName("min_y");
        min_y->setGeometry(QRect(300, 420, 81, 21));
        min_y->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"   background-color: #FAFAFF;\n"
"   color: black;\n"
"   border: none;\n"
"   border-radius: 10px;\n"
"   padding: 0px 20px;\n"
"}\n"
"\n"
"QLineEdit:!placeholder {\n"
"    color: black; /* \320\246\320\262\320\265\321\202 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    font-style: normal; /* \320\243\320\261\321\200\320\260\321\202\321\214 \320\272\321\203\321\200\321\201\320\270\320\262 \320\264\320\273\321\217 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}"));
        max_x = new QLineEdit(centralwidget);
        max_x->setObjectName("max_x");
        max_x->setGeometry(QRect(190, 420, 81, 21));
        max_x->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"   background-color: #FAFAFF;\n"
"   color: black;\n"
"   border: none;\n"
"   border-radius: 10px;\n"
"   padding: 0px 20px;\n"
"}\n"
"\n"
"QLineEdit:!placeholder {\n"
"    color: black; /* \320\246\320\262\320\265\321\202 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    font-style: normal; /* \320\243\320\261\321\200\320\260\321\202\321\214 \320\272\321\203\321\200\321\201\320\270\320\262 \320\264\320\273\321\217 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}"));
        graphics->setCentralWidget(centralwidget);

        retranslateUi(graphics);

        QMetaObject::connectSlotsByName(graphics);
    } // setupUi

    void retranslateUi(QMainWindow *graphics)
    {
        graphics->setWindowTitle(QCoreApplication::translate("graphics", "MainWindow", nullptr));
        pushButton_calc->setText(QCoreApplication::translate("graphics", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        max_y->setPlaceholderText(QCoreApplication::translate("graphics", "max y", nullptr));
        update->setText(QCoreApplication::translate("graphics", "\342\231\273", nullptr));
        min_x->setPlaceholderText(QCoreApplication::translate("graphics", "min x", nullptr));
        min_y->setPlaceholderText(QCoreApplication::translate("graphics", "min y", nullptr));
        max_x->setPlaceholderText(QCoreApplication::translate("graphics", "max x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphics: public Ui_graphics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICS_H

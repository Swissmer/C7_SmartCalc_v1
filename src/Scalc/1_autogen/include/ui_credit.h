/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_credit
{
public:
    QWidget *centralwidget;
    QLineEdit *sum;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *dif;
    QRadioButton *ann;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *percent;
    QLineEdit *date;
    QLabel *label_6;
    QPushButton *pushButton_update;
    QPushButton *pushButton_back;
    QTableWidget *table;

    void setupUi(QMainWindow *credit)
    {
        if (credit->objectName().isEmpty())
            credit->setObjectName("credit");
        credit->resize(640, 540);
        credit->setStyleSheet(QString::fromUtf8("QMainWindow { \n"
"background-color: #4C4C4C;\n"
" }"));
        centralwidget = new QWidget(credit);
        centralwidget->setObjectName("centralwidget");
        sum = new QLineEdit(centralwidget);
        sum->setObjectName("sum");
        sum->setGeometry(QRect(250, 100, 141, 21));
        sum->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 100, 31, 16));
        label->setStyleSheet(QString::fromUtf8("color: #d3d3d3;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(400, 160, 16, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: #d3d3d3;"));
        dif = new QRadioButton(centralwidget);
        dif->setObjectName("dif");
        dif->setGeometry(QRect(240, 270, 171, 21));
        dif->setStyleSheet(QString::fromUtf8("color: #d3d3d3;"));
        dif->setCheckable(true);
        dif->setChecked(false);
        ann = new QRadioButton(centralwidget);
        ann->setObjectName("ann");
        ann->setGeometry(QRect(240, 300, 171, 21));
        ann->setStyleSheet(QString::fromUtf8("color: #d3d3d3;\n"
"\n"
"QRadioButton::indicator:checked { background-color: black; }"));
        ann->setChecked(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 200, 41, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: #d3d3d3;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 140, 151, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: #d3d3d3;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(260, 70, 151, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: #d3d3d3;"));
        percent = new QLineEdit(centralwidget);
        percent->setObjectName("percent");
        percent->setGeometry(QRect(250, 160, 141, 21));
        percent->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        date = new QLineEdit(centralwidget);
        date->setObjectName("date");
        date->setGeometry(QRect(250, 220, 141, 21));
        date->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(400, 220, 61, 21));
        label_6->setStyleSheet(QString::fromUtf8("color: #d3d3d3;"));
        pushButton_update = new QPushButton(centralwidget);
        pushButton_update->setObjectName("pushButton_update");
        pushButton_update->setGeometry(QRect(260, 460, 121, 21));
        pushButton_update->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                             background-color: #FF8200;\n"
"                             color: black;\n"
"                             border: none;\n"
"                             border-radius: 10px;\n"
"                             padding: 0px 20px;\n"
"                         }"));
        pushButton_back = new QPushButton(centralwidget);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(20, 40, 61, 21));
        pushButton_back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                             background-color: #FF8200;\n"
"                             color: black;\n"
"                             border: none;\n"
"                             border-radius: 10px;\n"
"                         }"));
        table = new QTableWidget(centralwidget);
        if (table->columnCount() < 2)
            table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table->setObjectName("table");
        table->setGeometry(QRect(200, 340, 241, 101));
        table->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"   background-color: #FAFAFF;\n"
"   border: none;\n"
"   border-radius: 10px;\n"
"   padding: 0px 0px 10\n"
"}"));
        credit->setCentralWidget(centralwidget);

        retranslateUi(credit);

        QMetaObject::connectSlotsByName(credit);
    } // setupUi

    void retranslateUi(QMainWindow *credit)
    {
        credit->setWindowTitle(QCoreApplication::translate("credit", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("credit", "\321\200\321\203\320\261.", nullptr));
        label_2->setText(QCoreApplication::translate("credit", "%", nullptr));
        dif->setText(QCoreApplication::translate("credit", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));
        ann->setText(QCoreApplication::translate("credit", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
        label_3->setText(QCoreApplication::translate("credit", "\320\241\321\200\320\276\320\272", nullptr));
        label_4->setText(QCoreApplication::translate("credit", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202", nullptr));
        label_5->setText(QCoreApplication::translate("credit", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("credit", "\320\234\320\265\321\201\321\217\321\206.", nullptr));
        pushButton_update->setText(QCoreApplication::translate("credit", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        pushButton_back->setText(QCoreApplication::translate("credit", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("credit", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("credit", "\320\237\320\273\320\260\321\202\320\265\320\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class credit: public Ui_credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_halal;
    QPushButton *pushButton_haram;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton_start;
    QLabel *label_3;
    QLCDNumber *lcdNumber_2;
    QLabel *label_prosh;
    QLabel *label_ost;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 740);
        MainWindow->setMouseTracking(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMouseTracking(true);
        centralWidget->setTabletTracking(false);
        pushButton_halal = new QPushButton(centralWidget);
        pushButton_halal->setObjectName(QString::fromUtf8("pushButton_halal"));
        pushButton_halal->setGeometry(QRect(20, 650, 331, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        font.setPointSize(12);
        pushButton_halal->setFont(font);
        pushButton_halal->setMouseTracking(true);
        pushButton_haram = new QPushButton(centralWidget);
        pushButton_haram->setObjectName(QString::fromUtf8("pushButton_haram"));
        pushButton_haram->setGeometry(QRect(370, 650, 331, 71));
        QFont font1;
        font1.setPointSize(12);
        pushButton_haram->setFont(font1);
        pushButton_haram->setMouseTracking(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 110, 512, 512));
        label->setMouseTracking(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-40, 110, 800, 505));
        QFont font2;
        font2.setPointSize(8);
        label_2->setFont(font2);
        label_2->setMouseTracking(true);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(520, 20, 171, 41));
        lcdNumber->setFont(font2);
        lcdNumber->setMouseTracking(true);
        lcdNumber->setDigitCount(8);
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(200, 70, 321, 71));
        pushButton_start->setFont(font1);
        pushButton_start->setMouseTracking(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 200, 480, 270));
        label_3->setMouseTracking(true);
        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(30, 20, 171, 41));
        lcdNumber_2->setMouseTracking(true);
        lcdNumber_2->setDigitCount(8);
        label_prosh = new QLabel(centralWidget);
        label_prosh->setObjectName(QString::fromUtf8("label_prosh"));
        label_prosh->setGeometry(QRect(60, 0, 121, 16));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        label_prosh->setFont(font3);
        label_prosh->setMouseTracking(true);
        label_ost = new QLabel(centralWidget);
        label_ost->setObjectName(QString::fromUtf8("label_ost"));
        label_ost->setGeometry(QRect(540, 0, 131, 16));
        label_ost->setFont(font3);
        label_ost->setMouseTracking(true);
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(235, 25, 251, 31));
        tableWidget->setMouseTracking(true);
        tableWidget->setAutoScroll(false);
        tableWidget->setAutoScrollMargin(15);
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(50);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setHighlightSections(false);
        MainWindow->setCentralWidget(centralWidget);
        pushButton_halal->raise();
        label->raise();
        label_2->raise();
        lcdNumber->raise();
        pushButton_start->raise();
        label_3->raise();
        lcdNumber_2->raise();
        label_prosh->raise();
        label_ost->raise();
        tableWidget->raise();
        pushButton_haram->raise();
        QWidget::setTabOrder(tableWidget, pushButton_start);
        QWidget::setTabOrder(pushButton_start, pushButton_halal);
        QWidget::setTabOrder(pushButton_halal, pushButton_haram);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_halal->setText(QApplication::translate("MainWindow", "\320\245\320\260\320\273\321\217\320\273\321\214", nullptr));
        pushButton_haram->setText(QApplication::translate("MainWindow", "\320\245\320\260\321\200\320\260\320\274", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        pushButton_start->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214", nullptr));
        label_3->setText(QString());
        label_prosh->setText(QApplication::translate("MainWindow", "\320\277\321\200\320\276\321\210\320\273\320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        label_ost->setText(QApplication::translate("MainWindow", "\320\276\321\201\321\202\320\260\320\273\320\276\321\201\321\214 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

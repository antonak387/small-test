#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define OURTIME 60

#include <QMainWindow>
#include <QTimer>
#include<QLabel>
#include<QMovie>
#include<QTableWidget>
#include<QPalette>
#include <QTableWidgetItem>
#include<QBrush>
#include <cmath>


#include <QMouseEvent>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void answer_false();

    void timer_tick(void);//событие

    void answer_true();

    void osnova();

    void time_over();

    void on_pushButton_halal_clicked();

    void on_pushButton_haram_clicked();

    void on_pushButton_start_clicked();

    void mouseMoveEvent(QMouseEvent *event);// перенаправляем евент движения мышки


private:
    Ui::MainWindow *ui;

    QTimer*timer;//указатель
    int counter;//счетчик

    int questionNumber;

    bool isAnswerHalal;

    int tryNumber=0;

    int lolnum = 0;

    //int numrandx=370;
    //int numrandy=650;

    bool isfirst = true; // флаг для маус мув ивента

    //int Mx,My;

    double xr1=999,xr2=999,yr1=999,yr2=999; //координаты для маус мув ивента

};

#endif // MAINWINDOW_H

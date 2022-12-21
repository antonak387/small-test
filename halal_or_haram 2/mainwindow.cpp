#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :// конструктор
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setStyleSheet("background-color: ;");
    ui->centralWidget->setStyleSheet("background-color:#dabdab");

    ui->pushButton_start->setStyleSheet("background-color:#f8f2ef");

    setWindowTitle("Халяль или харам 2");
    timer = new QTimer(this);//создание таймера
    counter = 0;//инициализация счетчика
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()),this,SLOT(timer_tick()));//соединение сигнала таймера с обработчиком

//    ui->lcdNumber->display("01:00:00");
//    ui->lcdNumber_2->display("00:00:00");
    ui->label_2->setEnabled(false);
    ui->label->setVisible(false);
    ui->label_2->setStyleSheet("background-color: rgba(0, 0, 0, 0)");
    ui->pushButton_halal->setVisible(false);
    ui->pushButton_haram->setVisible(false);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setEnabled(false);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->pushButton_haram->setStyleSheet("background-color:#ff0000");
    ui->pushButton_halal->setStyleSheet("background-color:#00ee00");





    int ones_counter = OURTIME*100;
    int m,sec,s_sec;//часы минуты секунды сотые секунды

    s_sec= ones_counter%100;
    sec=ones_counter/100;

    m = sec/60;
    sec=sec%60;

    m = m%60;

    QString str;
    str.clear();

    if ( m <10)
        str.append("0");
    str.append(QString::number(m)+":");
    if ( sec <10)
        str.append("0");
    str.append(QString::number(sec)+":");
    if ( s_sec <10)
        str.append("0");
    str.append(QString::number(s_sec));

    ui->lcdNumber->display(str);//выводим на счетчик


    int counter2=(OURTIME*100)-ones_counter;// второй счетчик

    s_sec= counter2%100;
    sec=counter2/100;

    m = sec/60;
    sec=sec%60;

    m = m%60;

    str.clear();

    if ( m <10)
        str.append("0");
    str.append(QString::number(m)+":");
    if ( sec <10)
        str.append("0");
    str.append(QString::number(sec)+":");
    if ( s_sec <10)
        str.append("0");
    str.append(QString::number(s_sec));
    ui->lcdNumber_2->display(str);//выводим на счетчик
}

MainWindow::~MainWindow()//деструктор
{
    delete ui;
}

void MainWindow::on_pushButton_halal_clicked()//нажал на кнопку халал
{
    isAnswerHalal=true;
    osnova();
}

void MainWindow::on_pushButton_haram_clicked()//нажал на кнопку харам
{
    isAnswerHalal=false;
    osnova();
}

void MainWindow::osnova()//основная чать кода где происходят все операции
{
    switch (questionNumber)
    {

    case 0:             //первый вопрос
        if(isAnswerHalal){
            answer_false();
        }
        else{

            answer_true();
            questionNumber++;
        }
        break;
    case 1:     //второй вопрос
        if(isAnswerHalal){

            answer_true();
            questionNumber++;
            ui->pushButton_halal->setText("Харам");
            ui->pushButton_haram->setText("Халяль");
        }
        else{
            answer_false();
        }
        break;
    case 2:     // третий вопрос
        if(isAnswerHalal){
            answer_false();

        }
        else{

            answer_true();
            questionNumber++;
            ui->pushButton_haram->setText("Харам");
            ui->pushButton_halal->setText("Халяль");
        }
        break;
    case 3:     // четвертый вопрос
        if(isAnswerHalal){
            answer_false();
        }
        else{

            answer_true();
            questionNumber++;
            //ui->pushButton_haram->setGeometry(370,650,331,71);


        }
        break;
    case 4:     // пятый вопрос
    {
        if(isAnswerHalal){
            answer_false();
        }

        else{
            timer->stop();
            questionNumber++;
            ui->pushButton_start->setText("Начать заново");
            ui->pushButton_halal->setVisible(false);
            ui->pushButton_haram->setVisible(false);
            ui->pushButton_start->setText("Начать заново");
            ui->pushButton_start->setVisible(true);
            ui->label->setVisible(false);
            ui->label_3->setVisible(true);
            //QPixmap myPixmap( "win.png");
            QMovie *movie = new QMovie("C:\\Users\\tohag\\Desktop\\halal_or_haram 2\\win"+QString::number(rand() % 3)+".gif");
            ui->label_3->setMovie(movie);
            movie->start();
            QTableWidgetItem * twi;
            twi=new QTableWidgetItem;
            ui->tableWidget->setItem(0,questionNumber-1,twi);
            ui->tableWidget->removeCellWidget(0,questionNumber-1);
            ui->tableWidget->item(0,questionNumber-1)->setBackground(Qt::green);

        }
    }
        break;
    default:

        break;
    }
}


void MainWindow::timer_tick()//то что будет по таймеру вызываться
{
    counter--;//обратный счетчик

    if(questionNumber==3&&lolnum<100){
        lolnum++;
        ui->pushButton_haram->setGeometry(370+5*lolnum,650,331,71);
    }

    if(questionNumber==4&&lolnum>90){
        lolnum--;
        ui->pushButton_haram->setGeometry(370+50*(lolnum-90),650,331,71);
    }

    int m,sec,s_sec;//часы минуты секунды сотые секунды

    s_sec= counter%100;
    sec=counter/100;

    m = sec/60;
    sec=sec%60;

    m = m%60;

    QString str;
    str.clear();

    if ( m <10)
        str.append("0");
    str.append(QString::number(m)+":");
    if ( sec <10)
        str.append("0");
    str.append(QString::number(sec)+":");
    if ( s_sec <10)
        str.append("0");
    str.append(QString::number(s_sec));

    ui->lcdNumber->display(str);//выводим на счетчик


    int counter2=(OURTIME*100)-counter;// второй счетчик

    s_sec= counter2%100;
    sec=counter2/100;

    m = sec/60;
    sec=sec%60;

    m = m%60;

    str.clear();

    if ( m <10)
        str.append("0");
    str.append(QString::number(m)+":");
    if ( sec <10)
        str.append("0");
    str.append(QString::number(sec)+":");
    if ( s_sec <10)
        str.append("0");
    str.append(QString::number(s_sec));
    ui->lcdNumber_2->display(str);//выводим на счетчик
    if (counter<=0)
    {
        timer->stop();
        time_over();
    }
}

void MainWindow::time_over()// время вышло
{
    timer->stop();
    ui->label_2->setEnabled(true);
    ui->label_2->setVisible(true);
    QPixmap myPixmap( "C:\\Users\\tohag\\Desktop\\halal_or_haram 2\\fail.png" );

    ui->label_2->setPixmap( myPixmap );
    ui->pushButton_start->setText("Начать заново");
    ui->pushButton_start->setVisible(true);
    ui->pushButton_halal->setEnabled(false);
    ui->pushButton_haram->setEnabled(false);
    ui->tableWidget->setVisible(true);
    //tryNumber++;
    QTableWidgetItem * twi;
    twi=new QTableWidgetItem;
    ui->tableWidget->setItem(0,questionNumber,twi);
    ui->tableWidget->removeCellWidget(0,questionNumber);
    ui->tableWidget->item(0,questionNumber)->setBackground(Qt::yellow);
    if(questionNumber==4)questionNumber++;
}

void MainWindow::answer_true()//если правильно ответил
{
    QPixmap myPixmap( "C:\\Users\\tohag\\Desktop\\halal_or_haram 2\\picture"+ QString::number(questionNumber+1) +".png" );
    ui->label->setPixmap( myPixmap );
    ui->tableWidget->setVisible(true);
    QTableWidgetItem * twi;
    twi=new QTableWidgetItem;
    ui->tableWidget->setItem(0,questionNumber,twi);
    ui->tableWidget->removeCellWidget(0,questionNumber);
    ui->tableWidget->item(0,questionNumber)->setBackground(Qt::green);
}

void MainWindow::answer_false()//если не правильно ответил
{
    timer->stop();
    ui->label_2->setEnabled(true);
    ui->label_2->setVisible(true);
    QPixmap myPixmap( "C:\\Users\\tohag\\Desktop\\halal_or_haram 2\\fail.png" );
    ui->label_2->setPixmap( myPixmap );

    ui->pushButton_start->setText("Начать заново");
    ui->pushButton_start->setVisible(true);
    ui->pushButton_halal->setEnabled(false);
    ui->pushButton_haram->setEnabled(false);
    ui->tableWidget->setVisible(true);
    //tryNumber++;
    QTableWidgetItem * twi;
    twi=new QTableWidgetItem;
    ui->tableWidget->setItem(0,questionNumber,twi);
    ui->tableWidget->removeCellWidget(0,questionNumber);
    ui->tableWidget->item(0,questionNumber)->setBackground(Qt::red);
    if(questionNumber==4)questionNumber++;
}


void MainWindow::on_pushButton_start_clicked()//нажал на кнопку старт
{
    counter=OURTIME*100;
    timer->start();
    questionNumber = 0;
    QPixmap myPixmap( "C:\\Users\\tohag\\Desktop\\halal_or_haram 2\\picture"+ QString::number(questionNumber) +".png");

    ui->label->setPixmap( myPixmap );


    ui->label->setVisible(true);
    ui->pushButton_halal->setVisible(true);
    ui->pushButton_haram->setVisible(true);
    ui->pushButton_start->setVisible(false);
    ui->label_3->clear();
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->pushButton_halal->setEnabled(true);
    ui->pushButton_haram->setEnabled(true);
    lolnum = 0;
    ui->pushButton_haram->setText("Харам");
    ui->pushButton_halal->setText("Халяль");
    ui->pushButton_haram->setGeometry(370,650,331,71);
    QTableWidgetItem * twi;
    for(int i=0;i<5;i++){

        twi=new QTableWidgetItem;
        ui->tableWidget->setItem(0,i,twi);
        ui->tableWidget->removeCellWidget(0,i);
        ui->tableWidget->item(0,i)->setBackground(Qt::white);
    }

    //ui->tableWidget->setVisible(false);


}


void MainWindow::mouseMoveEvent(QMouseEvent *event)// отлавливаем маус мув евент + то что движет кнопку от мыши
{
    //Mx = event->x(), My = event->y();
    if(questionNumber ==4){
        int X = event->x()-(ui->pushButton_haram->x()+165);
        int Y = event->y()-(ui->pushButton_haram->y()+35);
        if(X*X + Y*Y <=40000){
            if(isfirst){
                xr1 = X;
                yr1 = Y;
                xr2 = X;
                yr2 = Y;
                isfirst=false;
            }

            if(xr2*xr2 + yr2*yr2>=X*X + Y*Y){

                if(X>0)
                    ui->pushButton_haram->setGeometry(event->x()-int(abs(xr1))-165,ui->pushButton_haram->y(),331,71);
                else {
                    ui->pushButton_haram->setGeometry(event->x()+int(abs(xr1))-165,ui->pushButton_haram->y(),331,71);
                }
                if(Y>0)
                    ui->pushButton_haram->setGeometry(ui->pushButton_haram->x(),event->y()-int(abs(yr1))-35,331,71);
                else {
                    ui->pushButton_haram->setGeometry(ui->pushButton_haram->x(),event->y()+int(abs(yr1))-35,331,71);
                }

            }
            else {
                isfirst = true;
                xr2 = X;
                yr2 = Y;

            }
        }
        else {
            isfirst = true;
        }

        if(ui->pushButton_haram->x()<=-105)
            ui->pushButton_haram->setGeometry(width()-300,ui->pushButton_haram->y(),331,71);
        if(ui->pushButton_haram->x()>=width()-225)
            ui->pushButton_haram->setGeometry(-30,ui->pushButton_haram->y(),331,71);
        if(ui->pushButton_haram->y()<=-50)
            ui->pushButton_haram->setGeometry(ui->pushButton_haram->x(),height()-70,331,71);
        if(ui->pushButton_haram->y()>=height()-20)
            ui->pushButton_haram->setGeometry(ui->pushButton_haram->x(),0,331,71);

    }
    //    if(questionNumber ==0){
    //        int X = event->x()-ui->pushButton_start->x();
    //        int Y = event->y()-ui->pushButton_start->y();
    //        if(X*X + Y*Y <=40000){
    //            if(isfirst){
    //                xr1 = X;
    //                yr1 = Y;
    //                xr2 = X;
    //                yr2 = Y;
    //                isfirst=false;
    //            }

    //            if(xr2*xr2 + yr2*yr2>=X*X + Y*Y){

    //                if(X>0)
    //                    ui->pushButton_start->setGeometry(event->x()-int(abs(xr1)),ui->pushButton_start->y(),331,71);
    //                else {
    //                    ui->pushButton_start->setGeometry(event->x()+int(abs(xr1)),ui->pushButton_start->y(),331,71);
    //                }
    //                if(Y>0)
    //                    ui->pushButton_start->setGeometry(ui->pushButton_start->x(),event->y()-int(abs(yr1)),331,71);
    //                else {
    //                    ui->pushButton_start->setGeometry(ui->pushButton_start->x(),event->y()+int(abs(yr1)),331,71);
    //                }

    //            }
    //            else {
    //                isfirst = true;
    //                xr2 = X;
    //                yr2 = Y;

    //            }



    //        }
    //        else {
    //            isfirst = true;
    //        }

    //        if(ui->pushButton_start->x()<=0)
    //            ui->pushButton_start->setGeometry(690,ui->pushButton_start->y(),331,71);
    //        if(ui->pushButton_start->x()>=704)
    //            ui->pushButton_start->setGeometry(20,ui->pushButton_start->y(),331,71);
    //        if(ui->pushButton_start->y()<=0)
    //            ui->pushButton_start->setGeometry(ui->pushButton_start->x(),710,331,71);
    //        if(ui->pushButton_start->y()>=724)
    //            ui->pushButton_start->setGeometry(ui->pushButton_start->x(),20,331,71);

    //    }
}


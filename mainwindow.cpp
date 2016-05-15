#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QKeyEvent>
#include <QTimer>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->background->hide();
    ui->Time->hide();
    ui->Score->hide();
    ui->cntime->hide();
    ui->scorevalue->hide();
    ui->tiRed->hide();
    ui->tiBlu->hide();
    ui->J->hide();
    ui->K->hide();
    ui->drum->hide();
    ui->finaltext->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()                //start
{
    QMessageBox::information(this,"Taiko","Game Start");

    timer = new QTimer(this);                              //計時
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    timer->start(1000);

    scorenum=0;
    ui->scorevalue->setText(QString::number(scorenum));
    ui->scorevalue->show();
    ui->label->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->background->show();
    ui->Time->show();
    ui->Score->show();
    ui->cntime->show();
    ui->tiRed->show();
    ui->tiBlu->show();
    ui->J->show();
    ui->K->show();
    ui->finalsco->hide();
    ui->finaltext->hide();
    ui->drum->show();
    ui->drumR1->show();
    ui->drumR2->show();
    ui->drumR3->show();
    ui->drumR4->show();
    ui->drumR5->show();
    ui->drumB1->show();
    ui->drumB2->show();
    ui->drumB3->show();
    ui->drumB4->show();
    ui->drumB5->show();
    ui->drumR1->setGeometry(520,100,91,91);
    ui->drumR2->setGeometry(520,100,91,91);
    ui->drumR3->setGeometry(520,100,91,91);
    ui->drumR4->setGeometry(520,100,91,91);
    ui->drumR5->setGeometry(520,100,91,91);
    ui->drumB1->setGeometry(527,100,91,91);
    ui->drumB2->setGeometry(527,100,91,91);
    ui->drumB3->setGeometry(527,100,91,91);
    ui->drumB4->setGeometry(527,100,91,91);
    ui->drumB5->setGeometry(527,100,91,91);

    rnb = new QTimer(this);
    connect(rnb, SIGNAL(timeout()), this, SLOT(Random()));
    rnb->start(250);



}

void MainWindow::timer_timeout()
{
    cnt--;
    ui->cntime->setText(QString::number(cnt));

    if(cnt<=2)
    {
        rnb->stop();
        if(cnt<0)
        {
            timer1->stop();
            timer2->stop();
            timer3->stop();
            timer4->stop();
            timer5->stop();
            timer6->stop();
            timer7->stop();
            timer8->stop();
            timer9->stop();
            timer10->stop();
        }
    }

    if(cnt<0)
    {
        ui->finalsco->show();
        ui->finalsco->setText(QString::number(finalscore));
        ui->finaltext->show();
        finalscore=0;
        timer->stop();
        flag=0;
        flag2=0;
        flag3=0;
        flag4=0;
        flag5=0;
        flag6=0;
        flag7=0;
        flag8=0;
        flag9=0;
        flag10=0;
        cnt=30;
        ui->cntime->setText(QString::number(cnt));
        ui->cntime->hide();
        ui->background->hide();
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->Time->hide();
        ui->Score->hide();
        rnb->stop();
        ui->drumR1->setGeometry(520,100,91,91);
        ui->drumR1->hide();
        ui->drumR2->setGeometry(520,100,91,91);
        ui->drumR2->hide();
        ui->drumR3->setGeometry(520,100,91,91);
        ui->drumR3->hide();
        ui->drumR4->setGeometry(520,100,91,91);
        ui->drumR4->hide();
        ui->drumR5->setGeometry(520,100,91,91);
        ui->drumR5->hide();
        ui->drumB1->setGeometry(527,100,91,91);
        ui->drumB1->hide();
        ui->drumB2->setGeometry(527,100,91,91);
        ui->drumB2->hide();
        ui->drumB3->setGeometry(527,100,91,91);
        ui->drumB3->hide();
        ui->drumB4->setGeometry(527,100,91,91);
        ui->drumB4->hide();
        ui->drumB5->setGeometry(527,100,91,91);
        ui->drumB5->hide();
        ui->scorevalue->hide();
        ui->tiRed->hide();
        ui->tiBlu->hide();
        ui->J->hide();
        ui->K->hide();
        ui->drum->hide();
    }
}

void MainWindow::MoveRed_1()
{
    ui->drumR1->move(QPoint(ui->drumR1->x()-2,100));
}

void MainWindow::MoveRed_2()
{
        ui->drumR2->move(QPoint(ui->drumR2->x()-2,100));
}

void MainWindow::MoveRed_3()
{
        ui->drumR3->move(QPoint(ui->drumR3->x()-2,100));
}

void MainWindow::MoveRed_4()
{
        ui->drumR4->move(QPoint(ui->drumR4->x()-2,100));
}

void MainWindow::MoveRed_5()
{
        ui->drumR5->move(QPoint(ui->drumR5->x()-2,100));
}

void MainWindow::MoveBlue_1()
{
        ui->drumB1->move(QPoint(ui->drumB1->x()-2,100));
}

void MainWindow::MoveBlue_2()
{
        ui->drumB2->move(QPoint(ui->drumB2->x()-2,100));
}

void MainWindow::MoveBlue_3()
{
        ui->drumB3->move(QPoint(ui->drumB3->x()-2,100));
}

void MainWindow::MoveBlue_4()
{
        ui->drumB4->move(QPoint(ui->drumB4->x()-2,100));
}

void MainWindow::MoveBlue_5()
{
        ui->drumB5->move(QPoint(ui->drumB5->x()-2,100));
}

void MainWindow::Random()                       //rand
{
    RandomNum = rand()%10;

    if(RandomNum==0)
    {
        flag++;
        if(ui->drumR1->x()+50<0)
            {
             timer1->stop();
             ui->drumR1->show();
             ui->drumR1->setGeometry(520,100,91,91);
             flag=0;
            }
        if(flag==1)
        {
            ui->drumR1->show();
            timer1 = new QTimer(this);
            connect(timer1, SIGNAL(timeout()), this, SLOT(MoveRed_1()));
            timer1->start(10);
        }
    }

    if(RandomNum==1)
    {
        flag2++;
        if(ui->drumR2->x()+50<0)
            {
             timer2->stop();
             ui->drumR2->show();
             ui->drumR2->setGeometry(520,100,91,91);
             flag2=0;
            }
        if(flag2==1)
        {
            ui->drumR2->show();
            timer2 = new QTimer(this);
            connect(timer2, SIGNAL(timeout()), this, SLOT(MoveRed_2()));
            timer2->start(10);
        }
    }
    if(RandomNum==2)
    {
        flag3++;
        if(ui->drumR3->x()+50<0)
            {
             timer3->stop();
             ui->drumR3->show();
             ui->drumR3->setGeometry(520,100,91,91);
             flag3=0;
            }
        if(flag3==1)
        {
            ui->drumR3->show();
            timer3 = new QTimer(this);
            connect(timer3, SIGNAL(timeout()), this, SLOT(MoveRed_3()));
            timer3->start(10);
        }
    }
    if(RandomNum==3)
    {
        flag4++;
        if(ui->drumR4->x()+50<0)
            {
             timer4->stop();
             ui->drumR4->show();
             ui->drumR4->setGeometry(520,100,91,91);
             flag4=0;
            }
        if(flag4==1)
        {
            ui->drumR4->show();
            timer4 = new QTimer(this);
            connect(timer4, SIGNAL(timeout()), this, SLOT(MoveRed_4()));
            timer4->start(10);
        }
    }
    if(RandomNum==4)
    {
        flag5++;
        if(ui->drumR5->x()+50<0)
            {
             timer5->stop();
             ui->drumR5->show();
             ui->drumR5->setGeometry(520,100,91,91);
             flag5=0;
            }
        if(flag5==1)
        {
            ui->drumR5->show();
            timer5 = new QTimer(this);
            connect(timer5, SIGNAL(timeout()), this, SLOT(MoveRed_5()));
            timer5->start(10);
        }
    }
    if(RandomNum==5)
    {
        flag6++;
        if(ui->drumB1->x()+50<0)
            {
             timer6->stop();
             ui->drumB1->show();
             ui->drumB1->setGeometry(527,100,91,91);
             flag6=0;
            }
        if(flag6==1)
        {
            ui->drumB1->show();
            timer6 = new QTimer(this);
            connect(timer6, SIGNAL(timeout()), this, SLOT(MoveBlue_1()));
            timer6->start(10);
        }
    }
    if(RandomNum==6)
    {
        flag7++;
        if(ui->drumB2->x()+50<0)
            {
             timer7->stop();
             ui->drumB2->show();
             ui->drumB2->setGeometry(527,100,91,91);
             flag7=0;
            }
        if(flag7==1)
        {
            ui->drumB2->show();
            timer7 = new QTimer(this);
            connect(timer7, SIGNAL(timeout()), this, SLOT(MoveBlue_2()));
            timer7->start(10);
        }
    }
    if(RandomNum==7)
    {
        flag8++;
        if(ui->drumB3->x()+50<0||cnt<=1)
            {
             timer8->stop();
             ui->drumB3->show();
             ui->drumB3->setGeometry(527,100,91,91);
             flag8=0;
            }
        if(flag8==1)
        {
            ui->drumB3->show();
            timer8 = new QTimer(this);
            connect(timer8, SIGNAL(timeout()), this, SLOT(MoveBlue_3()));
            timer8->start(10);
        }
    }
    if(RandomNum==8)
    {
        flag9++;
        if(ui->drumB4->x()+50<0||cnt<=1)
            {
             timer9->stop();
             ui->drumB4->show();
             ui->drumB4->setGeometry(527,100,91,91);
             flag9=0;
            }
        if(flag9==1)
        {
            ui->drumB4->show();
            timer9 = new QTimer(this);
            connect(timer9, SIGNAL(timeout()), this, SLOT(MoveBlue_4()));
            timer9->start(10);
        }
    }
    if(RandomNum==9)
    {
        flag10++;
        if(ui->drumB5->x()+50<0||cnt<=1)
        {
             timer10->stop();
             ui->drumB5->show();
             ui->drumB5->setGeometry(527,100,91,91);
             flag10=0;
            }
        if(flag10==1)
        {
            ui->drumB5->show();
            timer10 = new QTimer(this);
            connect(timer10, SIGNAL(timeout()), this, SLOT(MoveBlue_5()));
            timer10->start(10);
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_J)
    {
        if(ui->drumR1->x()<44&&ui->drumR1->x()>8)
        {
            ui->drumR1->hide();
            scorenum++;
            finalscore++;
            ui->scorevalue->setText(QString::number(scorenum));
        }
        if(ui->drumR2->x()<44&&ui->drumR2->x()>8)
        {
            ui->drumR2->hide();
            scorenum++;
            finalscore++;
            ui->scorevalue->setText(QString::number(scorenum));
        }
        if(ui->drumR3->x()<44&&ui->drumR3->x()>8)
        {
            ui->drumR3->hide();
            scorenum++;
            finalscore++;
            ui->scorevalue->setText(QString::number(scorenum));
        }
        if(ui->drumR4->x()<44&&ui->drumR4->x()>8)
        {
            ui->drumR4->hide();
            scorenum++;
            finalscore++;
            ui->scorevalue->setText(QString::number(scorenum));
        }
        if(ui->drumR5->x()<44&&ui->drumR5->x()>8)
        {
            ui->drumR5->hide();
            scorenum++;
            finalscore++;
            ui->scorevalue->setText(QString::number(scorenum));
        }

    }
    if(event->key() == Qt::Key_K)
    {
        if(ui->drumB1->x()<50&&ui->drumB1->x()>15)
        {
            ui->drumB1->hide();
            scorenum++;
            finalscore++;
            ui->scorevalue->setText(QString::number(scorenum));
        }
        if(ui->drumB2->x()<50&&ui->drumB2->x()>15)
        {
            ui->drumB2->hide();
            scorenum++;
            finalscore++;
            ui->scorevalue->setText(QString::number(scorenum));
        }
        if(ui->drumB3->x()<50&&ui->drumB3->x()>15)
        {
            ui->drumB3->hide();
            scorenum++;
            finalscore++;
            ui->scorevalue->setText(QString::number(scorenum));
        }
        if(ui->drumB4->x()<50&&ui->drumB4->x()>15)
        {
            ui->drumB4->hide();
            scorenum++;
            finalscore++;
            ui->scorevalue->setText(QString::number(scorenum));
        }
        if(ui->drumB5->x()<50&&ui->drumB5->x()>15)
        {
            ui->drumB5->hide();
            scorenum++;
            finalscore++;
            ui->scorevalue->setText(QString::number(scorenum));
        }

    }
}



void MainWindow::on_pushButton_2_clicked()              //exit
{
    QMessageBox::information(this,"Taiko","Game Over");
    close();
}




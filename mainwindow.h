#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void timer_timeout();

    void MoveRed_1();

    void MoveRed_2();

    void MoveRed_3();

    void MoveRed_4();

    void MoveRed_5();

    void MoveBlue_1();

    void MoveBlue_2();

    void MoveBlue_3();

    void MoveBlue_4();

    void MoveBlue_5();

    void Random();


private:
    void keyPressEvent(QKeyEvent *);
    Ui::MainWindow *ui;
    int RandomNum = 0;
    int scorenum = 0,finalscore = 0;
    int cnt = 30;
    int flag=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag7=0,flag8=0,flag9=0,flag10=0;
    QTimer *timer,*timer1,*timer2,*timer3,*timer4,*timer5,*timer6,*timer7,*timer8,*timer9,*timer10,*rnb;


};

#endif // MAINWINDOW_H

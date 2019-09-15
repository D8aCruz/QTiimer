#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    count = 10;
    QObject::connect(timer,&QTimer::timeout,this,[&](){
        ui->dial->setValue(count);
        ui->progressBar->setValue(10-count);
        if(count == 0 ){
            close();
        }
        count--;
    });
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "QKeyEvent"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::keyPressEvent(QKeyEvent * event)
//{
//    if(event->key() == Qt::Key_U)
//    {
//        std::cout<<"pressed U ";
//    }
//}

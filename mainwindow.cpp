#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customtabstyle.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(582,627);
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->tableWidget->setRowCount(700);
    //ui->tableWidget->verticalHeader()->setDefaultSectionSize(20);
    for (int i =0; i<5;i++){
        for (int j=0; j<4;j++){
            //ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
    ui->textBrowser->setText(tr("Crow/0.1 server is running at 0.0.0.0:18080 using 4 threads..."));
    ui->textBrowser->append(tr("(1-th Query Information)  Patient ID: P0066, Check-Up No: (C0002, C0005) \nQuery Type: range query, Username:Doctor;"));

    for (int i =0; i< 3; i++){
        for (int j =0; j <5; j++){
            ui->tableWidget->item(i,j)->setBackgroundColor(QColor(0,200,0));
        }
    }
    for (int j =0; j <5; j++){
        ui->tableWidget->item(3,j)->setBackgroundColor(QColor(200,0,0));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mainexit_2_clicked()
{
    //disable 'start server' button once it is pressed
    ui->mainexit_2->setEnabled(false);
}

void MainWindow::on_mainexit_clicked()
{
    //change the value of server parameter.
}

void MainWindow::on_mainexit_3_clicked()
{
    //change the data in the database directly...
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customtabstyle.h"
#include <iostream>
#include <fstream>
#include <QTimer>
#include "dialog2.h"
#include "pbutton.h"
#include <QHBoxLayout>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(582,627);
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->tableWidget->setRowCount(700);


    //ui->textBrowser->setText(tr("Crow/0.1 server is running at 0.0.0.0:18080 using 4 threads..."));
    //ui->textBrowser->append(tr("(1-th Query Information)  Patient ID: P0066, Check-Up No: (C0002, C0005) \nQuery Type: range query, Username:Doctor;"));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer->start(1000);

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

void MainWindow::timeout()
{
    update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    ifstream fin;
    string str;
    QString qstr;
    fin.open("/Users/scaryang/Desktop/Interface/server/test.txt");
    ui->textBrowser->setText(tr("Test whether it can display dynamically"));
    while(!fin.eof())
    {
        getline(fin,str);
        qstr = QString::fromStdString(str);
        ui->textBrowser->append(qstr);
    }
    fin.close();

    //read bit.txt then verdict use function. Last, update bit.txt (Yes/No)
    string str1;
{
    ifstream fin1("/Users/scaryang/Desktop/Interface/server/bit.txt");
    fin1 >> str1;
}
    //test output
    cout << str1 << endl;

    if( str1 == "Yes")
    {
        checkbit();
        //modify the bit
        ofstream outfile("/Users/scaryang/Desktop/Interface/server/bit.txt", ofstream::out);
        outfile << "No";
        outfile.close();
    }
}

void MainWindow::checkbit()
{
    //update the interface of database
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem("Check-Successfully"));
}

void MainWindow::on_mainexit_2_clicked()
{
    //disable 'start server' button once it is pressed
    ui->mainexit_2->setEnabled(false);

    //generate the data button
    //generate multi-button
    QString str;
    int i = 0;
    PButton *button[3];

    //set font in button
    QFont FontObj;
    FontObj.setFamily(QStringLiteral("Helvetica"));
    FontObj.setPointSize(14);
    FontObj.setUnderline(true);

    for (;i < 3;i++)
    {
        button[i] = new PButton(this);
        button[i]->setVisible(true);
        str.setNum(i,10);
        button[i]->setText("No." + str);
        //button[i]->setGeometry(10,i*height+3, width,height);
        button[i]->setclick();
        button[i]->setBackgroundRole(QPalette::Base);
        button[i]->setFlat(true);
        button[i]->setFont(FontObj);
        button[i]->setStyleSheet("QPushButton {color: blue}");


        QWidget* pWidget = new QWidget();
        QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
        pLayout->addWidget(button[i]);
        pWidget->setLayout(pLayout);
        pLayout->setAlignment(Qt::AlignCenter);
        pLayout->setContentsMargins(0, 0, 0, 0);
        ui->tableWidget->setCellWidget(i,0 ,pWidget);
    }
}

void MainWindow::on_mainexit_clicked()
{
    //change the value of server parameter.    
}

void MainWindow::on_mainexit_3_clicked()
{
    //change the data in the database directly...
    ofstream outfile;
    outfile.open("/Users/scaryang/Desktop/Interface/server/test.txt", ios::app);
    outfile << "Scarlett" << endl;
    outfile.close();
}

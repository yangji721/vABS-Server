#include "dialog2.h"
#include "ui_dialog2.h"

dialog2::dialog2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog2)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
}

dialog2::~dialog2()
{
    delete ui;
}

void dialog2::transmit(QString teemo)
{
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(teemo));
}

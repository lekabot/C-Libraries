#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSet>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->pushButton_0, SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_1, SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_3, SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_4, SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_5, SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_6, SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_7, SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_8, SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_9, SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_unary_sign, SIGNAL(clicked()),this,SLOT(unary_sign()));
//    connect(ui->pushButton_ac, SIGNAL(clicked()),this,SLOT(all_clean()));
//    connect(ui->pushButton_percent, SIGNAL(clicked()),this,SLOT(percent()));
//    connect(ui->pushButton_division, SIGNAL(clicked()),this,SLOT(math_operations()));
//    connect(ui->pushButton_mutiply, SIGNAL(clicked()),this,SLOT(math_operations()));
//    connect(ui->pushButton_plus, SIGNAL(clicked()),this,SLOT(math_operations()));
//    connect(ui->pushButton_minus, SIGNAL(clicked()),this,SLOT(math_operations()));

//    ui->pushButton_division->setCheckable(true);
//    ui->pushButton_mutiply->setCheckable(true);
//    ui->pushButton_plus->setCheckable(true);
//    ui->pushButton_minus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}



#include "mainwindow.h"
#include "./ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reset();
    connect(
    ui->pb1, &QPushButton::clicked, this, &MainWindow::on_input
    );
    connect(
    ui->pb2, &QPushButton::clicked, this, &MainWindow::on_input
    );
    connect(
    ui->pb3, &QPushButton::clicked, this, &MainWindow::on_input
    );
    connect(
    ui->pb4, &QPushButton::clicked, this, &MainWindow::on_input
    );
    connect(
    ui->pb5, &QPushButton::clicked, this, &MainWindow::on_input
    );
    connect(
    ui->pb6, &QPushButton::clicked, this, &MainWindow::on_input
    );
    connect(
    ui->pb7, &QPushButton::clicked, this, &MainWindow::on_input
    );
    connect(
    ui->pb8, &QPushButton::clicked, this, &MainWindow::on_input
    );
    connect(
    ui->pb9, &QPushButton::clicked, this, &MainWindow::on_input
    );
    connect(
    ui->pb0, &QPushButton::clicked, this, &MainWindow::on_input
    );
    connect(
    ui->pbCLEAR, &QPushButton::clicked, this, &MainWindow::reset
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset() {
    ui->leINPUT->setText("0");
    state = State::FirstDigit;
}

void MainWindow::on_input() {
    if(state == State::FirstDigit)
        ui->leINPUT->setText("");
    QString digit = dynamic_cast<QPushButton*>(sender())->text();
    ui->leINPUT->setText(ui->leINPUT->text()+digit);
    if(digit != "0")
        state = State::InputNumper;

}

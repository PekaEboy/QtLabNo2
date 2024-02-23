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
    finu=0;
    senu=0;
    pointex = false;
    state = State::FirstDigit;
}

void MainWindow::on_input() {
    if(state == State::FirstDigit || state == State::Calculation || state == State::ErrorMes)
        ui->leINPUT->setText("");
    if(state == State::SecondInput && (ui->leINPUT->text()).toDouble() == 0 && !pointex)
        ui->leINPUT->setText("");
    if (memoryused) {
        ui->leINPUT->setText("");
        memoryused = false;
    }
    QString digit = dynamic_cast<QPushButton*>(sender())->text();
    ui->leINPUT->setText(ui->leINPUT->text()+digit);
    if(digit != "0") {
        if(state == State::Calculation)
            state = State::SecondInput;
        else if (state==State::FirstDigit)
            state = State::InputNumper;
    } else {
        if (state == State::Calculation) {
            state = State::SecondInput;
        }
    }

}

void MainWindow::on_pbPLUS_clicked()
{
    QString leinp = ui->leINPUT->text();
    if(state==State::InputNumper || state==State::FirstDigit) {
        finu = leinp.toDouble();
        state = State::Calculation;
        oper = Operation::Plus;
        pointex = false;
    } else if (state==State::SecondInput) {
        senu = leinp.toDouble();
        finu += senu;
        ui->leINPUT->setText(QString::number(finu));
        state=State::Calculation;
        oper = Operation::Plus;
        pointex = false;
    }
}


void MainWindow::on_pbEQUAL_clicked()
{
    QString leinp = ui->leINPUT->text();
    if(state==State::SecondInput) {
        switch(oper) {
            case Operation::Plus:
                senu = leinp.toDouble();
                finu += senu;
                ui->leINPUT->setText(QString::number(finu));
                state=State::FirstDigit;
                break;
            case Operation::Minus:
                senu = leinp.toDouble();
                finu -= senu;
                ui->leINPUT->setText(QString::number(finu));
                state=State::FirstDigit;
                break;
            case Operation::Comp:
                senu = leinp.toDouble();
                finu *= senu;
                ui->leINPUT->setText(QString::number(finu));
                state=State::FirstDigit;
                break;
            case Operation::Divis:
                senu = leinp.toDouble();
                if(leinp.toInt()==0) {
                    ui->leINPUT->setText("ERROR");
                    state = State::ErrorMes;
                } else {
                    finu = finu / senu;
                    ui->leINPUT->setText(QString::number(finu));
                    state=State::FirstDigit;
                }
                break;
        }
    } else if (state==State::FirstDigit) {
        switch(oper) {
            case Operation::Plus:
                finu += senu;
                ui->leINPUT->setText(QString::number(finu));
                break;
            case Operation::Minus:
                finu -= senu;
                ui->leINPUT->setText(QString::number(finu));
                break;
            case Operation::Comp:
                finu *= senu;
                ui->leINPUT->setText(QString::number(finu));
                break;
            case Operation::Divis:
                finu /= senu;
                ui->leINPUT->setText(QString::number(finu));
                break;
        }
    } else if (state==State::Calculation) {
        switch(oper) {
            case Operation::Plus:
                senu = finu;
                finu += finu;
                ui->leINPUT->setText(QString::number(finu));
                state=State::FirstDigit;
                break;
            case Operation::Minus:
                senu = finu;
                finu -= finu;
                ui->leINPUT->setText(QString::number(finu));
                state=State::FirstDigit;
                break;
            case Operation::Comp:
                senu = finu;
                finu *= finu;
                ui->leINPUT->setText(QString::number(finu));
                state=State::FirstDigit;
                break;
            case Operation::Divis:
                senu = finu;
                if(senu==0) {
                    ui->leINPUT->setText("ERROR");
                    state = State::ErrorMes;
                } else {
                    finu /= finu;
                    ui->leINPUT->setText(QString::number(finu));
                    state=State::FirstDigit;
                    break;
                }
        }
    }
    if(finu-floor(finu)==0){
        pointex = false;
    }
}


void MainWindow::on_pbPLUSMINUS_clicked()
{
    QString leinp = ui->leINPUT->text();
    double p = leinp.toDouble();
    p *= -1;
    ui->leINPUT->setText(QString::number(p));
    state=State::InputNumper;
}


void MainWindow::on_pbCLEARNUMBER_clicked()
{
    ui->leINPUT->setText("0");
}


void MainWindow::on_pbMINUS_clicked()
{
    QString leinp = ui->leINPUT->text();
    if(state==State::InputNumper || state==State::FirstDigit) {
        finu = leinp.toDouble();
        state = State::Calculation;
        oper = Operation::Minus;
        pointex = false;
    } else if (state==State::SecondInput) {
        senu = leinp.toDouble();
        finu -= senu;
        ui->leINPUT->setText(QString::number(finu));
        state=State::Calculation;
        oper = Operation::Minus;
        pointex = false;
    }
}


void MainWindow::on_pbCOMP_clicked()
{
    QString leinp = ui->leINPUT->text();
    if(state==State::InputNumper || state==State::FirstDigit) {
        finu = leinp.toDouble();
        state = State::Calculation;
        oper = Operation::Comp;
        pointex = false;
    } else if (state==State::SecondInput) {
        senu = leinp.toDouble();
        finu *= senu;
        ui->leINPUT->setText(QString::number(finu));
        state=State::Calculation;
        oper = Operation::Comp;
        pointex = false;
    }
}


void MainWindow::on_pbDIVIS_clicked()
{
    QString leinp = ui->leINPUT->text();
    if(state==State::InputNumper || state==State::FirstDigit) {
        finu = leinp.toDouble();
        state = State::Calculation;
        oper = Operation::Divis;
    } else if (state==State::SecondInput) {
        senu = leinp.toDouble();
        if(senu==0) {
            ui->leINPUT->setText("ERROR");
            state = State::ErrorMes;
        } else {
            finu /= senu;
            ui->leINPUT->setText(QString::number(finu));
            state=State::Calculation;
            oper = Operation::Divis;
        }
    }
    pointex = false;
}


void MainWindow::on_pbPOINT_clicked()
{
    if(!pointex) {

        if(state==State::FirstDigit) {
            ui->leINPUT->setText("0.");
            state = State::InputNumper;
        } else if (state==State::Calculation) {
            ui->leINPUT->setText("0.");
            state = State::SecondInput;
        } else {
            ui->leINPUT->setText(ui->leINPUT->text()+".");
        }
        pointex=true;
    }
}


void MainWindow::on_pbMEMORYSAVE_clicked()
{
    memory = (ui->leINPUT->text()).toDouble();
    memorysaved = true;
    memoryused = true;
}


void MainWindow::on_pbMEMORYREPLACE_clicked()
{
    if(memorysaved) {
        ui->leINPUT->setText(QString::number(memory));
        if(state==State::FirstDigit) {
            state = State::InputNumper;
        } else if (state == State::Calculation) {
            state = State::SecondInput;
        }
        memoryused = true;
    }
}


void MainWindow::on_pbMEMORYCLEAR_clicked()
{
    memory = 0;
    memorysaved=false;
    memoryused = true;
}


void MainWindow::on_pbMEMORYPLUS_clicked()
{
    memory = memory + (ui->leINPUT->text()).toDouble();
    memorysaved = true;
    memoryused = true;
}


void MainWindow::on_pbMEMORYMINUS_clicked()
{
    memory = memory - (ui->leINPUT->text()).toDouble();
    memorysaved = true;
    memoryused = true;
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum State {
        FirstDigit, InputNumper, Calculation, SecondInput, ErrorMes
    };
    enum Operation {
        Plus, Minus, Comp, Divis
    };
    Operation oper;
    State state;
    double finu;
    double senu;
    double memory;
    bool memorysaved = false;
    bool pointex = false;
    bool memoryused = false;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_input();

    void on_pbPLUS_clicked();

    void on_pbEQUAL_clicked();

    void on_pbPLUSMINUS_clicked();

    void on_pbCLEARNUMBER_clicked();

    void on_pbMINUS_clicked();

    void on_pbCOMP_clicked();

    void on_pbDIVIS_clicked();

    void on_pbPOINT_clicked();

    void on_pbMEMORYSAVE_clicked();

    void on_pbMEMORYREPLACE_clicked();

    void on_pbMEMORYCLEAR_clicked();

    void on_pbMEMORYPLUS_clicked();

    void on_pbMEMORYMINUS_clicked();

private:
    Ui::MainWindow *ui;
    void reset();
};
#endif // MAINWINDOW_H

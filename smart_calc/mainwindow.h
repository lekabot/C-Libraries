#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
//    void digits_numbers();
//    void on_pushButton_dot_clicked();
//    void unary_sign();
//    void all_clean();
//    void percent();
//    void on_pushButton_eq_clicked();
//    void math_operations();
};
#endif // MAINWINDOW_H

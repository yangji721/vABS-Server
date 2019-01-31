#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void paintEvent(QPaintEvent*);

    void checkbit();

private slots:

    void on_mainexit_2_clicked();

    void on_mainexit_clicked();

    void on_mainexit_3_clicked();

    void timeout();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

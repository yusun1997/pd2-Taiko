#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialog.h"
#include "dialog2.h"
#include <QMainWindow>
#include <QtMultimedia/QMediaPlayer>
#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_exitButton_clicked();

    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *mdialog;
    Dialog2 *edialog;
    QMediaPlayer *cena;
    QMediaPlayer *nice;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>

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
    void on_insert_clicked();

    void on_create_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

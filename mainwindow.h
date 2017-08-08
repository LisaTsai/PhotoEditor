#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include "myCV.h"

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
    void on_actionLoad_BMP_Files_triggered();

    void on_actionSave_BMP_Image_Using_QImage_triggered();

    void on_actionSave_BMP_Image_Using_fstream_triggered();

private:
    QString saveImage();

    Ui::MainWindow *ui;
    std::string fileName;
    myCV::myMat image;
    QImage test;
};

#endif // MAINWINDOW_H

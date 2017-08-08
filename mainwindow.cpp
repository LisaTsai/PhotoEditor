#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_BMP_Files_triggered()
{
    //get file path
    fileName = QFileDialog::getOpenFileName(this, "Open Image", QDir::currentPath(), "BMP files (*.bmp)").toStdString();

    //read BMP file
    image.read(fileName.c_str());

    //import to QImage
    test = QImage(image.data_(),image.getWidth(),image.getHeight(),image.getStep(),QImage::Format_RGB888);
    QImage showImage;
    showImage = test;
    if(image.getWidth() > 2000)
    {
        showImage = test.scaled(image.getWidth()/2, image.getHeight()/2);
    }
    else
    {
        showImage = test;
    }
    QRect mainWindowGeometry = this->geometry();
    mainWindowGeometry.setWidth(showImage.width());
    mainWindowGeometry.setHeight(showImage.height()+54);
    this->setGeometry(mainWindowGeometry);
    ui->show_BMP_files->setGeometry(0,0,showImage.width(), showImage.height());
    ui->show_BMP_files->setPixmap(QPixmap::fromImage(showImage));

    //set button enable
    ui->actionSave_BMP_Image_Using_fstream->setEnabled(true);
    ui->actionSave_BMP_Image_Using_QImage->setEnabled(true);
}

void MainWindow::on_actionSave_BMP_Image_Using_QImage_triggered()
{
    QString name = saveImage();
    if(!name.isEmpty())
    {
        test.save(name);
    }
}

void MainWindow::on_actionSave_BMP_Image_Using_fstream_triggered()
{
    QString name = saveImage();
    if(!name.isEmpty())
    {
      image.write(name.toStdString().c_str());
    }
}

QString MainWindow::saveImage()
{
    //Extract file name from string
    size_t fileHead = fileName.find_last_of("/") + 1;
    size_t fileNameLength = fileName.find_last_of(".") - fileHead;

    //Get current path & file name
    QString saveFileName = QDir::currentPath() + "/" + QString::fromStdString(fileName.substr(fileHead, fileNameLength)) + "-modified" + ".bmp";

    //rename flag
    int count = 2;
    while(1)
    {
        //check if there's any duplicated file name.
        if(QFile::exists(saveFileName))
        {
            saveFileName = QDir::currentPath() + "/" + QString::fromStdString(fileName.substr(fileHead, fileNameLength)) + "-modified-" + QString::number(count) + ".bmp";
            count++;
        }
        else
        {
            break;
        }
    }

    //open file dialog
    saveFileName = QFileDialog::getSaveFileName(this, "Save Image", saveFileName, "BMP files (*.bmp)");

    return saveFileName;
}

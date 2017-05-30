#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    // using std::fstream
    std::ifstream file("/tmp/myfile.txt");
    QString buffer = "";
    char c_buf[4096];
    while (!file.eof()) {
        file.getline(c_buf,4096);
        buffer += c_buf;
        buffer += "\n";
    }
    */
    // using QFile
    QFile file("/tmp/myfile.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      return;

    QTextStream in(&file);
    QString buffer;
    while (!in.atEnd()) {
        buffer += in.readLine();
        buffer += "\n";

    }
    ui->textEdit->setText(buffer);

}

MainWindow::~MainWindow()
{
    delete ui;
}

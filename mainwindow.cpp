#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QColor>
#include <QColorDialog>
#include <QTextCursor>

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

void MainWindow::on_pushButton_clicked()
{

    //qDebug()<<"Read Data" << str;
    QString str = QFileDialog::getSaveFileName();
    QFile file(str);
    file.open(QIODevice::WriteOnly);
    file.write(ui->textEdit->toPlainText().toUtf8());
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString strin = QFileDialog::getOpenFileName();
    QByteArray data;
    QFile file(strin);
    file.open(QIODevice::ReadOnly);
    data = file.readAll();
    qDebug()<<"Read Data" << data;
    ui->textEdit->setText(data);
}

void MainWindow::on_pushButton_3_clicked()
{
    //QPalette palette = ui->textEdit->palette();
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    QString str = cursor.selectedText();
    qDebug()<<"Selected text"<<str;
    QColor color = QColorDialog::getColor();
    //palette.setColor(ui->textEdit->tex, color);
    ui->textEdit->setTextColor(color);
}

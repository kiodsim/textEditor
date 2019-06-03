#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QColor>
#include <QColorDialog>
#include <QTextCursor>
#include <QFontDialog>
#include <QTextCodec>

QTextCodec *codec;

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

void MainWindow::on_action_triggered()
{
    QString str = QFileDialog::getSaveFileName();
    QFile file(str);
    file.open(QIODevice::WriteOnly);
    file.write(ui->textEdit->toPlainText().toUtf8());
    file.close();
}

void MainWindow::on_action_2_triggered()
{
    QString strin = QFileDialog::getOpenFileName();
    QByteArray data;
    QFile file(strin);
    file.open(QIODevice::ReadOnly);
    data = file.readAll();
    qDebug()<<"Read Data" << data;
    ui->textEdit->setText(data);
}

void MainWindow::on_action_3_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    QString str = cursor.selectedText();
    qDebug()<<"Selected text"<<str;
    QColor color = QColorDialog::getColor();
    //palette.setColor(ui->textEdit->tex, color);
    ui->textEdit->setTextColor(color);
}

void MainWindow::on_action_4_triggered()
{
    ui->textEdit->setFont(QFontDialog::getFont(0,ui->textEdit->font()));
}

void MainWindow::on_actionWindows_1251_triggered()
{
    ui->actionWindows_1251->setDisabled(true);
    ui->actionCP_1251->setEnabled(true);
    ui->actionIBM_866->setEnabled(true);
    ui->actionUTF_8->setEnabled(true);
    ui->actionCP866->setEnabled(true);

    QString str = ui->textEdit->toPlainText();
    QByteArray str2 = str.toUtf8();
    qDebug() << "Win 1251: " <<str2;
    codec = QTextCodec::codecForName("CP-1251");
    str = codec->toUnicode(str2);
    qDebug() << "Win 1251: " <<str;
    codec = QTextCodec::codecForName("Windows-1251");
    str = codec->toUnicode(str2);
    ui->textEdit->clear();
    qDebug() << "textRdit:" << ui->textEdit->toPlainText();
    ui->textEdit->setText(str);
}

void MainWindow::on_actionUTF_8_triggered()
{
    ui->actionWindows_1251->setEnabled(true);
    ui->actionCP_1251->setEnabled(true);
    ui->actionIBM_866->setEnabled(true);
    ui->actionUTF_8->setDisabled(true);
    ui->actionCP866->setEnabled(true);

    QString str = ui->textEdit->toPlainText();
    QByteArray str2 = str.toUtf8();
    qDebug() << "UTF-8: " <<str2;
    codec = QTextCodec::codecForName("CP-1251");
    str = codec->toUnicode(str2);
    qDebug() << "UTF-8: " <<str;
    codec = QTextCodec::codecForName("UTF-8");
    str = codec->toUnicode(str2);
    ui->textEdit->clear();
    qDebug() << "textRdit:" << ui->textEdit->toPlainText();
    ui->textEdit->setText(str);
}

void MainWindow::on_actionIBM_866_triggered()
{
    ui->actionWindows_1251->setEnabled(true);
    ui->actionCP_1251->setEnabled(true);
    ui->actionIBM_866->setDisabled(true);
    ui->actionUTF_8->setEnabled(true);
    ui->actionCP866->setEnabled(true);

    QString str = ui->textEdit->toPlainText();
    QByteArray str2 = str.toUtf8();
    qDebug() << "IBM 866: " <<str2;
    codec = QTextCodec::codecForName("CP-1251");
    str = codec->toUnicode(str2);
    qDebug() << "IBM 866: " <<str;
    codec = QTextCodec::codecForName("IBM 866");
    str = codec->toUnicode(str2);
    ui->textEdit->clear();
    qDebug() << "textRdit:" << ui->textEdit->toPlainText();
    ui->textEdit->setText(str);
}

void MainWindow::on_actionCP_1251_triggered()
{
    ui->actionWindows_1251->setEnabled(true);
    ui->actionCP_1251->setDisabled(true);
    ui->actionIBM_866->setEnabled(true);
    ui->actionUTF_8->setEnabled(true);
    ui->actionCP866->setEnabled(true);

    QString str = ui->textEdit->toPlainText();
    QByteArray str2 = str.toUtf8();
    qDebug() << "CP 1251: " <<str2;
    codec = QTextCodec::codecForName("CP-1251");
    str = codec->toUnicode(str2);
    qDebug() << "CP 1251: " <<str;
    ui->textEdit->clear();
    qDebug() << "textRdit:" << ui->textEdit->toPlainText();
    ui->textEdit->setText(str);
}

void MainWindow::on_actionCP866_triggered()
{
    ui->actionWindows_1251->setEnabled(true);
    ui->actionCP_1251->setEnabled(true);
    ui->actionIBM_866->setEnabled(true);
    ui->actionUTF_8->setEnabled(true);
    ui->actionCP866->setDisabled(true);
    QString str = ui->textEdit->toPlainText();
    QByteArray str2 = str.toUtf8();
    qDebug() << "CP866: " <<str2;
    codec = QTextCodec::codecForName("CP-1251");
    str = codec->toUnicode(str2);
    qDebug() << "CP866: " <<str;
    codec = QTextCodec::codecForName("CP866");
    str = codec->toUnicode(str2);
    ui->textEdit->clear();
    qDebug() << "textRdit:" << ui->textEdit->toPlainText();
    ui->textEdit->setText(str);
}

void MainWindow::on_action_5_triggered()
{
    QColor color = QColorDialog::getColor();
    ui->textEdit->setTextBackgroundColor(color);
}

void MainWindow::on_action_6_triggered()
{
    QPalette p = ui->textEdit->palette();
    p.setColor(QPalette::Base, QColorDialog::getColor());
    ui->textEdit->setPalette(p);
}

void MainWindow::on_textEdit_cursorPositionChanged()
{
    //qDebug() << ui->textEdit->height();
    //qDebug() << ui->textEdit->width();
    //ui->textEdit->resize(ui->MainWindow->centralWidget->geometry()->height(),ui->MainWindow->centralWidget->geometry()->width());

}

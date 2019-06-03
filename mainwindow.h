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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_actionWindows_1251_triggered();

    void on_actionUTF_8_triggered();

    void on_actionIBM_866_triggered();

    void on_actionCP_1251_triggered();

    void on_actionCP866_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_textEdit_cursorPositionChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

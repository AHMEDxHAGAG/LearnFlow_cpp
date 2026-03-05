#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_navHome_clicked();

    void on_navTasks_clicked();

    void on_navCalendar_clicked();

    void on_filterAll_clicked();

    void on_filterOverdue_clicked();

    void on_filterHighPriority_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

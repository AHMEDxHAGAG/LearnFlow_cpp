#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QDateTime>
#include <QDebug>
#include <QString>
typedef long long ll;
using namespace std;

void setHomePage(Ui::MainWindow *ui);
void setTasksPage(Ui::MainWindow *ui);
void setCalendarPage(Ui::MainWindow *ui);
void applyShadow (QWidget *widget, qreal blurRadius, qreal dx, qreal dy, const QColor &color);
void applyingShadows(Ui::MainWindow *ui);
void setCurrentTime(Ui::MainWindow *ui);
void firstRun(Ui::MainWindow *ui);
vector<pair<ll,ll>> tasks;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    firstRun(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_navHome_clicked()
{
    setHomePage(ui);
}


void MainWindow::on_navTasks_clicked()
{
    setTasksPage(ui);
}


void MainWindow::on_navCalendar_clicked()
{
    setCalendarPage(ui);
}

void setHomePage(Ui::MainWindow *ui){
    ui->navHome->setStyleSheet(
        "QPushButton#navHome { border: none; background: transparent; border-image: url(:/home.png) 0 0 0 0 stretch stretch; min-height: 142px; max-width: 53px;}"
        );
    ui->navCalendar->setStyleSheet(
        "QPushButton#navCalendar { border: none; background: transparent; border-image: url(:/notcalendar.png) 0 0 0 0 stretch stretch; min-height: 170px; max-width: 53px;}"
        );
    ui->navTasks->setStyleSheet(
        "QPushButton#navTasks { border: none; background: transparent; border-image: url(:/nottasks.png) 0 0 0 0 stretch stretch; min-height: 144px; max-width: 53px;}"
        );
    ui->contentStack->setCurrentIndex(0);
}


void setTasksPage(Ui::MainWindow *ui){
    ui->navHome->setStyleSheet(
        "QPushButton#navHome { border: none; background: transparent; border-image: url(:/nothome.png) 0 0 0 0 stretch stretch; min-height: 142px; max-width: 53px;}"
        );
    ui->navCalendar->setStyleSheet(
        "QPushButton#navCalendar { border: none; background: transparent; border-image: url(:/notcalendar.png) 0 0 0 0 stretch stretch; min-height: 170px; max-width: 53px;}"
        );
    ui->navTasks->setStyleSheet(
        "QPushButton#navTasks { border: none; background: transparent; border-image: url(:/tasks.png) 0 0 0 0 stretch stretch; min-height: 144px; max-width: 53px;}"
        );
    ui->contentStack->setCurrentIndex(1);
}

void setCalendarPage(Ui::MainWindow *ui){
    ui->navHome->setStyleSheet(
        "QPushButton#navHome { border: none; background: transparent; border-image: url(:/nothome.png) 0 0 0 0 stretch stretch; min-height: 142px; max-width: 53px;}"
        );
    ui->navCalendar->setStyleSheet(
        "QPushButton#navCalendar { border: none; background: transparent; border-image: url(:/calendar.png) 0 0 0 0 stretch stretch; min-height: 170px; max-width: 53px;}"
        );
    ui->navTasks->setStyleSheet(
        "QPushButton#navTasks { border: none; background: transparent; border-image: url(:/nottasks.png) 0 0 0 0 stretch stretch; min-height: 144px; max-width: 53px;}"
        );
    ui->contentStack->setCurrentIndex(2);
}

void applyShadow (QWidget *widget, qreal blurRadius, qreal dx, qreal dy, const QColor &color) {
    auto *shadow = new QGraphicsDropShadowEffect(widget);
    shadow->setBlurRadius(blurRadius);
    shadow->setOffset(dx, dy);
    shadow->setColor(color);
    widget->setGraphicsEffect(shadow);
};

void applyingShadows(Ui::MainWindow *ui){
    applyShadow(ui->cardTotalTasks,   4, 0, 0, QColor(0, 0, 0, 22));
    applyShadow(ui->cardInProgress,   4, 0, 0, QColor(0, 0, 0, 22));
    applyShadow(ui->cardProductivity, 4, 0, 0, QColor(0, 0, 0, 22));
    applyShadow(ui->cardCompleted,    4, 0, 0, QColor(0, 0, 0, 22));
    applyShadow(ui->taskInput,        4, 0, 0, QColor(0, 0, 0, 22));
    applyShadow(ui->tasksSearchBar,   4, 0, 0, QColor(0, 0, 0, 22));
}

void setCurrentTime(Ui::MainWindow *ui){
    QDateTime time = QDateTime::currentDateTime();
    ui->calendarDate->setText(time.toString("dd MMM"));
    ui->calendarDate->adjustSize();
}

void intializeCards(Ui::MainWindow *ui){

}

void firstRun(Ui::MainWindow *ui){
    setHomePage(ui);
    applyingShadows(ui);
    setCurrentTime(ui);
    intializeCards(ui);
}


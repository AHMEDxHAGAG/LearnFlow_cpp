#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_navHome_clicked()
{
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


void MainWindow::on_navTasks_clicked()
{
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


void MainWindow::on_navCalendar_clicked()
{
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


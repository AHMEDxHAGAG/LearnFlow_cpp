#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QDateTime>
#include <QDebug>
#include <QString>
typedef long long ll;
typedef long double ld;
using namespace std;

void setHomePage(Ui::MainWindow *ui);
void setTasksPage(Ui::MainWindow *ui);
void setCalendarPage(Ui::MainWindow *ui);
void applyShadow (QWidget *widget, qreal blurRadius, qreal dx, qreal dy, const QColor &color);
void applyingShadows(Ui::MainWindow *ui);
QDateTime getCurrentTime(Ui::MainWindow *ui);
void intializeCardsData(Ui::MainWindow *ui);
void intializeCardsView(Ui::MainWindow *ui, QString tasksNum, QString completedNum, QString progressNum, QString productivityNum);
void intializeCards(Ui::MainWindow *ui);
void update(Ui::MainWindow *ui);
void filterAllMode(Ui::MainWindow *ui);
void filterOverdueMode(Ui::MainWindow *ui);
void filterHighPriority(Ui::MainWindow *ui);
void displayDateCardForward(Ui::MainWindow *ui);
void displayDateCardBackward(Ui::MainWindow *ui);
void firstRun(Ui::MainWindow *ui);

vector<pair<ll,ll>> tasks;
QString tasksNum, completedNum, progressNum, productivityNum;
QDateTime playableTime, currentPlayableTime;

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
    filterAllMode(ui);
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
    currentPlayableTime = getCurrentTime(ui);
    displayDateCardForward(ui);
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

QDateTime getCurrentTime(Ui::MainWindow *ui){
    QDateTime time = QDateTime::currentDateTime();
    ui->calendarDate->setText(time.toString("dd MMM"));
    ui->calendarDate->adjustSize();
    return time;
}

void intializeCardsData(){
    ll compN = 0; // i need to Implement this the rest is already done, dont forget when u finish the list logic
    ll tasksN = tasks.size();
    ll progN = tasksN-compN;
    ll prodN = 0; if(tasksN!=0) prodN = ((compN/(ld)tasksN)*100);
    completedNum = QString::fromStdString(to_string(compN));
    tasksNum = QString::fromStdString(to_string(tasksN));
    progressNum = QString::fromStdString(to_string(progN));
    productivityNum = QString::fromStdString(to_string(prodN));
}

void intializeCardsView(Ui::MainWindow *ui){
    ui->valueCompleted->setText(completedNum);
    ui->valueInProgress->setText(progressNum);
    ui->valueProductivity->setText(productivityNum);
    ui->valueTotalTasks->setText(tasksNum);
}

void intializeCards(Ui::MainWindow *ui){
    intializeCardsData();
    intializeCardsView(ui);
}

void update(Ui::MainWindow *ui){
    intializeCards(ui);
}

void filterAllMode(Ui::MainWindow *ui){
    ui->filterAll->setStyleSheet(
        R"(
            QPushButton#filterAll {
                background-color: #06B6A4;
            border: none;
                border-radius: 28px;
            color: white;
                font-family: 'Inter';
                font-size: 18px;
                font-weight: 700;
            padding: 6px 20px;
                min-height: 20px;
            }
            QPushButton#filterAll:hover {
                background-color: #059E8E;
            }
        )"
        );

    ui->filterOverdue->setStyleSheet(
        R"(
            QPushButton#filterOverdue{
                background-color: transparent;
            border: 1px solid #065F56;
                border-radius: 28px;
            color: #065F56;
                font-family: 'Inter';
                font-size: 18px;
                font-weight: 600;
            padding: 6px 20px;
                min-height: 20px;
            }
            QPushButton#filterOverdue:hover {
                background-color: rgba(6, 182, 164, 0.1);
            }
        )"
        );

    ui->filterHighPriority->setStyleSheet(
        R"(
            QPushButton#filterHighPriority {
                background-color: transparent;
            border: 1px solid #065F56;
                border-radius: 28px;
            color: #065F56;
                font-family: 'Inter';
                font-size: 18px;
                font-weight: 600;
            padding: 6px 20px;
                min-height: 20px;
            }
            QPushButton#filterHighPriority:hover {
                background-color: rgba(6, 182, 164, 0.1);
            }
        )"
        );
}

void filterOverdueMode(Ui::MainWindow *ui){
    ui->filterOverdue->setStyleSheet(
        R"(
            QPushButton#filterOverdue {
                background-color: #06B6A4;
            border: none;
                border-radius: 28px;
            color: white;
                font-family: 'Inter';
                font-size: 18px;
                font-weight: 700;
            padding: 6px 20px;
                min-height: 20px;
            }
            QPushButton#filterOverdue:hover {
                background-color: #059E8E;
            }
        )"
    );

    ui->filterAll->setStyleSheet(
        R"(
            QPushButton#filterAll{
                background-color: transparent;
            border: 1px solid #065F56;
                border-radius: 28px;
            color: #065F56;
                font-family: 'Inter';
                font-size: 18px;
                font-weight: 600;
            padding: 6px 20px;
                min-height: 20px;
            }
            QPushButton#filterAll:hover {
                background-color: rgba(6, 182, 164, 0.1);
            }
        )"
    );

    ui->filterHighPriority->setStyleSheet(
        R"(
            QPushButton#filterHighPriority {
                background-color: transparent;
            border: 1px solid #065F56;
                border-radius: 28px;
            color: #065F56;
                font-family: 'Inter';
                font-size: 18px;
                font-weight: 600;
            padding: 6px 20px;
                min-height: 20px;
            }
            QPushButton#filterHighPriority:hover {
                background-color: rgba(6, 182, 164, 0.1);
            }
        )"
    );
}

void filterHighPriority(Ui::MainWindow *ui){
    ui->filterHighPriority->setStyleSheet(
        R"(
            QPushButton#filterHighPriority {
                background-color: #06B6A4;
            border: none;
                border-radius: 28px;
            color: white;
                font-family: 'Inter';
                font-size: 18px;
                font-weight: 700;
            padding: 6px 20px;
                min-height: 20px;
            }
            QPushButton#HighPriority:hover {
                background-color: #059E8E;
            }
        )"
    );

    ui->filterOverdue->setStyleSheet(
        R"(
            QPushButton#filterOverdue{
                background-color: transparent;
            border: 1px solid #065F56;
                border-radius: 28px;
            color: #065F56;
                font-family: 'Inter';
                font-size: 18px;
                font-weight: 600;
            padding: 6px 20px;
                min-height: 20px;
            }
            QPushButton#filterOverdue:hover {
                background-color: rgba(6, 182, 164, 0.1);
            }
        )"
    );

    ui->filterAll->setStyleSheet(
        R"(
            QPushButton#filterAll {
                background-color: transparent;
            border: 1px solid #065F56;
                border-radius: 28px;
            color: #065F56;
                font-family: 'Inter';
                font-size: 18px;
                font-weight: 600;
            padding: 6px 20px;
                min-height: 20px;
            }
            QPushButton#filterAll:hover {
                background-color: rgba(6, 182, 164, 0.1);
            }
        )"
    );
}

void firstRun(Ui::MainWindow *ui){
    setHomePage(ui);
    applyingShadows(ui);

    update(ui);
}

void MainWindow::on_filterAll_clicked()
{
    filterAllMode(ui);
}

void MainWindow::on_filterOverdue_clicked()
{
    filterOverdueMode(ui);
}

void MainWindow::on_filterHighPriority_clicked()
{
    filterHighPriority(ui);
}

void displayDateCardForward(Ui::MainWindow *ui){
    playableTime = currentPlayableTime;
    ui->dayLabelY->setText(playableTime.toString("MMM ddd"));
    ui->dayNumY->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(1);
    ui->dayLabel0->setText(playableTime.toString("MMM ddd"));
    ui->dayNum0->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(1);
    ui->dayLabel1->setText(playableTime.toString("MMM ddd"));
    ui->dayNum1->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(1);
    ui->dayLabel2->setText(playableTime.toString("MMM ddd"));
    ui->dayNum2->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(1);
    ui->dayLabel3->setText(playableTime.toString("MMM ddd"));
    ui->dayNum3->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(1);
    ui->dayLabel4->setText(playableTime.toString("MMM ddd"));
    ui->dayNum4->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(1);
    ui->dayLabel5->setText(playableTime.toString("MMM ddd"));
    ui->dayNum5->setText(playableTime.toString("dd"));

    currentPlayableTime = currentPlayableTime.addDays(1);
}

void displayDateCardBackward(Ui::MainWindow *ui){
    playableTime = currentPlayableTime.addDays(4);
    ui->dayLabel5->setText(playableTime.toString("MMM ddd"));
    ui->dayNum5->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(-1);
    ui->dayLabel4->setText(playableTime.toString("MMM ddd"));
    ui->dayNum4->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(-1);
    ui->dayLabel3->setText(playableTime.toString("MMM ddd"));
    ui->dayNum3->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(-1);
    ui->dayLabel2->setText(playableTime.toString("MMM ddd"));
    ui->dayNum2->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(-1);
    ui->dayLabel1->setText(playableTime.toString("MMM ddd"));
    ui->dayNum1->setText(playableTime.toString("dd"));

    playableTime = playableTime.addDays(-1);
    ui->dayLabel0->setText(playableTime.toString("MMM ddd"));
    ui->dayNum0->setText(playableTime.toString("dd"));
    currentPlayableTime = playableTime;

    playableTime = playableTime.addDays(-1);
    ui->dayLabelY->setText(playableTime.toString("MMM ddd"));
    ui->dayNumY->setText(playableTime.toString("dd"));

}

void MainWindow::on_calBtnNext_clicked()
{
    displayDateCardForward(ui);
}


void MainWindow::on_calBtnPrev_clicked()
{
    displayDateCardBackward(ui);
}


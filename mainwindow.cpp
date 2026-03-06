#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addtaskdialog.h"
#include <QGraphicsDropShadowEffect>
#include <QDateTime>
#include <QDebug>
#include <QString>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QDate>
#include <vector>
#include <set>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Task {
    QString title;
    QString description;
    bool completed = false;
    QString priority = "Medium"; // "High", "Medium", "Low"
    QString project = "General";
    QDate dueDate = QDate::currentDate().addDays(7);
    QDate endDate = QDate::currentDate().addDays(7);
    QTime dueTime = QTime(9, 0); // Default to 9:00 AM
    QTime endTime = QTime(10, 0); // Default to 10:00 AM
};

void setHomePage(Ui::MainWindow *ui);
void setTasksPage(Ui::MainWindow *ui);
void setCalendarPage(Ui::MainWindow *ui);
void applyShadow (QWidget *widget, qreal blurRadius, qreal dx, qreal dy, const QColor &color);
void applyingShadows(Ui::MainWindow *ui);
QDateTime getCurrentTime(Ui::MainWindow *ui);
void intializeCardsData();
void intializeCardsView(Ui::MainWindow *ui);
void intializeCards(Ui::MainWindow *ui);
void update(Ui::MainWindow *ui);
void filterAllMode(Ui::MainWindow *ui);
void filterOverdueMode(Ui::MainWindow *ui);
void filterHighPriority(Ui::MainWindow *ui);
void firstRun(Ui::MainWindow *ui);

vector<Task> taskList;
QString tasksNum, completedNum, progressNum, productivityNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    QDate today = QDate::currentDate();
    m_currentYear = today.year();
    m_currentMonth = today.month();
    m_selectedDay = today.day();
    m_currentWeekStart = today.addDays(-(today.dayOfWeek() - 1));

    m_currentFilter = "All";
    m_searchQuery = "";

    createTaskListView();
    initializeCalendarView();
    
    connect(ui->tasksSearchBar, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    
    firstRun(ui);
    refreshTaskList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_navHome_clicked()
{
    setHomePage(ui);
    refreshTaskList();
}

void MainWindow::on_navTasks_clicked()
{
    setTasksPage(ui);
    refreshTaskList();
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
    applyShadow(ui->tasksSearchBar,   4, 0, 0, QColor(0, 0, 0, 22));
    applyShadow(ui->fabButton,        12, 0, 4, QColor(0, 0, 0, 40));
}

QDateTime getCurrentTime(Ui::MainWindow *ui){
    QDateTime time = QDateTime::currentDateTime();
    return time;
}

void intializeCardsData(){
    ll compN = 0;
    for (const auto &t : taskList) if (t.completed) compN++;
    ll tasksN = taskList.size();
    ll progN = tasksN - compN;
    ll prodN = 0; if(tasksN!=0) prodN = ((compN/(ld)tasksN)*100);
    completedNum = QString::number(compN);
    tasksNum = QString::number(tasksN);
    progressNum = QString::number(progN);
    productivityNum = QString::number(prodN);
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
    m_currentFilter = "All";
    filterAllMode(ui);
    refreshTaskList();
}

void MainWindow::on_filterOverdue_clicked()
{
    m_currentFilter = "Overdue";
    filterOverdueMode(ui);
    refreshTaskList();
}

void MainWindow::on_filterHighPriority_clicked()
{
    m_currentFilter = "High Priority";
    filterHighPriority(ui);
    refreshTaskList();
}

void MainWindow::onSearchTextChanged(const QString &text)
{
    m_searchQuery = text.trimmed();
    refreshTaskList();
}

void MainWindow::on_calBtnNext_clicked()
{
    m_currentMonth++;
    if (m_currentMonth > 12) {
        m_currentMonth = 1;
        m_currentYear++;
    }
    renderMiniCalendar();
}


void MainWindow::on_calBtnPrev_clicked()
{
    m_currentMonth--;
    if (m_currentMonth < 1) {
        m_currentMonth = 12;
        m_currentYear--;
    }
    renderMiniCalendar();
}

void MainWindow::initializeCalendarView()
{
    // Clear the container
    if (ui->calendarContainer->layout()) {
        QLayoutItem *child;
        while ((child = ui->calendarContainer->layout()->takeAt(0)) != nullptr) {
            if (child->widget()) { child->widget()->deleteLater(); }
            delete child;
        }
        delete ui->calendarContainer->layout();
    }

    QHBoxLayout *mainLayout = new QHBoxLayout(ui->calendarContainer);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // ── LEFT SIDEBAR ──
    m_calendarSidebar = new QWidget;
    m_calendarSidebar->setFixedWidth(280);
    m_calendarSidebar->setStyleSheet("background-color: transparent;");
    m_sidebarLayout = new QVBoxLayout(m_calendarSidebar);
    m_sidebarLayout->setContentsMargins(20, 20, 20, 20);
    m_sidebarLayout->setSpacing(25);

    // ── RIGHT MAIN AREA (Weekly Grid) ──
    m_timelineScroll = new QScrollArea;
    m_timelineScroll->setObjectName("weeklyGridScroll");
    m_timelineScroll->setWidgetResizable(true);
    m_timelineScroll->setFrameShape(QFrame::NoFrame);
    m_timelineScroll->setStyleSheet("QScrollArea#weeklyGridScroll { background-color: transparent; border-left: 1px solid rgba(0, 0, 0, 0.05); }");
    
    m_timelineContent = new QWidget;
    m_timelineContent->setStyleSheet("background-color: transparent;");
    m_timelineLayout = new QHBoxLayout(m_timelineContent);
    m_timelineLayout->setContentsMargins(10, 20, 10, 20);
    m_timelineLayout->setSpacing(0);
    m_timelineScroll->setWidget(m_timelineContent);

    // Mini Header (Month Selector)
    QHBoxLayout *miniHead = new QHBoxLayout;
    QLabel *monthLabel = new QLabel;
    monthLabel->setObjectName("miniMonthLabel");
    monthLabel->setStyleSheet("font-family: 'Inter'; font-size: 14px; font-weight: 700; color: #111111;");
    
    QPushButton *prev = new QPushButton("<");
    QPushButton *next = new QPushButton(">");
    QString btnStyle = "QPushButton { border: none; color: #06B6A4; font-size: 16px; font-weight: 800; padding: 5px; background: transparent; } QPushButton:hover { background: rgba(6, 182, 164, 0.1); border-radius: 14px; }";
    prev->setStyleSheet(btnStyle);
    next->setStyleSheet(btnStyle);
    
    miniHead->addWidget(monthLabel);
    miniHead->addStretch();
    miniHead->addWidget(prev);
    miniHead->addSpacing(10);
    miniHead->addWidget(next);

    connect(prev, &QPushButton::clicked, this, [this](){
        m_currentMonth--;
        if (m_currentMonth < 1) { m_currentMonth = 12; m_currentYear--; }
        m_selectedDay = QDate(m_currentYear, m_currentMonth, 1).day();
        m_currentWeekStart = QDate(m_currentYear, m_currentMonth, 1).addDays(-(QDate(m_currentYear, m_currentMonth, 1).dayOfWeek() - 1));
        renderMiniCalendar();
        renderTimeline();
    });
    connect(next, &QPushButton::clicked, this, [this](){
        m_currentMonth++;
        if (m_currentMonth > 12) { m_currentMonth = 1; m_currentYear++; }
        m_selectedDay = QDate(m_currentYear, m_currentMonth, 1).day();
        m_currentWeekStart = QDate(m_currentYear, m_currentMonth, 1).addDays(-(QDate(m_currentYear, m_currentMonth, 1).dayOfWeek() - 1));
        renderMiniCalendar();
        renderTimeline();
    });

    m_miniCalendarGrid = new QGridLayout;
    m_miniCalendarGrid->setSpacing(2);
    
    m_sidebarLayout->addLayout(miniHead);
    m_sidebarLayout->addLayout(m_miniCalendarGrid);
    
    // Upcoming Info Card
    QFrame *infoCard = new QFrame;
    infoCard->setStyleSheet("background: white; border-radius: 16px;");
    applyShadow(infoCard, 10, 0, 2, QColor(0, 0, 0, 20));
    QVBoxLayout *iLay = new QVBoxLayout(infoCard);
    iLay->setContentsMargins(15, 15, 15, 15);
    
    QLabel *iHead = new QLabel("Next Appointment");
    iHead->setStyleSheet("color: #06B6A4; font-family: 'Inter'; font-weight: 700; font-size: 10px; text-transform: uppercase; letter-spacing: 0.5px; background: transparent;");
    QLabel *iTitle = new QLabel("Update tasks to see");
    iTitle->setStyleSheet("color: #111111; font-family: 'Inter'; font-weight: 700; font-size: 14px; background: transparent;");
    
    iLay->addWidget(iHead);
    iLay->addWidget(iTitle);
    
    m_sidebarLayout->addSpacing(10);
    m_sidebarLayout->addWidget(infoCard);

    // Upcoming Schedule List (Placeholder logic that can be refined)
    QLabel *upcomingHead = new QLabel("Upcoming Schedule");
    upcomingHead->setStyleSheet("color: #111111; font-family: 'Inter'; font-weight: 700; font-size: 14px; margin-top: 10px; background: transparent;");
    m_sidebarLayout->addWidget(upcomingHead);
    
    // We will append actual upcoming events when renderMiniCalendar or refresh logic runs, 
    // for now we just add a stretch at the bottom of the sidebar
    m_sidebarLayout->addStretch();

    mainLayout->addWidget(m_calendarSidebar);
    mainLayout->addWidget(m_timelineScroll, 1);

    renderTimeline();
    renderMiniCalendar();
}

void MainWindow::renderTimeline()
{
    // Clear old timeline
    QLayoutItem *child;
    while ((child = m_timelineLayout->takeAt(0)) != nullptr) {
        if (child->widget()) { child->widget()->deleteLater(); }
        delete child;
    }

    // Update Week Range Label "Month D1 - D2, Year"
    QDate weekEnd = m_currentWeekStart.addDays(6);
    QString weekRangeStr;
    if (m_currentWeekStart.month() == weekEnd.month()) {
        weekRangeStr = QString("%1 %2 - %3, %4")
            .arg(m_currentWeekStart.toString("MMMM"))
            .arg(m_currentWeekStart.day())
            .arg(weekEnd.day())
            .arg(m_currentWeekStart.year());
    } else {
        weekRangeStr = QString("%1 %2 - %3 %4, %5")
            .arg(m_currentWeekStart.toString("MMM"))
            .arg(m_currentWeekStart.day())
            .arg(weekEnd.toString("MMM"))
            .arg(weekEnd.day())
            .arg(m_currentWeekStart.year());
    }
    
    QLabel *weekRangeLbl = ui->calendarPage->findChild<QLabel*>("calendarWeekRange");
    if (weekRangeLbl) {
        weekRangeLbl->setText(weekRangeStr);
    }

    // Constants for grid size
    const int hourHeight = 60;
    const int dayWidth = 140; // Base width, can expand
    const int totalHeight = 24 * hourHeight + 60; // Extra padding

    QWidget *gridContainer = new QWidget;
    gridContainer->setMinimumSize(7 * dayWidth + 60, totalHeight);
    gridContainer->setStyleSheet("background-color: transparent;");

    // We will place everything absolutely or using a custom layout approach.
    // For simplicity, absolute positioning inside the container works well for timeline grids.
    
    // 1. Draw Hour Lines and Labels
    for (int h = 0; h < 24; ++h) {
        int y = h * hourHeight + 60; // Offset by header height
        
        // Label
        QLabel *timeLabel = new QLabel(gridContainer);
        QString timeStr = h == 0 ? "12 AM" : QString("%1 %2").arg(h > 12 ? h - 12 : (h == 0 ? 12 : h)).arg(h >= 12 ? "PM" : "AM");
        timeLabel->setText(timeStr);
        timeLabel->setGeometry(0, y - 10, 50, 20);
        timeLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        timeLabel->setStyleSheet("font-family: 'Inter'; font-size: 11px; font-weight: 500; color: #6A7282; background: transparent; padding-right: 10px;");
        
        // Line
        QFrame *line = new QFrame(gridContainer);
        line->setGeometry(60, y, 7 * dayWidth, 1);
        line->setStyleSheet("background-color: rgba(0, 0, 0, 0.05); border: none;");
    }

    QDate today = QDate::currentDate();

    // 2. Draw Day Columns and Events
    for (int d = 0; d < 7; ++d) {
        QDate colDate = m_currentWeekStart.addDays(d);
        int x = 60 + d * dayWidth;
        
        // Header
        QLabel *dayName = new QLabel(gridContainer);
        dayName->setText(QString("%1 %2").arg(colDate.toString("ddd").toUpper()).arg(colDate.day()));
        dayName->setGeometry(x, 10, dayWidth, 40);
        dayName->setAlignment(Qt::AlignCenter);
        
        bool isToday = (colDate == today);
        if (isToday) {
            dayName->setStyleSheet("font-family: 'Inter'; font-size: 12px; font-weight: 700; color: #06B6A4; background: transparent;");
        } else {
            dayName->setStyleSheet("font-family: 'Inter'; font-size: 12px; font-weight: 600; color: #6A7282; background: transparent;");
        }

        // Draw Vertical Separator
        if (d > 0) {
            QFrame *vLine = new QFrame(gridContainer);
            vLine->setGeometry(x, 60, 1, totalHeight - 60);
            vLine->setStyleSheet("background-color: rgba(0, 0, 0, 0.03); border: none;");
        }

        // Render Events
        for (const auto &task : taskList) {
            if (task.completed) continue;
            
            if (colDate >= task.dueDate && colDate <= task.endDate) {
                // If the event spans multiple days
                bool isStartDay = (colDate == task.dueDate);
                bool isEndDay = (colDate == task.endDate);
                
                int startY = 60; // Default full day start
                if (isStartDay) {
                    startY = 60 + task.dueTime.hour() * hourHeight + (task.dueTime.minute() * hourHeight / 60);
                }
                
                int endY = totalHeight; // Default full day end
                if (isEndDay) {
                    endY = 60 + task.endTime.hour() * hourHeight + (task.endTime.minute() * hourHeight / 60);
                }
                
                int height = endY - startY;
                if (height <= 0) height = hourHeight; // Minimum 1 hour height if invalid
                
                QFrame *event = new QFrame(gridContainer);
                event->setGeometry(x + 2, startY, dayWidth - 4, height);
                
                // Colors based on project category
                QString bgColor, borderColor;
                if (task.project == "Project Work") { bgColor = "rgba(239, 68, 68, 0.12)"; borderColor = "#EF4444"; }
                else if (task.project == "Education") { bgColor = "rgba(16, 185, 129, 0.12)"; borderColor = "#10B981"; }
                else if (task.project == "Meeting") { bgColor = "rgba(245, 158, 11, 0.12)"; borderColor = "#F59E0B"; }
                else if (task.project == "Group Discussion") { bgColor = "rgba(139, 92, 246, 0.12)"; borderColor = "#8B5CF6"; }
                else { bgColor = "rgba(6, 182, 164, 0.12)"; borderColor = "#06B6A4"; }

                event->setStyleSheet(QString(
                    "QFrame {"
                    "   background-color: %1;"
                    "   border-left: 4px solid %2;"
                    "   border-radius: 8px;"
                    "}"
                ).arg(bgColor).arg(borderColor));
                applyShadow(event, 4, 0, 2, QColor(0, 0, 0, 10));
                
                QVBoxLayout *eLay = new QVBoxLayout(event);
                eLay->setContentsMargins(8, 6, 8, 6);
                eLay->setSpacing(2);
                
                QLabel *eTitle = new QLabel(task.title);
                eTitle->setStyleSheet("font-family: 'Inter'; font-weight: 700; font-size: 12px; color: #111111; background: transparent;");
                eTitle->setWordWrap(true);
                
                QLabel *eTime = new QLabel(QString("%1 - %2").arg(task.dueTime.toString("hh:mm")).arg(task.endTime.toString("hh:mm")));
                eTime->setStyleSheet("font-family: 'Inter'; font-size: 10px; font-weight: 500; color: #6A7282; background: transparent;");
                
                eLay->addWidget(eTitle);
                eLay->addWidget(eTime);
                eLay->addStretch();
            }
        }
    }

    // 3. Draw Current Time Indicator (if current week)
    if (today >= m_currentWeekStart && today <= m_currentWeekStart.addDays(6)) {
        QTime now = QTime::currentTime();
        int y = 60 + now.hour() * hourHeight + (now.minute() * hourHeight / 60);
        
        QFrame *timeLine = new QFrame(gridContainer);
        timeLine->setGeometry(50, y, 7 * dayWidth + 10, 2);
        timeLine->setStyleSheet("background-color: #06B6A4; border: none;");
        
        QFrame *timeDot = new QFrame(gridContainer);
        timeDot->setGeometry(46, y - 3, 8, 8);
        timeDot->setStyleSheet("background-color: #06B6A4; border-radius: 4px; border: none;");

        QLabel *timeText = new QLabel(gridContainer);
        timeText->setText(now.toString("hh:mm AP"));
        timeText->setGeometry(0, y - 10, 50, 20);
        timeText->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        timeText->setStyleSheet("font-family: 'Inter'; font-size: 10px; font-weight: 700; color: #06B6A4; background: transparent; padding-right: 5px;");
    }

    m_timelineLayout->addWidget(gridContainer);
    gridContainer->setMinimumWidth(60 + 7 * dayWidth);
}

void MainWindow::renderMiniCalendar()
{
    // Clear old mini grid
    QLayoutItem *child;
    while ((child = m_miniCalendarGrid->takeAt(0)) != nullptr) {
        if (child->widget()) { child->widget()->deleteLater(); }
        delete child;
    }

    QDate firstDate(m_currentYear, m_currentMonth, 1);
    QDate today = QDate::currentDate();
    
    // Update sidebar Month Label
    QLabel *monthLabel = m_calendarSidebar->findChild<QLabel*>("miniMonthLabel");
    if (monthLabel) monthLabel->setText(firstDate.toString("MMMM yyyy"));

    QStringList headers = {"S", "M", "T", "W", "T", "F", "S"};
    for (int i = 0; i < 7; ++i) {
        QLabel *label = new QLabel(headers[i]);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("font-family:'Inter'; font-weight:600; color:#70757A; font-size:10px; padding: 5px; background: transparent;");
        m_miniCalendarGrid->addWidget(label, 0, i);
    }

    int startDay = firstDate.dayOfWeek();
    if (startDay == 7) startDay = 0;
    
    int daysInMonth = firstDate.daysInMonth();

    for (int day = 1; day <= daysInMonth; ++day) {
        int r = (day + startDay - 1) / 7 + 1;
        int c = (day + startDay - 1) % 7;

        QPushButton *dayBtn = new QPushButton(QString::number(day));
        dayBtn->setFixedSize(28, 28);
        dayBtn->setCursor(Qt::PointingHandCursor);

        bool isSelected = (day == m_selectedDay);
        bool isCurrentMonth = (m_currentYear == today.year() && m_currentMonth == today.month());
        bool isToday = (isCurrentMonth && day == today.day());

        QString style = "QPushButton { border: none; font-family: 'Inter'; font-size: 11px; font-weight: 500; border-radius: 14px; ";
        if (isSelected) {
            style += "background-color: rgba(6, 182, 164, 0.15); color: #06B6A4; font-weight: 700;";
        } else if (isToday) {
            style += "background-color: #06B6A4; color: white; font-weight: 700;";
        } else {
            style += "color: #3C4043; background: transparent;";
        }
        style += " } QPushButton:hover { background-color: rgba(6, 182, 164, 0.08); }";
        dayBtn->setStyleSheet(style);

        connect(dayBtn, &QPushButton::clicked, this, [this, day]() {
            m_selectedDay = day;
            renderTimeline();
            renderMiniCalendar();
        });

        m_miniCalendarGrid->addWidget(dayBtn, r, c);
    }
}

QFrame* createPriorityHeader(const QString &priority, int taskCount, int projectCount) {
    QFrame *header = new QFrame;
    header->setFixedHeight(50);
    QHBoxLayout *lay = new QHBoxLayout(header);
    lay->setContentsMargins(0, 10, 0, 10);
    lay->setSpacing(12);

    QLabel *title = new QLabel(priority + " Priority");
    title->setStyleSheet("font-family: 'Inter'; font-weight: 800; font-size: 24px; color: #111111; background: transparent;");

    QLabel *stats = new QLabel(QString("%1 Tasks • %2 Projects").arg(taskCount).arg(projectCount));
    stats->setStyleSheet("font-family: 'Inter'; font-weight: 500; font-size: 14px; color: #9CA3AF; background: transparent; padding-top: 6px;");

    lay->addWidget(title);
    lay->addWidget(stats);
    lay->addStretch();

    return header;
}


void MainWindow::on_fabButton_clicked()
{
    auto *dlg = new AddTaskDialog(this);
    connect(dlg, &AddTaskDialog::taskCreated, this,
        [this](const QString &title, const QString &desc, const QString &priority, const QString &category, const QDate &startDate, const QDate &endDate, const QTime &time, const QTime &endTime) {
            Task t; 
            t.title = title; 
            t.description = desc;
            t.priority = priority;
            t.project = category;
            t.dueDate = startDate;
            t.endDate = endDate;
            t.dueTime = time;
            t.endTime = endTime;
            
            taskList.push_back(t);
            refreshTaskList();
            renderTimeline();
            ::update(ui);
        });
}

void MainWindow::on_addScheduleBtn_clicked()
{
    on_fabButton_clicked();
}

void MainWindow::createTaskListView()
{
    // Home Page Task List
    m_homeTaskScroll = new QScrollArea(ui->homePage);
    m_homeTaskScroll->setGeometry(48, 280, 1040, 750); // Adjusted geometry for Home
    m_homeTaskScroll->setWidgetResizable(true);
    m_homeTaskScroll->setFrameShape(QFrame::NoFrame);
    m_homeTaskScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_homeTaskScroll->setStyleSheet("QScrollArea{background:transparent;}");

    m_homeTaskContainer = new QWidget;
    m_homeTaskContainer->setObjectName("homeTaskContainer");
    m_homeTaskContainer->setStyleSheet("background:transparent;");
    m_homeTaskLayout = new QVBoxLayout(m_homeTaskContainer);
    m_homeTaskLayout->setContentsMargins(0, 0, 12, 0);
    m_homeTaskLayout->setSpacing(12);
    m_homeTaskScroll->setWidget(m_homeTaskContainer);

    // Tasks Page Task List
    m_tasksTaskScroll = new QScrollArea(ui->tasksPage);
    m_tasksTaskScroll->setGeometry(109, 220, 1150, 740); // Adjusted geometry for Tasks Page
    m_tasksTaskScroll->setWidgetResizable(true);
    m_tasksTaskScroll->setFrameShape(QFrame::NoFrame);
    m_tasksTaskScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_tasksTaskScroll->setStyleSheet("QScrollArea{background:transparent;}");

    m_tasksTaskContainer = new QWidget;
    m_tasksTaskContainer->setObjectName("tasksTaskContainer");
    m_tasksTaskContainer->setStyleSheet("background:transparent;");
    m_tasksTaskLayout = new QVBoxLayout(m_tasksTaskContainer);
    m_tasksTaskLayout->setContentsMargins(0, 0, 12, 0);
    m_tasksTaskLayout->setSpacing(12);
    m_tasksTaskScroll->setWidget(m_tasksTaskContainer);
}

void MainWindow::refreshTaskList()
{
    auto clearLayout = [](QVBoxLayout *layout) {
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr) {
            if (child->widget()) { child->widget()->deleteLater(); }
            delete child;
        }
    };

    clearLayout(m_homeTaskLayout);
    clearLayout(m_tasksTaskLayout);

    QDate today = QDate::currentDate();
    QStringList priorities = {"High", "Medium", "Low"};
    bool hasTasks = false;
    
    for (const QString &p : priorities) {
        vector<int> indices;
        set<QString> projects;
        
        for (int i = 0; i < (int)taskList.size(); i++) {
            const Task &t = taskList[i];
            
            // 1. Search Filter
            if (!m_searchQuery.isEmpty() && !t.title.contains(m_searchQuery, Qt::CaseInsensitive)) {
                continue;
            }
            
            // 2. Category Filter
            if (m_currentFilter == "Overdue" && t.dueDate >= today) {
                continue;
            }
            if (m_currentFilter == "High Priority" && t.priority != "High") {
                continue;
            }
            
            // 3. Priority Grouping (for rendering)
            if (t.priority == p) {
                indices.push_back(i);
                projects.insert(t.project);
            }
        }

        if (!indices.empty()) {
            hasTasks = true;
            m_homeTaskLayout->addWidget(createPriorityHeader(p, indices.size(), projects.size()));
            m_tasksTaskLayout->addWidget(createPriorityHeader(p, indices.size(), projects.size()));
            
            for (int idx : indices) {
                m_homeTaskLayout->addWidget(createTaskItem(idx));
                m_tasksTaskLayout->addWidget(createTaskItem(idx));
            }
            m_homeTaskLayout->addSpacing(10);
            m_tasksTaskLayout->addSpacing(10);
        }
    }

    if (!hasTasks) {
        m_homeTaskLayout->addWidget(createEmptyStateWidget());
        m_tasksTaskLayout->addWidget(createEmptyStateWidget());
    }
    
    m_homeTaskLayout->addStretch();
    m_tasksTaskLayout->addStretch();
    
    intializeCardsData();
    intializeCardsView(ui);
}

QWidget* MainWindow::createEmptyStateWidget()
{
    QWidget *w = new QWidget();
    QVBoxLayout *lay = new QVBoxLayout(w);
    lay->setContentsMargins(0, 40, 0, 40);
    lay->setAlignment(Qt::AlignCenter);
    
    QLabel *icon = new QLabel("📋");
    icon->setStyleSheet("font-size: 64px; background: transparent; color: #064E3B;");
    icon->setAlignment(Qt::AlignCenter);
    
    QLabel *text = new QLabel("No tasks found");
    text->setStyleSheet("font-family: 'Inter'; font-size: 20px; font-weight: 700; color: #374151; background: transparent; margin-top: 10px;");
    text->setAlignment(Qt::AlignCenter);
    
    QLabel *subtext = new QLabel("Try adjusting your filters or create a new task!");
    subtext->setStyleSheet("font-family: 'Inter'; font-size: 14px; font-weight: 500; color: #6B7280; background: transparent;");
    subtext->setAlignment(Qt::AlignCenter);
    
    lay->addWidget(icon);
    lay->addWidget(text);
    lay->addWidget(subtext);
    
    return w;
}

QFrame* MainWindow::createTaskItem(int idx)
{
    const Task &task = taskList[idx];
    QFrame *frame = new QFrame;
    frame->setFixedHeight(90);
    frame->setObjectName("taskItemCard");
    frame->setStyleSheet(R"(
        QFrame#taskItemCard {
            background: white;
            border: 1px solid rgba(0, 0, 0, 0.08);
            border-radius: 16px;
        }
        QFrame#taskItemCard:hover {
            border: 1px solid rgba(6, 182, 164, 0.3);
            background: #FAFAFA;
        }
    )");

    QHBoxLayout *mainLay = new QHBoxLayout(frame);
    mainLay->setContentsMargins(20, 15, 20, 15);
    mainLay->setSpacing(16);

    // Checkbox
    QPushButton *chk = new QPushButton(task.completed ? QString::fromUtf8("\u2714") : ""); 
    chk->setFixedSize(28, 28);
    chk->setCursor(Qt::PointingHandCursor);
    QString chkStyle = task.completed
        ? "background-color: #06B6A4; color: white; border: none;"
        : "background-color: transparent; border: 2px solid rgba(0, 0, 0, 0.1);";
    chk->setStyleSheet(QString("QPushButton { %1 border-radius: 8px; font-size: 14px; }").arg(chkStyle));

    // Title & Project
    QVBoxLayout *infoLay = new QVBoxLayout();
    infoLay->setSpacing(4);
    
    QLabel *title = new QLabel(task.title);
    title->setStyleSheet(task.completed 
        ? "font-family: 'Inter'; font-size: 18px; font-weight: 700; color: #9CA3AF; text-decoration: line-through; background: transparent;"
        : "font-family: 'Inter'; font-size: 18px; font-weight: 700; color: #111111; background: transparent;");
    
    QLabel *description = new QLabel(task.description.isEmpty() ? "No description provided" : task.description);
    description->setStyleSheet("font-family: 'Inter'; font-size: 14px; font-weight: 500; color: #6B7280; background: transparent;");
    description->setWordWrap(false);
    
    infoLay->addWidget(title);
    infoLay->addWidget(description);

    // Due Date Label
    int daysDiff = QDate::currentDate().daysTo(task.dueDate);
    QString dateStyle = "font-family: 'Inter'; font-size: 13px; font-weight: 700; padding: 6px 12px; border-radius: 8px; ";
    if (daysDiff < 0) dateStyle += "color: #EF4444; background: rgba(239, 68, 68, 0.1);";
    else if (daysDiff <= 2) dateStyle += "color: #F59E0B; background: rgba(245, 158, 11, 0.1);";
    else dateStyle += "color: #06B6A4; background: rgba(6, 182, 164, 0.1);";
    
    QLabel *dateLabel = new QLabel(task.dueDate.toString("MMM d"));
    dateLabel->setStyleSheet(dateStyle);
    
    // Deletion Button (Material Design circular red-brown)
    QPushButton *deleteBtn = new QPushButton("✕");
    deleteBtn->setFixedSize(32, 32);
    deleteBtn->setCursor(Qt::PointingHandCursor);
    deleteBtn->setStyleSheet(R"(
        QPushButton {
            background-color: rgba(185, 28, 28, 0.15);
            color: #991B1B;
            border: none;
            border-radius: 16px;
            font-size: 16px;
            font-weight: 900;
        }
        QPushButton:hover {
            background-color: rgba(185, 28, 28, 0.25);
            color: #7F1D1D;
        }
        QPushButton:pressed {
            background-color: rgba(185, 28, 28, 0.35);
        }
    )");
    
    deleteBtn->setVisible(task.completed);

    connect(deleteBtn, &QPushButton::clicked, this, [this, idx]() {
        if (idx >= 0 && idx < (int)taskList.size()) {
            taskList.erase(taskList.begin() + idx);
            refreshTaskList();
            ::update(ui);
        }
    });

    mainLay->addWidget(chk);
    mainLay->addLayout(infoLay, 1);
    mainLay->addWidget(dateLabel);
    mainLay->addSpacing(8);
    mainLay->addWidget(deleteBtn);

    connect(chk, &QPushButton::clicked, this, [this, idx]() {
        taskList[idx].completed = !taskList[idx].completed;
        refreshTaskList();
    });

    applyShadow(frame, 10, 0, 4, QColor(0, 0, 0, 15));
    return frame;
}

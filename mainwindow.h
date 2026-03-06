#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QScrollArea;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QFrame;

#include <QDate>

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
    void on_calBtnNext_clicked();
    void on_calBtnPrev_clicked();
    void on_fabButton_clicked();
    void on_addScheduleBtn_clicked();
    void onSearchTextChanged(const QString &text);

private:
    void createTaskListView();
    void refreshTaskList();
    QFrame* createTaskItem(int index);
    QWidget* createEmptyStateWidget();

    // Calendar / Timeline
    void initializeCalendarView();
    void renderTimeline();
    void renderMiniCalendar();
    void onDayClicked(int day);

    Ui::MainWindow *ui;
    QScrollArea    *m_homeTaskScroll;
    QWidget        *m_homeTaskContainer;
    QVBoxLayout    *m_homeTaskLayout;

    QScrollArea    *m_tasksTaskScroll;
    QWidget        *m_tasksTaskContainer;
    QVBoxLayout    *m_tasksTaskLayout;
    
    // Calendar/Timeline state
    int m_currentYear;
    int m_currentMonth;
    int m_selectedDay;
    QDate m_currentWeekStart;
    
    QWidget *m_timelineContent;
    QHBoxLayout *m_timelineLayout;
    QScrollArea *m_timelineScroll;
    
    QWidget *m_calendarSidebar;
    QVBoxLayout *m_sidebarLayout;
    QGridLayout *m_miniCalendarGrid;

    QString m_currentFilter;
    QString m_searchQuery;
};
#endif // MAINWINDOW_H

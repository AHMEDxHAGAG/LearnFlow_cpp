/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QFrame *sidebar;
    QLabel *sidebarCheckIcon;
    QPushButton *navHome;
    QPushButton *navTasks;
    QPushButton *navCalendar;
    QPushButton *settingsButton;
    QStackedWidget *contentStack;
    QWidget *homePage;
    QLabel *homeBackground;
    QLabel *homeFadeOverlay;
    QLabel *profileImage;
    QLabel *greetingHello;
    QLabel *greetingName;
    QLabel *mindLabel;
    QLineEdit *taskInput;
    QPushButton *addButton;
    QLabel *tasksHeading;
    QFrame *cardTotalTasks;
    QLabel *labelTotalTasks;
    QLabel *valueTotalTasks;
    QFrame *iconContainerBlue;
    QLabel *iconTotalTasks;
    QFrame *cardInProgress;
    QLabel *labelInProgress;
    QLabel *valueInProgress;
    QFrame *iconContainerOrange;
    QLabel *iconInProgress;
    QFrame *cardProductivity;
    QLabel *labelProductivity;
    QLabel *valueProductivity;
    QFrame *iconContainerPurple;
    QLabel *iconProductivity;
    QFrame *cardCompleted;
    QLabel *labelCompleted;
    QLabel *valueCompleted;
    QFrame *iconContainerGreen;
    QLabel *iconCompleted;
    QWidget *tasksPage;
    QLabel *tasksBackground;
    QLabel *tasksFadeOverlay;
    QLineEdit *tasksSearchBar;
    QLabel *tasksSearchIcon;
    QPushButton *filterAll;
    QPushButton *filterOverdue;
    QPushButton *filterHighPriority;
    QWidget *calendarPage;
    QLabel *calendarBackground;
    QLabel *calendarFadeOverlay;
    QLabel *calendarPageTitle;
    QLabel *calendarDate;
    QWidget *layoutWidget;
    QHBoxLayout *dayPickerRow_2;
    QPushButton *calBtnPrev;
    QHBoxLayout *dayCardsLayout_2;
    QFrame *dayCardY;
    QVBoxLayout *dayCardYL;
    QLabel *dayLabelY;
    QLabel *dayNumY;
    QFrame *dayCard0;
    QVBoxLayout *dayCard0L;
    QLabel *dayLabel0;
    QLabel *dayNum0;
    QFrame *dayCard1;
    QVBoxLayout *dayCard1L;
    QLabel *dayLabel1;
    QLabel *dayNum1;
    QFrame *dayCard2;
    QVBoxLayout *dayCard2L;
    QLabel *dayLabel2;
    QLabel *dayNum2;
    QFrame *dayCard3;
    QVBoxLayout *dayCard3L;
    QLabel *dayLabel3;
    QLabel *dayNum3;
    QFrame *dayCard4;
    QVBoxLayout *dayCard4L;
    QLabel *dayLabel4;
    QLabel *dayNum4;
    QFrame *dayCard5;
    QVBoxLayout *dayCard5L;
    QLabel *dayLabel5;
    QLabel *dayNum5;
    QPushButton *calBtnNext;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1440, 1024);
        MainWindow->setMinimumSize(QSize(1440, 1024));
        MainWindow->setMaximumSize(QSize(1440, 1024));
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QWidget#MainWindow {\n"
"  background-color: #EAF7F6;\n"
"}\n"
"\n"
"QFrame#sidebar {\n"
"  background-color: #EAF7F6;\n"
"  border-right: 1px solid rgba(0, 0, 0, 0.08);\n"
"}\n"
"\n"
"QLabel#sidebarCheckIcon {\n"
"  color: #06B6A4;\n"
"  font-size: 20px;\n"
"}\n"
"\n"
"QPushButton#navHome {\n"
"  border: none;\n"
"  background: transparent;\n"
"  border-image: url(:/home.png) 0 0 0 0 stretch stretch;\n"
"  min-height: 142px;\n"
"  max-width: 53px;\n"
"}\n"
"\n"
"QPushButton#navHome:hover {\n"
"  opacity: 0.9;\n"
"}\n"
"\n"
"QPushButton#navTasks {\n"
"  border: none;\n"
"  background: transparent;\n"
"  border-image: url(:/nottasks.png) 0 0 0 0 stretch stretch;\n"
"  min-height: 144px;\n"
"  max-width: 53px;\n"
"}\n"
"\n"
"QPushButton#navCalendar {\n"
"  border: none;\n"
"  background: transparent;\n"
"  border-image: url(:/notcalendar.png) 0 0 0 0 stretch stretch;\n"
"  min-height: 170px;\n"
"  max-width: 53px;\n"
"}\n"
"\n"
"QPushButton#navTasks:hover,\n"
"QPushButton#navCalendar:hover {\n"
"  opacity: "
                        "0.9;\n"
"}\n"
"\n"
"QPushButton#settingsButton {\n"
"  background-color: transparent;\n"
"  border: none;\n"
"  padding: 4px;\n"
"}\n"
"\n"
"QPushButton#settingsButton:hover {\n"
"  background-color: rgba(6, 95, 86, 0.1);\n"
"  border-radius: 8px;\n"
"}\n"
"\n"
"QLabel#profileImage {\n"
"  border-radius: 38px;\n"
"  background-color: #cccccc;\n"
"}\n"
"\n"
"QLabel#greetingHello {\n"
"  font-family: 'Roboto Flex';\n"
"  font-weight: 900;\n"
"  font-size: 80px;\n"
"  color: #111111;\n"
"}\n"
"\n"
"QLabel#greetingName {\n"
"  font-family: 'Patrick Hand';\n"
"  font-weight: 400;\n"
"  font-size: 55px;\n"
"  color: #111111;\n"
"}\n"
"\n"
"QLabel#mindLabel {\n"
"  font-family: 'Roboto Flex';\n"
"  font-weight: 900;\n"
"  font-size: 36px;\n"
"  color: #111111;\n"
"}\n"
"\n"
"QLineEdit#taskInput {\n"
"  background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(255,255,255,0.88),\n"
"    stop:1 rgba(255,255,255,0.58));\n"
"  border: 2px solid rgba(255,255,255,0.95);\n"
"  border-top-color: rgba(255,255,25"
                        "5,1.0);\n"
"  border-left-color: rgba(255,255,255,0.98);\n"
"  border-bottom-color: rgba(200,210,208,0.45);\n"
"  border-right-color: rgba(200,210,208,0.35);\n"
"  border-radius: 31px;\n"
"  padding: 0px 24px;\n"
"  font-family: 'Inter';\n"
"  font-size: 20px;\n"
"  color: #374151;\n"
"  font-weight: 600;\n"
"  min-height: 62px;\n"
"  selection-background-color: #06B6A4;\n"
"  selection-color: white;\n"
"}\n"
"\n"
"QLineEdit#taskInput:hover {\n"
"  background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(255,255,255,0.94),\n"
"    stop:1 rgba(255,255,255,0.68));\n"
"  border: 2px solid rgba(255,255,255,1.0);\n"
"  border-bottom-color: rgba(200,210,208,0.50);\n"
"}\n"
"\n"
"QLineEdit#taskInput:focus {\n"
"  background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(255,255,255,0.96),\n"
"    stop:1 rgba(255,255,255,0.72));\n"
"  border: 2px solid rgba(6, 182, 164, 0.45);\n"
"  border-top-color: rgba(6, 182, 164, 0.55);\n"
"}\n"
"\n"
"QPushButton#addButton {\n"
"  background-color: #0"
                        "6B6A4;\n"
"  color: white;\n"
"  border: none;\n"
"  border-radius: 31px;\n"
"  font-family: 'Manrope';\n"
"  font-weight: 800;\n"
"  font-size: 30px;\n"
"  min-width: 170px;\n"
"  min-height: 62px;\n"
"  padding: 0px 24px;\n"
"}\n"
"\n"
"QPushButton#addButton:hover {\n"
"  background-color: #059E8E;\n"
"}\n"
"\n"
"QPushButton#addButton:pressed {\n"
"  background-color: #048A7C;\n"
"}\n"
"\n"
"QLabel#questionMark {\n"
"  font-family: 'Pecita';\n"
"  font-size: 64px;\n"
"  color: #06B6A4;\n"
"}\n"
"\n"
"QLabel#tasksHeading {\n"
"  font-family: 'Roboto Flex';\n"
"  font-weight: 900;\n"
"  font-size: 70px;\n"
"  color: #065F56;\n"
"}\n"
"\n"
"QFrame#cardTotalTasks,\n"
"QFrame#cardInProgress,\n"
"QFrame#cardProductivity,\n"
"QFrame#cardCompleted {\n"
"  background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(255,255,255,0.92),\n"
"    stop:0.5 rgba(255,255,255,0.78),\n"
"    stop:1 rgba(245,248,247,0.60));\n"
"  border: 2px solid rgba(255,255,255,0.96);\n"
"  border-top-color: rgba(255,255,255,1.0)"
                        ";\n"
"  border-left-color: rgba(255,255,255,0.98);\n"
"  border-bottom-color: rgba(200,210,208,0.40);\n"
"  border-right-color: rgba(200,210,208,0.30);\n"
"  border-radius: 22px;\n"
"}\n"
"\n"
"QFrame#cardTotalTasks:hover,\n"
"QFrame#cardInProgress:hover,\n"
"QFrame#cardProductivity:hover,\n"
"QFrame#cardCompleted:hover {\n"
"  background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(255,255,255,0.98),\n"
"    stop:0.5 rgba(255,255,255,0.88),\n"
"    stop:1 rgba(250,252,251,0.72));\n"
"  border: 2px solid rgba(255,255,255,1.0);\n"
"  border-bottom-color: rgba(200,210,208,0.45);\n"
"}\n"
"\n"
"QLabel#labelTotalTasks,\n"
"QLabel#labelInProgress,\n"
"QLabel#labelProductivity,\n"
"QLabel#labelCompleted {\n"
"  font-family: 'Inter';\n"
"  font-weight: 400;\n"
"  font-size: 14px;\n"
"  color: #6A7282;\n"
"  background: transparent;\n"
"}\n"
"\n"
"QLabel#valueTotalTasks,\n"
"QLabel#valueInProgress,\n"
"QLabel#valueProductivity,\n"
"QLabel#valueCompleted {\n"
"  font-family: 'Inter';\n"
"  font-weight: "
                        "900;\n"
"  font-size: 36px;\n"
"  color: #111111;\n"
"  background: transparent;\n"
"}\n"
"\n"
"QFrame#iconContainerBlue {\n"
"  background-color: #DBEAFE;\n"
"  border-radius: 14px;\n"
"  min-width: 48px;\n"
"  min-height: 48px;\n"
"  max-width: 48px;\n"
"  max-height: 48px;\n"
"}\n"
"\n"
"QFrame#iconContainerOrange {\n"
"  background-color: #FFEDD4;\n"
"  border-radius: 14px;\n"
"  min-width: 48px;\n"
"  min-height: 48px;\n"
"  max-width: 48px;\n"
"  max-height: 48px;\n"
"}\n"
"\n"
"QFrame#iconContainerPurple {\n"
"  background-color: #F3E8FF;\n"
"  border-radius: 14px;\n"
"  min-width: 48px;\n"
"  min-height: 48px;\n"
"  max-width: 48px;\n"
"  max-height: 48px;\n"
"}\n"
"\n"
"QFrame#iconContainerGreen {\n"
"  background-color: #DCFCE7;\n"
"  border-radius: 14px;\n"
"  min-width: 48px;\n"
"  min-height: 48px;\n"
"  max-width: 48px;\n"
"  max-height: 48px;\n"
"}\n"
"\n"
"QLabel#iconTotalTasks {\n"
"  color: #155DFC;\n"
"  font-weight: 900;\n"
"  font-size: 24px;\n"
"  background: transparent;\n"
"}\n"
"\n"
"Q"
                        "Label#iconInProgress {\n"
"  color: #F54900;\n"
"  font-weight: 900;\n"
"  font-size: 24px;\n"
"  background: transparent;\n"
"}\n"
"\n"
"QLabel#iconProductivity {\n"
"  color: #9810FA;\n"
"  font-weight: 900;\n"
"  font-size: 24px;\n"
"  background: transparent;\n"
"}\n"
"\n"
"QLabel#iconCompleted {\n"
"  color: #00A63E;\n"
"  font-weight: 900;\n"
"  font-size: 24px;\n"
"  background: transparent;\n"
"}\n"
"\n"
"QStackedWidget#contentStack {\n"
"  background: transparent;\n"
"}\n"
"\n"
"QWidget#homePage,\n"
"QWidget#tasksPage,\n"
"QWidget#calendarPage {\n"
"  background: transparent;\n"
"}\n"
"\n"
"QLabel#tasksPageTitle,\n"
"QLabel#calendarPageTitle {\n"
"  font-family: 'Roboto Flex';\n"
"  font-weight: 900;\n"
"  font-size: 70px;\n"
"  color: #065F56;\n"
"}\n"
"\n"
"QLabel#calendarDate {\n"
"  font-family: 'Inter';\n"
"  font-weight: 500;\n"
"  font-size: 60px;\n"
"  color: #7b8185;\n"
"}\n"
"\n"
"QLabel#homeBackground,\n"
"QLabel#tasksBackground,\n"
"QLabel#calendarBackground {\n"
"  background-image: url(:"
                        "/BackgroundPattern.png);\n"
"  background-repeat: repeat;\n"
"}\n"
"\n"
"QLabel#homeFadeOverlay,\n"
"QLabel#tasksFadeOverlay,\n"
"QLabel#calendarFadeOverlay {\n"
"  background-color: rgba(234, 247, 246, 230);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"  background: transparent;\n"
"  width: 8px;\n"
"  margin: 0;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"  background: rgba(6, 95, 86, 0.3);\n"
"  border-radius: 4px;\n"
"  min-height: 30px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"  background: rgba(6, 95, 86, 0.5);\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"  height: 0;\n"
"}\n"
"   \n"
"/* Tasks Page */\n"
"QLineEdit#tasksSearchBar {\n"
"  background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(255,255,255,0.88),\n"
"    stop:1 rgba(255,255,255,0.58));\n"
"  border: 2px solid rgba(255,255,255,0.95);\n"
"  border-top-color: rgba(255,255,255,1.0);\n"
"  border-left-color: rgba(255,255,255,0.98);\n"
"  border-bottom-color: rgba(200,210,2"
                        "08,0.45);\n"
"  border-right-color: rgba(200,210,208,0.35);\n"
"  border-radius: 30px;\n"
"  padding: 0px 24px 0px 56px;\n"
"  font-family: 'Inter';\n"
"  font-size: 18px;\n"
"  color: #374151;\n"
"  min-height: 60px;\n"
"  selection-background-color: #06B6A4;\n"
"  selection-color: white;\n"
"}\n"
"QLineEdit#tasksSearchBar:hover {\n"
"  background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(255,255,255,0.94),\n"
"    stop:1 rgba(255,255,255,0.68));\n"
"  border: 2px solid rgba(255,255,255,1.0);\n"
"  border-bottom-color: rgba(200,210,208,0.50);\n"
"}\n"
"QLineEdit#tasksSearchBar:focus {\n"
"  background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(255,255,255,0.96),\n"
"    stop:1 rgba(255,255,255,0.72));\n"
"  border: 2px solid rgba(6, 182, 164, 0.45);\n"
"  border-top-color: rgba(6, 182, 164, 0.55);\n"
"}\n"
"QLabel#tasksSearchIcon {\n"
"  background: transparent;\n"
"}\n"
"QPushButton#filterAll {\n"
"  background-color: #06B6A4;\n"
"  border: none;\n"
"  border-radius: 28px"
                        ";\n"
"  color: white;\n"
"  font-family: 'Inter';\n"
"  font-size: 18px;\n"
"  font-weight: 700;\n"
"  padding: 6px 20px;\n"
"  min-height: 20px;\n"
"}\n"
"QPushButton#filterAll:hover {\n"
"  background-color: #059E8E;\n"
"}\n"
"QPushButton#filterOverdue, QPushButton#filterHighPriority {\n"
"  background-color: transparent;\n"
"  border: 1px solid #065F56;\n"
"  border-radius: 28px;\n"
"  color: #065F56;\n"
"  font-family: 'Inter';\n"
"  font-size: 18px;\n"
"  font-weight: 600;\n"
"  padding: 6px 20px;\n"
"  min-height: 20px;\n"
"}\n"
"QPushButton#filterOverdue:hover, QPushButton#filterHighPriority:hover {\n"
"  background-color: rgba(6, 182, 164, 0.1);\n"
"}\n"
"/* Calendar Arrows */\n"
"QPushButton#calBtnPrev, QPushButton#calBtnNext {\n"
"  border: none;\n"
"  background-color: transparent;\n"
"  border-radius: 28px;\n"
"}\n"
"QPushButton#calBtnPrev:hover, QPushButton#calBtnNext:hover {\n"
"  background-color: rgba(6, 182, 164, 0.12);\n"
"}\n"
""));
        sidebar = new QFrame(MainWindow);
        sidebar->setObjectName("sidebar");
        sidebar->setGeometry(QRect(0, 0, 72, 1024));
        sidebar->setFrameShape(QFrame::Shape::NoFrame);
        sidebarCheckIcon = new QLabel(sidebar);
        sidebarCheckIcon->setObjectName("sidebarCheckIcon");
        sidebarCheckIcon->setGeometry(QRect(16, 24, 40, 40));
        sidebarCheckIcon->setPixmap(QPixmap(QString::fromUtf8(":/sidebarTopCheck.png")));
        sidebarCheckIcon->setScaledContents(true);
        sidebarCheckIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);
        navHome = new QPushButton(sidebar);
        navHome->setObjectName("navHome");
        navHome->setGeometry(QRect(10, 96, 53, 142));
        navTasks = new QPushButton(sidebar);
        navTasks->setObjectName("navTasks");
        navTasks->setGeometry(QRect(10, 267, 53, 144));
        navCalendar = new QPushButton(sidebar);
        navCalendar->setObjectName("navCalendar");
        navCalendar->setGeometry(QRect(10, 438, 53, 170));
        settingsButton = new QPushButton(sidebar);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setGeometry(QRect(16, 966, 40, 40));
        settingsButton->setFlat(true);
        contentStack = new QStackedWidget(MainWindow);
        contentStack->setObjectName("contentStack");
        contentStack->setGeometry(QRect(72, 0, 1368, 1024));
        homePage = new QWidget();
        homePage->setObjectName("homePage");
        homeBackground = new QLabel(homePage);
        homeBackground->setObjectName("homeBackground");
        homeBackground->setGeometry(QRect(0, 0, 1368, 1024));
        homeFadeOverlay = new QLabel(homePage);
        homeFadeOverlay->setObjectName("homeFadeOverlay");
        homeFadeOverlay->setGeometry(QRect(0, 0, 1368, 1024));
        profileImage = new QLabel(homePage);
        profileImage->setObjectName("profileImage");
        profileImage->setGeometry(QRect(48, 68, 76, 76));
        profileImage->setPixmap(QPixmap(QString::fromUtf8(":/profileImage.png")));
        profileImage->setScaledContents(true);
        greetingHello = new QLabel(homePage);
        greetingHello->setObjectName("greetingHello");
        greetingHello->setGeometry(QRect(138, 56, 260, 90));
        greetingHello->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        greetingName = new QLabel(homePage);
        greetingName->setObjectName("greetingName");
        greetingName->setGeometry(QRect(360, 60, 400, 90));
        greetingName->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        mindLabel = new QLabel(homePage);
        mindLabel->setObjectName("mindLabel");
        mindLabel->setGeometry(QRect(48, 171, 600, 50));
        mindLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        taskInput = new QLineEdit(homePage);
        taskInput->setObjectName("taskInput");
        taskInput->setGeometry(QRect(48, 245, 581, 66));
        addButton = new QPushButton(homePage);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(640, 244, 218, 64));
        addButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        tasksHeading = new QLabel(homePage);
        tasksHeading->setObjectName("tasksHeading");
        tasksHeading->setGeometry(QRect(48, 346, 446, 112));
        tasksHeading->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        cardTotalTasks = new QFrame(homePage);
        cardTotalTasks->setObjectName("cardTotalTasks");
        cardTotalTasks->setGeometry(QRect(1108, 370, 200, 100));
        cardTotalTasks->setFrameShape(QFrame::Shape::NoFrame);
        labelTotalTasks = new QLabel(cardTotalTasks);
        labelTotalTasks->setObjectName("labelTotalTasks");
        labelTotalTasks->setGeometry(QRect(24, 24, 100, 20));
        valueTotalTasks = new QLabel(cardTotalTasks);
        valueTotalTasks->setObjectName("valueTotalTasks");
        valueTotalTasks->setGeometry(QRect(24, 52, 80, 36));
        iconContainerBlue = new QFrame(cardTotalTasks);
        iconContainerBlue->setObjectName("iconContainerBlue");
        iconContainerBlue->setGeometry(QRect(140, 24, 48, 48));
        iconContainerBlue->setFrameShape(QFrame::Shape::NoFrame);
        iconTotalTasks = new QLabel(iconContainerBlue);
        iconTotalTasks->setObjectName("iconTotalTasks");
        iconTotalTasks->setGeometry(QRect(12, 12, 24, 24));
        iconTotalTasks->setAlignment(Qt::AlignmentFlag::AlignCenter);
        cardInProgress = new QFrame(homePage);
        cardInProgress->setObjectName("cardInProgress");
        cardInProgress->setGeometry(QRect(1108, 490, 200, 100));
        cardInProgress->setFrameShape(QFrame::Shape::NoFrame);
        labelInProgress = new QLabel(cardInProgress);
        labelInProgress->setObjectName("labelInProgress");
        labelInProgress->setGeometry(QRect(24, 24, 100, 20));
        valueInProgress = new QLabel(cardInProgress);
        valueInProgress->setObjectName("valueInProgress");
        valueInProgress->setGeometry(QRect(24, 52, 80, 36));
        iconContainerOrange = new QFrame(cardInProgress);
        iconContainerOrange->setObjectName("iconContainerOrange");
        iconContainerOrange->setGeometry(QRect(140, 24, 48, 48));
        iconContainerOrange->setFrameShape(QFrame::Shape::NoFrame);
        iconInProgress = new QLabel(iconContainerOrange);
        iconInProgress->setObjectName("iconInProgress");
        iconInProgress->setGeometry(QRect(12, 12, 24, 24));
        iconInProgress->setAlignment(Qt::AlignmentFlag::AlignCenter);
        cardProductivity = new QFrame(homePage);
        cardProductivity->setObjectName("cardProductivity");
        cardProductivity->setGeometry(QRect(1108, 610, 200, 100));
        cardProductivity->setFrameShape(QFrame::Shape::NoFrame);
        labelProductivity = new QLabel(cardProductivity);
        labelProductivity->setObjectName("labelProductivity");
        labelProductivity->setGeometry(QRect(24, 24, 100, 20));
        valueProductivity = new QLabel(cardProductivity);
        valueProductivity->setObjectName("valueProductivity");
        valueProductivity->setGeometry(QRect(24, 52, 80, 36));
        iconContainerPurple = new QFrame(cardProductivity);
        iconContainerPurple->setObjectName("iconContainerPurple");
        iconContainerPurple->setGeometry(QRect(140, 24, 48, 48));
        iconContainerPurple->setFrameShape(QFrame::Shape::NoFrame);
        iconProductivity = new QLabel(iconContainerPurple);
        iconProductivity->setObjectName("iconProductivity");
        iconProductivity->setGeometry(QRect(12, 12, 24, 24));
        iconProductivity->setAlignment(Qt::AlignmentFlag::AlignCenter);
        cardCompleted = new QFrame(homePage);
        cardCompleted->setObjectName("cardCompleted");
        cardCompleted->setGeometry(QRect(1108, 730, 200, 100));
        cardCompleted->setFrameShape(QFrame::Shape::NoFrame);
        labelCompleted = new QLabel(cardCompleted);
        labelCompleted->setObjectName("labelCompleted");
        labelCompleted->setGeometry(QRect(24, 24, 100, 20));
        valueCompleted = new QLabel(cardCompleted);
        valueCompleted->setObjectName("valueCompleted");
        valueCompleted->setGeometry(QRect(24, 52, 80, 36));
        iconContainerGreen = new QFrame(cardCompleted);
        iconContainerGreen->setObjectName("iconContainerGreen");
        iconContainerGreen->setGeometry(QRect(140, 24, 48, 48));
        iconContainerGreen->setFrameShape(QFrame::Shape::NoFrame);
        iconCompleted = new QLabel(iconContainerGreen);
        iconCompleted->setObjectName("iconCompleted");
        iconCompleted->setGeometry(QRect(12, 12, 24, 24));
        iconCompleted->setAlignment(Qt::AlignmentFlag::AlignCenter);
        contentStack->addWidget(homePage);
        tasksPage = new QWidget();
        tasksPage->setObjectName("tasksPage");
        tasksBackground = new QLabel(tasksPage);
        tasksBackground->setObjectName("tasksBackground");
        tasksBackground->setGeometry(QRect(0, 0, 1368, 1024));
        tasksFadeOverlay = new QLabel(tasksPage);
        tasksFadeOverlay->setObjectName("tasksFadeOverlay");
        tasksFadeOverlay->setGeometry(QRect(0, 0, 1368, 1024));
        tasksSearchBar = new QLineEdit(tasksPage);
        tasksSearchBar->setObjectName("tasksSearchBar");
        tasksSearchBar->setGeometry(QRect(109, 56, 1150, 64));
        tasksSearchIcon = new QLabel(tasksPage);
        tasksSearchIcon->setObjectName("tasksSearchIcon");
        tasksSearchIcon->setGeometry(QRect(134, 72, 28, 28));
        tasksSearchIcon->setPixmap(QPixmap(QString::fromUtf8(":/search.png")));
        tasksSearchIcon->setScaledContents(true);
        tasksSearchIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);
        filterAll = new QPushButton(tasksPage);
        filterAll->setObjectName("filterAll");
        filterAll->setGeometry(QRect(109, 144, 90, 58));
        filterAll->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        filterAll->setCheckable(true);
        filterAll->setChecked(true);
        filterOverdue = new QPushButton(tasksPage);
        filterOverdue->setObjectName("filterOverdue");
        filterOverdue->setGeometry(QRect(213, 144, 148, 58));
        filterOverdue->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        filterOverdue->setCheckable(true);
        filterHighPriority = new QPushButton(tasksPage);
        filterHighPriority->setObjectName("filterHighPriority");
        filterHighPriority->setGeometry(QRect(375, 144, 178, 58));
        filterHighPriority->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        filterHighPriority->setCheckable(true);
        contentStack->addWidget(tasksPage);
        calendarPage = new QWidget();
        calendarPage->setObjectName("calendarPage");
        calendarBackground = new QLabel(calendarPage);
        calendarBackground->setObjectName("calendarBackground");
        calendarBackground->setGeometry(QRect(0, 0, 1368, 1024));
        calendarFadeOverlay = new QLabel(calendarPage);
        calendarFadeOverlay->setObjectName("calendarFadeOverlay");
        calendarFadeOverlay->setGeometry(QRect(0, 0, 1368, 1024));
        calendarPageTitle = new QLabel(calendarPage);
        calendarPageTitle->setObjectName("calendarPageTitle");
        calendarPageTitle->setGeometry(QRect(109, 56, 331, 100));
        calendarPageTitle->setTextFormat(Qt::TextFormat::RichText);
        calendarPageTitle->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        calendarDate = new QLabel(calendarPage);
        calendarDate->setObjectName("calendarDate");
        calendarDate->setGeometry(QRect(440, 70, 241, 100));
        calendarDate->setAutoFillBackground(false);
        calendarDate->setTextFormat(Qt::TextFormat::RichText);
        calendarDate->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        layoutWidget = new QWidget(calendarPage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 190, 1180, 128));
        dayPickerRow_2 = new QHBoxLayout(layoutWidget);
        dayPickerRow_2->setSpacing(0);
        dayPickerRow_2->setObjectName("dayPickerRow_2");
        dayPickerRow_2->setContentsMargins(0, 0, 0, 0);
        calBtnPrev = new QPushButton(layoutWidget);
        calBtnPrev->setObjectName("calBtnPrev");
        calBtnPrev->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        calBtnPrev->setStyleSheet(QString::fromUtf8("min-width: 60px;\n"
"max-width: 60px;\n"
"min-height: 60px;\n"
"max-height: 60px;\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/left_arrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        calBtnPrev->setIcon(icon);
        calBtnPrev->setIconSize(QSize(36, 36));

        dayPickerRow_2->addWidget(calBtnPrev);

        dayCardsLayout_2 = new QHBoxLayout();
        dayCardsLayout_2->setSpacing(12);
        dayCardsLayout_2->setObjectName("dayCardsLayout_2");
        dayCardY = new QFrame(layoutWidget);
        dayCardY->setObjectName("dayCardY");
        dayCardY->setMinimumSize(QSize(132, 124));
        dayCardY->setMaximumSize(QSize(132, 124));
        dayCardY->setStyleSheet(QString::fromUtf8("\n"
"              QFrame#dayCardY {\n"
"                background: transparent;\n"
"                border: 1px solid rgba(0, 0, 0, 0.1);\n"
"                border-radius: 8px;\n"
"				 padding: 8px;\n"
"              }\n"
"             "));
        dayCardYL = new QVBoxLayout(dayCardY);
        dayCardYL->setSpacing(8);
        dayCardYL->setContentsMargins(6, 6, 6, 6);
        dayCardYL->setObjectName("dayCardYL");
        dayLabelY = new QLabel(dayCardY);
        dayLabelY->setObjectName("dayLabelY");
        dayLabelY->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 12px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 0.48px;\n"
"                   text-transform: uppercase;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayLabelY->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCardYL->addWidget(dayLabelY, 0, Qt::AlignmentFlag::AlignHCenter);

        dayNumY = new QLabel(dayCardY);
        dayNumY->setObjectName("dayNumY");
        dayNumY->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 50px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 2px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayNumY->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCardYL->addWidget(dayNumY, 0, Qt::AlignmentFlag::AlignHCenter);


        dayCardsLayout_2->addWidget(dayCardY);

        dayCard0 = new QFrame(layoutWidget);
        dayCard0->setObjectName("dayCard0");
        dayCard0->setMinimumSize(QSize(132, 124));
        dayCard0->setMaximumSize(QSize(132, 124));
        dayCard0->setStyleSheet(QString::fromUtf8("QFrame#dayCard0{\n"
"    background-color: #06B6A4;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"}"));
        dayCard0L = new QVBoxLayout(dayCard0);
        dayCard0L->setSpacing(8);
        dayCard0L->setContentsMargins(6, 6, 6, 6);
        dayCard0L->setObjectName("dayCard0L");
        dayCard0L->setContentsMargins(-1, 6, -1, 6);
        dayLabel0 = new QLabel(dayCard0);
        dayLabel0->setObjectName("dayLabel0");
        dayLabel0->setEnabled(true);
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter")});
        font.setWeight(QFont::DemiBold);
        dayLabel0->setFont(font);
        dayLabel0->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(255, 255, 255, 0.8);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 12px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 0.48px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayLabel0->setLineWidth(1);
        dayLabel0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard0L->addWidget(dayLabel0, 0, Qt::AlignmentFlag::AlignHCenter);

        dayNum0 = new QLabel(dayCard0);
        dayNum0->setObjectName("dayNum0");
        dayNum0->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(255, 254, 254, 0.8);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 50px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 2px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayNum0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard0L->addWidget(dayNum0);


        dayCardsLayout_2->addWidget(dayCard0);

        dayCard1 = new QFrame(layoutWidget);
        dayCard1->setObjectName("dayCard1");
        dayCard1->setMinimumSize(QSize(132, 124));
        dayCard1->setMaximumSize(QSize(132, 124));
        dayCard1->setStyleSheet(QString::fromUtf8("\n"
"              QFrame#dayCard1{\n"
"                background: transparent;\n"
"                border: 1px solid rgba(0, 0, 0, 0.1);\n"
"                border-radius: 8px;\n"
"				 padding: 8px;\n"
"              }\n"
"             "));
        dayCard1L = new QVBoxLayout(dayCard1);
        dayCard1L->setSpacing(8);
        dayCard1L->setContentsMargins(6, 6, 6, 6);
        dayCard1L->setObjectName("dayCard1L");
        dayLabel1 = new QLabel(dayCard1);
        dayLabel1->setObjectName("dayLabel1");
        dayLabel1->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 12px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 0.48px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayLabel1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard1L->addWidget(dayLabel1, 0, Qt::AlignmentFlag::AlignHCenter);

        dayNum1 = new QLabel(dayCard1);
        dayNum1->setObjectName("dayNum1");
        dayNum1->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 50px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 2px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayNum1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard1L->addWidget(dayNum1, 0, Qt::AlignmentFlag::AlignHCenter);


        dayCardsLayout_2->addWidget(dayCard1);

        dayCard2 = new QFrame(layoutWidget);
        dayCard2->setObjectName("dayCard2");
        dayCard2->setMinimumSize(QSize(132, 124));
        dayCard2->setMaximumSize(QSize(132, 124));
        dayCard2->setStyleSheet(QString::fromUtf8("\n"
"              QFrame#dayCard2{\n"
"                background: transparent;\n"
"                border: 1px solid rgba(0, 0, 0, 0.1);\n"
"                border-radius: 8px;\n"
"				 padding: 8px;\n"
"              }\n"
"             "));
        dayCard2L = new QVBoxLayout(dayCard2);
        dayCard2L->setSpacing(8);
        dayCard2L->setContentsMargins(6, 6, 6, 6);
        dayCard2L->setObjectName("dayCard2L");
        dayLabel2 = new QLabel(dayCard2);
        dayLabel2->setObjectName("dayLabel2");
        dayLabel2->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 12px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 0.48px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayLabel2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard2L->addWidget(dayLabel2, 0, Qt::AlignmentFlag::AlignHCenter);

        dayNum2 = new QLabel(dayCard2);
        dayNum2->setObjectName("dayNum2");
        dayNum2->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 50px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 2px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayNum2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard2L->addWidget(dayNum2, 0, Qt::AlignmentFlag::AlignHCenter);


        dayCardsLayout_2->addWidget(dayCard2);

        dayCard3 = new QFrame(layoutWidget);
        dayCard3->setObjectName("dayCard3");
        dayCard3->setMinimumSize(QSize(132, 124));
        dayCard3->setMaximumSize(QSize(132, 124));
        dayCard3->setStyleSheet(QString::fromUtf8("\n"
"              QFrame#dayCard3 {\n"
"                background: transparent;\n"
"                border: 1px solid rgba(0, 0, 0, 0.1);\n"
"                border-radius: 8px;\n"
"				 padding: 8px;\n"
"              }\n"
"             "));
        dayCard3L = new QVBoxLayout(dayCard3);
        dayCard3L->setSpacing(8);
        dayCard3L->setContentsMargins(6, 6, 6, 6);
        dayCard3L->setObjectName("dayCard3L");
        dayLabel3 = new QLabel(dayCard3);
        dayLabel3->setObjectName("dayLabel3");
        dayLabel3->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 12px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 0.48px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayLabel3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard3L->addWidget(dayLabel3, 0, Qt::AlignmentFlag::AlignHCenter);

        dayNum3 = new QLabel(dayCard3);
        dayNum3->setObjectName("dayNum3");
        dayNum3->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 50px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 2px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayNum3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard3L->addWidget(dayNum3, 0, Qt::AlignmentFlag::AlignHCenter);


        dayCardsLayout_2->addWidget(dayCard3);

        dayCard4 = new QFrame(layoutWidget);
        dayCard4->setObjectName("dayCard4");
        dayCard4->setMinimumSize(QSize(132, 124));
        dayCard4->setMaximumSize(QSize(132, 124));
        dayCard4->setStyleSheet(QString::fromUtf8("\n"
"              QFrame#dayCard4 {\n"
"                background: transparent;\n"
"                border: 1px solid rgba(0, 0, 0, 0.1);\n"
"                border-radius: 8px;\n"
"				 padding: 8px;\n"
"              }\n"
"             "));
        dayCard4L = new QVBoxLayout(dayCard4);
        dayCard4L->setSpacing(8);
        dayCard4L->setContentsMargins(6, 6, 6, 6);
        dayCard4L->setObjectName("dayCard4L");
        dayLabel4 = new QLabel(dayCard4);
        dayLabel4->setObjectName("dayLabel4");
        dayLabel4->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 12px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 0.48px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayLabel4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard4L->addWidget(dayLabel4, 0, Qt::AlignmentFlag::AlignHCenter);

        dayNum4 = new QLabel(dayCard4);
        dayNum4->setObjectName("dayNum4");
        dayNum4->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 50px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 2px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayNum4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard4L->addWidget(dayNum4, 0, Qt::AlignmentFlag::AlignHCenter);


        dayCardsLayout_2->addWidget(dayCard4);

        dayCard5 = new QFrame(layoutWidget);
        dayCard5->setObjectName("dayCard5");
        dayCard5->setMinimumSize(QSize(132, 124));
        dayCard5->setMaximumSize(QSize(132, 124));
        dayCard5->setStyleSheet(QString::fromUtf8("\n"
"              QFrame#dayCard5 {\n"
"                background: transparent;\n"
"                border: 1px solid rgba(0, 0, 0, 0.1);\n"
"                border-radius: 8px;\n"
"              }\n"
"             "));
        dayCard5L = new QVBoxLayout(dayCard5);
        dayCard5L->setSpacing(8);
        dayCard5L->setContentsMargins(6, 6, 6, 6);
        dayCard5L->setObjectName("dayCard5L");
        dayLabel5 = new QLabel(dayCard5);
        dayLabel5->setObjectName("dayLabel5");
        dayLabel5->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 12px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 0.48px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayLabel5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard5L->addWidget(dayLabel5, 0, Qt::AlignmentFlag::AlignHCenter);

        dayNum5 = new QLabel(dayCard5);
        dayNum5->setObjectName("dayNum5");
        dayNum5->setStyleSheet(QString::fromUtf8("\n"
"                 QLabel {\n"
"                   color: rgba(0, 0, 0, 0.5);\n"
"                   font-family: \"Inter\";\n"
"                   font-size: 50px;\n"
"                   font-weight: 600;\n"
"                   letter-spacing: 2px;\n"
"                   border: none;\n"
"                 }\n"
"                "));
        dayNum5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        dayCard5L->addWidget(dayNum5, 0, Qt::AlignmentFlag::AlignHCenter);


        dayCardsLayout_2->addWidget(dayCard5);


        dayPickerRow_2->addLayout(dayCardsLayout_2);

        calBtnNext = new QPushButton(layoutWidget);
        calBtnNext->setObjectName("calBtnNext");
        calBtnNext->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        calBtnNext->setStyleSheet(QString::fromUtf8("min-width: 60px;\n"
"max-width: 60px;\n"
"min-height: 60px;\n"
"max-height: 60px;\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/right_arrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        calBtnNext->setIcon(icon1);
        calBtnNext->setIconSize(QSize(36, 36));

        dayPickerRow_2->addWidget(calBtnNext);

        contentStack->addWidget(calendarPage);

        retranslateUi(MainWindow);

        contentStack->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LearnFlow Desktop", nullptr));
        sidebarCheckIcon->setText(QString());
        navHome->setText(QString());
        navTasks->setText(QString());
        navCalendar->setText(QString());
        settingsButton->setText(QCoreApplication::translate("MainWindow", "\342\232\231", nullptr));
        profileImage->setText(QString());
        greetingHello->setText(QCoreApplication::translate("MainWindow", "Hello,", nullptr));
        greetingName->setText(QCoreApplication::translate("MainWindow", " Ahmed Hagag", nullptr));
        mindLabel->setText(QCoreApplication::translate("MainWindow", "What's On Your Mind?", nullptr));
        taskInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type a task...", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add \342\244\266", nullptr));
        tasksHeading->setText(QCoreApplication::translate("MainWindow", "Tasks", nullptr));
        labelTotalTasks->setText(QCoreApplication::translate("MainWindow", "Total Tasks", nullptr));
        valueTotalTasks->setText(QCoreApplication::translate("MainWindow", "24", nullptr));
        iconTotalTasks->setText(QCoreApplication::translate("MainWindow", "\342\227\213", nullptr));
        labelInProgress->setText(QCoreApplication::translate("MainWindow", "In Progress", nullptr));
        valueInProgress->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        iconInProgress->setText(QCoreApplication::translate("MainWindow", "\342\217\261", nullptr));
        labelProductivity->setText(QCoreApplication::translate("MainWindow", "Productivity", nullptr));
        valueProductivity->setText(QCoreApplication::translate("MainWindow", "75", nullptr));
        iconProductivity->setText(QCoreApplication::translate("MainWindow", "\360\237\223\210", nullptr));
        labelCompleted->setText(QCoreApplication::translate("MainWindow", "Completed", nullptr));
        valueCompleted->setText(QCoreApplication::translate("MainWindow", "18", nullptr));
        iconCompleted->setText(QCoreApplication::translate("MainWindow", "\342\234\223", nullptr));
        tasksSearchBar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search anything....", nullptr));
        filterAll->setText(QCoreApplication::translate("MainWindow", "All", nullptr));
        filterOverdue->setText(QCoreApplication::translate("MainWindow", "Overdue", nullptr));
        filterHighPriority->setText(QCoreApplication::translate("MainWindow", "High Priority", nullptr));
        calendarPageTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Inter'; font-weight:700; color:#06b6a4;\">Calendar</span></p></body></html>", nullptr));
        calendarDate->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Inter'; font-size:60px; font-weight:500; color:#7b8185;\">20 Feb</span></p></body></html>", nullptr));
        calBtnPrev->setText(QString());
        dayLabelY->setText(QCoreApplication::translate("MainWindow", "THU", nullptr));
        dayNumY->setText(QCoreApplication::translate("MainWindow", "19", nullptr));
        dayLabel0->setText(QCoreApplication::translate("MainWindow", "FRI", nullptr));
        dayNum0->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        dayLabel1->setText(QCoreApplication::translate("MainWindow", "SAT", nullptr));
        dayNum1->setText(QCoreApplication::translate("MainWindow", "21", nullptr));
        dayLabel2->setText(QCoreApplication::translate("MainWindow", "SUN", nullptr));
        dayNum2->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        dayLabel3->setText(QCoreApplication::translate("MainWindow", "MON", nullptr));
        dayNum3->setText(QCoreApplication::translate("MainWindow", "23", nullptr));
        dayLabel4->setText(QCoreApplication::translate("MainWindow", "TUE", nullptr));
        dayNum4->setText(QCoreApplication::translate("MainWindow", "24", nullptr));
        dayLabel5->setText(QCoreApplication::translate("MainWindow", "WED", nullptr));
        dayNum5->setText(QCoreApplication::translate("MainWindow", "25", nullptr));
        calBtnNext->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

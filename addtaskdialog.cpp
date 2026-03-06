#include "addtaskdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QPalette>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QGraphicsDropShadowEffect>
#include <QMenu>
#include <QAction>
#include <QCalendarWidget>
#include <QWidgetAction>

AddTaskDialog::AddTaskDialog(QWidget *parent)
    : QWidget(parent)
{
    m_selectedPriority = "Medium";
    m_selectedCategory = "Project Work";
    m_selectedDate = QDate::currentDate().addDays(1);
    m_selectedEndDate = m_selectedDate;
    m_selectedTime = QTime(9, 0);
    m_selectedEndTime = QTime(10, 0);

    if (parent) setFixedSize(parent->size());
    raise();
    setFocusPolicy(Qt::StrongFocus);
    setupUi();
    m_titleInput->setFocus();
    show();
}

AddTaskDialog::~AddTaskDialog() {}

QString AddTaskDialog::taskTitle() const { return m_titleInput->text(); }
QString AddTaskDialog::taskDescription() const { return m_descInput->toPlainText(); }

void AddTaskDialog::mousePressEvent(QMouseEvent *e) {
    if (!m_card->geometry().contains(e->pos())) onClose();
    QWidget::mousePressEvent(e);
}

void AddTaskDialog::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Escape) onClose();
    QWidget::keyPressEvent(e);
}

void AddTaskDialog::onCreateClicked() {
    QString t = m_titleInput->text().trimmed();
    if (!t.isEmpty()) {
        emit taskCreated(t, m_descInput->toPlainText(), m_selectedPriority, m_selectedCategory, m_selectedDate, m_selectedEndDate, m_selectedTime, m_selectedEndTime);
        close(); deleteLater();
    }
}

void AddTaskDialog::onClose() {
    emit cancelled();
    close(); deleteLater();
}

void AddTaskDialog::setupUi() {
    QVBoxLayout *outer = new QVBoxLayout(this);
    outer->setAlignment(Qt::AlignCenter);

    m_card = new QFrame(this);
    m_card->setObjectName("addTaskCard");
    m_card->setFixedSize(680, 400);
    auto *shadow = new QGraphicsDropShadowEffect(m_card);
    shadow->setBlurRadius(40);
    shadow->setOffset(0, 8);
    shadow->setColor(QColor(0, 0, 0, 50));
    m_card->setGraphicsEffect(shadow);

    QVBoxLayout *cardLay = new QVBoxLayout(m_card);
    cardLay->setContentsMargins(0, 0, 0, 0);
    cardLay->setSpacing(0);

    // ── TOP BAR ──
    QFrame *topBar = new QFrame;
    topBar->setObjectName("topBar");
    topBar->setFixedHeight(52);
    QHBoxLayout *topLay = new QHBoxLayout(topBar);
    topLay->setContentsMargins(24, 0, 24, 0);

    QLabel *proj = new QLabel("LearnFlow");
    proj->setObjectName("projectLabel");
    QLabel *dot = new QLabel("  •  ");
    dot->setObjectName("dotSeparator");
    QPushButton *mil = new QPushButton("Select Milestone");
    mil->setObjectName("milestoneBtn");
    mil->setCursor(Qt::PointingHandCursor);
    m_closeBtn = new QPushButton("✕");
    m_closeBtn->setObjectName("dialogCloseBtn");
    m_closeBtn->setCursor(Qt::PointingHandCursor);
    m_closeBtn->setFixedSize(32, 32);
    connect(m_closeBtn, &QPushButton::clicked, this, &AddTaskDialog::onClose);

    topLay->addWidget(proj);
    topLay->addStretch();
    topLay->addWidget(m_closeBtn);

    QFrame *sep1 = new QFrame; sep1->setObjectName("dialogSep"); sep1->setFixedHeight(1);

    // ── CONTENT ──
    QWidget *content = new QWidget;
    QVBoxLayout *cLay = new QVBoxLayout(content);
    cLay->setContentsMargins(24, 20, 24, 12);
    cLay->setSpacing(8);

    m_titleInput = new QLineEdit;
    m_titleInput->setObjectName("dialogTitleInput");
    m_titleInput->setPlaceholderText("Task Title");
    m_titleInput->setFixedHeight(44);
    QPalette tp = m_titleInput->palette();
    tp.setColor(QPalette::PlaceholderText, QColor("#9CA3AF"));
    m_titleInput->setPalette(tp);

    m_descInput = new QTextEdit;
    m_descInput->setObjectName("dialogDescInput");
    m_descInput->setPlaceholderText("Add Description....");
    m_descInput->setFrameShape(QFrame::NoFrame);
    m_descInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_descInput->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QPalette dp = m_descInput->palette();
    dp.setColor(QPalette::PlaceholderText, QColor("#9CA3AF"));
    m_descInput->setPalette(dp);

    cLay->addWidget(m_titleInput);
    cLay->addWidget(m_descInput, 1);

    QFrame *sep2 = new QFrame; sep2->setObjectName("dialogSep"); sep2->setFixedHeight(1);

    // ── BOTTOM BAR (Grouped Layout) ──
    QFrame *bot = new QFrame;
    bot->setObjectName("dialogBottomBar");
    bot->setFixedHeight(100); // Taller to fit two rows if needed
    QVBoxLayout *bMainLay = new QVBoxLayout(bot);
    bMainLay->setContentsMargins(24, 0, 24, 10);
    bMainLay->setSpacing(8);
    
    QHBoxLayout *topRow = new QHBoxLayout;
    topRow->setSpacing(8);
    QHBoxLayout *botRow = new QHBoxLayout;
    botRow->setSpacing(8);

    auto chip = [](const QString &t) {
        auto *b = new QPushButton(t);
        b->setObjectName("dialogChipBtn");
        b->setCursor(Qt::PointingHandCursor);
        return b;
    };
    
    m_dateBtn = chip("▣ Start: " + m_selectedDate.toString("MMM d"));
    m_endDateBtn = chip("▣ End: " + m_selectedEndDate.toString("MMM d"));
    m_timeBtn = chip("🕒 " + m_selectedTime.toString("hh:mm AP"));
    m_endTimeBtn = chip("⏳ " + m_selectedEndTime.toString("hh:mm AP"));
    
    m_priorityBtn = chip("◆ " + m_selectedPriority);
    m_categoryBtn = chip("📁 " + m_selectedCategory);
    
    // Priority Menu
    QMenu *priMenu = new QMenu(this);
    priMenu->setStyleSheet("QMenu { background: white; border: 1px solid #E5E7EB; border-radius: 8px; padding: 4px; }"
                           "QMenu::item { padding: 8px 24px; border-radius: 4px; color: #374151; font-family: 'Inter'; }"
                           "QMenu::item:selected { background: #F3F4F6; color: #06B6A4; }");
    
    QStringList priorities = {"High", "Medium", "Low"};
    for (const QString &p : priorities) {
        QAction *act = priMenu->addAction(p);
        connect(act, &QAction::triggered, this, [this, p]() {
            m_selectedPriority = p;
            m_priorityBtn->setText("◆ " + p);
        });
    }
    m_priorityBtn->setMenu(priMenu);

    // Category Menu
    QMenu *catMenu = new QMenu(this);
    catMenu->setStyleSheet("QMenu { background: white; border: 1px solid #E5E7EB; border-radius: 8px; padding: 4px; }"
                           "QMenu::item { padding: 8px 24px; border-radius: 4px; color: #374151; font-family: 'Inter'; }"
                           "QMenu::item:selected { background: #F3F4F6; color: #06B6A4; }");
    
    QStringList categories = {"Project Work", "Meeting", "Education", "Group Discussion", "Other"};
    for (const QString &c : categories) {
        QAction *act = catMenu->addAction(c);
        connect(act, &QAction::triggered, this, [this, c]() {
            m_selectedCategory = c;
            m_categoryBtn->setText("📁 " + c);
        });
    }
    m_categoryBtn->setMenu(catMenu);

    // Date Menu
    QMenu *dateMenu = new QMenu(this);
    dateMenu->setStyleSheet("QMenu { background: white; border: 1px solid #E5E7EB; border-radius: 8px; padding: 4px; }");
    
    QWidgetAction *calcAction = new QWidgetAction(dateMenu);
    QCalendarWidget *cal = new QCalendarWidget();
    cal->setMinimumDate(QDate::currentDate());
    cal->setSelectionMode(QCalendarWidget::SingleSelection);
    cal->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
    cal->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    cal->setNavigationBarVisible(true);
    cal->setMinimumHeight(420);
    cal->setMinimumWidth(380);
    
    cal->setStyleSheet(R"(
        QCalendarWidget {
            background-color: white;
            border-radius: 12px;
            font-family: 'Inter';
        }
        QCalendarWidget QWidget#qt_calendar_navigationbar {
            background-color: white;
            border-bottom: 2px solid #F3F4F6;
            min-height: 60px;
        }
        QCalendarWidget QToolButton {
            color: #111111;
            font-size: 16px;
            font-weight: 700;
            background: transparent;
            border: none;
            border-radius: 10px;
            margin: 6px;
            padding: 8px 12px;
        }
        QCalendarWidget QToolButton:hover {
            background-color: #F9FAFB;
        }
        QCalendarWidget QToolButton#qt_calendar_prevmonth {
            qproperty-icon: none;
            qproperty-text: "←";
        }
        QCalendarWidget QToolButton#qt_calendar_nextmonth {
            qproperty-icon: none;
            qproperty-text: "→";
        }
        QCalendarWidget QAbstractItemView {
            background-color: white;
            selection-background-color: #06B6A4;
            selection-color: white;
            outline: none;
            border: none;
            font-size: 15px;
        }
        QCalendarWidget QAbstractItemView:enabled {
            color: #374151;
        }
        QCalendarWidget QAbstractItemView:disabled {
            color: #D1D5DB;
        }
        QCalendarWidget QWidget#qt_calendar_calendarview {
            background-color: white;
        }
        /* Header (Day Names) */
        QCalendarWidget QTableView#qt_calendar_calendarview {
            alternate-background-color: white;
        }
        QCalendarWidget QHeaderView {
            background-color: white;
            border: none;
        }
        QCalendarWidget QWidget#qt_calendar_calendarview QHeaderView::section {
            background-color: white;
            color: #9CA3AF;
            font-size: 12px;
            font-weight: 700;
            border: none;
            padding: 12px 0;
        }
    )");
    calcAction->setDefaultWidget(cal);
    dateMenu->addAction(calcAction);
    
    connect(cal, &QCalendarWidget::activated, this, [this, dateMenu](const QDate &date) {
        // Enforce Start <= End rule
        if (date > m_selectedEndDate) m_selectedEndDate = date;
        m_selectedDate = date;
        m_dateBtn->setText("▣ Start: " + date.toString("MMM d"));
        m_endDateBtn->setText("▣ End: " + m_selectedEndDate.toString("MMM d"));
        dateMenu->close();
    });
    
    m_dateBtn->setMenu(dateMenu);

    // End Date Menu
    QMenu *endDateMenu = new QMenu(this);
    endDateMenu->setStyleSheet(dateMenu->styleSheet());
    
    QWidgetAction *endCalcAction = new QWidgetAction(endDateMenu);
    QCalendarWidget *endCal = new QCalendarWidget();
    endCal->setMinimumDate(m_selectedDate);
    endCal->setSelectionMode(QCalendarWidget::SingleSelection);
    endCal->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
    endCal->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    endCal->setNavigationBarVisible(true);
    endCal->setMinimumHeight(420);
    endCal->setMinimumWidth(380);
    endCal->setStyleSheet(cal->styleSheet());
    
    endCalcAction->setDefaultWidget(endCal);
    endDateMenu->addAction(endCalcAction);
    
    connect(endCal, &QCalendarWidget::activated, this, [this, endDateMenu](const QDate &date) {
        m_selectedEndDate = date;
        m_endDateBtn->setText("▣ End: " + date.toString("MMM d"));
        endDateMenu->close();
    });
    
    m_endDateBtn->setMenu(endDateMenu);

    // Time Menu
    QMenu *timeMenu = new QMenu(this);
    timeMenu->setStyleSheet("QMenu { background: white; border: 1px solid #E5E7EB; border-radius: 8px; padding: 4px; }"
                            "QMenu::item { padding: 8px 20px; border-radius: 4px; color: #374151; font-family: 'Inter'; }"
                            "QMenu::item:selected { background: #F3F4F6; color: #06B6A4; }");
    
    for (int h = 0; h < 24; h++) {
        for (int m = 0; m < 60; m += 30) {
            QTime t(h, m);
            QAction *act = timeMenu->addAction(t.toString("hh:mm AP"));
            connect(act, &QAction::triggered, this, [this, t]() {
                m_selectedTime = t;
                m_timeBtn->setText("🕒 " + t.toString("hh:mm AP"));
            });
        }
    }
    m_timeBtn->setMenu(timeMenu);

    // End Time Menu
    QMenu *endTimeMenu = new QMenu(this);
    endTimeMenu->setStyleSheet("QMenu { background: white; border: 1px solid #E5E7EB; border-radius: 8px; padding: 4px; }"
                            "QMenu::item { padding: 8px 20px; border-radius: 4px; color: #374151; font-family: 'Inter'; }"
                            "QMenu::item:selected { background: #F3F4F6; color: #06B6A4; }");
    
    for (int h = 0; h < 24; h++) {
        for (int m = 0; m < 60; m += 30) {
            QTime t(h, m);
            QAction *act = endTimeMenu->addAction(t.toString("hh:mm AP"));
            connect(act, &QAction::triggered, this, [this, t]() {
                m_selectedEndTime = t;
                m_endTimeBtn->setText("⏳ " + t.toString("hh:mm AP"));
            });
        }
    }
    m_endTimeBtn->setMenu(endTimeMenu);

    topRow->addWidget(m_dateBtn);
    topRow->addWidget(m_endDateBtn);
    topRow->addWidget(m_timeBtn);
    topRow->addWidget(m_endTimeBtn);
    topRow->addStretch();
    
    botRow->addWidget(m_categoryBtn);
    botRow->addWidget(m_priorityBtn);
    botRow->addStretch();

    m_createBtn = new QPushButton("Create Task");
    m_createBtn->setObjectName("createTaskBtn");
    m_createBtn->setCursor(Qt::PointingHandCursor);
    connect(m_createBtn, &QPushButton::clicked, this, &AddTaskDialog::onCreateClicked);
    botRow->addWidget(m_createBtn);
    
    bMainLay->addLayout(topRow);
    bMainLay->addLayout(botRow);

    cardLay->addWidget(topBar);
    cardLay->addWidget(sep1);
    cardLay->addWidget(content, 1);
    cardLay->addWidget(sep2);
    cardLay->addWidget(bot);
    outer->addWidget(m_card);

    // ── STYLESHEET ──
    m_card->setStyleSheet(R"(
QFrame#addTaskCard {
    background: qlineargradient(x1:0,y1:0,x2:0,y2:1,
        stop:0 rgba(255,255,255,0.97), stop:0.5 rgba(255,255,255,0.95),
        stop:1 rgba(248,250,249,0.92));
    border: 2px solid rgba(255,255,255,0.96);
    border-top-color: rgba(255,255,255,1.0);
    border-left-color: rgba(255,255,255,0.98);
    border-bottom-color: rgba(200,210,208,0.40);
    border-right-color: rgba(200,210,208,0.30);
    border-radius: 22px;
}
QFrame#topBar, QFrame#dialogBottomBar { background:transparent; border:none; }
QFrame#dialogSep { background-color:rgba(0,0,0,0.08); border:none; }
QLabel#projectLabel {
    font-family:'Inter'; font-weight:700; font-size:14px;
    color:#111111; background:transparent;
}
QLabel#dotSeparator { font-family:'Inter'; font-size:14px; color:#06B6A4; background:transparent; }
QPushButton#milestoneBtn {
    background:transparent; border:none; font-family:'Inter';
    font-size:14px; font-weight:500; color:#6A7282; padding:0;
}
QPushButton#milestoneBtn:hover { color:#06B6A4; }
QPushButton#dialogCloseBtn {
    background:transparent; border:none; font-size:18px;
    color:#6A7282; border-radius:16px;
}
QPushButton#dialogCloseBtn:hover { background-color:rgba(0,0,0,0.06); color:#111111; }
QLineEdit#dialogTitleInput {
    background:transparent; border:none; font-family:'Inter';
    font-size:22px; font-weight:700; color:#111111; padding:6px 14px;
}
QTextEdit#dialogDescInput {
    background:transparent; border:none; font-family:'Inter';
    font-size:15px; font-weight:400; color:#374151; padding:6px 14px;
}
QPushButton#dialogChipBtn {
    background-color:transparent; border:1px solid rgba(0,0,0,0.12);
    border-radius:0px; color:#6A7282; font-family:'Inter';
    font-size:13px; font-weight:500; padding:6px 14px;
}
QPushButton#dialogChipBtn:hover {
    background-color:rgba(6,182,164,0.08);
    border-color:rgba(6,182,164,0.3); color:#065F56;
}
QPushButton#createTaskBtn {
    background-color:#06B6A4; color:white; border:none;
    border-radius:5px; font-family:'Inter'; font-weight:700;
    font-size:12px; padding:0px; min-height:50px; min-width:100px; max-height:50px; max-width:100px;
}
QPushButton#createTaskBtn:hover { background-color:#059E8E; transform: scale(1.02); }
QPushButton#createTaskBtn:pressed { background-color:#048A7C; }
QScrollBar:vertical { background:transparent; width:6px; }
QScrollBar::handle:vertical { background:rgba(6,95,86,0.25); border-radius:3px; min-height:20px; }
QScrollBar::handle:vertical:hover { background:rgba(6,95,86,0.45); }
QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height:0; }
    )");
}

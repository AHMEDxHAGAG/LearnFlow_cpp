#ifndef ADDTASKDIALOG_H
#define ADDTASKDIALOG_H

#include <QWidget>
#include <QDate>

class QLineEdit;
class QTextEdit;
class QPushButton;
class QFrame;

class AddTaskDialog : public QWidget
{
    Q_OBJECT
public:
    explicit AddTaskDialog(QWidget *parent = nullptr);
    ~AddTaskDialog();
    QString taskTitle() const;
    QString taskDescription() const;

signals:
    void taskCreated(const QString &title, const QString &desc, const QString &priority, const QString &project, const QDate &startDate, const QDate &endDate, const QTime &dueTime, const QTime &endTime);
    void cancelled();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onCreateClicked();
    void onClose();

private:
    void setupUi();
    QFrame    *m_card;
    QLineEdit *m_titleInput;
    QTextEdit *m_descInput;
    QPushButton *m_createBtn;
    QPushButton *m_closeBtn;
    QPushButton *m_priorityBtn;
    QPushButton *m_categoryBtn;
    QPushButton *m_dateBtn;
    QPushButton *m_endDateBtn;
    QPushButton *m_timeBtn;
    QPushButton *m_endTimeBtn;
    
    QString     m_selectedPriority;
    QString     m_selectedCategory;
    QDate       m_selectedDate;
    QDate       m_selectedEndDate;
    QTime       m_selectedTime;
    QTime       m_selectedEndTime;
};

#endif // ADDTASKDIALOG_H

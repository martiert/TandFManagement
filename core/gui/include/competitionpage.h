#ifndef COMPETITION_PAGE_H
#define COMPETITION_PAGE_H

#include <QWidget>

class QPushButton;
class QVBoxLayout;

class CompetitionPage : public QWidget
{
    Q_OBJECT

public:
    CompetitionPage(QWidget * parent);
    ~CompetitionPage();

private slots:
    void newContestant();
    void setupContest();

private:
    QPushButton * addContestant;
    QPushButton * setup;

    QVBoxLayout * layout;
};

#endif

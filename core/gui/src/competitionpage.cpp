#include "competitionpage.h"

#include <QPushButton>
#include <QVBoxLayout>

CompetitionPage::CompetitionPage(QWidget * parent)
    : addContestant(new QPushButton(tr("Add Contestant"))),
      setup(new QPushButton(tr("Setup Competition"))),
      layout(new QVBoxLayout)
{
    connect(addContestant, SIGNAL(clicked()), this, SLOT(newContestant()));
    connect(setup, SIGNAL(clicked()), this, SLOT(setupContest()));

    layout->addWidget(addContestant);
    layout->addWidget(setup);
    setLayout(layout);
}

CompetitionPage::~CompetitionPage()
{
    delete layout;
    delete addContestant;
}

void CompetitionPage::newContestant()
{
}

void CompetitionPage::setupContest()
{
}

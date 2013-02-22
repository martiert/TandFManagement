#include "menubar.h"
#include "mainwindow.h"

#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

MenuBar::MenuBar(MainWindow * mainwindow)
    : mainwindow(mainwindow),
      newCompetitionAction(std::make_shared<QAction>(QApplication::tr("&New"), mainwindow)),
      loadCompetitionAction(new QAction(QApplication::tr("&Load"), mainwindow)),
      quitAction(new QAction(QApplication::tr("&Quit"), mainwindow)),
      helpAction(new QAction(QApplication::tr("&Help"), mainwindow)),
      aboutAction(new QAction(QApplication::tr("&About"), mainwindow)),
      menubar(mainwindow->menuBar())
{
    setupActions();
    createToolBar();
}

void MenuBar::setupActions()
{
    newCompetitionAction->setIcon(QIcon(":/images/new.png"));
    newCompetitionAction->setShortcut(QKeySequence::New);
    newCompetitionAction->setStatusTip(QApplication::tr("Create a new competition"));
    QObject::connect(newCompetitionAction.get(), SIGNAL(triggered()), mainwindow, SLOT(newCompetition()));

    loadCompetitionAction->setIcon(QIcon(":/images/load.png"));
    loadCompetitionAction->setShortcut(QKeySequence::Open);
    loadCompetitionAction->setStatusTip(QApplication::tr("Load a competition"));
    QObject::connect(loadCompetitionAction.get(), SIGNAL(triggered()), mainwindow, SLOT(loadCompetition()));

    quitAction->setIcon(QIcon(":/images/quit.png"));
    quitAction->setShortcut(QKeySequence("CTRL+Q"));
    quitAction->setStatusTip(QApplication::tr("Quit application"));
    QObject::connect(quitAction.get(), SIGNAL(triggered()), qApp, SLOT(quit()));

    helpAction->setIcon(QIcon(":/images/help.png"));
    helpAction->setShortcut(QKeySequence::HelpContents);
    helpAction->setStatusTip(QApplication::tr("Show help dialog"));
    QObject::connect(quitAction.get(), SIGNAL(triggered()), mainwindow, SLOT(showHelp()));

    aboutAction->setIcon(QIcon(":/images/about.png"));
    aboutAction->setShortcut(QKeySequence("SHIFT+F1"));
    aboutAction->setStatusTip(QApplication::tr("About this application"));
    QObject::connect(aboutAction.get(), SIGNAL(triggered()), mainwindow, SLOT(showAbout()));
}

void MenuBar::createToolBar()
{
    QMenu * menu = menubar->addMenu(QApplication::tr("&File"));
    menu->addAction(newCompetitionAction.get());
    menu->addAction(loadCompetitionAction.get());
    menu->addSeparator();
    menu->addAction(quitAction.get());

    menubar->addSeparator();
    menu = menubar->addMenu(QApplication::tr("&Help"));
    menu->addAction(helpAction.get());
    menu->addSeparator();
    menu->addAction(aboutAction.get());
}



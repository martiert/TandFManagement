#include "menubar.h"
#include "mainwindow.h"

#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

MenuBar::MenuBar(MainWindow * mainwindow)
    : mainwindow(mainwindow),
      newCompetitionAction(new QAction(QApplication::tr("&New"), mainwindow)),
      loadCompetitionAction(new QAction(QApplication::tr("&Load"), mainwindow)),
      saveCompetitionAction(new QAction(QApplication::tr("&Save"), mainwindow)),
      quitAction(new QAction(QApplication::tr("&Quit"), mainwindow)),
      helpAction(new QAction(QApplication::tr("&Help"), mainwindow)),
      aboutAction(new QAction(QApplication::tr("&About"), mainwindow)),
      aboutQtAction(new QAction(QApplication::tr("&About Qt"), mainwindow)),
      menubar(mainwindow->menuBar())
{
    setupActions();
    createToolBar();
}

MenuBar::~MenuBar()
{
    delete newCompetitionAction;
    delete loadCompetitionAction;
    delete saveCompetitionAction;
    delete quitAction;
    delete helpAction;
    delete aboutAction;
    delete aboutQtAction;
}

void MenuBar::setupActions()
{
    newCompetitionAction->setIcon(QIcon(":/images/new.png"));
    newCompetitionAction->setShortcut(QKeySequence::New);
    newCompetitionAction->setStatusTip(QApplication::tr("Create a new competition"));
    QObject::connect(newCompetitionAction, SIGNAL(triggered()), mainwindow, SLOT(newCompetition()));

    loadCompetitionAction->setIcon(QIcon(":/images/load.png"));
    loadCompetitionAction->setShortcut(QKeySequence::Open);
    loadCompetitionAction->setStatusTip(QApplication::tr("Load a competition"));
    QObject::connect(loadCompetitionAction, SIGNAL(triggered()), mainwindow, SLOT(loadCompetition()));

    saveCompetitionAction->setIcon(QIcon(":/images/save.png"));
    saveCompetitionAction->setShortcut(QKeySequence::Save);
    saveCompetitionAction->setStatusTip(QApplication::tr("Save a competition"));
    QObject::connect(saveCompetitionAction, SIGNAL(triggered()), mainwindow, SLOT(saveCompetition()));

    quitAction->setIcon(QIcon(":/images/quit.png"));
    quitAction->setShortcut(QKeySequence("CTRL+Q"));
    quitAction->setStatusTip(QApplication::tr("Quit application"));
    QObject::connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    helpAction->setIcon(QIcon(":/images/help.png"));
    helpAction->setShortcut(QKeySequence::HelpContents);
    helpAction->setStatusTip(QApplication::tr("Show help dialog"));
    QObject::connect(helpAction, SIGNAL(triggered()), mainwindow, SLOT(showHelp()));

    aboutAction->setIcon(QIcon(":/images/about.png"));
    aboutAction->setShortcut(QKeySequence("SHIFT+F1"));
    aboutAction->setStatusTip(QApplication::tr("About this application"));
    QObject::connect(aboutAction, SIGNAL(triggered()), mainwindow, SLOT(showAbout()));

    aboutQtAction->setIcon(QIcon(":/images/about.png"));
    aboutQtAction->setShortcut(QKeySequence("SHIFT+F2"));
    aboutQtAction->setStatusTip(QApplication::tr("About Qt"));
    QObject::connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MenuBar::createToolBar()
{
    QMenu * menu = menubar->addMenu(QApplication::tr("&File"));
    menu->addAction(newCompetitionAction);
    menu->addAction(loadCompetitionAction);
    menu->addAction(saveCompetitionAction);
    menu->addSeparator();
    menu->addAction(quitAction);

    menubar->addSeparator();
    menu = menubar->addMenu(QApplication::tr("&Help"));
    menu->addAction(helpAction);
    menu->addSeparator();
    menu->addAction(aboutAction);
    menu->addAction(aboutQtAction);
}



#include "mainwindow.h"
#include "menubar.h"

MainWindow::MainWindow()
    : menubar(new MenuBar(this))
{
}

void MainWindow::closeEvent(QCloseEvent * event)
{
}

void MainWindow::newCompetition()
{
}

void MainWindow::loadCompetition()
{
}

void MainWindow::showHelp()
{
}

void MainWindow::showAbout()
{
}

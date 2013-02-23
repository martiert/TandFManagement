#include "mainwindow.h"
#include "menubar.h"
#include "startupscreen.h"
#include "aboutdialog.h"

#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow()
    : menubar(std::make_shared<MenuBar>(this)),
      startupScreen(std::make_shared<StartupScreen>()),
      aboutDialog(std::make_shared<AboutDialog>(this))
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
    QString supportedFileTypes = "Track and Field Management Files (*.taf)\n"
                                 "All Files (*.*)";
    QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), tr("."), supportedFileTypes);
}

void MainWindow::saveCompetition()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save file"), tr("."), "Track and Field Management Files (*.taf)");
}

void MainWindow::showHelp()
{
    QMessageBox::information(this, tr("Help"), tr("Sorry, no help available yet"));
}

void MainWindow::showAbout()
{
    aboutDialog->show();
    aboutDialog->raise();
    aboutDialog->activateWindow();
}

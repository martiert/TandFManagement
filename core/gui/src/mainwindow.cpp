#include "mainwindow.h"
#include "menubar.h"
#include "startupscreen.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>

MainWindow::MainWindow()
    : menubar(std::make_shared<MenuBar>(this)),
      startupScreen(std::make_shared<StartupScreen>())
{
    readSettings();
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
    QMessageBox::about(this, tr("About Track and Field Management"),
            tr("<h3>About</h3>"
              "<p>This is Track and Field Management system<br/>"
              "A program which lets you manage your track and field competitions"
              "<p>This program is licensed under the LGPLv2.1<br/>"
              "Please refer to <a href=http://www.gnu.org/licenses/lgpl-2.1.html>http://www.gnu.org/licenses/lgpl-2.1.html</a> for questions about the license"
              "<p>Copyright &copy; 2013 Martin Ertsaas"));
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    writeSettings();
}

void MainWindow::readSettings()
{
    QSettings settings("TrackAndField", "Management");
    restoreGeometry(settings.value("geometry").toByteArray());
}

void MainWindow::writeSettings()
{
    QSettings settings("TrackAndField", "Management");
    settings.setValue("geometry", saveGeometry());
}

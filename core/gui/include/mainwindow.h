#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class MenuBar;
class StartupScreen;

class MainWindow : public QMainWindow
{
    Q_OBJECT;

public:
    MainWindow();
    ~MainWindow();

public slots:
    void newCompetition();
    void loadCompetition();
    void saveCompetition();
    void showHelp();
    void showAbout();

private:
    void closeEvent(QCloseEvent * event);
    void readSettings();
    void writeSettings();

    MenuBar * menubar;
    StartupScreen * startupScreen;
};

#endif

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class MenuBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT;

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent * event);

public slots:
    void newCompetition();
    void loadCompetition();
    void showHelp();
    void showAbout();

private:
    MenuBar * menubar;
};

#endif

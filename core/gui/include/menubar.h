#ifndef MENU_BAR_H
#define MENU_BAR_H

class MainWindow;
class QAction;
class QMenuBar;

class MenuBar
{
public:
    MenuBar(MainWindow * mainwindow);

private:
    void setupActions();
    void createToolBar();

private:
    MainWindow * mainwindow;

    QAction * newCompetitionAction;
    QAction * loadCompetitionAction;
    QAction * quitAction;
    QAction * helpAction;
    QAction * aboutAction;

    QMenuBar * menubar;
};

#endif

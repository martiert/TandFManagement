#ifndef MENU_BAR_H
#define MENU_BAR_H

class MainWindow;
class QAction;
class QMenuBar;

class MenuBar
{
public:
    MenuBar(MainWindow * mainwindow);
    ~MenuBar();

private:
    void setupActions();
    void createToolBar();

private:
    MainWindow * mainwindow;

    QAction * newCompetitionAction;
    QAction * loadCompetitionAction;
    QAction * saveCompetitionAction;
    QAction * quitAction;
    QAction * helpAction;
    QAction * aboutAction;
    QAction * aboutQtAction;

    QMenuBar * menubar;
};

#endif

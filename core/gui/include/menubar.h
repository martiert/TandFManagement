#ifndef MENU_BAR_H
#define MENU_BAR_H

#include <memory>

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

    std::shared_ptr<QAction> newCompetitionAction;
    std::shared_ptr<QAction> loadCompetitionAction;
    std::shared_ptr<QAction> quitAction;
    std::shared_ptr<QAction> helpAction;
    std::shared_ptr<QAction> aboutAction;

    std::shared_ptr<QMenuBar> menubar;
};

#endif

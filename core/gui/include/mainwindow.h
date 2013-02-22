#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include <memory>

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
    std::shared_ptr<MenuBar> menubar;
};

#endif

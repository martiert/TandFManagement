#ifndef ABOUT_DIALOG_H
#define ABOUT_DIALOG_H

#include <QDialog>
#include <memory>

class QPushButton;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    AboutDialog(QWidget * parent = NULL);

private:
    QString getDialogContent() const;
    void setupLayouts();
    void addLayouts();

    std::shared_ptr<QPushButton> okButton;
    std::shared_ptr<QLabel> textLabel;
    std::shared_ptr<QLabel> iconLabel;
    std::shared_ptr<QHBoxLayout> mainLayout;
    std::shared_ptr<QVBoxLayout> iconLayout;
    std::shared_ptr<QVBoxLayout> labelLayout;
    std::shared_ptr<QHBoxLayout> buttonLayout;
};

#endif

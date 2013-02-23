#include "aboutdialog.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

AboutDialog::AboutDialog(QWidget * parent)
    : QDialog(parent),
      okButton(std::make_shared<QPushButton>(tr("OK"))),
      textLabel(std::make_shared<QLabel>(getDialogContent())),
      iconLabel(std::make_shared<QLabel>()),
      mainLayout(std::make_shared<QHBoxLayout>()),
      iconLayout(std::make_shared<QVBoxLayout>()),
      labelLayout(std::make_shared<QVBoxLayout>()),
      buttonLayout(std::make_shared<QHBoxLayout>())
{
    connect(okButton.get(), SIGNAL(clicked()), this, SLOT(accept()));

    setupLayouts();
    addLayouts();

    setWindowTitle(tr("About Track and Field Management"));
    setFixedHeight(sizeHint().height());
}

void AboutDialog::setupLayouts()
{
    iconLabel->setPixmap(QPixmap(":/images/about.png"));
    iconLayout->addWidget(iconLabel.get());
    iconLayout->addStretch();

    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton.get());
    buttonLayout->addStretch();

    labelLayout->addWidget(textLabel.get());
}

void AboutDialog::addLayouts()
{
    mainLayout->addLayout(iconLayout.get());
    mainLayout->addLayout(labelLayout.get());
    labelLayout->addLayout(buttonLayout.get());
    setLayout(mainLayout.get());
}

QString AboutDialog::getDialogContent() const
{
    return tr("About\n"
              "\n"
              "This is Track and Field Management system\n"
              "A program which lets you manage your track and field competitions\n"
              "\n"
              "This program is licensed under the LGPLv2.1\n"
              "Please refer to http://www.gnu.org/licenses/lgpl-2.1.html for questions about the license\n"
              "\n"
              "Copyright \x00A9 2013 Martin Ertsaas\n");
}

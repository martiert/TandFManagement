#include "aboutdialog.h"

#include <QDebug>
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
    textLabel->setTextFormat(Qt::RichText);
    textLabel->setOpenExternalLinks(true);

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
    return tr("<h3>About</h3>"
              "<p>This is Track and Field Management system<br/>"
              "A program which lets you manage your track and field competitions"
              "<p>This program is licensed under the LGPLv2.1<br/>"
              "Please refer to <a href=http://www.gnu.org/licenses/lgpl-2.1.html>http://www.gnu.org/licenses/lgpl-2.1.html</a> for questions about the license"
              "<p>Copyright &copy; 2013 Martin Ertsaas");
}

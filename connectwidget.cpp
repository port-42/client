#include <QFormLayout>
#include <QLabel>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonObject>
#include <QStackedWidget>
#include "connectwidget.h"
#include "apicommunicator.h"

ConnectWidget::ConnectWidget(QWidget *parent) :
  QWidget(parent),
  _hostServerInput(new QLineEdit(this))
{
  _hostServerInput->setText("http://127.0.0.1:8080");
  _hostServerInput->setMinimumWidth(600);
  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->addWidget(new QLabel("ETNA_Config"));
  QFormLayout *hostAddressForm = new QFormLayout();
  hostAddressForm->addRow("Host address:", _hostServerInput);
  auto connectButton = new QPushButton("Connect");
  hostAddressForm->addWidget(connectButton);
  mainLayout->addLayout(hostAddressForm);

  connect(connectButton, &QPushButton::clicked, [=]() {
    if (!_hostServerInput->text().length()) {
      qDebug() << "Empty URL";
      return;
    }
    QUrl url(_hostServerInput->text(), QUrl::StrictMode);
    if (!url.isValid()) {
      qDebug() << "Invalid URL";
      return;
    }
    emit connectClicked(url);
  });
}

ConnectWidget::~ConnectWidget()
{
  delete _hostServerInput;
}

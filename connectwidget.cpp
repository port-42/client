#include <QFormLayout>
#include <QLabel>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonObject>
#include <QStackedWidget>
#include "connectwidget.h"
#include "requests.h"
#include "apicommunicator.h"

ConnectWidget::ConnectWidget(QWidget *parent) :
  QWidget(parent),
  _comm(new ApiCommunicator(this)),
  _hostServerInput(new QLineEdit(this)),
  _connectButton(new QPushButton("Connect"))
{
  _hostServerInput->setText("http://127.0.0.1:8080");
  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->addWidget(new QLabel("ETNA_Config"));
  QFormLayout *hostAddressForm = new QFormLayout();
  hostAddressForm->addRow("Host address:", _hostServerInput);
  hostAddressForm->addWidget(_connectButton);
  mainLayout->addLayout(hostAddressForm);

  connect(_connectButton, &QPushButton::clicked, this, &ConnectWidget::onConnectClicked);
  connect(_comm, &ApiCommunicator::osDataReady, [=](const QJsonObject &data) {
    emit osDataReady(data);
    emit dataReady();
  });
  connect(_comm, &ApiCommunicator::cpuDataReady, [=](const QJsonObject &data) {
    emit cpuDataReady(data);
    emit dataReady();
  });
  connect(_comm, &ApiCommunicator::ramDataReady, [=](const QJsonObject &data) {
    emit ramDataReady(data);
    emit dataReady();
 });
  connect(_comm, &ApiCommunicator::hddDataReady, [=](const QJsonObject &data) {
    emit hddDataReady(data);
    emit dataReady();
  });
}

void ConnectWidget::onConnectClicked() {
  const QString hostAddress = _hostServerInput->text();
  if (!hostAddress.length())
    return;

  _comm->fetchOsData(QUrl(hostAddress));
  _comm->fetchCpuData(QUrl(hostAddress));
  _comm->fetchRamData(QUrl(hostAddress));
  _comm->fetchHddData(QUrl(hostAddress));
}

ConnectWidget::~ConnectWidget()
{
  delete _hostServerInput;
  delete _connectButton;
}

#include "apicommunicator.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QDebug>

ApiCommunicator::ApiCommunicator(QObject *parent) :
  QObject(parent),
  _nam(new QNetworkAccessManager())
{
}

void ApiCommunicator::fetchOsData(const QUrl &serverUrl) const
{
  QUrl endpoint = QUrl(serverUrl);
  endpoint.setPath("/os");
  _sendRequest(endpoint, &ApiCommunicator::osDataReady);
}

void ApiCommunicator::fetchCpuData(const QUrl &serverUrl) const
{
  QUrl endpoint = QUrl(serverUrl);
  endpoint.setPath("/cpu");
  _sendRequest(endpoint, &ApiCommunicator::cpuDataReady);
}

void ApiCommunicator::fetchRamData(const QUrl &serverUrl) const
{
  QUrl endpoint = QUrl(serverUrl);
  endpoint.setPath("/ram");
  _sendRequest(endpoint, &ApiCommunicator::ramDataReady);
}

void ApiCommunicator::fetchHddData(const QUrl &serverUrl) const
{
  QUrl endpoint = QUrl(serverUrl);
  endpoint.setPath("/hdd");
  _sendRequest(endpoint, &ApiCommunicator::hddDataReady);
}

void ApiCommunicator::_sendRequest(const QUrl &url, void (ApiCommunicator::*signal)(const QJsonObject &) const) const
{
  qDebug() << "GET" << url.toString();
  QNetworkReply *reply = _nam->get(QNetworkRequest(url));
  connect(reply, &QNetworkReply::readChannelFinished, [=]() {
    if (reply->error()) {
      qDebug() << "Request error:" << reply->errorString();
      return;
    }
    const QByteArray data = reply->readAll();
    reply->deleteLater();
    if (data.size() <= 1)
      return;
    qDebug() << "GET" << url.toString() << ">>" << data;

    QJsonParseError parseError;
    const QJsonObject json = QJsonDocument::fromJson(data, &parseError).object();
    if (parseError.error)
      qDebug() << "JSON parse error:" << parseError.errorString();
    else {
      emit (this->*signal)(json);
      emit dataFetched(json);
    }
  });
}

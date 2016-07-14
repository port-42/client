#ifndef APICOMMUNICATOR_H
#define APICOMMUNICATOR_H

#include <QObject>
#include <QJsonObject>
#include <QNetworkAccessManager>

class ApiCommunicator : public QObject
{
  Q_OBJECT
public:
  explicit ApiCommunicator(QObject *parent = 0);

public slots:
  void fetchOsData(const QUrl &serverUrl) const;
  void fetchCpuData(const QUrl &serverUrl) const;
  void fetchRamData(const QUrl &serverUrl) const;
  void fetchHddData(const QUrl &serverUrl) const;

signals:
  void osDataReady(const QJsonObject &data) const;
  void cpuDataReady(const QJsonObject &data) const;
  void ramDataReady(const QJsonObject &data) const;
  void hddDataReady(const QJsonObject &data) const;
  void dataFetched(const QJsonObject &data) const;

private:
  void _sendRequest(const QUrl &url, void (ApiCommunicator::* signal)(const QJsonObject &) const) const;

private:
  QNetworkAccessManager *_nam;
};

#endif // APICOMMUNICATOR_H

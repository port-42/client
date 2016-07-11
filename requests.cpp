#include "requests.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QtDebug>

QJsonObject Requests::fetchRemoteSysDetails(const QString &) {
  return QJsonObject();
}

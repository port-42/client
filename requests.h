#ifndef REQUESTS_H
#define REQUESTS_H

#include <QString>
#include <QJsonObject>

class Requests
{
private:
  Requests() = delete;

public:
  static QJsonObject fetchRemoteSysDetails(const QString &hostAddress);
};

#endif // REQUESTS_H

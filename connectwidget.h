#ifndef CONNECTWIDGET_H
#define CONNECTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include "apicommunicator.h"

class ConnectWidget : public QWidget
{
  Q_OBJECT

public:
  explicit ConnectWidget(QWidget *parent = 0);
  ~ConnectWidget();

public slots:
  void onConnectClicked();

signals:
  void dataFetched(const QJsonObject &data);

private:
  ApiCommunicator *_comm;

private:
  QLineEdit *_hostServerInput;
  QPushButton *_connectButton;
};

#endif // CONNECTWIDGET_H

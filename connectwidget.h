#ifndef CONNECTWIDGET_H
#define CONNECTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

class ConnectWidget : public QWidget
{
  Q_OBJECT

public:
  explicit ConnectWidget(QWidget *parent = 0);
  ~ConnectWidget();

signals:
  void connectClicked(const QUrl &url);

private:
  QLineEdit *_hostServerInput;
};

#endif // CONNECTWIDGET_H

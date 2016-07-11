#ifndef SUMMARYWIDGET_H
#define SUMMARYWIDGET_H

#include <QWidget>

class QLineEdit;

class SummaryWidget : public QWidget
{
  Q_OBJECT
public:
  explicit SummaryWidget(QWidget *parent = 0);

signals:

public slots:
  void updateOsData(const QJsonObject &data);
  void updateCpuData(const QJsonObject &data);
  void updateRamData(const QJsonObject &data);
  void updateHddData(const QJsonObject &data);


private:
  QLineEdit *_osName;
  QLineEdit *_osArch;
  QLineEdit *_osVersion;

  QLineEdit *_cpuCount;
  QLineEdit *_cpuArch;
  QLineEdit *_cpuModel;
  QLineEdit *_cpuUsage;

  QLineEdit *_ramTotal;
  QLineEdit *_ramUsage;

  QLineEdit *_hddCount;
  QLineEdit *_hddTotal;
  QLineEdit *_hddUsage;
};

#endif // SUMMARYWIDGET_H

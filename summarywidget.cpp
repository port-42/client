#include "summarywidget.h"
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QJsonDocument>
#include <QJsonObject>

SummaryWidget::SummaryWidget(QWidget *parent) :
  QWidget(parent),
  _osName(new QLineEdit),
  _osVersion(new QLineEdit),
  _osArch(new QLineEdit),
  _cpuCount(new QLineEdit),
  _cpuModel(new QLineEdit),
  _cpuArch(new QLineEdit),
  _cpuUsage(new QLineEdit),
  _ramTotal(new QLineEdit),
  _ramUsage(new QLineEdit),
  _hddCount(new QLineEdit),
  _hddTotal(new QLineEdit),
  _hddUsage(new QLineEdit)
{
  _osName->setReadOnly(true);
  _osVersion->setReadOnly(true);
  _osArch->setReadOnly(true);
  _cpuCount->setReadOnly(true);
  _cpuModel->setReadOnly(true);
  _cpuArch->setReadOnly(true);
  _cpuUsage->setReadOnly(true);
  _ramTotal->setReadOnly(true);
  _ramUsage->setReadOnly(true);
  _hddCount->setReadOnly(true);
  _hddTotal->setReadOnly(true);
  _hddUsage->setReadOnly(true);
  _osName->setMinimumWidth(300);
  _osArch->setMinimumWidth(300);
  _osVersion->setMinimumWidth(300);
  _cpuCount->setMinimumWidth(300);
  _cpuArch->setMinimumWidth(300);
  _cpuModel->setMinimumWidth(300);
  _cpuUsage->setMinimumWidth(300);
  _ramTotal->setMinimumWidth(300);
  _ramUsage->setMinimumWidth(300);
  _hddCount->setMinimumWidth(300);
  _hddTotal->setMinimumWidth(300);
  _hddUsage->setMinimumWidth(300);

  auto mainLayout = new QVBoxLayout(this);
  auto summaryLayout = new QGridLayout;
  mainLayout->addLayout(summaryLayout);

  auto osGroup = new QGroupBox("OS");
  auto osLayout = new QFormLayout(osGroup);
  osLayout->addRow("Name", _osName);
  osLayout->addRow("Version", _osVersion);
  osLayout->addRow("Architecture", _osArch);
  summaryLayout->addWidget(osGroup, 0, 0);

  auto cpuGroup = new QGroupBox("CPU");
  auto cpuLayout = new QFormLayout(cpuGroup);
  cpuLayout->addRow("Count", _cpuCount);
  cpuLayout->addRow("Model", _cpuModel);
  cpuLayout->addRow("Architecture", _cpuArch);
  cpuLayout->addRow("Usage", _cpuUsage);
  summaryLayout->addWidget(cpuGroup, 0, 1);

  auto ramGroup = new QGroupBox("RAM");
  auto ramLayout = new QFormLayout(ramGroup);
  ramLayout->addRow("Total", _ramTotal);
  ramLayout->addRow("Usage", _ramUsage);
  summaryLayout->addWidget(ramGroup, 1, 0);

  auto hddGroup = new QGroupBox("RAM");
  auto hddLayout = new QFormLayout(hddGroup);
  hddLayout->addRow("Count", _hddCount);
  hddLayout->addRow("Total", _hddTotal);
  hddLayout->addRow("Usage", _hddUsage);
  summaryLayout->addWidget(hddGroup, 1, 1);

  auto refreshButton = new QPushButton("Refresh");
  mainLayout->addWidget(refreshButton);

  connect(refreshButton, &QPushButton::clicked, this, &SummaryWidget::refreshClicked);
}

void SummaryWidget::updateOsData(const QJsonObject &data) {
  _osName->setText(data["name"].toString());
  _osArch->setText(data["architecture"].toString());
  _osVersion->setText(data["version"].toString());
}

void SummaryWidget::updateCpuData(const QJsonObject &data) {
  _cpuCount->setText(data["count"].toString());
  _cpuArch->setText(data["architecture"].toString());
  _cpuModel->setText(data["model"].toString());
  _cpuUsage->setText(data["usage"].toString());
}

void SummaryWidget::updateRamData(const QJsonObject &data) {
  _ramTotal->setText(data["total"].toString());
  _ramUsage->setText(data["usage"].toString());
}

void SummaryWidget::updateHddData(const QJsonObject &data) {
  _hddCount->setText(data["count"].toString());
  _hddTotal->setText(data["total"].toString());
  _hddUsage->setText(data["usage"].toString());
}

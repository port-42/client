#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectwidget.h"
#include "summarywidget.h"
#include "apicommunicator.h"
#include <QStackedWidget>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  _comm(new ApiCommunicator)
{
  ui->setupUi(this);
  setMinimumSize(970, 600);
  QStackedWidget *stackWidget = new QStackedWidget(this);
  ConnectWidget *connectWidget = new ConnectWidget;
  SummaryWidget *summaryWidget = new SummaryWidget;
  stackWidget->addWidget(connectWidget);
  stackWidget->addWidget(summaryWidget);
  setCentralWidget(stackWidget);

  connect(connectWidget, &ConnectWidget::connectClicked, [=](const QUrl &url) {
    _hostAddress = url;
    refreshData();
  });
  connect(_comm, &ApiCommunicator::dataFetched, [=](){stackWidget->setCurrentIndex(1);});
  connect(_comm, &ApiCommunicator::osDataReady, summaryWidget, &SummaryWidget::updateOsData);
  connect(_comm, &ApiCommunicator::cpuDataReady, summaryWidget, &SummaryWidget::updateCpuData);
  connect(_comm, &ApiCommunicator::ramDataReady, summaryWidget, &SummaryWidget::updateRamData);
  connect(_comm, &ApiCommunicator::hddDataReady, summaryWidget, &SummaryWidget::updateHddData);
  connect(summaryWidget, &SummaryWidget::refreshClicked, this, &MainWindow::refreshData);
}

void MainWindow::refreshData() {
  _comm->fetchOsData(_hostAddress);
  _comm->fetchCpuData(_hostAddress);
  _comm->fetchRamData(_hostAddress);
  _comm->fetchHddData(_hostAddress);
}

MainWindow::~MainWindow()
{
  delete ui;
}

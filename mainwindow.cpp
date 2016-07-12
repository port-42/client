#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectwidget.h"
#include "summarywidget.h"
#include <QStackedWidget>

#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  setMinimumSize(970, 600);
  QStackedWidget *stackWidget = new QStackedWidget(this);
  ConnectWidget *connectWidget = new ConnectWidget;
  SummaryWidget *summaryWidget = new SummaryWidget;
  stackWidget->addWidget(connectWidget);
  stackWidget->addWidget(summaryWidget);
  setCentralWidget(stackWidget);

  connect(connectWidget, &ConnectWidget::osDataReady, summaryWidget, &SummaryWidget::updateOsData);
  connect(connectWidget, &ConnectWidget::cpuDataReady, summaryWidget, &SummaryWidget::updateCpuData);
  connect(connectWidget, &ConnectWidget::ramDataReady, summaryWidget, &SummaryWidget::updateRamData);
  connect(connectWidget, &ConnectWidget::hddDataReady, summaryWidget, &SummaryWidget::updateHddData);
  connect(connectWidget, &ConnectWidget::dataReady, [=](){stackWidget->setCurrentIndex(1);});
}

MainWindow::~MainWindow()
{
  delete ui;
}

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
  QStackedWidget *stackWidget = new QStackedWidget(this);
  ConnectWidget *connectWidget = new ConnectWidget(stackWidget);
  SummaryWidget *summaryWidget = new SummaryWidget(stackWidget);
  stackWidget->addWidget(connectWidget);
  stackWidget->addWidget(summaryWidget);
  setCentralWidget(stackWidget);

  connect(connectWidget, &ConnectWidget::dataFetched, summaryWidget, &SummaryWidget::displaySummary);
  connect(connectWidget, &ConnectWidget::dataFetched, [=](){stackWidget->setCurrentIndex(1);});
}

MainWindow::~MainWindow()
{
  delete ui;
}

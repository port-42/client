#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>

namespace Ui {
class MainWindow;
}

class ApiCommunicator;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void refreshData();

private:
  Ui::MainWindow *ui;

private:
  QUrl _hostAddress;
  ApiCommunicator *_comm;
};

#endif // MAINWINDOW_H

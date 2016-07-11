#ifndef SUMMARYWIDGET_H
#define SUMMARYWIDGET_H

#include <QWidget>

class QTextEdit;

class SummaryWidget : public QWidget
{
  Q_OBJECT
public:
  explicit SummaryWidget(QWidget *parent = 0);

signals:

public slots:
  void displaySummary(const QJsonObject &data);

private:
  QTextEdit *_text;
};

#endif // SUMMARYWIDGET_H

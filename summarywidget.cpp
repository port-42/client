#include "summarywidget.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QJsonDocument>
#include <QJsonObject>

SummaryWidget::SummaryWidget(QWidget *parent) :
  QWidget(parent),
  _text(new QTextEdit(this))
{
  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->addWidget(_text);
}

void SummaryWidget::displaySummary(const QJsonObject &data) {
  _text->setText(_text->toPlainText().append(QJsonDocument(data).toJson()));
}

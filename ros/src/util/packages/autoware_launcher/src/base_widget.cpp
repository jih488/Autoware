#include "base_widget.hpp"

#include <QLabel>
#include <QPainter>

#define MERGIN 4

namespace autoware_launcher {

AwBaseWidget::AwBaseWidget()
{
    title_ = new QLabel("Title:");
    value_ = new QLabel("Value");
    value_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    header_ = new QHBoxLayout;
    header_->setSpacing(MERGIN);
    header_->addWidget(title_);
    header_->addWidget(value_);

    content_ = new QLabel("data\ndata\ndata");

    auto vlayout = new QVBoxLayout;
    vlayout->setMargin(MERGIN);
    vlayout->setSpacing(MERGIN * 2);
    vlayout->addLayout(header_);
    vlayout->addWidget(content_);
    setLayout(vlayout);

    //setStyleSheet("border: 1px solid red");
    setStyleSheet("font-size: 14px");
}

void AwBaseWidget::addButton(QWidget* button)
{
    header_->addWidget(button);
}

void AwBaseWidget::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.drawRect(0, 0, width()-1, height()-1);

    int bottom = layout()->itemAt(0)->geometry().bottom() + MERGIN;
    painter.drawLine(0, bottom, width()-1, bottom);
}

}

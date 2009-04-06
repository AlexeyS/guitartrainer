#include <QtGui>

#include "fretboardwidget.h"

FretboardWidget::FretboardWidget(QWidget *parent)
    : QWidget(parent)
{
    _background.load(":/res/GuitarFretboard.bmp");
}

QSize FretboardWidget::minimumSizeHint() const
{
    return QSize(626, 86);
}

QSize FretboardWidget::maximumSize() const
{
    return QSize(626, 86);
}

void FretboardWidget::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawPixmap(0, 0, _background);

    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

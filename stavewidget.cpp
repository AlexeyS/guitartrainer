#include <QtGui>

#include "stavewidget.h"

static const unsigned int HORIZONTAL_OFFSET = 15;
static const unsigned int VERTICAL_OFFSET = 15;
static const unsigned int LINES_DISTANCE = 7;
static const unsigned int LINES_NUM = 5;
static const unsigned int ADDITIONAL_LINES_NUM = 2;

static const unsigned int MIN_HEIGHT = 2 * VERTICAL_OFFSET + (LINES_NUM + 2 * ADDITIONAL_LINES_NUM - 1) * LINES_DISTANCE;
static const unsigned int MIN_WIDTH = MIN_HEIGHT * 4;

StaveWidget::StaveWidget(QWidget *parent)
    : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

QSize StaveWidget::minimumSizeHint() const
{
    return QSize(MIN_WIDTH, MIN_HEIGHT);
}

QSize StaveWidget::sizeHint() const
{
    return QSize(20 * MIN_WIDTH, 20 * MIN_HEIGHT);
}

void StaveWidget::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // draw background
    painter.setPen(palette().dark().color());
    painter.setBrush(QBrush(Qt::white));
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

    // draw stave lines
    painter.setPen(Qt::black);
    for (unsigned int i = 0; i < height() / MIN_HEIGHT; ++i)
    {
        for (unsigned int j = 0; j < LINES_NUM; ++j)
       {
           painter.drawLine(HORIZONTAL_OFFSET,
                            VERTICAL_OFFSET + i * MIN_HEIGHT + (j + ADDITIONAL_LINES_NUM) * LINES_DISTANCE,
                            width() - HORIZONTAL_OFFSET,
                            VERTICAL_OFFSET + i * MIN_HEIGHT + (j + ADDITIONAL_LINES_NUM) * LINES_DISTANCE);
       }
    }
}

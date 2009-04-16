#include <QtGui>

#include "fretboardwidget.h"

FretboardWidget::FretboardWidget(QWidget* parent)
    : QWidget(parent)
{
}

QSize FretboardWidget::minimumSizeHint() const
{
    return QSize(626, 86);
}

void FretboardWidget::setGuitar(const Guitar& guitar)
{
    _guitar = guitar;
}
static const QColor OctaveColors[OCTAVES_COUNT] = { Qt::red,
                                                    Qt::darkRed,
                                                    Qt::yellow,
                                                    Qt::darkYellow,
                                                    Qt::green,
                                                    Qt::darkGreen,
                                                    Qt::blue,
                                                    Qt::darkBlue,
                                                    Qt::magenta };

void FretboardWidget::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(palette().dark().color());

    QPixmap woodTexture(":/res/wood.jpg");
    painter.setBrush(QBrush(woodTexture));

    QRect fretRect(0, 0, 0, 0);
    const unsigned int stringsCount =  _guitar.getStringCount();

    for (unsigned int i = 0; i < 24; ++i)
    {
        fretRect.setLeft(width() - int(width() * pow(2, - double(i) / 12)));
        fretRect.setRight(width() - int(width() * pow(2, - double(i + 1) / 12)));

        for (unsigned int j = 0; j < stringsCount; ++j)
        {
            fretRect.setTop(height() * j / stringsCount);
            fretRect.setBottom(height() * (j + 1) / stringsCount);

            //Sound sound;
            //_guitar.getFretSound(i, j, sound);
            //painter.setBrush(OctaveColors[sound.octave()]);

            painter.drawRect(fretRect);
        }

        painter.setPen(Qt::black);
        painter.drawLine(fretRect.left(), 0, fretRect.left(), height());
        painter.setPen(palette().dark().color());
    }
}

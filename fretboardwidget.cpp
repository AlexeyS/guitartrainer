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

    QBrush woodenBrush(QPixmap(":/res/wood.jpg"));
    painter.setBrush(woodenBrush);

    const int margin = 1;
    QRect fretboardRect(margin,
                        margin,
                        width() - 2 * margin,
                        height() - 2 * margin);
    painter.drawRect(fretboardRect);

    painter.setBrush(QBrush(Qt::transparent));

    const unsigned int stringsCount =  _guitar.getStringCount();
    const int realFretWidth = width() * 4 / 3;
    const int pointsConf[24] = { 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 2, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 2 };
    const int pointRadius = height() / 20;

    for (unsigned int i = 0; i < 24; ++i)
    {
        const int fretLeft = realFretWidth - int(realFretWidth * pow(2, - double(i) / 12));
        const int fretRight = realFretWidth - int(realFretWidth * pow(2, - double(i + 1) / 12));

        // draw fret points
        for (int j = 0; j < pointsConf[i]; ++j)
        {
            painter.setPen(Qt::darkGray);
            painter.setBrush(QBrush(Qt::gray));

            painter.drawEllipse(QPoint((fretRight + fretLeft) / 2,
                                       (height() - 2 * margin) * (j + 1) / (pointsConf[i] + 1)),
                                pointRadius,
                                pointRadius);
        }

        // draw frets
        painter.setPen(Qt::darkGray);
        painter.drawLine(fretRight - 1, 0, fretRight - 1, height());
        painter.setPen(Qt::black);
        painter.drawLine(fretRight, 0, fretRight, height());

        // draw marked sounds
        for (unsigned int j = 0; j < stringsCount; ++j)
        {
            const int stringY = (height() - 2 * margin) * double(j + 0.5) / stringsCount;

            Sound sound;
            _guitar.getFretSound(i, j, sound);
            if (_markedSounds.contains(sound))
            {
                painter.setBrush(OctaveColors[sound.octave()]);
                painter.drawEllipse(QPoint((fretRight + fretLeft) / 2,
                                           stringY),
                                    pointRadius,
                                    pointRadius);
            }
        }
    }

    // draw strings
    for (unsigned int j = 0; j < stringsCount; ++j)
    {
        const int stringY = (height() - 2 * margin) * double(j + 0.5) / stringsCount;

        painter.setPen(Qt::gray);
        painter.drawLine(margin, stringY - 1, width() - 2 * margin, stringY - 1);

        painter.setPen(Qt::darkGray);
        painter.drawLine(margin, stringY, width() - 2 * margin, stringY);
    }

    // draw marked sounds
    for (unsigned int i = 0; i < 24; ++i)
    {
        const int fretLeft = realFretWidth - int(realFretWidth * pow(2, - double(i) / 12));
        const int fretRight = realFretWidth - int(realFretWidth * pow(2, - double(i + 1) / 12));

        for (unsigned int j = 0; j < stringsCount; ++j)
        {
            const int stringY = (height() - 2 * margin) * double(j + 0.5) / stringsCount;

            Sound sound;
            _guitar.getFretSound(i, j, sound);
            if (_markedSounds.contains(sound))
            {
                painter.setBrush(OctaveColors[sound.octave()]);
                painter.drawEllipse(QPoint((fretRight + fretLeft) / 2,
                                           stringY),
                                    pointRadius,
                                    pointRadius);
            }
        }
    }
}

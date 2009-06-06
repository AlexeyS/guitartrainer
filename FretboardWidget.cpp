#include <QtGui>

#include "FretboardWidget.h"

FretboardWidget::FretboardWidget(QWidget* parent)
    : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

QSize FretboardWidget::minimumSizeHint() const
{
    return QSize(626, 86);
}

void FretboardWidget::setGuitar(const Guitar& guitar)
{
    _guitar = guitar;
    repaint(rect());
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

int FretboardWidget::fretPosition(int fretNumber)
{
    const int stringLen = (width() - zeroFretPos) * 4 / 3;
    return zeroFretPos + stringLen - stringLen * pow(2, - static_cast<double>(fretNumber) / 12);
}

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
    static const int pointsConf[25] = { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 2, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 2 };
    const int pointRadius = height() / 20;

    for (unsigned int i = 0; i < 25; ++i)
    {
        const int fretLeft = (i == 0) ? 0 : fretPosition(i - 1);
        const int fretRight = fretPosition(i);

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
        if (i == 0)
        {
            QRect rect(fretRight - 10, 0, 10, height());
            painter.setPen(Qt::transparent);
            painter.setBrush(QColor(50, 50, 50));
            painter.drawRect(rect);
            painter.setPen(Qt::black);
            painter.drawLine(fretRight - 10, 0, fretRight - 10, height());
            painter.drawLine(fretRight, 0, fretRight, height());
        }
        else
        {
            painter.setPen(Qt::darkGray);
            painter.drawLine(fretRight - 1, 0, fretRight - 1, height());
            painter.setPen(Qt::black);
            painter.drawLine(fretRight, 0, fretRight, height());
        }

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
    painter.setPen(Qt::black);
    for (unsigned int i = 0; i < 25; ++i)
    {
        const int fretLeft = i == 0 ? 0 : fretPosition(i - 1);
        const int fretRight = fretPosition(i);

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

#ifndef FRETBOARDWIDGET_H
#define FRETBOARDWIDGET_H

#include <QPixmap>
#include <QWidget>
#include <QList>

#include "guitar.h"
#include "sound.h"

class FretboardWidget : public QWidget
{
    Q_OBJECT

public:

    FretboardWidget(QWidget* parent = 0);

    QSize minimumSizeHint() const;

    void setGuitar(const Guitar& guitar);

    void toggleSound(const Sound& sound)
    {
        if (_markedSounds.contains(sound))
            _markedSounds.removeOne(sound);
        else
            _markedSounds.append(sound);
        repaint(rect());
    }

protected:

    void paintEvent(QPaintEvent *event);

private:

    Guitar _guitar;
    QList<Sound> _markedSounds;
};

#endif // FRETBOARDWIDGET_H

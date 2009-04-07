#ifndef FRETBOARDWIDGET_H
#define FRETBOARDWIDGET_H

#include <QPixmap>
#include <QWidget>

#include "guitar.h"

class FretboardWidget : public QWidget
{
    Q_OBJECT

public:

    FretboardWidget(QWidget* parent = 0);

    QSize minimumSizeHint() const;

    void setGuitar(const Guitar& guitar);

protected:

    void paintEvent(QPaintEvent *event);

private:

    Guitar* _guitar;

    QPixmap _background;
};

#endif // FRETBOARDWIDGET_H

#ifndef STAVEWIDGET_H
#define STAVEWIDGET_H

#include <QWidget>

class StaveWidget : public QWidget
{
Q_OBJECT

public:

    StaveWidget(QWidget* parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

protected:

    void paintEvent(QPaintEvent *event);

};

#endif // STAVEWIDGET_H

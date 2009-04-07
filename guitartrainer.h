#ifndef GUITARTRAINER_H
#define GUITARTRAINER_H

#include <QPushButton>
#include <QWidget>

#include "sound.h"
#include "fretboardwidget.h"
#include "stavewidget.h"

class GuitarTrainer : public QWidget
{
    Q_OBJECT

public:
    GuitarTrainer();
    ~GuitarTrainer();

private:

    FretboardWidget* _fretboard;
    StaveWidget* _stave;
    QPushButton* _noteButtons[NOTES_COUNT];
};

#endif // GUITARTRAINER_H

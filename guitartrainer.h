#ifndef GUITARTRAINER_H
#define GUITARTRAINER_H

#include <QWidget>

#include "sound.h"
#include "fretboardwidget.h"
#include "stavewidget.h"
#include "NoteButton.h" 

class GuitarTrainer : public QWidget
{
    Q_OBJECT

public:

    GuitarTrainer();
    ~GuitarTrainer();

private slots:

    void noteButtonClicked(Note note);

private:

    FretboardWidget* _fretboard;
    StaveWidget* _stave;
    NoteButton* _noteButtons[NOTES_COUNT];
};

#endif // GUITARTRAINER_H

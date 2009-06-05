#ifndef GUITARTRAINER_H
#define GUITARTRAINER_H

#include <QWidget>

#include "Sound.h"
#include "FretboardWidget.h"
#include "StaveWidget.h"
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

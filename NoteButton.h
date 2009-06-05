#ifndef NOTE_BUTTON_H
#define NOTE_BUTTON_H

#include <QPushButton>

#include "sound.h"

class NoteButton : public QPushButton
{
    Q_OBJECT

public:

    NoteButton(Note note)
        : QPushButton(NoteNames[note]),
          _note(note)
    {
        connect(this, SIGNAL(clicked(bool)), this, SLOT(parentClicked(bool)));
    }

signals:

    void clicked(Note note);

private slots:

    void parentClicked(bool) { emit clicked(_note); }

private:

    Note _note;
};

#endif

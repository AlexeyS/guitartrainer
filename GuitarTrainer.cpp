#include <QtGui>

#include "GuitarTrainer.h"

GuitarTrainer::GuitarTrainer()
{
    _fretboard = new FretboardWidget;
    _stave = new StaveWidget;

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    setWindowTitle(tr("Guitar Trainer"));

    mainLayout->addWidget(_fretboard, 0);
    mainLayout->addWidget(_stave, 0);

    for (int i = 0; i < NOTES_COUNT; ++i)
    {
        _noteButtons[i] = new NoteButton(static_cast<Note>(i));
        connect(_noteButtons[i], SIGNAL(clicked(Note)), SLOT(noteButtonClicked(Note)));
        buttonsLayout->addWidget(_noteButtons[i], 0);
    }
    mainLayout->addLayout(buttonsLayout, 0);
}

void GuitarTrainer::noteButtonClicked(Note note)
{
    _fretboard->toggleSound(Sound(note, FIRST_OCTAVE));
}

GuitarTrainer::~GuitarTrainer()
{
}

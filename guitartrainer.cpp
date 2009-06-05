#include <QtGui>

#include "guitartrainer.h"

GuitarTrainer::GuitarTrainer()
{
    _fretboard = new FretboardWidget;
    _stave = new StaveWidget;

    QGridLayout* mainLayout = new QGridLayout;
    QGridLayout* buttonsLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->setRowStretch(2, 1);

    mainLayout->addWidget(_fretboard, 0, 1, Qt::AlignHCenter);
    mainLayout->setRowMinimumHeight(1, 6);
    mainLayout->addWidget(_stave, 2, 1, Qt::AlignCenter);
    mainLayout->setRowMinimumHeight(3, 6);

    for (int i = 0; i < NOTES_COUNT; ++i)
    {
        _noteButtons[i] = new NoteButton(static_cast<Note>(i));
        connect(_noteButtons[i], SIGNAL(clicked(Note)), SLOT(noteButtonClicked(Note)));

        buttonsLayout->addWidget(_noteButtons[i], 0, i, Qt::AlignCenter);
    }
    mainLayout->addLayout(buttonsLayout, 4, 1);

    setLayout(mainLayout);

    setWindowTitle(tr("Guitar Trainer"));
}

void GuitarTrainer::noteButtonClicked(Note note)
{
    _fretboard->toggleSound(Sound(note, FIRST_OCTAVE));
}

GuitarTrainer::~GuitarTrainer()
{
}

#include <QtGui>

#include "GuitarTrainer.h"

GuitarTrainer::GuitarTrainer()
{
    setWindowTitle(tr("Guitar Trainer"));

    _fretboard = new FretboardWidget;
    _stave = new StaveWidget;
    _notePanel = new NotePanel;
    connect(_notePanel, SIGNAL(noteSelected(Note)), SLOT(noteSelected(Note)));

    _guitarBox = new QComboBox;
    _guitarBox->addItem(tr("6 strings, classic"));
    _guitars[0].addString(Sound(NOTE_E, FIRST_OCTAVE));
    _guitars[0].addString(Sound(NOTE_H, SMALL_OCTAVE));
    _guitars[0].addString(Sound(NOTE_G, SMALL_OCTAVE));
    _guitars[0].addString(Sound(NOTE_D, SMALL_OCTAVE));
    _guitars[0].addString(Sound(NOTE_A, LARGE_OCTAVE));
    _guitars[0].addString(Sound(NOTE_E, LARGE_OCTAVE));

    _guitarBox->addItem(tr("4 strings, bass"));
    _guitars[1].addString(Sound(NOTE_G, LARGE_OCTAVE));
    _guitars[1].addString(Sound(NOTE_D, LARGE_OCTAVE));
    _guitars[1].addString(Sound(NOTE_A, CONTR_OCTAVE));
    _guitars[1].addString(Sound(NOTE_E, CONTR_OCTAVE));
    connect(_guitarBox, SIGNAL(currentIndexChanged(int)), SLOT(guitarSelected(int)));

    _fretboard->setGuitar(_guitars[0]);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* notesLayout = new QHBoxLayout;
    QVBoxLayout* sidePane = new QVBoxLayout;

    mainLayout->addWidget(_fretboard, 0);
    mainLayout->addLayout(notesLayout);
    notesLayout->addWidget(_stave, 0);
    notesLayout->addLayout(sidePane);
    sidePane->addWidget(_guitarBox, 0);
    sidePane->addWidget(_notePanel, 0);
    sidePane->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum,
                                                  QSizePolicy::Expanding));
}

void GuitarTrainer::noteSelected(Note note)
{
    _fretboard->toggleSound(Sound(note, FIRST_OCTAVE));
}

void GuitarTrainer::guitarSelected(int index)
{
    _fretboard->setGuitar(_guitars[index]);
}

GuitarTrainer::~GuitarTrainer()
{
}

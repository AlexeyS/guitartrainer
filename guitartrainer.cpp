#include <QtGui>

#include "guitartrainer.h"

GuitarTrainer::GuitarTrainer()
{
    _fretboard = new FretboardWidget;

    QGridLayout* mainLayout = new QGridLayout;
    QGridLayout* buttonsLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->setRowStretch(1, 1);

    mainLayout->addWidget(_fretboard, 0, 1, Qt::AlignHCenter);
    mainLayout->setRowMinimumHeight(1, 6);

    for (int i = 0; i < NOTES_COUNT; ++i)
    {
        _noteButtons[i] = new QPushButton(NoteNames[i]);

        buttonsLayout->addWidget(_noteButtons[i], 0, i, Qt::AlignCenter);
    }
    mainLayout->addLayout(buttonsLayout, 2, 1);

    setLayout(mainLayout);

    setWindowTitle(tr("Guitar Trainer"));
}

GuitarTrainer::~GuitarTrainer()
{
}
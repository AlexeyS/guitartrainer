#include "guitar.h"

Guitar::Guitar()
{
    // default tune for guitar

    _tune.push_back(Sound(NOTE_E, FIRST_OCTAVE));
    _tune.push_back(Sound(NOTE_H, SMALL_OCTAVE));
    _tune.push_back(Sound(NOTE_G, SMALL_OCTAVE));
    _tune.push_back(Sound(NOTE_D, SMALL_OCTAVE));
    _tune.push_back(Sound(NOTE_A, LARGE_OCTAVE));
    _tune.push_back(Sound(NOTE_E, LARGE_OCTAVE));

    //_tune.push_back(Sound(NOTE_G, LARGE_OCTAVE));
    //_tune.push_back(Sound(NOTE_D, LARGE_OCTAVE));
    //_tune.push_back(Sound(NOTE_A, CONTR_OCTAVE));
    //_tune.push_back(Sound(NOTE_E, CONTR_OCTAVE));
}

Guitar::Guitar(const QVector<Sound>& tune)
    : _tune(tune)
{
}

bool Guitar::checkFretSound(unsigned int fret, unsigned int string, Note note) const
{
    Q_ASSERT(fret <= 24);
    Q_ASSERT(string < (unsigned int) _tune.size());

    Sound sound = _tune[string];
    for (unsigned int i = 0; i < fret; ++i)
        sound.next();

    return sound.note() == note;
}

void Guitar::getFretSound(unsigned int fret, unsigned int string, Sound& sound) const
{
    Q_ASSERT(fret <= 24);
    Q_ASSERT(string < (unsigned int) _tune.size());

    Sound curSound = _tune[string];
    for (unsigned int i = 0; i < fret; ++i)
        curSound.next();

    sound = curSound;
}

unsigned int Guitar::getStringCount() const
{
    return _tune.size();
}

#include "Guitar.h"

void Guitar::addString(const Sound& tune)
{
    _tune.push_back(tune);
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

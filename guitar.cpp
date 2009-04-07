#include "guitar.h"

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

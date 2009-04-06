#include "guitar.h"

GuitarString::GuitarString(Sound tune)
    : _tune(tune)
{
}

Sound GuitarString::getFretSound(unsigned int fret)
{
    Q_ASSERT(fret <= 24);

    Sound sound = _tune;
    for (unsigned int i = 0; i < fret; ++i)
        sound.next();

    return sound;
}

Guitar::Guitar(const QVector<GuitarString*>& strings)
    : _strings(strings)
{
}

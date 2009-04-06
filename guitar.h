#ifndef GUITAR_H
#define GUITAR_H

#include <QVector.h>

#include "sound.h"

class GuitarString
{
public:

    GuitarString(Sound tune);

    Sound getFretSound(unsigned int freat);

private:

    const Sound _tune;
};

class Guitar
{
public:

    Guitar(const QVector<GuitarString*>& strings);

private:

    QVector<GuitarString*> _strings;
};

#endif // GUITAR_H

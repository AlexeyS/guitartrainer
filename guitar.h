#ifndef GUITAR_H
#define GUITAR_H

#include <QVector>

#include "sound.h"

class Guitar
{
public:

    Guitar(const QVector<Sound>& tune);

    bool checkFretSound(unsigned int fret, unsigned int string, Note note) const;

private:

    QVector<Sound> _tune;
};

#endif // GUITAR_H

#ifndef GUITAR_H
#define GUITAR_H

#include <QVector>

#include "sound.h"

class Guitar
{
public:

    Guitar();
    Guitar(const QVector<Sound>& tune);

    bool checkFretSound(unsigned int fret, unsigned int string, Note note) const;
    void getFretSound(unsigned int fret, unsigned int string, Sound& sound) const;

    unsigned int getStringCount() const;

private:

    QVector<Sound> _tune;
};

#endif // GUITAR_H

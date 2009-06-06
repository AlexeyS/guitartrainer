#ifndef SOUND_H
#define SOUND_H

#include <QString>
#include <QVector>

enum Note
{
    NOTE_FIRST,
    NOTE_C = NOTE_FIRST,
    NOTE_Cis,
    NOTE_D,
    NOTE_Dis,
    NOTE_E,
    NOTE_F,
    NOTE_Fis,
    NOTE_G,
    NOTE_Gis,
    NOTE_A,
    NOTE_Ais,
    NOTE_H,
    NOTE_LAST = NOTE_H,
    NOTES_COUNT
};

static const QString NoteNames[NOTES_COUNT] = { "C",
                                                "C#",
                                                "D",
                                                "Eb",
                                                "E",
                                                "F",
                                                "F#",
                                                "G",
                                                "Ab",
                                                "A",
                                                "Hb",
                                                "H" };

enum Octave
{
    OCTAVE_FIRST,
    SUBCONTR_OCTAVE = OCTAVE_FIRST,
    CONTR_OCTAVE,
    LARGE_OCTAVE,
    SMALL_OCTAVE,
    FIRST_OCTAVE,
    SECOND_OCTAVE,
    THIRD_OCTAVE,
    FOURTH_OCTAVE,
    FIFTH_OCTAVE,
    OCTAVE_LAST = FIFTH_OCTAVE,
    OCTAVES_COUNT
};

static const QString OctaveNames[OCTAVES_COUNT] = { "Subcontroctave",
                                                    "Controctave",
                                                    "Large octave",
                                                    "Small octave",
                                                    "First octave",
                                                    "Second octave",
                                                    "Third octave",
                                                    "Fourth octave",
                                                    "Fifth octave" };

class Sound
{
public:

    Sound();
    Sound(Note note, Octave octave);

    void next();
    void prev();

    Note note() const;
    Octave octave() const;

    bool operator==(const Sound& o)
    {
        return _note == o._note && _octave == o._octave;
    }

private:

    Note _note;
    Octave _octave;
};


#endif // SOUND_H

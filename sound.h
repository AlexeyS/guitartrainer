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
    NOTE_B,
    NOTE_LAST = NOTE_B,
    NOTES_COUNT
};

static const QString NoteNames[NOTES_COUNT] = { "C",
                                                "Cis",
                                                "D",
                                                "Dis",
                                                "E",
                                                "F",
                                                "Fis",
                                                "G",
                                                "Gis",
                                                "A",
                                                "Ais",
                                                "B" };

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

private:

    Note _note;
    Octave _octave;
};


#endif // SOUND_H

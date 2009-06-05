#include "Sound.h"

Sound::Sound(Note note, Octave octave)
    : _note(note)
    , _octave(octave)
{
}

Sound::Sound()
    : _note(NOTE_FIRST)
    , _octave(OCTAVE_FIRST)
{
}

void Sound::next()
{
    if (_note != NOTE_LAST)
        _note = Note(_note + 1);
    else if(_octave != OCTAVE_LAST)
    {
        _octave = Octave(_octave + 1);
        _note = NOTE_FIRST;
    }
}

void Sound::prev()
{
    if (_note != NOTE_FIRST)
        _note = Note(_note - 1);
    else if(_octave != OCTAVE_FIRST)
    {
        _octave = Octave(_octave - 1);
        _note = NOTE_LAST;
    }
}

Note Sound::note() const
{
    return _note;
}

Octave Sound::octave() const
{
    return _octave;
}

#ifndef GUITARTRAINER_H
#define GUITARTRAINER_H

#include <QWidget>
#include <QComboBox>

#include "Sound.h"
#include "FretboardWidget.h"
#include "StaveWidget.h"
#include "NotePanel.h" 

class GuitarTrainer : public QWidget
{
    Q_OBJECT

public:

    GuitarTrainer();
    ~GuitarTrainer();

private slots:

    void noteSelected(Note note);
    void guitarSelected(int index);

private:

    Guitar _guitars[2];

    FretboardWidget* _fretboard;
    StaveWidget* _stave;
    NotePanel* _notePanel;
    QComboBox* _guitarBox;
};

#endif // GUITARTRAINER_H

#ifndef NOTE_PANEL_H
#define NOTE_PANEL_H

#include <QWidget>
#include <QGridLayout>

#include "NoteButton.h"

class NotePanel : public QWidget
{
    Q_OBJECT

public:

    NotePanel()
    {
        QGridLayout* layout = new QGridLayout;
        for (int i = 0; i < NOTES_COUNT; ++i)
        {
            _buttons[i] = new NoteButton(static_cast<Note>(i));
            connect(_buttons[i], SIGNAL(clicked(Note)), SLOT(noteButtonClicked(Note)));
            layout->addWidget(_buttons[i], i / 3, i % 3);
        }
        setLayout(layout);
    }

signals:

    void noteSelected(Note note);

private slots:

    void noteButtonClicked(Note note)
    {
        emit noteSelected(note);
    }

private:

    QPushButton* _buttons[NOTES_COUNT];
};

#endif

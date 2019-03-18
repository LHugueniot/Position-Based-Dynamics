#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "glwidget.h"

class KeyPress : public QWidget
{
    Q_OBJECT
public:
    explicit KeyPress(QWidget *parent=0);

protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
};


#endif // EVENTHANDLER_H

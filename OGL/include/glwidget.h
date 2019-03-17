#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <QObject>
#include <QGLWidget>
#include <QTimer>
#include <glm/glm.hpp>

#include <PBDLib>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent=0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    int time;
    std::vector<float> CamPos;
    std::vector<float> LookAt;
    float angle=0;
private:
    QTimer timer;

protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

    LuHu::PBDobject m_testObj;
};

#endif // GLWIDGET_H

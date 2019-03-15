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
private:
    QTimer timer;

protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

    const aiScene* scene=LuHu::getModel("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/deCube.obj");
    LuHu::posVector ConnectedPoints= LuHu::getConnectedPoints(scene,0);
};

#endif // GLWIDGET_H

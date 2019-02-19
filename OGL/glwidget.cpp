#include "glwidget.h"
#include <GL/glut.h>
#include <QKeyEvent>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(1);
    setFocusPolicy(Qt::StrongFocus);
    CamPos={10,10,-10};
    LookAt={0,0,0};
}

void GLWidget::initializeGL()
{
    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
    glLoadIdentity();
    gluLookAt(CamPos[0],CamPos[1],CamPos[2], LookAt[0], LookAt[1], LookAt[2], 0, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 0, 0.5);

    //    glBindBuffer(GL_ARRAY_BUFFER, buf1);
    //    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    //    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glPushMatrix();
    //auto p=Cloth.OtherObjs[0]->m_pos;
    //glTranslated(p.x,p.y,p.z);
    //glutSolidSphere(Cloth.OtherObjs[0]->m_radius,20,20);
    glPopMatrix();

    glBegin(GL_LINES);
//    for(uint i=0; i<Cloth.m_ConPtrs.size(); i++)
//    {
//        auto pA=Cloth.m_ConPtrs[i]->m_pA->m_ppos;
//        auto pB=Cloth.m_ConPtrs[i]->m_pB->m_ppos;

//        glColor3f(1, 0, 0);
//        glVertex3f(pA.x, pA.y, pA.z);
//        glColor3f(0, 1, 0);
//        glVertex3f(pB.x, pB.y, pB.z);
//    }
    glEnd();
    //gluLookAt(CamPos[0],CamPos[1],CamPos[2], LookAt[0], LookAt[1], LookAt[2], 0, 1, 0);

}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(CamPos[0],CamPos[1],CamPos[2], LookAt[0], LookAt[1], LookAt[2], 0, 1, 0);
}

//-------------------------------------------------------Camera manipulation--------------------------------------------

void GLWidget::keyPressEvent(QKeyEvent *event)
{
    makeCurrent();
    switch(event->key()){

    case Qt::Key_Escape:
        std::cout<<"Esc pressed";
        break;
    case Qt::Key_W:
        CamPos[0]+=1;
        LookAt[0]+=1;
        break;
    case Qt::Key_S:
        CamPos[0]-=1;
        LookAt[0]-=1;
        break;
    case Qt::Key_A:
        CamPos[2]+=1;
        LookAt[2]+=1;
        break;
    case Qt::Key_D:
        CamPos[2]-=1;
        LookAt[2]-=1;
        break;
    }
}

void GLWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        std::cout<<"Esc unpressed";
    }
}

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
    m_testObj.Initialize("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/deCube.obj",glm::vec3(0));

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

//    glPushMatrix();
//    //auto p=Cloth.OtherObjs[0]->m_pos;
//    //glTranslated(p.x,p.y,p.z);
//    //glutSolidSphere(Cloth.OtherObjs[0]->m_radius,20,20);
//    glPopMatrix();



    glRotatef(angle,0,1,0);


    glBegin(GL_LINES);

    for(uint i=0; i<m_testObj.getConstraints().size(); i++)
    {
        auto p1 =m_testObj.getConstraints()[i].get()->getPoint(0).get()->getP();
        auto p2 =m_testObj.getConstraints()[i].get()->getPoint(1).get()->getP();
        LuHu::printVec3(p1);
        LuHu::printVec3(p2);
        std::cout<<"\n";

        glColor3f(1, 0, 0);
        glVertex3f(p1.x, p1.y, p1.z);
        glColor3f(0, 1, 0);
        glVertex3f(p2.x, p2.y, p2.z);


        //glm::vec3 p1 = m_testObj.getConstraints()[i].get()->getPoint(0);
    }
    std::cout<<"\n\n";
    glEnd();

        glLoadIdentity();
    //gluLookAt(CamPos[0],CamPos[1],CamPos[2], LookAt[0], LookAt[1], LookAt[2], 0, 1, 0);
        angle++;

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

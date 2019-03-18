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

    m_solver= new LuHu::solver(1.0f, glm::vec3(0,-0.1,0));
    addPlain();
    //addCone();
}

void GLWidget::paintGL()
{
    glLoadIdentity();
    gluLookAt(CamPos[0],CamPos[1],CamPos[2], LookAt[0], LookAt[1], LookAt[2], 0, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 0, 0.5);

    if(simulate==true && m_solver)
    {
        m_solver->RunSolver(5.0f);

    }

    glRotatef(angle,0,1,0);
    drawPBDObjects(LINES);

    glLoadIdentity();
    //angle++;

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
        angle-=1.0;
        break;
    case Qt::Key_D:
        angle+=1.0;
        break;
    case Qt::Key_M:
        simulate=!simulate;
        break;
    case Qt::Key_N:
        //simulate=true;
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


void GLWidget::addPlain()
{
    auto m_testObj = std::shared_ptr<LuHu::PBDobject>(new LuHu::PBDobject);
    auto a=m_testObj->Initialize("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/plaine.obj",0,glm::vec3(0,5,0));
    if(a)
    {
        std::cout<<"working!";
        m_solver->addPBDobject(m_testObj);
        m_testObj->getPoints()[0]->setIM(0);
        m_testObj->getPoints()[20]->setIM(0);
    }
    else
    {
        std::cout<<"its not working";
    }
}

void GLWidget::addcube()
{
    auto m_testObj = std::shared_ptr<LuHu::PBDobject>(new LuHu::PBDobject);
    auto a=m_testObj->Initialize("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/deCube.obj",0,glm::vec3(0,5,0));
    m_solver->addPBDobject(m_testObj);
    m_testObj->getPoints()[0]->setIM(0);
}

void GLWidget::addCone()
{
    auto m_testObj = std::shared_ptr<LuHu::PBDobject>(new LuHu::PBDobject);
    auto a=m_testObj->Initialize("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/cone.obj",0,glm::vec3(0));

    if(a)
    {
        auto testobj =m_testObj->getPoints();

        std::shared_ptr<LuHu::point> topPoint;
        for(auto p : testobj)
        {
            if(p.get()->getP().y>0.1)
            {
                topPoint=p;

            }
        }
        std::shared_ptr<LuHu::point> newp(new LuHu::point(glm::vec3(0,5,0), glm::vec3(0,0,0), 1.0));

        newp->setIM(0);
        std::shared_ptr<LuHu::distanceConstraint> newCon(new LuHu::distanceConstraint(newp,topPoint));

        newCon->setRestLength(5);

        m_solver->addPBDobject(m_testObj);

        m_testObj->addPoint(newp);
        m_testObj->addConstraint(newCon);
    }
    else
    {
        std::cout<<"its not working";
    }
}

bool GLWidget::drawPBDObjects(paintType _type)
{
    uint totalNumOfObj = m_solver->getObjects().size();

    if(totalNumOfObj!=0)
    {
        for(auto o : m_solver->getObjects())
        {
            switch (_type) {
            case LINES:
            {
                glBegin(GL_LINES);


                for(uint i=0; i<o.get()->getConstraints().size(); i++)
                {
                    auto p1 =o.get()->getConstraints()[i].get()->getPoint(0).get()->getP();
                    auto p2 =o.get()->getConstraints()[i].get()->getPoint(1).get()->getP();

                    glColor3f(1, 0, 0);
                    glVertex3f(p1.x, p1.y, p1.z);
                    glColor3f(0, 1, 0);
                    glVertex3f(p2.x, p2.y, p2.z);
                }

                glEnd();
                break;
            }
            case TRIANGLES:
            {
                glBegin(GL_TRIANGLES);

                for(uint i=0; i<o.get()->getFacesPoints().size(); i+=3)
                {
                    auto p1=o.get()->getFacesPoints()[i].get()->getP();
                    auto p2=o.get()->getFacesPoints()[i+1].get()->getP();
                    auto p3=o.get()->getFacesPoints()[i+2].get()->getP();

                    glColor3f(1, 0, 0);
                    glVertex3f(p1.x, p1.y, p1.z);
                    glColor3f(0, 1, 0);
                    glVertex3f(p2.x, p2.y, p2.z);
                    glColor3f(0, 0, 1);
                    glVertex3f(p3.x, p3.y, p3.z);

                }
                glEnd();
                break;
            }
            default:
                break;
            }

        }
    }
}

void GLWidget::drawGrid(uint size)
{
    glBegin(GL_LINES);

    glEnd();
}

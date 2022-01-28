#include "openglcube.h"

OpenGlCube::OpenGlCube(QWidget *parent)
    :QOpenGLWidget{ parent }
{

}

void OpenGlCube::initializeGL()
{
    initializeOpenGLFunctions();

}

void OpenGlCube::resizeGL(int width, int height)
{
    glViewport(0,0, width, height);
}

void OpenGlCube::paintGL()
{
    glClearColor(0, 255, 255, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}

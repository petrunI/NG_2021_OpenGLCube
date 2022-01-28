#ifndef OPENGLCUBE_H
#define OPENGLCUBE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OpenGlCube : public QOpenGLWidget, public QOpenGLFunctions
{
public:
    OpenGlCube(QWidget *parent = nullptr);
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
};

#endif // OPENGLCUBE_H

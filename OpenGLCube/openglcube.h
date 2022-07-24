#ifndef OPENGLCUBE_H
#define OPENGLCUBE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QDebug>

struct VertexData
{
    VertexData(QVector3D crds, QVector2D texture):
        coordinates(crds), textCrds(texture)
    {
    }
    QVector3D coordinates;
    QVector2D textCrds;
};

class OpenGlCube : public QOpenGLWidget, public QOpenGLFunctions
{
public:
    OpenGlCube(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

    void buildShader();
    void buildModel(float mWidth);

private slots:
    void rotateUp();

private:
    int cubeWidth = 1;
    QOpenGLShaderProgram m_program;
    QMatrix4x4 m_matrix;
    QOpenGLBuffer m_coords;
    QOpenGLBuffer m_indexes;
    QOpenGLTexture *m_texture;
    QVector<GLuint> indexes;
};

#endif // OPENGLCUBE_H

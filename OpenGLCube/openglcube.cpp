#include "openglcube.h"

OpenGlCube::OpenGlCube(QWidget *parent)
    :QOpenGLWidget(parent), m_indexes(QOpenGLBuffer::IndexBuffer), m_texture(0)
{

}

void OpenGlCube::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0, 255, 255, 0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    buildShader();
    buildModel(cubeWidth);
}

void OpenGlCube::resizeGL(int width, int height)
{
    m_matrix.setToIdentity();
    m_matrix.perspective(45, width / (float)height, 0.1, 10.0);

}

void OpenGlCube::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 viewMatrix;
    viewMatrix.setToIdentity();
    viewMatrix.translate(0, 0, -5.0);

    m_texture->bind();

    m_program.bind();
    m_program.setUniformValue("qt_ModelViewProjectionMatrix", m_matrix * viewMatrix);
    m_program.setUniformValue("qt_Texture0", 0);

    m_coords.bind();

    int loc = m_program.attributeLocation("qt_Vertex");
    m_program.enableAttributeArray(loc);
    m_program.setAttributeBuffer(loc, GL_FLOAT, 0, 3, sizeof (VertexData));


    m_indexes.bind();

    int tex = m_program.attributeLocation("qt_MultiTexCoord0");
    m_program.enableAttributeArray(tex);
    m_program.setAttributeBuffer(tex, GL_FLOAT, sizeof(QVector3D), 2, sizeof (VertexData));

    glDrawElements(GL_TRIANGLES, m_indexes.size(), GL_UNSIGNED_INT, 0);

}

void OpenGlCube::buildShader()
{
    if (!m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.vsh"))
        close();
    if (!m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.fsh"))
        close();
    if (!m_program.link())
        close();

    m_texture = new QOpenGLTexture(QImage(":/surfaces1.png").mirrored());
    m_texture->setMinificationFilter(QOpenGLTexture::Nearest);
    m_texture->setMagnificationFilter(QOpenGLTexture::Linear);
    m_texture->setWrapMode(QOpenGLTexture::Repeat);
}

void OpenGlCube::buildModel(float mWidth)
{
    float halfSide = mWidth/2;
    QVector<VertexData> vertexCoords;

    vertexCoords.append(VertexData(QVector3D(-halfSide, halfSide, halfSide), QVector2D(0, 1)));
    vertexCoords.append(VertexData(QVector3D(-halfSide, -halfSide, halfSide), QVector2D(0, 0)));
    vertexCoords.append(VertexData(QVector3D(halfSide, halfSide, halfSide), QVector2D(1, 1)));
    vertexCoords.append(VertexData(QVector3D(halfSide, -halfSide, halfSide), QVector2D(1, 0)));

    vertexCoords.append(VertexData(QVector3D(halfSide, halfSide, halfSide), QVector2D(0, 1)));
    vertexCoords.append(VertexData(QVector3D(halfSide, -halfSide, halfSide), QVector2D(0, 0)));
    vertexCoords.append(VertexData(QVector3D(halfSide, halfSide, -halfSide), QVector2D(1, 1)));
    vertexCoords.append(VertexData(QVector3D(halfSide, -halfSide, -halfSide), QVector2D(1, 0)));

    vertexCoords.append(VertexData(QVector3D(halfSide, halfSide, halfSide), QVector2D(0, 1)));
    vertexCoords.append(VertexData(QVector3D(halfSide, halfSide, -halfSide), QVector2D(0, 0)));
    vertexCoords.append(VertexData(QVector3D(-halfSide, halfSide, halfSide), QVector2D(1, 1)));
    vertexCoords.append(VertexData(QVector3D(-halfSide, halfSide, -halfSide), QVector2D(1, 0)));

    vertexCoords.append(VertexData(QVector3D(-halfSide, halfSide, -halfSide), QVector2D(0, 1)));
    vertexCoords.append(VertexData(QVector3D(-halfSide, -halfSide, -halfSide), QVector2D(0, 0)));
    vertexCoords.append(VertexData(QVector3D(halfSide, halfSide, -halfSide), QVector2D(1, 1)));
    vertexCoords.append(VertexData(QVector3D(halfSide, -halfSide, -halfSide), QVector2D(1, 0)));

    vertexCoords.append(VertexData(QVector3D(-halfSide, halfSide, halfSide), QVector2D(0, 1)));
    vertexCoords.append(VertexData(QVector3D(-halfSide, -halfSide, halfSide), QVector2D(0, 0)));
    vertexCoords.append(VertexData(QVector3D(-halfSide, halfSide, -halfSide), QVector2D(1, 1)));
    vertexCoords.append(VertexData(QVector3D(-halfSide, -halfSide, -halfSide), QVector2D(1, 0)));

    vertexCoords.append(VertexData(QVector3D(halfSide, -halfSide, halfSide), QVector2D(0, 1)));
    vertexCoords.append(VertexData(QVector3D(halfSide, -halfSide, -halfSide), QVector2D(0, 0)));
    vertexCoords.append(VertexData(QVector3D(-halfSide, -halfSide, halfSide), QVector2D(1, 1)));
    vertexCoords.append(VertexData(QVector3D(-halfSide, -halfSide, -halfSide), QVector2D(1, 0)));


    for (int i = 0; i < 24; i+=4){
        indexes.append(i+0);
        indexes.append(i+1);
        indexes.append(i+2);
        indexes.append(i+2);
        indexes.append(i+1);
        indexes.append(i+3);
    }

    m_coords.create();
    m_coords.bind();
    m_coords.allocate(vertexCoords.constData(), vertexCoords.size() * sizeof(VertexData));
    m_coords.release();

    m_indexes.create();
    m_indexes.bind();
    m_indexes.allocate(indexes.constData(), indexes.size() * sizeof(GLuint));
    m_indexes.release();

}

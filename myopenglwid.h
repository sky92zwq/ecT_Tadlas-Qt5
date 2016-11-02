#ifndef MYOPENGLWID_H
#define MYOPENGLWID_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <qvector.h>
#include <qvector2d.h>
#include <QMatrix4x4>
#include <QOpenGLFunctions_1_1>

//#define DELTA 0.005

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class myOpenGLwid : public QOpenGLWidget/*, protected QOpenGLFunctions*/, public QOpenGLFunctions_1_1
{
	Q_OBJECT

public:
	myOpenGLwid(QWidget *parent = 0);
	~myOpenGLwid();

	void cleanup();

protected:
	void initializeGL()Q_DECL_OVERRIDE;
	
	void resizeGL(int w, int h)Q_DECL_OVERRIDE;
	
	void paintGL()Q_DECL_OVERRIDE;
	


	void setvertexposition();

	void setvertexcolor();
private:
	QOpenGLVertexArrayObject m_vao;
	QOpenGLBuffer m_Vbo_position,m_Vbo_color;
	QOpenGLShaderProgram *m_program;

	GLfloat Position[48 * 49 * 2*2];
    GLfloat Color[(47 * 2 + 2) * 49 * 3];
    GLfloat *color;
    GLfloat *position;
	QVector<QVector2D>  verpos;
	QMatrix4x4 m_proj;
	QMatrix4x4 m_camera;
	QMatrix4x4 m_world;
private slots:
	void drawreconstruct();

};


#endif // MYOPENGLWID_H

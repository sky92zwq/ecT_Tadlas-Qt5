#include "myopenglwid.h"

myOpenGLwid::myOpenGLwid(QWidget *parent)
    : QOpenGLWidget(parent)/*,QOpenGLFunctions()*/,QOpenGLFunctions_1_1()
{

}

myOpenGLwid::~myOpenGLwid()
{

}
void myOpenGLwid::cleanup()
{
	makeCurrent();
	delete m_program;
	m_program = 0;
	doneCurrent();
}

void myOpenGLwid::setvertexposition()//set vertex position
{	
	int flagcount = 0;
	int rowcount = 0;
	float DELTA = 0.02;
    verpos.append(QVector2D(0.2, 0.5));
    Position[0] = verpos.last().x(); Position[1] = verpos.last().y();
    for (int i = 1; i < 48 * 49 * 2; i++)
	{
        if (flagcount > 3)
        {
            flagcount = 0;
        }

        if (i % (49 * 2) == 0)
        {
            if (flagcount == 1)
                verpos.append(QVector2D(verpos.last().x(), verpos.last().y()));
            if (flagcount == 3)
                verpos.append(QVector2D(verpos.last().x(), verpos.last().y() - DELTA));
            Position[2*i] = verpos.last().x(); Position[2*i+1] = verpos.last().y();
            flagcount = 0;
            rowcount++;
            continue;
        }
        if (flagcount == 0)
        {
            verpos+=(QVector2D(verpos.last().x(), verpos.last().y()+DELTA));
        }
        if (flagcount == 1)
        {
            if(rowcount%2==0)
                verpos.append(QVector2D(verpos.last().x()+ DELTA, verpos.last().y() ));
            else
            {
                verpos.append(QVector2D(verpos.last().x() - DELTA, verpos.last().y()));
            }
        }
        if (flagcount == 2)
        {
            verpos.append(QVector2D(verpos.last().x(), verpos.last().y() - DELTA));
        }
        if (flagcount == 3)
        {
            if (rowcount % 2 == 0)
                verpos.append(QVector2D(verpos.last().x() + DELTA, verpos.last().y()));
            else
            {
                verpos.append(QVector2D(verpos.last().x() - DELTA, verpos.last().y()));
            }
        }
        Position[2 * i] = verpos.last().x(); Position[2 * i + 1] = verpos.last().y();
        flagcount ++;
        //Position[2 * i] = i/100+i*DELTA; Position[2 * i + 1] =  DELTA;
	}
}

void myOpenGLwid::setvertexcolor()//set vertex color
{	
	/*m_Vbo_color.bind();*/
	
	for (int i = 0; i < 48*49*2; i++)
	{
		//if (i % 2 == 0)//ou
		//{
		//	;
		//	;
		//	for (int j = 0; j<48; j++)
		//	{

		//	}
		//}
		//else//ji
		//{
		//	;
		//	;
		//	for (int j = 48; j > 0; j--)
		//	{

		//	};
		//}
        Color[3*i] = 0.1;
        Color[3 * i+1] = 0.2;
        Color[3 * i+2] = 0.3;
	
	}
	/*m_Vbo_color.allocate(color,48*92*2*3);*/
}
static const char *vertexShaderSourceCore =
"#version 150\n"
"attribute  vec2 vposition;\n"
"attribute  vec3 vcolor;\n"
"out vec3 varyingcolor;\n"
"void main() {\n"
"   varyingcolor=vcolor;\n"
"	if (vposition.x < 1e-4)vposition.x = 0.0f;\n"
"	if (vposition.y < 1e-4)vposition.y = 0.0f;\n"
"   gl_Position = vec4(vposition,1.0f,1.0f);\n"
"}\n";

static const char *fragmentShaderSourceCore =
"#version 150\n"
"in vec3 varyingcolor;\n"
"out vec4 vfragcolor;\n"
"void main() {\n"

"   gl_FragColor = vec4(varyingcolor, 1.0f);\n"
"}\n";


void myOpenGLwid::initializeGL()
{
	connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &myOpenGLwid::cleanup);
	// Set up the rendering context, load shaders and other resources, etc.:
    QOpenGLFunctions_1_1::initializeOpenGLFunctions();
	
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

	m_program = new QOpenGLShaderProgram;
	m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSourceCore);
	m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSourceCore);
	m_program->bindAttributeLocation("vposition", 0);
	m_program->bindAttributeLocation("vcolor", 1);
	m_program->link();

	m_program->bind();
	qDebug()<<m_program->isLinked();
	// Create a vertex array object. In OpenGL ES 2.0 and OpenGL 2.x
	// implementations this is optional and support may not be present
	// at all. Nonetheless the below code works in all cases and makes
	// sure there is a VAO when one is needed.
	m_vao.create();
	QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

	// Setup our vertex buffer object.
	m_Vbo_position.create();
	m_Vbo_position.bind();
	setvertexposition();
	m_Vbo_position.allocate(Position, 48*49*2*2);
	// Store the vertex attribute bindings for the program.
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    position=(GLfloat*)m_Vbo_position.map(QOpenGLBuffer::ReadWrite);
    m_Vbo_position.unmap();

	// Setup our vertex buffer object.
	m_Vbo_color.create();
	//m_Vbo_color.setUsagePattern(QOpenGLBuffer::DynamicDraw);
	m_Vbo_color.bind();
	setvertexcolor();
    m_Vbo_color.allocate(Color, 48*49*2*3);
	//Color=m_Vbo_color.map(QOpenGLBuffer::Access::ReadWrite);
	// Store the vertex attribute bindings for the program.
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	
}

void myOpenGLwid::resizeGL(int w, int h)
{
	// Update projection matrix and other size related settings:
	/*m_projection.setToIdentity();
	m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);*/
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);

}

void myOpenGLwid::paintGL()
{	// Draw the scene:
    makeCurrent();
    glShadeModel( GL_SMOOTH );
    glClear(GL_COLOR_BUFFER_BIT );

	//glViewport(0, 50, width(),height());
//	QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);
//	m_program->bind();
//    f->glDrawArrays(GL_QUADS,0,verpos.count()/3);
//	m_program->release();
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);

//    glBegin(GL_TRIANGLES);
//    glVertex3f(0.0,1.0,0.0);
//    glVertex3f(-1.0,-1.0,0.0);
//    glVertex3f(1.0,-1.0,0.0);
//    glEnd();
    glBegin(GL_POLYGON);

       glColor3f(0.0,0.1,0.2);//设置左下顶点坐标颜色
       glVertex3f(-0.2,-0.3,0);//设置左下顶点坐标

       glColor3f(0.1,0.2,0.3);//设置右下顶点坐标颜色
       glVertex3f(0.2,0,0);//设置右下顶点坐标

       glColor3f(0.2,0.3,0.4);//设置右上顶点坐标颜色
       glVertex3f(0.2,0.2,0);//设置右上顶点坐标

       glColor3f(0.0,0.0,0.0);//设置左上顶点坐标颜色
       glVertex3f(-0.2,0.2,0);//设置左上顶点坐标
    glEnd();
}

void myOpenGLwid::drawreconstruct()
{
	//set vertex color
	setvertexcolor();
	m_Vbo_color.bind();
	m_Vbo_color.allocate(Color, sizeof(Color));
	update();
}

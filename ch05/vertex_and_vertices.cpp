#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLfloat g_vertices[8][3] =
{
	{-0.25	,-0.25	,0.25},
	{-0.25	,0.25	,0.25},
	{0.25	,0.25	,0.25},
	{0.25	,-0.25	,0.25},
	{-0.25	,-0.25	,-0.25},
	{-0.25	,0.25	,-0.25},
	{0.25	,0.25	,-0.25},
	{0.25	,-0.25	,-0.25}
};

GLfloat g_color[8][3] =
{
	{0.2,0.2,0.2},
	{1.0,0.0,0.0},
	{1.0,1.0,0.0},
	{0.0,1.0,0.0},
	{0.0,0.0,1.0},
	{1.0,0.0,1.0},
	{1.0,1.0,1.0},
	{0.0,1.0,1.0}
};

GLubyte g_vertexList[24] =
{
	0,3,2,1, 2,3,7,6, 0,4,7,3, 1,2,6,5, 4,5,6,7, 0,1,5,4
};

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// �ݽð� ���� ����(Counter-ClockWise) - ������ ��Ģ ���
	// 0 3 2 1 ������ ������ ����ȴ�.
	glFrontFace(GL_CCW);			
	glEnable(GL_CULL_FACE);			// �� ��Ұ� ���ٸ� �ݴ��� �� �� �������� ���̸� �� �Ǵ� ���� ���̰� �ȴ�.
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	// ���� �迭 ����� ����, �÷�, �÷� �ε���, ���� ����, �ؽ�ó ��ǥ ����� ���ȴ�.
	glColorPointer(3, GL_FLOAT, 0, g_color);
	glVertexPointer(3, GL_FLOAT, 0, g_vertices);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(30.0, 1.0, 1.0, 1.0);

	for (GLint i = 0; i < 6; i++)
	{
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &g_vertexList[4 * i]);
	}

	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(200, 200);

	glutCreateWindow("vertices and color test");
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
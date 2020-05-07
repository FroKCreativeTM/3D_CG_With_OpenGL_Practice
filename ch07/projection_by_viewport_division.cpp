#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

int g_width;
int g_height;

void Init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void DrawScene()
{
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	{
		glBegin(GL_QUADS);
		{
			glVertex3f(2.0, 0.0, 2.0);
			glVertex3f(2.0, 0.0, -2.0);
			glVertex3f(-2.0, 0.0, -2.0);
			glVertex3f(-2.0, 0.0, 2.0);
		}
		glEnd();
	}
	glPopMatrix();
	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	{
		glTranslatef(0.0, 0.0, -0.5);
		glutWireTeapot(1.0);
	}
	glPopMatrix();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, g_width / 2, g_height / 2);
	glPushMatrix();
	{
		gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		DrawScene();
	}
	glPopMatrix();

	glViewport(g_width / 2, 0, g_width / 2, g_height / 2);
	glPushMatrix();
	{
		gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		DrawScene();
	}
	glPopMatrix();

	glViewport(0, g_height / 2, g_width / 2, g_height / 2);
	glPushMatrix();
	{
		gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
		DrawScene();
	}
	glPopMatrix();

	glViewport(g_width / 2, g_height / 2, g_width / 2, g_height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	{
		glLoadIdentity();
		gluPerspective(30, 1.0, 3.0, 50.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		{
			gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			DrawScene();
		}
		glPopMatrix();
	}
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}

void ReShape(int w, int h)
{
	g_width = w;
	g_height = h;
}

int main(int argc, char** argv)
{
	g_width = 500;
	g_height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(g_width, g_height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Projection By Viewport Division");
	Init();
	glutDisplayFunc(Display);
	glutReshapeFunc(ReShape);
	glutMainLoop();

	return 0;
}
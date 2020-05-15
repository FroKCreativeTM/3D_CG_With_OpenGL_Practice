#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>


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
	glPushMatrix();
	{
		DrawScene();
	}
	glPopMatrix();
	glFlush();
}

void ReShape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30, (GLdouble)w / (GLdouble)h, 1.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Projection By Viewport Division");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(Display);
	glutReshapeFunc(ReShape);
	glutMainLoop();

	return 0;
}
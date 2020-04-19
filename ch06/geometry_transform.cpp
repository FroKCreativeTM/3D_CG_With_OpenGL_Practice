#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glColor3f(1.0f, 0.5f, 0.0f);	// ���� ��ü

	
	glMatrixMode(GL_MODELVIEW);				// � ���� ���
	glLoadIdentity();						// ��� �ʱ�ȭ
	glPushMatrix();
	{
		glRotatef(45.0, 30.0, 30.0, 1.0);		// x������ 45�� y,z������ 30���� ȸ���ǰ�
		glTranslatef(0.6, 0.0, 0.0);			// �������� 0.6��ŭ �̵���
		glutSolidCube(0.3);						// 0.3 ������ ť�긦 �����϶�.

		glRotatef(0.0, 0.0, 0.0, 1.0);			// x������ 45�� y,z������ 30���� ȸ���ǰ�
		glTranslatef(-0.5, 1.0, 0.5);			// �������� 0.6��ŭ ȸ����
		glutSolidCube(0.6);						// 0.3 ������ ť�긦 �����϶�.

		glRotatef(45.0, 30.0, -30.0, 1.0);	// x������ 45�� y,z������ 30���� ȸ���ǰ�
		glTranslatef(-1.0, -0.5, 0.0);			// �������� 0.6��ŭ ȸ����
		glutSolidCube(0.3);						// 0.3 ������ ť�긦 �����϶�.
	}
	glPopMatrix();

	glFlush();	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("geometry_transform");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(display);

	glutMainLoop();
}
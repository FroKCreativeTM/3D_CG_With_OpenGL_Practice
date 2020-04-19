#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glColor3f(1.0f, 0.5f, 0.0f);	// 빨간 객체

	
	glMatrixMode(GL_MODELVIEW);				// 어떤 모델의 뷰는
	glLoadIdentity();						// 행렬 초기화
	glPushMatrix();
	{
		glRotatef(45.0, 30.0, 30.0, 1.0);		// x축으로 45도 y,z축으로 30도씩 회전되고
		glTranslatef(0.6, 0.0, 0.0);			// 원점에서 0.6만큼 이동된
		glutSolidCube(0.3);						// 0.3 비율의 큐브를 생성하라.

		glRotatef(0.0, 0.0, 0.0, 1.0);			// x축으로 45도 y,z축으로 30도씩 회전되고
		glTranslatef(-0.5, 1.0, 0.5);			// 원점에서 0.6만큼 회전된
		glutSolidCube(0.6);						// 0.3 비율의 큐브를 생성하라.

		glRotatef(45.0, 30.0, -30.0, 1.0);	// x축으로 45도 y,z축으로 30도씩 회전되고
		glTranslatef(-1.0, -0.5, 0.0);			// 원점에서 0.6만큼 회전된
		glutSolidCube(0.3);						// 0.3 비율의 큐브를 생성하라.
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
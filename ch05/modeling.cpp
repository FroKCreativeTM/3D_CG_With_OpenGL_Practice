#include <glut.h>
#include <gl/gl.h>
#include <gl/GLU.h>

/*
not ended program writing.
*/

// flatshading�� wireframe�� ��۸��ϱ� ���� �ο� ����
int flatShaded = 0;
int wireFramed = 0;

// ���콺 �����ӿ� ���� ������ �ٲٱ� ���� ����
int viewX = 0;
int viewY = 0;

void InitLight()
{
	GLfloat mat_diffuse[] = { 0.5,0.4,0.3,1.0 };
	GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat mat_ambient[] = { 0.5,0.4,0.3,1.0 };
	GLfloat mat_shininess[] = { 15.0 };
	GLfloat light_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_diffuse[] = { 0.8,0.8,0.8,1.0 };
	GLfloat light_ambient[] = { 0.3,0.3,0.3,1.0 };
	GLfloat light_position[] = { -3,6,3.0,0.0 };

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	/* LIGHT0 ������ ��Ʈ����Ʈ ����*/
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void mouseMove(GLint X, GLint Y)
{
	// ���콺 ������ X, Y�� ���� ������ ViewX, ViewY�� �Ҵ�
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q' : case 'Q' : case '\033':
		exit(0);
		break;
	case 's' : case 'S' : 
		if (flatShaded)
		{
			flatShaded = 0;
			glShadeModel(GL_SMOOTH);
		}
		else
		{
			flatShaded = 1;
			glShadeModel(GL_FLAT);
		}
		glutPostRedisplay();
		break;
		// ���⿡ ���̾� ������ ��۸��� ���� �ڵ带 ������ ��
		// ���� ���� ���� Wireframed�� ����� ��

	default:
		break;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// �� �Լ��� ������ ��Ÿ���� �Լ���
	// mouseMove �Լ��� ��ȭ�� ���� ��ȭ���� �����غ���
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 1.0, 1.0, 0.0);
	glutSolidTeapot(0.2);
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(400, 400);
	glutCreateWindow("Modeling practice");
	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(mouseMove);
	glutReshapeFunc(reshape);

	glutMainLoop();

	return 0;

}
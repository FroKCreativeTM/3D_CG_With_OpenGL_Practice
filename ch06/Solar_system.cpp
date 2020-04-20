#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

/*
�𵨸����� ���� �߿��� ���� �� �ϳ��� ���� ���� �𵨸��̴�.
�������� �����ȿ� �޷��ְ�, �����հ����� �����տ� �޷��ֵ��,
��� ���踦 �� ���� �𵨸��� �ϸ� ������ ���� ���� �ִ� �Ϳ� ���� �Ʒ��ִ� ��� ��ü���� �����̱� ������,
�� ��� ���踦 �� ������ �ϴ� ���� ���� ����. 

������ �����ϸ� �����ϰ� ������ �� ���� ���̴�.
�� ������ �߽����� �������� ȸ���ϴµ� ���� �� ���� ��� �߽����� a����ŭ ȸ���ߴٸ�,
�ٸ� �� �ȿ� �޷��ִ� ��ҵ� ���� a�� ��ŭ ȸ�� �̵��� �� ���̴�.

�¾�赵 ����������. 
�¾���� õü���� �¾��� �߽����� �̵��� �Ѵ�.
�� �¾��� �׸� �� �̿� ���ӵ� õü���� �׸� �� �̸� �����ϴ� ������� �׸��� ���� �����ϰ� �¾�踦 ��Ʈ���ϸ�
�𵨸��� �� �� ���� ���̴�.

�ٽ� ������ ���ƿͼ� ���� ���� ��ǥ�谡 ��ü�� �߽ɿ� �ִٰ� �����ϰ� GL�� �̿��ؼ� ���� �̵��� �׸��ٰ� �����ϸ�, 
�ϴ� ��ǥ�踦 ������ ����� �̵� ��Ű�µ�, x, y, z �� ������ ��ġ�� ���� ȸ�� ��ȯ��, ������ ��ġ�� ���� �̵� ��ȯ�� �Ѵ�.
�̰��� ������ Ű�׸�ƽ����� �θ���. �� ���� ������ �������� ������ �������鼭 ����ڰ� ���� �ʿ��� ��ũ�� ������ ������ ȸ����Ŵ���ν�,
���������� ���ϴ� �ڼ��� ������ ������ ���Ѵ�. ��! �� ����� ����ڰ� ������� ���ϴ� �ڼ��� �ʿ��� �� ���� �� �ִٴ� ������ ������
�� �������� ȸ������ ������ �־�����Ѵٴ� ������ �ֱ⿡
������ Ű��ƽ�� �� �������� ������ ���� ������ �Ѵ�. �̴� �������� � �������� ������ �ڵ����� ���Ǿ� �������� ���޵Ǵ� ������μ�,
���� �� ��ġ�� �����ϱ� ���� �ش� ������ �߽����� ��� ��ü�� �� ���� ȸ���ؾ� �ϴ����� ���� ���� ���Ѵ�.
*/

static int Day = 0, Time = 0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// �¾� �׸���
	glColor3f(1.0f, 0.3f, 0.3f);
	glutWireSphere(0.2, 20, 16); 
	glPushMatrix();
	{
		glRotatef((GLfloat)Day, 0.0, 1.0, 0.0); // Day��ŭ�� ����
		glTranslatef(0.7f, 0.0f, 0.0f);
		glRotatef((GLfloat)Time, 0.0f, 1.0f, 0.0f);
		// ���� �׸���
		glColor3f(0.5f, 0.6f, 0.7f);
		glutWireSphere(0.1, 10, 8);
		glPushMatrix();
		{
			glRotatef((GLfloat)Time, 0.0f, 1.0f, 0.0f);
			glTranslatef(0.2f, 0.0f, 0.0f);
			// �� �׸���
			glColor3f(0.9f, 0.8f, 0.2f);
			glutWireSphere(0.04f, 10, 8);
		}
		glPopMatrix();
	}
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd' : case 'D' : 
		Day = (Day + 10) % 360;
		glutPostRedisplay();
		break;
	case 't': case 'T':
		Time = (Time + 5) % 360;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("solar system");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0f, 1.0, -1.0f, 1.0, -1.0f, 1.0);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
}
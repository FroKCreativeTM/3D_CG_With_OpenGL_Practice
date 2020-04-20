#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

/*
모델링에서 제일 중요한 개념 중 하나인 계층 구조 모델링이다.
오른손이 오른팔에 달려있고, 오른손가락이 오른손에 달려있드시,
상속 관계를 잘 따라서 모델링을 하면 계층의 가장 위에 있는 것에 따라 아래있는 모든 개체들이 움직이기 때문에,
이 상속 관계를 잘 따르게 하는 것이 제일 좋다. 

관절을 생각하면 간단하게 이해할 수 있을 것이다.
이 관절은 중심점을 기준으로 회전하는데 만약 위 팔이 어깨 중심으로 a각만큼 회전했다면,
다른 위 팔에 달려있는 요소들 또한 a각 만큼 회전 이동을 할 것이다.

태양계도 마찬가지다. 
태양계의 천체들은 태양을 중심으로 이동을 한다.
즉 태양을 그린 뒤 이에 종속된 천체들을 그린 뒤 이를 조정하는 방식으로 그리면 아주 간단하게 태양계를 컨트롤하며
모델링을 할 수 있을 것이다.

다시 몸으로 돌아와서 만약 전역 좌표계가 몸체의 중심에 있다고 가정하고 GL을 이용해서 팔의 이동을 그린다고 생각하면, 
일단 좌표계를 몸에서 어깨로 이동 시키는데, x, y, z 축 방향의 일치를 위한 회전 변환과, 원점의 일치를 위한 이동 변환을 한다.
이것을 순방향 키네마틱스라고 부른다. 즉 계층 구조의 상위에서 하위로 내려오면서 사용자가 직접 필요한 만크믜 각도를 지정해 회전시킴으로써,
최종적으로 원하는 자세를 만들어내는 과정을 말한다. 단! 이 방식은 사용자가 마음대로 원하는 자세를 필요할 때 만들어낼 수 있다는 장점은 있으나
각 관절마다 회전값을 일일히 넣어줘야한다는 단점이 있기에
역방향 키네틱스 즉 하위부터 상위로 가는 접근을 한다. 이는 하위에서 어떤 움직임이 있으면 자동으로 계산되어 상위에도 전달되는 방식으로서,
손이 그 위치에 존재하기 위해 해당 관절을 중심으로 모든 객체가 몇 도씩 회전해야 하는지에 관한 것을 말한다.
*/

static int Day = 0, Time = 0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// 태양 그리기
	glColor3f(1.0f, 0.3f, 0.3f);
	glutWireSphere(0.2, 20, 16); 
	glPushMatrix();
	{
		glRotatef((GLfloat)Day, 0.0, 1.0, 0.0); // Day만큼의 각도
		glTranslatef(0.7f, 0.0f, 0.0f);
		glRotatef((GLfloat)Time, 0.0f, 1.0f, 0.0f);
		// 지구 그리기
		glColor3f(0.5f, 0.6f, 0.7f);
		glutWireSphere(0.1, 10, 8);
		glPushMatrix();
		{
			glRotatef((GLfloat)Time, 0.0f, 1.0f, 0.0f);
			glTranslatef(0.2f, 0.0f, 0.0f);
			// 달 그리기
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
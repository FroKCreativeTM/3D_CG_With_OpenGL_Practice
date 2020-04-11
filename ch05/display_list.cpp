#include <glut.h>
#include <gl/GL.h>
#include <gl/glu.h>

// GL �Լ��� ���� ����� �� �����̴�.
// 1. �������
// ��ü�� ȭ�鿡 �׸��� ���ÿ� ��ü ������ ���õ� ��� ������ �ı�
// ���� �� ��ü�� �ٽ� �׸����� ��� �ڵ带 ó������ �ٽ� �����ؾ��Ѵ�.
// ������ ��� �� �Ϻ� ��ü�� ���ϱ⸦ �ٶ����� ������ ��� ��ü�� �ٽ� �׷��ߵȴٴ�
// ������ �ִ�.

// 2.���� ���
// ���ǵ� ��ü ������ �״�� �����ϰ� �����Ѵ�.
// �� ��ü�� �ٽ� �׸��ٰ� �����ϸ� �̹� ���ǵ� ��ü�� �����ϵ� ���·� �����ѿ�
// ���� �ӵ��� �����Ѵٴ� ������ �ִ�.
// ���� ��� ������ ��ġ ����� �� �ѹ��� �����ϰ�, ���� ��ġ ������
// �״�� ���������ν� ���߿� �� ��ü�� �ٽ� �׸� �� �����Ѵ�.
// GL�� ���� ���� ���÷��� ����Ʈ��� ������ ���ؼ� �̷�����.
// ���� �� ����� ���÷��� ����Ʈ�� ���� �׷����� ���÷��� ����Ʈ�ʹ� �ٸ� �ǹ̸� ������.

// ���÷��� ����Ʈ�� �׷��� ó�� �ӵ��� ����ȴ�.
// ������ ��ü�� ���� �ӵ��� ó���ϱ� ���ؼ��� ���÷��� ����Ʈ�� �ʼ��̴�.
// �޸𸮿����� ���� ���Ǵ� �͵��� ĳ�ÿ� �־������ν� ���� �ӵ��� �ҷ����Ⱑ �����ϴ�.
GLint listID;

void CreateList()
{
	// ��� �� �� �Ϸ��� ���̵��� �˻��ϱ� ���� ���̴�.
	// ���ϴ� ������ parameter��.
	// ���� 3���� ���Ѵٸ�
	// listone, listtwo ,listthree
	// listone = glEndLists(3);
	// listtwo = listone + 1;
	// listthree = listtwo + 1;
	// �̷� ������ ������ �����ϴ�.
	listID = glGenLists(1);
	// ���� ����Ʈ�� ����� ������ ä���.
	// list�� ������ ����Ʈ�� ���̵�, mode�� ��ɾ� ���� ����̴�.
	// ���� GL_COMPILE_AND_EXECUTE��� ��ɾ ����ʰ� ���ÿ� 
	// ���÷��� ����Ʈ���� ����ǰ� ���� GL_COMPILE��� ������� �ʰ� ����ȴ�.
	glNewList(listID, GL_COMPILE);		
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glEndList();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glCallList(listID);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 300);
	
	glutCreateWindow("display list");
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(Display);
	CreateList();

	glutMainLoop();


	return 0;
}
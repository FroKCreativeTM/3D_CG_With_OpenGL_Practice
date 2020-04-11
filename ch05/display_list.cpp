#include <glut.h>
#include <gl/GL.h>
#include <gl/glu.h>

// GL 함수의 실행 방식은 두 가지이다.
// 1. 직접모드
// 물체를 화면에 그림과 동시에 물체 생성과 관련된 모든 정보를 파기
// 따라서 그 물체를 다시 그리려면 모든 코드를 처음부터 다시 실행해야한다.
// 복잡한 장면 중 일부 물체만 변하기를 바랄때도 나머지 모든 물체를 다시 그려야된다는
// 단점이 있다.

// 2.보류 모드
// 정의된 물체 정보를 그대로 유지하고 재사용한다.
// 즉 물체를 다시 그린다고 가정하면 이미 정의된 물체를 컴파일된 형태로 재사용한여
// 빠른 속도를 보장한다는 장점이 있다.
// 예를 들어 정점의 위치 계산은 단 한번만 실행하고, 계산된 위치 정보를
// 그대로 유지함으로써 나중에 그 물체를 다시 그릴 때 재사용한다.
// GL의 보류 모드는 디스플레이 리스트라는 개념을 통해서 이뤄진다.
// 물론 이 경우의 디스플레이 리스트는 벡터 그래픽의 디스플레이 리스트와는 다른 의미를 가진다.

// 디스플레이 리스트는 그래픽 처리 속도와 직결된다.
// 복잡한 물체를 빠른 속도로 처리하기 위해서면 디스플레이 리스트는 필수이다.
// 메모리에서는 자주 사용되는 것들을 캐시에 넣어줌으로써 빠른 속도로 불러오기가 가능하다.
GLint listID;

void CreateList()
{
	// 사용 안 된 일련의 아이디값을 검색하기 위한 것이다.
	// 원하는 갯수가 parameter다.
	// 만약 3개를 원한다면
	// listone, listtwo ,listthree
	// listone = glEndLists(3);
	// listtwo = listone + 1;
	// listthree = listtwo + 1;
	// 이런 식으로 선언이 가능하다.
	listID = glGenLists(1);
	// 실제 리스트를 만들고 내용을 채운다.
	// list는 생성될 리스트의 아이디, mode는 명령어 실행 모드이다.
	// 만약 GL_COMPILE_AND_EXECUTE라면 명령어가 실행됨과 동시에 
	// 디스플레이 리스트에도 저장되고 만약 GL_COMPILE라면 실행되지 않고 저장된다.
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
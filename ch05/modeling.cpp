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
}

int main(int argc, char ** argv)
{


}
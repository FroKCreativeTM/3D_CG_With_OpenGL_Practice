#include <glut.h>
#include <gl/gl.h>
#include <gl/GLU.h>

/*
not ended program writing.
*/

// flatshading과 wireframe을 토글링하기 위한 부울 변수
int flatShaded = 0;
int wireFramed = 0;

// 마우스 움직임에 따라 시점을 바꾸기 위한 변수
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
#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <cmath>


/* 
다음과 같은 이유로 이 함수는 느리다.
1. 실수를 쓴다.
2. 곱셈을 쓴다. (덧셈보다 크다.)
*/
void LineDraw(int x1, int y1, int x2, int y2)
{
	float y, m;
	int dx, dy;
	dx = x2 - x1; 
	dy = y2 - y1;
	m = dy / dx;			// 기울기
	for (int x = x1; x <= x2; x++)
	{
		y = m * (x - x1) + y1;
		// DrawPixel(x, round(y));
	}
}

/*
DDA(Digital Differential Analyzer)를 적용한 함수이다.
이 함수도 다음과 같은 이유로 여전히 느리다.

1. 실수를 쓴다. (정수보다 느리다.)
2. 곱셈을 쓴다. (덧셈보다 크다.)
3. round 함수 또한 느리다.
4. 연산 결과의 정밀도
*/
void LineDrawWithDDA(int x1, int y1, int x2, int y2)
{
	float y, m;
	int dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;
	m = dy / dx;			// 기울기
	y = y1;

	for (int x = x1; x <= x2; x++)
	{
		// DrawPixel(x, round(y));
		y += m;
	}
}

/*
브레스넘 알고리즘을 적용한 함수이다.
위에서 겪은 문제를 해결한다.

1. 실수를 정수로 바꾼다. 
2. 곱셈을 줄이거나 없앤다. 
3. round같은 자원을 많이 쓰는 함수를 줄인다.

이로써 정밀하면서도 빠른 함수를 만들 수 있다.

단 아래의 midpoint algorithm은 좀 더 개선될 수 있다.
*/
void MidpointLine(int x1, int y1, int x2, int y2)
{
	int dx, dy, incrE, incrNE, D, x, y;
	dx = x2 - x1; dy = y2 - y1;
	D = 2 * dy - dx;					// 결정 변수값을 초기화
	incrE = 2 * dy;						// 동쪽 화소 선택 시 증가분
	incrNE = 2 * dy - 2 * dx;			// 동북쪽 화소 선택 시 증가분
	x = x1; y = y1;						// 첫 화소
	// DrawPixel(x, y);					// 첫 화소 그리기
										// 
	while (x < x2)						// 
	{									// 
		if (D <= 0)						// 결정 변수가 음수, 동쪽 화소 선택
		{								// 
			D += incrE;					// 결정 변수 증가 
			x++;						// 다음 화소는 동쪽
		}								// 
		else							// 결정 변수가 양수, 동북쪽 화소 선택
		{								// 
			D += incrNE;				// 결정 변수 증가
			x++; y++;					// 다음 화소는 동북쪽
		}								// 
		// DrawPixel(x, y);				// 
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowSize(0, 0);
	glutCreateWindow("crossing calculation");

	return 0;
}
#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <cmath>


/* 
������ ���� ������ �� �Լ��� ������.
1. �Ǽ��� ����.
2. ������ ����. (�������� ũ��.)
*/
void LineDraw(int x1, int y1, int x2, int y2)
{
	float y, m;
	int dx, dy;
	dx = x2 - x1; 
	dy = y2 - y1;
	m = dy / dx;			// ����
	for (int x = x1; x <= x2; x++)
	{
		y = m * (x - x1) + y1;
		// DrawPixel(x, round(y));
	}
}

/*
DDA(Digital Differential Analyzer)�� ������ �Լ��̴�.
�� �Լ��� ������ ���� ������ ������ ������.

1. �Ǽ��� ����. (�������� ������.)
2. ������ ����. (�������� ũ��.)
3. round �Լ� ���� ������.
4. ���� ����� ���е�
*/
void LineDrawWithDDA(int x1, int y1, int x2, int y2)
{
	float y, m;
	int dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;
	m = dy / dx;			// ����
	y = y1;

	for (int x = x1; x <= x2; x++)
	{
		// DrawPixel(x, round(y));
		y += m;
	}
}

/*
�극���� �˰����� ������ �Լ��̴�.
������ ���� ������ �ذ��Ѵ�.

1. �Ǽ��� ������ �ٲ۴�. 
2. ������ ���̰ų� ���ش�. 
3. round���� �ڿ��� ���� ���� �Լ��� ���δ�.

�̷ν� �����ϸ鼭�� ���� �Լ��� ���� �� �ִ�.

�� �Ʒ��� midpoint algorithm�� �� �� ������ �� �ִ�.
*/
void MidpointLine(int x1, int y1, int x2, int y2)
{
	int dx, dy, incrE, incrNE, D, x, y;
	dx = x2 - x1; dy = y2 - y1;
	D = 2 * dy - dx;					// ���� �������� �ʱ�ȭ
	incrE = 2 * dy;						// ���� ȭ�� ���� �� ������
	incrNE = 2 * dy - 2 * dx;			// ������ ȭ�� ���� �� ������
	x = x1; y = y1;						// ù ȭ��
	// DrawPixel(x, y);					// ù ȭ�� �׸���
										// 
	while (x < x2)						// 
	{									// 
		if (D <= 0)						// ���� ������ ����, ���� ȭ�� ����
		{								// 
			D += incrE;					// ���� ���� ���� 
			x++;						// ���� ȭ�Ҵ� ����
		}								// 
		else							// ���� ������ ���, ������ ȭ�� ����
		{								// 
			D += incrNE;				// ���� ���� ����
			x++; y++;					// ���� ȭ�Ҵ� ������
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
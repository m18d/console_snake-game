#include<iostream>
#include<conio.h>
#include "funcion.h";

using namespace std;

enum eDir { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDir dir;



void setup(const int weight, const int hight, int& x, int& y, int& fx, int& fy, int& score)
{
	dir = STOP; //������� ��� ������������� � ����� ������� ������ �� ���������� � ��� ����� �� �����, �� ��������� �� ��������.
	x = weight / 2 - 1; //�������������� ���������� ������ �� ������� ����.
	y = hight / 2 - 1; //�������������� ��������� ������ �� ������ ����.
	fx = rand() % weight; //�������������� ���������� ������ �� ������� ����.
	fy = rand() % hight; //�������������� ��������� ������ �� ������ ����.
	score = 0; //��������� �������� �����.
}

void drow(const int weight, const int hight, const int x, const int y, const int fx, const int fy, const int score, const int nTail, int*& tailX, int*& tailY)
{
	system("cls");
	for (int i = 0; i < weight + 1; i++) //������ ������� �������.
		cout << "#";
	cout << endl;

	for (int i = 0; i < hight; i++) //������ ��� ����� ������� ������� � ������, �� ���� �� ����������� ������ �� ����, �������, � ����� �� �����.
	{
		for (int j = 0; j < weight; j++)
		{
			if (j == 0 || j == weight - 1) //���� ������ � �����.
				cout << "#";
			if (j == x && i == y) //������ ����.
				cout << "@";
			else if (i == fy && j == fx) //�����.
				cout << "0";
			else
			{
				bool flag = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)//����� ����.
					{
						cout << "o";
						flag = true;
					}
				}
				if (!flag) //������ ����.
					cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < weight + 1; i++) //������ �������� ����.
		cout << "#";
	cout << endl << "score \t" << score; //����� ���������� �����.
}

void input(int& x, int& y, bool& flag)
{
	if (_kbhit()) //�������� �������� �� �� ���-�� �� ����������.
	{
		switch (_getch()) //��������� � ���������� �������� � ����������.
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'x':
			flag = false;
			break;
		}
	}
}

void logic(const int weight, const int hight, int& x, int& y, int& fx, int& fy, int& score, bool& flag, int& nTail, int*& tailX, int*& tailY, int& size)
{
	//������ ������.
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	//������ �������� ������.
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	//������ �������� ������, ��������� ����� � ����� ����� ������.
	if (x == fx && y == fy)
	{
		score = score + 10;
		fx = rand() % weight;
		fy = rand() % hight;
		nTail++;
		delete[] tailX;
		delete[] tailY;
		size++;
		tailX = new int[size];
		tailY = new int[size];
	}
	//������ ��������� ���� � ������ �������, ���� ��� ����� �� ������.
	if (x >= weight - 1)
		x = 0;
	else if (x < 0)
		x = weight - 2;

	if (y >= hight)
		y = 0;
	else if (y < 0)
		y = hight - 2;
	//������ ������� ���������.
	//if ((x < 0) || (x > weight) || (y < 0) || (y > hight))
	//flag = false;
	for (int i = 0; i < nTail; i++) //���� ����� ���� �����
	{
		if (tailX[i] == x && tailY[i] == y)
			flag = false;
	}
}

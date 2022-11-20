#include<iostream>
#include<conio.h>
#include "level.h";

using namespace std;

enum eDir { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDir dir[2];




void setup(const int weight, const int hight, int& x, int& y, int& fx, int& fy, int& score)
{
	dir[0] = STOP; //������� ��� ������������� � ����� ������� ������ �� ���������� � ��� ����� �� �����, �� ��������� �� ��������.
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
			dir[1] = dir[0];
			dir[0] = LEFT;
			break;
		case 'd':
			dir[1] = dir[0];
			dir[0] = RIGHT;
			break;
		case 's':
			dir[1] = dir[0];
			dir[0] = DOWN;
			break;
		case 'w':
			dir[1] = dir[0];
			dir[0] = UP;
			break;
		case 'x':
			flag = false;
			break;
		}
	}
}

void logic(const int weight, const int hight, int& x, int& y, int& fx, int& fy, int& score, bool& flag, int& nTail, int*& tailX, int*& tailY, int& size, int& setting_wall)
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
	switch (dir[0])
	{
	case LEFT:
		if (dir[1] != RIGHT)
			x--;
		else
			x++;
		break;
	case RIGHT:
		if (dir[1] != LEFT)
			x++;
		else
			x--;
		break;
	case UP:
		if (dir[1] != DOWN)
			y--;
		else
			y++;
		break;
	case DOWN:
		if (dir[1] != UP)
			y++;
		else
			y--;
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
	switch (setting_wall)
	{
	case 0:
		if (x >= weight - 1)
			x = 0;
		else if (x < 0)
			x = weight - 2;
		if (y >= hight)
			y = 0;
		else if (y < 0)
			y = hight - 2;
		break;
	case 1:
		if ((x < 0) || (x > weight) || (y < 0) || (y > hight))
			flag = false;
		break;
	}
	//������ ������� ���������.
	for (int i = 0; i < nTail; i++) //���� ����� ���� �����
	{
		if (tailX[i] == x && tailY[i] == y)
			flag = false;
	}
}

#include<iostream>
#include<conio.h>
#include "level.h"
#include "Class.h"

using namespace std;

enum eDir { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDir dir[2];




void setup(field& poligonFirst, object& snake, object& fruit, int& score)
{
	dir[0] = STOP; //������� ��� ������������� � ����� ������� ������ �� ���������� � ��� ����� �� �����, �� ��������� �� ��������.
	snake.SetX(poligonFirst.GetW() / 2 - 1); //�������������� ���������� ������ �� ������� ����.
	snake.SetY(poligonFirst.GetH() / 2 - 1); //�������������� ��������� ������ �� ������ ����.
	fruit.SetX(rand() % poligonFirst.GetW()); //�������������� ���������� ������ �� ������� ����.
	fruit.SetY(rand() % poligonFirst.GetH()); //�������������� ��������� ������ �� ������ ����.
	score = 0; //��������� �������� �����.
}

void drow(field& poligonFirst, object& snake, object& fruit, const int score, const int nTail, int*& tailX, int*& tailY)
{
	system("cls");
	for (int i = 0; i < poligonFirst.GetW() + 1; i++) //������ ������� �������.
		cout << "#";
	cout << endl;

	for (int i = 0; i < poligonFirst.GetH(); i++) //������ ��� ����� ������� ������� � ������, �� ���� �� ����������� ������ �� ����, �������, � ����� �� �����.
	{
		for (int j = 0; j < poligonFirst.GetW(); j++)
		{
			if (j == 0 || j == poligonFirst.GetW() - 1) //���� ������ � �����.
				cout << "#";
			if (j == snake.GetX() && i == snake.GetY()) //������ ����.
				cout << "@";
			else if (i == fruit.GetY() && j == fruit.GetX()) //�����.
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

	for (int i = 0; i < poligonFirst.GetW() + 1; i++) //������ �������� ����.
		cout << "#";
	cout << endl << "score \t" << score; //����� ���������� �����.
}

void input(bool& flag)
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

void logic(field& poligonFirst, object& snake, object& fruit, int& score, bool& flag, int& nTail, int*& tailX, int*& tailY, int& size, int& setting_wall)
{
	//������ ������.
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = snake.GetX();
	tailY[0] = snake.GetY();
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
			snake.SetX(snake.GetX() - 1);
		else
			snake.SetX(snake.GetX() + 1);
		break;
	case RIGHT:
		if (dir[1] != LEFT)
			snake.SetX(snake.GetX() + 1);
		else
			snake.SetX(snake.GetX() - 1);
		break;
	case UP:
		if (dir[1] != DOWN)
			snake.SetY(snake.GetY() - 1);
		else
			snake.SetY(snake.GetY() + 1);
		break;
	case DOWN:
		if (dir[1] != UP)
			snake.SetY(snake.GetY() + 1);
		else
			snake.SetY(snake.GetY() - 1);
		break;
	}
	//������ �������� ������, ��������� ����� � ����� ����� ������.
	if (snake.GetX() == fruit.GetX() && snake.GetY() == fruit.GetY())
	{
		score = score + 10;
		fruit.SetX(rand() % poligonFirst.GetW());
		fruit.SetY(rand() % poligonFirst.GetH());
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
		if (snake.GetX() >= poligonFirst.GetW() - 1)
			snake.SetX(0);
		else if (snake.GetX() < 0)
			snake.SetX(poligonFirst.GetW() - 2);
		if (snake.GetY() >= poligonFirst.GetH())
			snake.SetX(0);
		else if (snake.GetY() < 0)
			snake.SetY(poligonFirst.GetH() - 2);
		break;
	case 1:
		if ((snake.GetX() < 0) || (snake.GetX() > poligonFirst.GetW()) || (snake.GetY() < 0) || (snake.GetY() > poligonFirst.GetH()))
			flag = false;
		break;
	}
	//������ ������� ���������.
	for (int i = 0; i < nTail; i++) //���� ����� ���� �����
	{
		if (tailX[i] == snake.GetX() && tailY[i] == snake.GetY())
			flag = false;
	}
}

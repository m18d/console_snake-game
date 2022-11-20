#include <iostream>;
#include "title.h";
#include "funcion.h";	

using namespace std;

void menu(int& choice)
{
	while (true)
	{
		system("cls");
		cout << "=========(Main menu)=========\n";
		cout << "1. New game.\n";
		cout << "2. Exit game.\n";
		cin >> choice;
		if (choice > 0 && choice < 3)
		{
			break;
		}
	}
}

void game() //�������, ������� ����������, ����� ������������ �������� ����� ����.
{
	const int weight = 20; //������ ����
	const int hight = 20; //������ ����
	int x, y, x_fruit, y_fruit, score; // ���������� ���� (x, y), ���������� ������� "�����" (x_fruit, y_fruit), ������� �����, ������� ������ ������������
	int ntail = 0, size = 1;//����� ������, ������ ������� � ������� ����� ��������� ���������� ���������� ������.
	int* tailX = new int[size], * tailY = new int[size];//������� � ������� ����� ���������� x � y ������ ��� ������������ ����� ����.
	bool flag = true;
	setup(weight, hight, x, y, x_fruit, y_fruit, score); //����� �������, ������� ���������� �������������� ��������� ������ ����, ������, � ����� �������� ������� �����, ������� �� ������� � ������� ����.
	while (flag)
	{
		drow(weight, hight, x, y, x_fruit, y_fruit, score, ntail, tailX, tailY); //������� ������� �������� �� ����������� ����, ��������� (���� � �� ������) � �������� � ����.
		input(x, y, flag); //������� ������� �������� �� ���� ���������� � ����������, � ������ � �������� ���� �� ������������ ������.
		logic(weight, hight, x, y, x_fruit, y_fruit, score, flag, ntail, tailX, tailY, size); //������� � ������� ���������� ��� ������ ����.
	}
	delete[] tailX;
	delete[] tailY;
}

void exit_game() //���������� ����.
{
	exit(0);
}

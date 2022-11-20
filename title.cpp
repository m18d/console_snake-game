#include <iostream>;
#include "title.h";
#include "level.h";	

using namespace std;

void menu(int& choice)
{
	while (true)
	{
		system("cls");
		cout << "=========(Main menu)=========\n";
		cout << "1. New game.\n";
		cout << "2. Setting.\n";
		cout << "3. Exit game.\n";
		cin >> choice;
		if (choice > 0 && choice < 4)
		{
			break;
		}
	}
}

void game(int& setting_wall) //�������, ������� ����������, ����� ������������ �������� ����� ����.
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
		logic(weight, hight, x, y, x_fruit, y_fruit, score, flag, ntail, tailX, tailY, size, setting_wall); //������� � ������� ���������� ��� ������ ����.
	}
	delete[] tailX;
	delete[] tailY;
}

void exit_game() //���������� ����.
{
	exit(0);
}

void setting(int& wall)
{
	int choice;
	bool flag = true;
	while (flag)
	{
		system("cls");
		cout << "1. ����� �������������� �� ������: ";
		if (wall == 0)
			cout << "����� � ��������������� �������.\n";
		else if (wall == 1)
			cout << "������� �� �����.\n";
		cout << "2. ����� �� ��������.\n";
		cout << "����: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (wall == 0)
				wall = 1;
			else if (wall == 1)
				wall = 0;
			break;
		case 2 :
			flag = false;
			break;
		}
	}
}
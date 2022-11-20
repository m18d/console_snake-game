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

void game(int& setting_wall) //Функция, которая вызывается, когда пользователь начинает новую игру.
{
	const int weight = 20; //Ширина поля
	const int hight = 20; //Высота поля
	int x, y, x_fruit, y_fruit, score; // Координаты змеи (x, y), координаты объекта "фрукт" (x_fruit, y_fruit), Счетчик очков, которые набрал пользователь
	int ntail = 0, size = 1;//Длина звоста, размер массива в котором будут храниться предыдущие координаты головы.
	int* tailX = new int[size], * tailY = new int[size];//Маасивы в которыз будут координаты x и y головы для последующего роста змеи.
	bool flag = true;
	setup(weight, hight, x, y, x_fruit, y_fruit, score); //Вызов функции, которая генерирует первоначальное положение головы змеи, фрукта, а также обнуляет счетчик очков, которое вы набрали в прошлой игре.
	while (flag)
	{
		drow(weight, hight, x, y, x_fruit, y_fruit, score, ntail, tailX, tailY); //Функция которая отвечает за отображение поля, персонажа (змеи и ее головы) и фуруктов в поле.
		input(x, y, flag); //Функция которая отвечает за ввод информации с клавиатуры, а именно в процессе игры за передвижение змейки.
		logic(weight, hight, x, y, x_fruit, y_fruit, score, flag, ntail, tailX, tailY, size, setting_wall); //Функция в которой происходит вся логика игры.
	}
	delete[] tailX;
	delete[] tailY;
}

void exit_game() //Завершение игры.
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
		cout << "1. Режим взаимодействия со стеной: ";
		if (wall == 0)
			cout << "Выход с противоположной стороны.\n";
		else if (wall == 1)
			cout << "Умирать от стены.\n";
		cout << "2. Выход из настроек.\n";
		cout << "Ввод: ";
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
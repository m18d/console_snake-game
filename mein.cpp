#include<iostream>
#include "title.h";

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	int choice, setting_wall = 0;
	while (true)
	{
		menu(choice); //Вызов начального меню.
		switch (choice)
		{
		case 1:
			game(setting_wall); //Запуск уровня.
			break;
		case 2:
			setting(setting_wall);
			break;
		case 3:
			exit_game(); //Выход и приложения.
		}
	}
}

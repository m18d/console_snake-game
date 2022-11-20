#include "funcion.h";
#include "title.h";

using namespace std;


int main()
{
	int choice;
	while (true)
	{
		menu(choice); //Вызов начального меню.
		switch (choice)
		{
		case 1:
			game(); //Запуск уровня.
			break;
		case 2:
			exit_game(); //Выход и приложения.
			break;
		}
	}
}

#include "funcion.h";
#include "title.h";

using namespace std;


int main()
{
	int choice;
	while (true)
	{
		menu(choice); //����� ���������� ����.
		switch (choice)
		{
		case 1:
			game(); //������ ������.
			break;
		case 2:
			exit_game(); //����� � ����������.
			break;
		}
	}
}

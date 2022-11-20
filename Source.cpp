#include<iostream>
#include<conio.h>


using namespace std;

enum eDir { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDir dir;

void menu(int& choice);
void game();
void setup(const int weight, const int hight, int& x, int& y, int& fx, int& fy, int &score);
void drow(const int weight, const int hight, const int x, const int y, const int fx, const int fy, const int score, const int nTail, int*& tailX, int*& tailY);
void input(int& x, int& y, bool& flag);
void logic(const int weight, const int hight, int& x, int& y, int& fx, int& fy, int& score, bool& flag, int& nTail, int*& tailX, int*& tailY, int& size);

int main()
{
	int choice;
	while (true)
	{
		menu(choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 2:
			exit(0);
			break;
		}
	}
}

void menu(int& choice)
{
	system("cls");
	cout << "=========(Main menu)=========\n";
	cout << "1. New game.\n";
	cout << "2. Exit game.\n";
	cin >> choice;
}

void game()
{
	const int weight = 20;
	const int hight = 20;
	int x, y, x_point, y_point, score;
	int ntail = 0, size = 1;
	int* tailX = new int[size], * tailY = new int[size];
	bool flag = true;
	setup(weight, hight, x, y, x_point, y_point, score);
	while (flag)
	{
		drow(weight, hight, x, y, x_point, y_point, score, ntail, tailX, tailY);
		input(x, y, flag);
		logic(weight, hight, x, y, x_point, y_point, score, flag, ntail, tailX, tailY, size);
	}
	delete[] tailX;
	delete[] tailY;
}

void setup(const int weight, const int hight, int &x, int &y, int &fx, int &fy, int &score)
{
	dir = STOP;
	x = weight / 2 - 1;
	y = hight / 2 - 1;
	fx = rand() % weight;
	fy = rand() % hight;
	score = 0;
}

void drow(const int weight, const int hight, const int x, const int y, const int fx, const int fy, const int score, const int nTail, int *& tailX, int *& tailY)
{
	system("cls");
	for (int i = 0; i < weight + 1; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < weight; j++)
		{
			if (j == 0 || j == weight - 1)
				cout << "#";
			if (j == x && i == y)
				cout << "@";
			else if (i == fy && j == fx)
				cout << "0";
			else
			{
				bool flag = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						flag = true;
					}
				}
				if (!flag)
					cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < weight + 1; i++)
		cout << "#";
	cout << endl << "score \t" << score;
}

void input(int& x, int& y, bool& flag)
{
	if (_kbhit())
	{
		switch (_getch())
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
	if (x == fx && y == fy)
	{
		score++;
		fx = rand() % weight;
		fy = rand() % hight;
		nTail++;
		delete[] tailX;
		delete[] tailY;
		size++;
		tailX = new int[size];
		tailY = new int[size];
	}
	
	//if ((x < 0) || (x > weight) || (y < 0) || (y > hight))
	//	flag = false;

	if (x >= weight)
		x = 0;
	else if (x < 0)
		x = weight - 1;

	if (y >= hight)
		y = 0;
	else if (y < 0)
		y = hight - 1;

	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			flag = false;
	}
}
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>

using namespace std;

void gotoxy(float x, float y)
{
	HANDLE hConsole;
	COORD cursorLoc;
	std::cout.flush();
	cursorLoc.X = x/10;
	cursorLoc.Y = y/10;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, cursorLoc);
}

void computer(int &x, int *&mass)
{
	int a, b;
	for (int i = 0; i < 9; i++)
	{
		if (mass[i] == 1)
		{
			a = i;
			for (int j = 0; j < 9; j++)
			{
				if (mass[i] == 1)
				{
					b = j;
				}
			}
	    }
		if (mass[i] == 1)b = i;
	}
}
void one(int x_mov,int y_mov,int x, int i,int *&mass, HDC hdc)
{
	x_mov = 0; y_mov = 0;
	for (int ii = 0; ii < 9; ii++)
	{
		if (x == ii + 1)
		{
				if ((i + 2) % 2 == 0)
				{
					MoveToEx(hdc, 50 + x_mov, 0 + y_mov, NULL);
					LineTo(hdc, 100 + x_mov, 50 + y_mov);
					MoveToEx(hdc, 50 + x_mov, 50 + y_mov, NULL);
					LineTo(hdc, 100 + x_mov, 0 + y_mov);
					mass[x - 1] = 1;
					goto out;
				}
				else
				{
					Ellipse(hdc, 55 + x_mov, 5 + y_mov, 95 + x_mov, 45 + y_mov);
					mass[x - 1] = 0;
					goto out;
				}
		}
		else
		{
			gotoxy(200, 200);
			x_mov = x_mov + 50;
			if ((ii + 1) % 3 == 0) { y_mov = y_mov + 50; }
			if ((ii + 1) % 3 == 0)x_mov = 0;
		}
	}
out:
	x_mov = 0; y_mov = 0;
}

int main(void)
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	HWND hwnd;
	char Title[1024];
	GetConsoleTitle(Title, 1024); // ”знаем им€ окна
	hwnd = FindWindow(NULL, Title); // ”знаем hwnd окна
	HDC hdc = GetDC(hwnd);    // ѕолучаем контекст дл€ рисовани€
	HPEN p1, p2 = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); 
	HPEN pp, pp2 = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	p1 = (HPEN)SelectObject(hdc, p2);  // «аносим красное перо в контекст рисовани€

	int mass[9] = { 3,3,3,3,3,3,3,3,3 };
	gotoxy(90, 25);	    cout << 1;
	gotoxy(150, 25);	cout << 2;
	gotoxy(210, 25);	cout << 3;
	gotoxy(90, 60);	    cout << 4;
	gotoxy(150, 60);	cout << 5;
	gotoxy(210, 60);	cout << 6;
	gotoxy(90, 100);	cout << 7;
	gotoxy(150, 100);	cout << 8;
	gotoxy(210, 100);	cout << 9;

	for (int i = 0; i <=150; i=i+50)
	{
		MoveToEx(hdc, 50+i, 0, NULL);
		LineTo(hdc, 50+i, 150);
		MoveToEx(hdc, 50, 0+i, NULL);
		LineTo(hdc, 200, 0+i);
	}
	int x; int x_mov = 0, y_mov = 0, mov = 0;
	for (int i = 0; i < 9; i++)
	{
		lab:
		if (i == 0 || i % 2 == 0)
		{
			x = rand() % 9 + 1;
		}else{

			gotoxy(300, 0);
			cout << "¬ведите сектор" << endl;
			gotoxy(300, 10);
			cin >> x;
			gotoxy(300, 10);
			cout << "                                    ";
			gotoxy(300, 30);
			cout << "                                    ";
		}
		if (mass[x - 1] != 3) { gotoxy(300, 30); cout << "сектор зан€т"; goto lab; }
		x_mov = 0; y_mov = 0;
		for (int ii = 0; ii < 9; ii++)
		{
			if (x == ii + 1)
			{
				// out возможно не нужна
				
					if ((i + 2) % 2 == 0)
					{
						MoveToEx(hdc, 50 + x_mov, 0 + y_mov, NULL);
						LineTo(hdc, 100 + x_mov, 50 + y_mov);
						MoveToEx(hdc, 50 + x_mov, 50 + y_mov, NULL);
						LineTo(hdc, 100 + x_mov, 0 + y_mov);
						mass[x - 1] = 1;
						goto out;
					}
					else
					{
						Ellipse(hdc, 55 + x_mov, 5 + y_mov, 95 + x_mov, 45 + y_mov);
						mass[x - 1] = 0;
						goto out;
					}
			}
			else
			{
				gotoxy(200, 200);
				x_mov = x_mov + 50;
				if ((ii+1) % 3 == 0) { y_mov = y_mov + 50; }
				if ((ii + 1) % 3 == 0)x_mov = 0;
			}
		}
		out:
		x_mov = 0; y_mov = 0;
			if (mass[0] == 1 && mass[4] == 1 && mass[8] == 1)
			{
				gotoxy(0, 130);
				cout << "win x";
				break;
			}
			if (mass[0] == 0 && mass[4] == 0 && mass[8] == 0)
			{
				gotoxy(0, 130);
				cout << "win circle";
				break;
			}
			if (mass[2] == 1 && mass[4] ==1 && mass[6] == 1)
			{
				gotoxy(0, 130);
				cout << "win x";
				break;
			}
			if (mass[2] == 0 && mass[4] == 0 && mass[6] == 0)
			{
				gotoxy(0, 130);
				cout << "win circle";
				break;
			}
			for (int j = 0; j < 9; j = j + 3)
			{
				if (mass[0 + j] ==1 && mass[1 + j] == 1 && mass[2 + j] ==1)
				{
					gotoxy(0, 130);
					cout << "win x";
					goto babel;
				}
				if (mass[0 + j] == 0 && mass[1 + j] == 0 && mass[2 + j] == 0)
				{
					gotoxy(0, 130);
					cout << "win circle";

					goto babel;
				}
			}
			for (int j = 0; j < 9; j = j + 2)
			{
				if (mass[0 + j] ==1 && mass[3 + j] == 1 && mass[6 + j] == 1)
				{
					gotoxy(0, 130);
					cout << "win x";
					goto babel;
				}
				if (mass[0 + j] == 0 && mass[3 + j] == 0 && mass[6 + j] ==0)
				{
					gotoxy(0, 130);
					cout << "win circle";
					goto babel;
				}
			}
	}
	babel:
	gotoxy(0, 140);
	cin.get();
	system("pause");
	return 0;
}
/*if (x == 1)
		{
			if (mass[0] != 3) { gotoxy(300, 30); cout << "сектор зан€т"; goto lab; }
			else
			{
				if ((i + 2) % 2 == 0)
				{
					MoveToEx(hdc, 50, 0, NULL);
					LineTo(hdc, 100, 50);
					MoveToEx(hdc, 50, 50, NULL);
					LineTo(hdc, 100, 0);
					mass[0] = 1;
				}
				else
				{
					Ellipse(hdc, 55, 5, 95, 45);
					mass[0] = 0;
				}
			}
		}
		if (x == 2)
		{
			if (mass[1] != 3) { gotoxy(300, 30); cout << "сектор зан€т"; goto lab; }
			else
			{
				if ((i+2) % 2 == 0)
				{
					MoveToEx(hdc, 100, 0, NULL);
					LineTo(hdc, 150, 50);
					MoveToEx(hdc, 100, 50, NULL);
					LineTo(hdc, 150, 0);
					mass[1] = 1;
				}
				else
				{
					Ellipse(hdc, 105, 5, 145, 45);
					mass[1] = 0;
				}
			}
		}
		if (x == 3)
		{
			if (mass[2] != 3) { gotoxy(300, 30); cout << "сектор зан€т"; goto lab; }
			else
			{
				if ((i + 2) % 2 == 0)
				{
					MoveToEx(hdc, 150, 0, NULL);
					LineTo(hdc, 200, 50);
					MoveToEx(hdc, 150, 50, NULL);
					LineTo(hdc, 200, 0);
					mass[2] = 1;
				}
				else
				{
					Ellipse(hdc, 155, 5, 195, 45);
					mass[2] = 0;
				}
			}
		}
		if (x == 4)
		{
			if (mass[3] != 3) { gotoxy(300, 30); cout << "сектор зан€т"; goto lab; }
			else
			{
				if ((i+2) % 2 == 0)
				{
					MoveToEx(hdc, 50, 50, NULL);
					LineTo(hdc, 100, 100);
					MoveToEx(hdc, 50, 100, NULL);
					LineTo(hdc, 100, 50);
					mass[3] = 1;
				}
				else
				{
					Ellipse(hdc, 55, 55, 95, 95);
					mass[3] = 0;
				}
			}
		}
		if (x == 5)
		{
				if (mass[4] != 3) { gotoxy(300, 30); cout << "сектор зан€т"; goto lab; }
				else
				{
					if ((i+2) % 2 == 0)
					{
						MoveToEx(hdc, 100, 50, NULL);
						LineTo(hdc, 150, 100);
						MoveToEx(hdc, 100, 100, NULL);
						LineTo(hdc, 150, 50);
						mass[4] = 1;
					}
					else
					{
						Ellipse(hdc, 105, 55, 145, 95);
						mass[4] = 0;
					}
				}
		}
		if (x == 6)
		{
			if (mass[5] != 3) { gotoxy(300, 30); cout << "сектор зан€т"; goto lab; }
			else {
				if ((i+2) % 2 == 0)
				{
					MoveToEx(hdc, 150, 50, NULL);
					LineTo(hdc, 200, 100);
					MoveToEx(hdc, 150, 100, NULL);
					LineTo(hdc, 200, 50);
					mass[5] = 1;
				}
				else
				{
					Ellipse(hdc, 155, 55, 195, 95);
					mass[5] = 0;
				}
			}
		}
		if (x == 7)
		{
			if (mass[6] != 3) { gotoxy(300, 30); cout << "сектор зан€т"; goto lab; }
			else {
				if ((i + 2) % 2 == 0)
				{
					MoveToEx(hdc, 50, 100, NULL);
					LineTo(hdc, 100, 150);
					MoveToEx(hdc, 50, 150, NULL);
					LineTo(hdc, 100, 100);
					mass[6] = 1;
				}
				else
				{
					Ellipse(hdc, 55, 105, 95, 145);
					mass[6] = 0;
				}
			}
		}
		if (x == 8)
		{
			if (mass[7] != 3) { gotoxy(300, 30); cout << "сектор зан€т"; goto lab; }
			else {
				if ((i+2) % 2 == 0)
				{
					MoveToEx(hdc, 100, 100, NULL);
					LineTo(hdc, 150, 150);
					MoveToEx(hdc, 100, 150, NULL);
					LineTo(hdc, 150, 100);
					mass[7] = 1;
				}
				else
				{
					Ellipse(hdc, 105, 105, 145, 145);
					mass[7] = 0;
				}
			}
		}
		if (x == 9)
		{
			if (mass[8] != 3) { gotoxy(300, 30); cout << "сектор зан€т"; goto lab; }
			else {
				if ((i+2) % 2 == 0)
				{
					MoveToEx(hdc, 150, 100, NULL);
					LineTo(hdc, 200, 150);
					MoveToEx(hdc, 150, 150, NULL);
					LineTo(hdc, 200, 100);
					mass[8] = 1;
				}
				else
				{
					Ellipse(hdc, 155, 105, 195, 145);
					mass[8] = 0;
				}
			}
		}*/
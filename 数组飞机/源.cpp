#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void Fly_printf(int a[][33])
{
	system("cls");
	for (int i = 0; i < 13; ++i)
	{
		for (int j = 0; j < 33; ++j)
		{
			if (a[i][j] == 0)
				cout << ' ';
			else if (a[i][j] == 1)
				cout << '*';
			else if (a[i][j] == 2)
				cout << 'A';
		}
		cout << endl;
	}
	return;
}
int main()
{
	int scr[13][33] = { 0 };
	int p_x = 6, p_y = 5;
	int bullet_x, bullet_y;
	scr[p_x][p_y] = 1;
	Fly_printf(scr);
	while (1)
	{
		if(_kbhit())
			switch (_getch())
			{
			case 'a':
				scr[p_x][p_y--] = 0;
				scr[p_x][p_y] = 1;
				Fly_printf(scr);
				break;
			case 'd':
				scr[p_x][p_y++] = 0;
				scr[p_x][p_y] = 1;
				Fly_printf(scr);
				break;
			case 'w':
				scr[p_x--][p_y] = 0;
				scr[p_x][p_y] = 1;
				Fly_printf(scr);
				break;
			case 's':
				scr[p_x++][p_y] = 0;
				scr[p_x][p_y] = 1;
				Fly_printf(scr);
				break;
			case ' ':
				bullet_x = p_x - 1;
				bullet_y = p_y;
				scr[bullet_x][bullet_y] = 2;
				break;

			}
		while (bullet_x >= 0)
		{
			scr[bullet_x--][bullet_y] = 0;
			scr[bullet_x][bullet_y] = 2;
			Fly_printf(scr);
		}
	}
	system("pause");  

	return 0;
}
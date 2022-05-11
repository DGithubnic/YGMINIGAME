#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct FVector2D
{
	int X;
	int Y;
};

char Map[10][10] = {
	{'#','#','#','#','#','#','#','#','#','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ','#',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#'}
};


void SetLocation(FVector2D NewLocation);

void DrawBG(FVector2D StartPosition)
{
	for (int X = 0; X < 10; ++X)
	{
		for (int Y = 0; Y < 10; ++Y)
		{
			FVector2D Temp;
			Temp.X = X + StartPosition.X;
			Temp.Y = Y + StartPosition.Y;
			SetLocation(Temp);
			cout << Map[X][Y];
		}
	}
}

int main()
{
	bool bRunning = true;
	FVector2D PlayerPosition;
	PlayerPosition.X = 0;
	PlayerPosition.Y = 0;

	srand(static_cast<unsigned int>(time(nullptr)));
	FVector2D StartPosition;
	StartPosition.X = rand() % 10 + 1;
	StartPosition.Y = rand() % 10 + 1;

	int W = 0;
	int S = 0;
	int A = 0;
	int D = 0;

	while (bRunning)
	{
		int KeyCode = _getch();

		switch (KeyCode)
		{
		case 'w':
		case 'W':
			PlayerPosition.Y--;
			W++;
			break;
		case 's':
		case 'S':
			PlayerPosition.Y++;
			S++;
			break;
		case 'a':
		case 'A':
			PlayerPosition.X--;
			A++;
			break;
		case 'd':
		case 'D':
			PlayerPosition.X++;
			D++;
			break;
		case 27:
			bRunning = false;
			break;
		}

		if (Map[(PlayerPosition.X) % 10][(PlayerPosition.Y) % 10] == '#')
		{
			if (W == 1)
			{
				PlayerPosition.Y++;
			}
			else if (S == 1)
			{
				PlayerPosition.Y--;
			}
			else if (A == 1)
			{
				PlayerPosition.X++;
			}
			else if (D == 1)
			{
				PlayerPosition.X--;
			}
		}

		W = 0;
		S = 0;
		A = 0;
		D = 0;


		PlayerPosition.X = PlayerPosition.X < 1 ? 1 : PlayerPosition.X;
		PlayerPosition.Y = PlayerPosition.Y < 1 ? 1 : PlayerPosition.Y;

		system("cls");

		DrawBG(StartPosition);
		FVector2D Temp;
		Temp.X = PlayerPosition.X + StartPosition.X;
		Temp.Y = PlayerPosition.Y + StartPosition.Y;
		SetLocation(Temp);
		cout << "P";
	}


	return 0;
}


void SetLocation(FVector2D NewLocation)
{
	COORD Cur;
	Cur.X = NewLocation.X;
	Cur.Y = NewLocation.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
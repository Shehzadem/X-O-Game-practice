#include <iostream>
using namespace std;


void DrawBoard(char** board)
{
	int height = 4;
	int width = 12;
	int x, y;
	for (int i = 0; i < height; i++)
	{
		x = i - 1;
		y = -1;
		if (i == 0)
		{
			for (int j = 0; j < width; j++)
			{
				cout << "_";
			}
			cout << endl;
		}
		else
		{
			for (int j = 0; j < width; j++)
			{
				if (j % 4 == 0)
				{
					cout << "|";
					y++;
				}
				else
				{
					if (board[x][y] != ' ' && (j == 2 ||
						j == 6 || j == 10))
						cout << board[x][y];
					else
						cout << "_";
				}
			}
			cout << "|";
			cout << endl;
		}
	}
}

char CheckWinner(char** board)
{

}

void main()
{
	char** board = new char* [3];
	for (int i = 0; i < 3; i++)
	{
		board[i] = new char[3];
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}

	DrawBoard(board);

	int choices = 0;
	bool isX = true;
	while (choices < 9)
	{
		int X, Y;
		cout << "Please enter X and Y for your location: ";
		cin >> X >> Y;
		while (board[X][Y] != ' ')
		{
			cout << "Location is not empty! Please try to input again: ";
			cin >> X >> Y;
		}

		if (isX)
		{
			board[X][Y] = 'X';
		}
		else
		{
			board[X][Y] = 'O';
		}

		isX = !isX;
		char winner = CheckWinner(board);
		if (winner == 'X')
		{
			cout << "X won!" << endl;
			return;
		}
		else
		{
			cout << "O won!" << endl;
			return;
		}
		DrawBoard(board);
	}
}
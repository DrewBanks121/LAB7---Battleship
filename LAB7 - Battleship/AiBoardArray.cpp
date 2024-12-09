#include "AiBoardArray.h"
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

char AiBoard[10][10];

AiBoardArray::AiBoardArray()
{
	setBoard();
}

AiBoardArray::~AiBoardArray()
{
}
//Sets the board to all ~
void AiBoardArray::setBoard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			AiBoard[i][j] = '~';
		}
	}
}
//Prints the board
void AiBoardArray::printBoard()
{
	cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << i + 1;
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		if (i < 9) {
			cout << i + 1 << " ";
			cout << setw(2);
			for (int j = 0; j < 10; j++)
			{

				cout << AiBoard[i][j] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << i + 1 << " ";
			for (int j = 0; j < 10; j++)
			{
				cout << AiBoard[i][j] << " ";
			}
			cout << endl;
		}
	}
}
//Checks if the ship can be placed on the board
bool AiBoardArray::checkShipPlacement(int size, int direction, int x, int y)
{
	x = x - 1;
	y = y - 1;
	bool validPlacement = true;
	int i = size;
	while (i != 0 && validPlacement == true)
	{
		switch (direction)
		{
		case 1: // Up
			if (AiBoard[y][x] == '~')
			{
				y--;
			}
			else
			{
				validPlacement = false;
				break;
			}
			break;
		case 2: // Down
			if (AiBoard[y][x] == '~')
			{
				y++;
			}
			else
			{
				validPlacement = false;
				break;
			}
			break;
		case 3: // Left
			if (AiBoard[y][x] == '~')
			{
				x--;
				if (x < 0)
				{
					validPlacement = false;
					break;
				}
			}
			else
			{
				validPlacement = false;
				break;
			}
			break;
		case 4: // Right
			if (AiBoard[y][x] == '~')
			{
				x++;
				if (x > 10)
				{
					validPlacement = false;
					break;
				}
			}
			else
			{
				validPlacement = false;
				break;
			}
			break;
		}
		i--;
	}

	return validPlacement;
}
//Places the ship on the board
void AiBoardArray::placeShip(int size, int direction, int x, int y)
{
	x = x - 1;
	y = y - 1;
	int i = size;
	while (i != 0)
	{
		switch (direction)
		{
		case 1: // Up
			AiBoard[y][x] = '#';
			y--;
			break;
		case 2: // Down
			AiBoard[y][x] = '#';
			y++;
			break;
		case 3: // Left
			AiBoard[y][x] = '#';
			x--;

			break;
		case 4: // Right
			AiBoard[y][x] = '#';
			x++;
			break;
		}
		i--;
	}
}

void AiBoardArray::setAttackBoard(char AttackBoard[10][10])
{
}
//Checks if the player hit a ship
bool AiBoardArray::checkHit(int x, int y)
{
	if (AiBoard[y][x] == '#')
	{
		AiBoard[y][x] = 'H';
		return true;
	}
	else
	{
		AiBoard[y][x] = 'M';
		return false;
	}
}


//Places ships on the board
void AiBoardArray::aiAddShips()
{
	srand(static_cast<unsigned int>(time(0)));
	int x, y;
	int direction;

	for (int i = 0; i < 5; i++)
	{


		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		direction = rand() % 4 + 1;
		if (checkShipPlacement(shipSize(i), direction, x, y))
		{
			placeShip(shipSize(i), direction, x, y);

		}
		else
		{
			i--;
		}
	}
}


int AiBoardArray::shipSize(int shipNumber)
{
	int size;
	switch (shipNumber)
	{
	case 0: // First ship (Size 5)
		size = 5;
		break;
	case 1: // Second ship (Size 4)
		size = 4;
		break;
	case 2: // Third ship (Size 3)
		size = 3;
		break;
	case 3: // Fourth ship (Size 3)
		size = 3;
		break;
	case 4: // Fifth ship (Size 2)
		size = 2;
		break;
	default:
		size = 0; // In case of an invalid shipNumber
		break;
	}
	return size;
}

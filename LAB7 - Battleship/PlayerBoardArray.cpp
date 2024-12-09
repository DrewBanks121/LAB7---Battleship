#include "PlayerBoardArray.h"
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

char PlayerBoard[10][10];


PlayerBoardArray::PlayerBoardArray()
{
	setBoard();
}

PlayerBoardArray::~PlayerBoardArray()
{
}
//Sets the board to all ~
void PlayerBoardArray::setBoard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			PlayerBoard[i][j] = '~';
		}
	}
}
//Prints the board
void PlayerBoardArray::printBoard()
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

				cout << PlayerBoard[i][j] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << i + 1 << " ";
			for (int j = 0; j < 10; j++)
			{
				cout << PlayerBoard[i][j] << " ";
			}
			cout << endl;
		}
	}
}
//Checks if the ship can be placed
bool PlayerBoardArray::checkShipPlacement(int size, int direction, int x, int y)
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
			if (PlayerBoard[y][x] == '~')
			{
				y--;
			}
			else
			{
				validPlacement = false;
				cout << "Invalid placement" << endl;
				break;
			}
			break;
		case 2: // Down
			if (PlayerBoard[y][x] == '~')
			{
				y++;
			}
			else
			{
				validPlacement = false;
				cout << "Invalid placement" << endl;
				break;
			}
			break;
		case 3: // Left
			if (PlayerBoard[y][x] == '~')
			{
				x--;
				if (x < 0)
				{
					validPlacement = false;
					cout << "Invalid placement" << endl;
					break;
				}
			}
			else
			{
				validPlacement = false;
				cout << "Invalid placement" << endl;
				break;
			}
			break;
		case 4: // Right
			if (PlayerBoard[y][x] == '~')
			{
				x++;
				if (x > 9)
				{
					validPlacement = false;
					cout << "Invalid placement" << endl;
					break;
				}
			}
			else
			{
				validPlacement = false;
				cout << "Invalid placement" << endl;
				break;
			}
			break;
		default:
			validPlacement = false;
			cout << "Error" << endl;
			break;
		}
		i--;
	}

	return validPlacement;
}

//Places the ship on the board
void PlayerBoardArray::placeShip(int size, int direction, int x, int y)
{
	x = x - 1;
	y = y - 1;
	int i = size;
	while (i != 0)
	{
		switch (direction)
		{
		case 1: // Up
			PlayerBoard[y][x] = '#';
			y--; 
			break;
		case 2: // Down
			PlayerBoard[y][x] = '#';
			y++;
			break;
		case 3: // Left
			PlayerBoard[y][x] = '#';
			x--;
			
			break;
		case 4: // Right
			PlayerBoard[y][x] = '#';
			x++;
			break;
		}
		i--;
	}
}
//Sets the attack board to all ~
void PlayerBoardArray::setAttackBoard(char AttackBoard[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			AttackBoard[i][j] = '~';
		}
	}
	
	
}
//Checks if the attack is a hit or miss
bool PlayerBoardArray::checkHit(int x, int y)
{
	if (PlayerBoard[y][x] == '#')
	{
		PlayerBoard[y][x] = 'H';
		return true;
	}
	else
	{
		PlayerBoard[y][x] = 'M';
		return false;
	}
}
//Checks if the attack has already been made
bool PlayerBoardArray::checkIfAlreadyHit(int x, int y)
{
	if (PlayerBoard[y][x] == 'H' || PlayerBoard[y][x] == 'M')
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
//Changes the player board
void PlayerBoardArray::changePlayerBoard(int x, int y, char c)
{
	PlayerBoard[y][x] = c;

}

//Adds the ships to the board
void PlayerBoardArray::AddShips()
{
	bool Second3Ship = false;
	int x, y;
	char comma;
	int direction;
	for (int i = 0; i < 5; i++)
	{
		printBoard();
		placingShip = true;
	
			if (i == 3 && Second3Ship == false)
			{
				while (placingShip)
				{
					cout << "Enter the cordnates for ship " << i + 1 << " (Size " << shipSize(i) << ")" << " (x,y): ";
					cin >> x >> comma >> y;
					if (cin.fail() || x > 10 || x < 1 || y < 1 || y > 10)
					{
						cin.clear();
						cin.ignore();
						cout << "Invalid input" << endl;
					
					}
					else
					{
						cout << "What direction would you like the ship to face? (1 = Up, 2 = Down, 3 = Left, 4 = Right): ";
						cin >> direction;
						if (cin.fail() || direction > 4 || direction < 1)
						{
							cin.clear();
							cin.ignore();
							cout << "Invalid input" << endl;

						}
						else
						{

							if (checkShipPlacement(shipSize(i), direction, x, y)) 
							{
								placeShip(shipSize(i), direction, x, y);
								Second3Ship = true;
								placingShip = false;
							}
						}
					}
					
				}
			}
			else
			{
				while (placingShip)
				{
					cout << "Enter the cordnates for ship " << i + 1 << " (Size " << shipSize(i) << ")" << " (x,y): ";
					cin >> x >> comma >> y;
					if (cin.fail() || x > 10 || x < 1 || y > 10 || y < 1)
					{
						cin.clear();
						cin.ignore();
						cout << "Invalid input" << endl;
				
					}
					else
					{
						cout << "What direction would you like the ship to face? (1 = Up, 2 = Down, 3 = Left, 4 = Right): ";
						cin >> direction;
						if (cin.fail() || direction > 4 || direction < 1)
						{
							cin.clear();
							cin.ignore();
							cout << "Invalid input" << endl;

						}
						else
						{
							if (checkShipPlacement(shipSize(i), direction, x, y))
							{
								placeShip(shipSize(i), direction, x, y);
								placingShip = false;
							}
						}
						
					}
				}
			}
		
		
	}
}
//Returns the size of the ship
int PlayerBoardArray::shipSize(int shipNumber)
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


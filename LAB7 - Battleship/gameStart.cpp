#include "gameStart.h"
#include <iostream>
#include "PlayerBoardArray.h"
#include "AiBoardArray.h"
#include <iomanip>


using namespace std;

PlayerBoardArray Player;
AiBoardArray AI;
char AIBoard[10][10];
char playerBoard[10][10];

gameStart::gameStart()
{
	//Set the board to all ~
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			AIBoard[i][j] = '~';
		}
	}

	
}

gameStart::~gameStart()
{
}

void gameStart::startGame()
{
	
	playerWin = false;
	aiWin = false;

	//Add ships to the board
	Player.AddShips();
	Player.printBoard();
	AI.aiAddShips();

	while (!checkWin())
	{
		
			playerTurn();
			
	
	}
}
//Player turn function
void gameStart::playerTurn()
{
	bool choiceActive = true;
	while (choiceActive)
	{
		cout << "Would you like to surrender? (y/n) ";
		char choice;
		cin >> choice;
		if (choice == 'y')
		{
			aiWin = true;
			cout << "AI Wins!" << endl;
			restart();
		}
		else if (choice == 'n')
		{
			choiceActive = false;
		}
		else
		{
			cout << "Invalid input please try again" << endl;
		}
	}
	
	if (quit == false)
	{
		cout << "Players board" << endl;
		Player.printBoard();

		cout << "Player's Turn" << endl;
		printPlayerAttackBoard();

		int x, y;
		char comma;
		cout << "Enter the x,y coordinates you would like to attack (x,y) : ";
		cin >> y >> comma >> x;

		if (x < 1 || x > 10 || y < 1 || y > 10)
		{
			cout << "Invalid coordinates, try again" << endl;
			playerTurn();
		}
		else
		{
			if (AI.checkHit(x - 1, y - 1))
			{
				cout << "Hit!" << endl;
				AIBoard[x - 1][y - 1] = 'H';
				AiHitsLeft--;
			}
			else
			{
				cout << "Miss!" << endl;
				AIBoard[x - 1][y - 1] = 'M';
			}
		}

		cout << "AI's Turn" << endl;

		//Check if for Win
		if (!checkWin())
		{
			TurnActive = true;
			while (TurnActive)
			{
				x = rand() % 10;
				y = rand() % 10;
				if (Player.checkIfAlreadyHit(x, y))
				{

				}
				else
				{
					if (Player.checkHit(x, y))
					{
						cout << "AI Hit!" << endl;
						Player.changePlayerBoard(x, y, 'H');
						PlayerHitsLeft--;
					}
					else
					{
						cout << "AI Miss!" << endl;
						Player.changePlayerBoard(x, y, 'M');
					}
					Player.printBoard();

					TurnActive = false;
				}

			}


		}

	}	

}

//Restart function
void gameStart::restart()
{
	char choice;
	choice = 'f';
	while (choice != 'y' && choice != 'n')
	{
		cout << "Would You like to play again? (y/n)   ";
		cin >> choice;
		cout << endl;
		if (cin.fail())
		{
			cout << "Invalid input please try again" << endl;
			choice = 'f';
		}
	}

	switch (choice)
	{
	default:
		break;
	case 'y':
	
		Player.setBoard();
		AI.setBoard();
		PlayerHitsLeft = 17;
		AiHitsLeft = 17;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				AIBoard[i][j] = '~';
			}
		}

		startGame();
		break;
	case 'n':
		quit = true;
		break;
	}
}
//Check win function
bool gameStart::checkWin()
{
	if  (AiHitsLeft == 0)
	{
		playerWin = true;
		cout << "Player Wins!" << endl;
		restart();
		return true;
	}
	else if (PlayerHitsLeft == 0)
	{
		aiWin = true;
		cout << "AI Wins!" << endl;
		restart();
		return true;
	}
	else
	{
		return false;
	}



}
//Print player attack board
void gameStart::printPlayerAttackBoard()
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

				cout << AIBoard[i][j] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << i + 1 << " ";
			for (int j = 0; j < 10; j++)
			{
				cout << AIBoard[i][j] << " ";
			}
			cout << endl;
		}
	}
}




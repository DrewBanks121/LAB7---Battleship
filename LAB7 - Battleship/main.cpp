/*
	Andrew Banks
	Computer Science Fall 2024
	Due: 12/3/2024
	Lab Name : Lab 7 Battleship
	Description : Make a simple battleship game
*/

#include "gameStart.h"
#include <iostream>

using namespace std;

void rules();

int main() {

	//Game start object
	gameStart game;
	cout << "Welcome to Battleship" << endl;
	cout << "1. Play" << endl;
	cout << "2. Rules" << endl;
	cout << "3. Exit" << endl;

	bool InputActive;
	int choice;

	InputActive = true;

	//While loop to keep menu active

	while (InputActive)
	{
		cout << "Please input your choice ";
		cin >> choice;
		cout << endl;

		if (cin.fail() || choice < 1 || choice > 3)
		{
			cout << "Invalid Input please try again" << endl;

			cin.clear();
			cin.ignore();
		}
		else
		{
			switch (choice)
			{
			case 1:
				game.startGame();
				break;
			case 2:
				rules();
				break;
			case 3:
				return 0;
				break;
			default:
				break;
			}
		}
	}
	
}

//Rules function
void rules() 
{
	cout << "In this game you will competing against the computer to sink each others ships" << endl;
	cout << "The game will be played on a 10x10 grid" << endl;
	cout << "You will have 5 ships to place on the grid. Your Carrier size 5, Your Battleship size 4, Your Cruiser size 3, " << endl;
	cout <<	"Your Submarine size 3, and your destoyer size 2" << endl;
	cout << "You will place your ships on the grid by inputing the starting coordinate and the direction you want the ship to go" << endl;
	cout << "The computer will place its ships randomly on the grid" << endl;
	cout << "You will take turns guessing the coordinates of the computer's ships" << endl;
	cout << "If you hit a ship you will be told you hit a ship with the letter H and if you miss you will be told with the letter M" << endl;
	cout << "The game will continue until one player has sunk all of the other players ships" << endl;
	cout << "Good Luck" << endl;


}
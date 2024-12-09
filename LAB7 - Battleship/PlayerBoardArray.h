#ifndef _PlayerBoardArray

#define _PlayerBoardArray

class PlayerBoardArray
{
public:
	PlayerBoardArray();
	~PlayerBoardArray();

	void setBoard();
	void printBoard();

	bool checkShipPlacement(int size, int direction, int x, int y);
	void placeShip(int size, int direction, int x, int y);

	void setAttackBoard(char AttackBoard[10][10]);
	bool checkHit(int x, int y);
	bool checkIfAlreadyHit(int x, int y);

	void changePlayerBoard(int x, int y, char c);


	void AddShips();
	int shipSize(int shipNumber);

private:
	int shipsAdded = 0;
	bool placingShip = true;

	char EnemyBoard[10][10];

};



#endif // !_PlayerBoardArray

#ifndef _AiBoardArray

#define _AiBoardArray

class AiBoardArray
{
public:
	AiBoardArray();
	~AiBoardArray();

	void setBoard();
	void printBoard();

	bool checkShipPlacement(int size, int direction, int x, int y);
	void placeShip(int size, int direction, int x, int y);

	void setAttackBoard(char AttackBoard[10][10]);
	bool checkHit(int x, int y);


	void aiAddShips();
	int shipSize(int shipNumber);

private:
	int shipsAdded = 0;
	bool placingShip = true;

	char EnemyBoard[10][10];

};



#endif // !_AiBoardArray

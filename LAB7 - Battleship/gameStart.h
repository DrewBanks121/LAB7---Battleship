#ifndef gameStart_h

#define gameStart_h

class gameStart
{
public:
	gameStart();
	~gameStart();

	void startGame();
	void playerTurn();
	void restart();

	bool checkWin();

	void printPlayerAttackBoard();
	

private:
	bool playerWin = false;
	bool aiWin = false;
	bool TurnActive = true;
	bool quit = false;
	
	int AiHitsLeft = 17;
	int PlayerHitsLeft = 17;

};

#endif // !gameStart_h

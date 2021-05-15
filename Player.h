#ifndef PLAYER
#define PLAYER

public:
	player(std::string name, int score, hand);

	void setName(std::string name);
	std::string getName();

	void setScore(int score);
	int getScore();

	void updateHand( );



private:

#endif //PLAYER

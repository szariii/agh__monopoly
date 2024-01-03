#include<iostream>;
#include "Field.h";
#include "PlayerInformations.h";
using namespace std;

class monopolyLogic {




	void startGame() {
		int boardPlayersPosition[40][6] = {};
		Field boardFields[40] = {};
		PlayerInformations players[6] = {};

		Field field;
		field.id = 0;
		field.name = "saf";
		field.houses = 0;
		field.owner = -1;
		field.buy = 100;
		field.earnMony[0] = 5;
		field.earnMony[1] = 5;
		field.earnMony[2] = 5;
		field.earnMony[3] = 5;
		field.earnMony[4] = 5;
	}

	Field createBoardFields() {

	}


	

	
	
};
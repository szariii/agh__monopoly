#include "Game.h";
#include<iostream>;
#include "MonopolyLogic.h";

using namespace std;

int main()
{
  	MonopolyLogic game1;
	  game1.createBoard();
    //Inicjalizacja gry.
    Game game;

    //Pętla gry
    while (game.running())
    {
        game.update();

        game.render();
    }

    return 0;
}
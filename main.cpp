#include <iostream>;
#include "Game.h"

using namespace std;

int main()
{
    //Inicjalizacja gry.
    Game game;

    //P�tla gry
    while (game.running())
    {
        game.update();

        game.render();
    }

    return 0;
}
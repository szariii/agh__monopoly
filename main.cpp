//Biblioteki c++
#include <iostream>;

//Pliki gry
#include "Game.h";
#include "MonopolyLogic.h";
#include "StartWindow.h"

using namespace std;

int main() {
    StartWindow startWindow;
    int result = startWindow.run();

    if (result == 0)
    {
        MonopolyLogic game1;
        game1.createBoard();
    }

    return 0;
}
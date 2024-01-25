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

    if (result >= 2 || result <= 4)
    {
        MonopolyLogic game1;
        game1.createBoard(result);
    }

    return 0;
}
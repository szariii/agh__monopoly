#pragma once
#include<SFML/Graphics.hpp>


class Cancel
{
public:
    // Zmiana: Usuniêto nadmiarowy 'public:'
   int PressedA;

    sf::Image icon;
    sf::RenderWindow window;
    sf::Event event;
    sf::Font font;

    sf::RectangleShape Buttonrect;
    sf::RectangleShape Rect1;
    sf::Text Text1;

    void ShowAnuluj();

    Cancel();
    ~Cancel();


};


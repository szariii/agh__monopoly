#pragma once
#include<SFML/Graphics.hpp>


class Cancel
{
public:
   
   int PressedA;

    sf::Image icon;
    sf::RenderWindow window;
    sf::Event event;
    sf::Font font;
    sf::Text Text2;
    sf::RectangleShape Buttonrect;
    sf::RectangleShape Rect1;
    sf::Text Text1;

    void ShowAnuluj();

    Cancel();
    ~Cancel();


};


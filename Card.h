#pragma once

//Bibiloteki c++
#include <iostream>
#include <sstream>

//Bibloteki sfml
#include <SFML/Graphics.hpp>

class Card
{
private:
    sf::RenderWindow window;
    sf::Event event;
    sf::Font font;

    sf::RectangleShape cardRect;
    sf::Text titleText;
    sf::Text contentText;

public:
    Card();
    ~Card();

    void showCard(const std::string& title, const std::string& content); //funkcja pokazuj¹ca kartê na ekranie
};

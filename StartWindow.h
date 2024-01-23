#pragma once

//Biblioteki c++
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class StartWindow
{
private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Text titleText;
    sf::Text playButton;
    sf::Text exitButton;
    sf::Color defaultTextColor;

public:
    StartWindow();
    ~StartWindow();

    void handleMouseEvents();
    int run();
};

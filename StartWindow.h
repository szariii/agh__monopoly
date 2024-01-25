#pragma once

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
    sf::Text playerCountText;
    sf::Text confirmButton;
    sf::RectangleShape playerCountRectangle;

    int selectedPlayerCount;

public:
    StartWindow();
    ~StartWindow();

    void handleMouseEvents();
    int run();
    int choosePlayerCount();
    int getSelectedPlayerCount() const;
};

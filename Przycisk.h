#ifndef PRZYCISK_H
#define PRZYCISK_H
//Bibiloteki c++
#include <iostream>
#include <sstream>

//Bibloteki sfml
#include <SFML/Graphics.hpp>

class Button
{
private:
    sf::RenderWindow window;
    sf::Event event;
    sf::Font font;
    sf::Texture texture1;
    sf::Sprite sprite1;

    sf::RectangleShape buttonRect;
    sf::Text titleText;
    sf::Text contentText;
    sf::Text contentText2;
    sf::Text contentText3;
    sf::RectangleShape OKrect;


    //Zmienne dla okna wyboru 1
    sf::RectangleShape Rect1;
    sf::RectangleShape Rect2;
    sf::RectangleShape Rect3;
    sf::RectangleShape Rect4;

    sf::Text Naglowek;
    sf::Text Text1;
    sf::Text Text2;
    sf::Text Text3;
    sf::Text Text4;

    sf::Text TextR1;
    sf::Text TextR2;
    sf::Text TextR3;
    sf::Text TextR4;

public:
    Button();
    ~Button();

    void showButton(const std::string& title, const std::string& content); //funkcja pokazuj¹ca przycisk na ekranie
    void showButton2(const std::string& title, const std::string& content, const std::string& content2);
    void closeButton();
    void showOptions();
    void chooseOptions();
};

#endif // PRZYCISK_H
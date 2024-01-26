#ifndef PRZYCISK_H
#define PRZYCISK_H
//Bibiloteki c++
#pragma once
#include <iostream>
#include <sstream>

//Bibloteki sfml
#include <SFML/Graphics.hpp>

class Button
{

public:
    int Pressed1;
    int Pressed2;
    int Pressed3;
    int Pressed4;
    int Pressed5;
    sf::RenderWindow window;
    sf::RenderWindow window1;
    sf::RenderWindow window2;
    sf::Event event;
    sf::Font font;
    sf::Texture texture1;
    sf::Sprite sprite1;
    sf::Image icon;
    sf::Image icon1;
    sf::Image icon2;
    sf::Image icon3;
    sf::RectangleShape buttonRect;
    sf::RectangleShape buttonRect1;
    sf::RectangleShape buttonRect2;
    sf::RectangleShape buttonRect3;
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
   

    sf::Text TextR1;
    sf::Text TextR2;
    sf::Text TextR3;
    sf::Text TextR4;

    
    //Zmienne dla okna wyboru 2 ale ze ejst trzecim oknem no to "3"
    sf::RectangleShape Rect1_3;
    sf::RectangleShape Rect2_3;
    sf::RectangleShape Rect3_3;
    sf::RectangleShape Rect4_3;
   
    sf::Text TextR1_3;
    sf::Text TextR2_3;
    sf::Text TextR3_3;
    
    //Zmienne dla okna zakupu
    sf::RectangleShape Rect1_4;
    sf::RectangleShape Rect2_4;
    sf::Text titleText2;
    sf::Text TextR1_4;
    sf::Text TextR2_4;

public:
    Button();
    ~Button();

    void showButton(const std::string& title); //funkcja pokazuj¹ca przycisk na ekranie
    void showButton2(const std::string& title, const std::string& content, const std::string& content2);
    void showButton3(const std::string& title);
    void showButton4(const std::string& title, const std::string& title2);
    void showOptions();
    int ReturnValue(int & value);
 
    int chooseOptions();
};

#endif // PRZYCISK_H
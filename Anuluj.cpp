#pragma once
#include "Anuluj.h"
#include<iostream>


Cancel::Cancel()
{
}

Cancel::~Cancel()
{
}


void Cancel::ShowAnuluj()
{
    //Tworzenie nowego okna o wymiarach 500x300
    window.create(sf::VideoMode(200, 240), "Anulowanie");
    window.setPosition(sf::Vector2i(400, 350));

    //Ikona
    icon.loadFromFile("Textures/beer.png");
    //Ustaw ikony dla okna
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Inicjalizacja czcionki
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
    //tlo

    Buttonrect.setSize(sf::Vector2f(200.f, 240.f));
    Buttonrect.setFillColor(sf::Color(255, 255, 153));



    //Inicjalizacja prostokata 
    sf::Vector2u WindowSize = window.getSize();
    sf::Vector2f Rect1size(100.f, 40.f);
    Rect1.setSize(Rect1size);
    Rect1.setOrigin(Rect1size.x / 2, Rect1size.y / 2);
    Rect1.setFillColor(sf::Color(255, 255, 50));
    Rect1.setPosition((WindowSize.x / 2) , (WindowSize.y / 2));
    Rect1.setFillColor(sf::Color(255, 255, 50));
    Rect1.setOutlineThickness(0.5f);
    Rect1.setOutlineColor(sf::Color::Black);


    //Init tekstu wyzej


    Text2.setFont(font);
    Text2.setCharacterSize(15);
    Text2.setFillColor(sf::Color::Black);
    Text2.setStyle(sf::Text::Bold);
    Text2.setString("Opcja niedostepna");
    sf::FloatRect text2Bounds = Text2.getLocalBounds();
    Text2.setOrigin(text2Bounds.left + text2Bounds.width / 2.0f, text2Bounds.top + text2Bounds.height / 2.0f);
    Text2.setPosition(Rect1.getPosition().x, ((Rect1.getPosition().y)/3)*2);




    //Init tekstu do recta

    Text1.setFont(font);
    Text1.setCharacterSize(15);
    Text1.setFillColor(sf::Color::Black);
    Text1.setStyle(sf::Text::Bold);
    Text1.setString("Anuluj");
    sf::FloatRect text1Bounds = Text1.getLocalBounds();
    Text1.setOrigin(text1Bounds.left + text1Bounds.width / 2.0f, text1Bounds.top + text1Bounds.height / 2.0f);
    Text1.setPosition(Rect1.getPosition().x, Rect1.getPosition().y);



    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
                    sf::FloatRect Rect1Pos = Rect1.getGlobalBounds();

                    if (Rect1Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {
                        PressedA = 40;
                        window.close();
                    }

                }

            }
            else if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect OKPos = Rect1.getGlobalBounds();

                if (OKPos.contains(static_cast<sf::Vector2f>(MousePosition)))
                {
                    Rect1.setFillColor(sf::Color(255, 255, 150));
                }
                else
                {
                    Rect1.setFillColor(sf::Color(255, 255, 50));
                }
            }
         

        }
        window.clear();
        window.draw(Buttonrect);
        window.draw(Rect1);
        window.draw(Text1);
        window.draw(Text2);
        window.display();

    }




}


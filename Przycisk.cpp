#include "Przycisk.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"


Przycisk::Przycisk(const KonfigPrzycisku& config, sf::RenderWindow& window) : okno(window)
{


    przycisk.setSize(sf::Vector2f(config.szerokosc, config.wysokosc));
    przycisk.setFillColor(config.kolorTla);
    przycisk.setOrigin(sf::Vector2f(config.szerokosc / 2.0f, config.wysokosc / 2.0f));
    przycisk.setPosition(sf::Vector2f(config.x, config.y));
    tekst.setFont(config.czcionka);
    tekst.setString(config.tekst);
    tekst.setCharacterSize(config.wielkoscLiter);
    tekst.setFillColor(config.kolorTekstu);
    // Ustawianie pozycji tekstu w centrum przycisku
    sf::FloatRect textBounds = tekst.getLocalBounds();
    tekst.setOrigin(sf::Vector2f(textBounds.width / 2.0f, textBounds.height / 2.0f));
    // Pozycja tekstu ustawiona w odniesieniu do przycisku
    tekst.setPosition(sf::Vector2f(config.x, config.y));
}


Przycisk::~Przycisk() 
{
    
}

void Przycisk::rysuj()
{
    okno.draw(przycisk);
    okno.draw(tekst);
}

void Przycisk::czy_wcisniety(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
            if (przycisk.getGlobalBounds().contains(mousePosition))
            {
                okno.close();
            }
        }
    }
}
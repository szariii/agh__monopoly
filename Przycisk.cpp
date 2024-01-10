#include "Przycisk.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"


Przycisk::Przycisk(const KonfigPrzycisku& config, sf::RenderWindow& window) : okno(window)
{
  
    przycisk.setPosition(config.x, config.y);
    przycisk.setSize(sf::Vector2f(config.szerokosc, config.wysokosc));
    przycisk.setFillColor(config.kolorTla);
    tekst.setFont(config.czcionka);  
    tekst.setString(config.tekst);
    tekst.setCharacterSize(config.wielkoscLiter);
    tekst.setFillColor(config.kolorTekstu);
    tekst.setPosition(
        config.x + (config.szerokosc - tekst.getGlobalBounds().width) / 2,
        config.y + (config.wysokosc - tekst.getGlobalBounds().height) / 2
    );
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
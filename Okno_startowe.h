#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class OknoStartowe{
public:
    OknoStartowe(sf::RenderWindow& window) : okno(window) {}

    void uruchom() {
        sf::Font czcionka;
        if (!czcionka.loadFromFile("arial.ttf")) {
            // Obs³uga b³êdu ³adowania czcionki
            return;
        }

        // Przygotuj przyciski i pola tekstowe
        sf::Text liczbaLabel("Podaj liczbe:", czcionka, 24);
        sf::Text nazwaGraczaLabel("Podaj nazwe gracza:", czcionka, 24);

        sf::RectangleShape liczbaInput(sf::Vector2f(200.f, 30.f));
        sf::RectangleShape nazwaGraczaInput(sf::Vector2f(200.f, 30.f));

        liczbaInput.setFillColor(sf::Color::White);
        nazwaGraczaInput.setFillColor(sf::Color::White);

        liczbaLabel.setPosition(50.f, 50.f);
        liczbaInput.setPosition(300.f, 50.f);

        nazwaGraczaLabel.setPosition(50.f, 100.f);
        nazwaGraczaInput.setPosition(300.f, 100.f);

        // G³ówna pêtla okna startowego
        while (okno.isOpen()) {
            sf::Event event;
            while (okno.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    okno.close();
                }
            }

            // Rysowanie elementów okna startowego
            okno.clear(sf::Color::Black);
            okno.draw(liczbaLabel);
            okno.draw(liczbaInput);
            okno.draw(nazwaGraczaLabel);
            okno.draw(nazwaGraczaInput);
            okno.display();
        }
    }

private:
    sf::RenderWindow& okno;
};


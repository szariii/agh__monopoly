#pragma once

//Biblioteki SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

//Plki klas
#include "Graphic.h"

/*
	Główna klasa gry.
*/
class Game
{
	//Zmienne
	sf::Event event;

	//Okno
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	//Tło
	sf::Texture boardTexture;

	//Funkcje prywatne
	void initVariables(); //Funkcja inicjująca zmienne.
	void initWindow(); //Funkcja tworząca okno aplikacji.
	void initPlayer(); //Funkcja dodająca graczy

public:
	//Konstruktor i destruktor
	Game();
	~Game();

	const bool running() const; //Funkcja sprawdzająca czy gra działa, czy okno jest otwarte.

	//Główne funkcje
	void pollEvents(); //Funkcja reagująca na zdarzenia okna.
	void update(); //Funkcja aktualizująca obiekty gry.
	void render(); //Funkcja tworząca obiekty gry

	//Funkcje
	void displayText(const std::string& mainText, const std::string& topText, const sf::Vector2f& position, unsigned int characterSize, const sf::Color& textColor); // Funkcja karty szansa
};


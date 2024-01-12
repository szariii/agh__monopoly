#pragma once

//Biblioteki SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

//Plki klas
#include "Graphic.h"

/*
	G��wna klasa gry.
*/
class Game
{
	//Zmienne
	sf::Event event;

	//Okno
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	//T�o
	sf::Texture boardTexture;

	//Funkcje prywatne
	void initVariables(); //Funkcja inicjuj�ca zmienne.
	void initWindow(); //Funkcja tworz�ca okno aplikacji.
	void initPlayer(); //Funkcja dodaj�ca graczy

public:
	//Konstruktor i destruktor
	Game();
	~Game();

	const bool running() const; //Funkcja sprawdzaj�ca czy gra dzia�a, czy okno jest otwarte.

	//G��wne funkcje
	void pollEvents(); //Funkcja reaguj�ca na zdarzenia okna.
	void update(); //Funkcja aktualizuj�ca obiekty gry.
	void render(); //Funkcja tworz�ca obiekty gry

	//Funkcje
};


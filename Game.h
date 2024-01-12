#pragma once

//Biblioteki SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

//Plki klas
#include "Graphic.h"

/*
	G³ówna klasa gry.
*/
class Game
{
	//Zmienne
	sf::Event event;

	//Okno
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	//T³o
	sf::Texture boardTexture;

	//Funkcje prywatne
	void initVariables(); //Funkcja inicjuj¹ca zmienne.
	void initWindow(); //Funkcja tworz¹ca okno aplikacji.
	void initPlayer(); //Funkcja dodaj¹ca graczy

public:
	//Konstruktor i destruktor
	Game();
	~Game();

	const bool running() const; //Funkcja sprawdzaj¹ca czy gra dzia³a, czy okno jest otwarte.

	//G³ówne funkcje
	void pollEvents(); //Funkcja reaguj¹ca na zdarzenia okna.
	void update(); //Funkcja aktualizuj¹ca obiekty gry.
	void render(); //Funkcja tworz¹ca obiekty gry

	//Funkcje
};


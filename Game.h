﻿#pragma once

//Biblioteki C++
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip> 

//Biblioteki SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

//Plki klas
#include "Player.h"

//Zmienne globalne

const int playerNumber = 4;

/*
	Główna klasa gry.
*/
class GameGraphic
{
	//Zmienne
	sf::Event event; //Przechytywanie akcji okna
	int hoveredFieldId; //Na którym polu mysz
	sf::Text balancesText; //Stan konta

	//czcionka
	sf::Font font; 

	//Okno
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	//Tło
	sf::Texture boardTexture;
	sf::Sprite boardSprite;

	//Pionki
	std::vector<Player> players; //Wektor przechowujący pionki graczy

	std::vector<float> playerAccounts; // Stany kont graczy

	//Funkcje prywatne
	void initVariables(); //Funkcja inicjująca zmienne.
	void initWindow(); //Funkcja tworząca okno aplikacji.

public:
	//Konstruktor i destruktor
	GameGraphic();
	~GameGraphic();

	const bool running() const; //Funkcja sprawdzająca czy gra działa, czy okno jest otwarte.

	//Funkcje
	void loadBoardTexture(const std::string& filePath);
	void createPlayers(int numPlayers); // Funkcja tworząca daną liczbę graczy
	void movePlayer(int playerId, int propId); // Funcja poruszająca gracza o danym id na dane pole
	void displayText(const std::string& mainText, const std::string& topText); // Funkcja karty szansa
	void displayPlayerAccounts();
	void updatePlayerAccount(int playerId, float amount = 150.0f); // Domyślna wartość dla kwoty
	void handleHover();
	void displayFieldCard();

	//Funkcje renderujące
	void renderBoard(); // Tworzenie planszy
	void renderPlayers(); // Tworznie graczy

	//Główne funkcje
	void pollEvents(); //Funkcja reagująca na zdarzenia okna.
	void update(); //Funkcja aktualizująca obiekty gry.
	void render(); //Funkcja tworząca obiekty gry

};


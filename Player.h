#pragma once

//Bibloteki c++
#include <iostream>

//Biblioteki sfml
#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

class Player
{
public:
	sf::CircleShape pawn;  //Pionek gracza
	sf::Vector2f position; //Aktualna pozycja gracza
	sf::Color color;       //Kolor gracza

	Player(sf::Vector2f startPos = sf::Vector2f(500.f, 500.f), sf::Color color = sf::Color::Yellow) {
		pawn.setRadius(20.0f);
		pawn.setFillColor(color);
		pawn.setPosition(startPos);
		pawn.setOutlineThickness(2.f);
		pawn.setOutlineColor(sf::Color::Black);
		position = startPos;
		this->color = color;
	}

	void movePlayer(int playerId, int propId) {
		/*
			Funkcja poruszająca obiekt gracza na podstawie id pola.
			Odbywa się to na podstawie matematycznego obliczenia pozycji.
		*/
		const int PROP_WIDTH = 82;
		const int PROP_HEIGHT = 131;
		const int GO_WIDTH = 131;
		const int PLAYER_SIZE = 20;
		int xPos, yPos;

		if (propId == 0) {
			xPos = SCREEN_WIDTH - (GO_WIDTH / 2 + PLAYER_SIZE);
			yPos = SCREEN_HEIGHT - (GO_WIDTH / 2 + PLAYER_SIZE);
		}

		else if (propId >= 1 && propId <= 9) {
			xPos = SCREEN_WIDTH - (GO_WIDTH + PROP_WIDTH / 2 + PLAYER_SIZE + PROP_WIDTH * (propId - 1));
			yPos = SCREEN_HEIGHT - (PROP_HEIGHT / 2 + PLAYER_SIZE);
		}
		else if (propId == 10) {
			xPos = GO_WIDTH / 2 - PLAYER_SIZE;
			yPos = SCREEN_HEIGHT - (GO_WIDTH / 2 + PLAYER_SIZE);
		}
		else if (propId >= 11 && propId <= 19) {
			xPos = GO_WIDTH / 2 - PLAYER_SIZE;
			yPos = SCREEN_HEIGHT - (GO_WIDTH + PROP_WIDTH/2 + PLAYER_SIZE + PROP_WIDTH * (propId - 11));
		}
		else if (propId == 20) {
			xPos = GO_WIDTH/2 - PLAYER_SIZE;
			yPos = GO_WIDTH/2 - PLAYER_SIZE;
		}
		else if (propId >= 21 && propId <= 29) {
			xPos = GO_WIDTH + PROP_WIDTH / 2 - PLAYER_SIZE + PROP_WIDTH * (propId - 21);
			yPos = PROP_HEIGHT / 2 - PLAYER_SIZE;
		}
		else if (propId == 30) {
			//xPos = SCREEN_WIDTH - (GO_WIDTH / 2 + PLAYER_SIZE);
			//yPos = GO_WIDTH / 2 - PLAYER_SIZE;
			
			//Przeniesienie od razu do więzienia
			xPos = GO_WIDTH / 2 - PLAYER_SIZE + 15;
			yPos = SCREEN_HEIGHT - (GO_WIDTH / 2 + PLAYER_SIZE + 15);
		}
		else if (propId >= 31 && propId <= 39) {
			xPos = SCREEN_WIDTH - (GO_WIDTH / 2 + PLAYER_SIZE);
			yPos = GO_WIDTH + PROP_WIDTH / 2 - PLAYER_SIZE + PROP_WIDTH * (propId - 31);
		}
		else if (propId == 90) {
			xPos = GO_WIDTH / 2 - PLAYER_SIZE + 15;
			yPos = SCREEN_HEIGHT - (GO_WIDTH / 2 + PLAYER_SIZE + 15);
		}
		pawn.setPosition(sf::Vector2f(xPos, yPos+(playerId*2)));
	}
};

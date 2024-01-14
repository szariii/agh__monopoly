#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

class Player {
public:
	sf::CircleShape pawn;  // Pionek gracza
	sf::Vector2f position; // Aktualna pozycja gracza

	Player(sf::Vector2f startPos = sf::Vector2f(500.f, 500.f), sf::Color color = sf::Color::Yellow) {
		pawn.setRadius(20.0f);
		pawn.setFillColor(color);
		pawn.setPosition(startPos);
		position = startPos;
	}

	void movePlayer(int propId) {
		/*
			Funkcja poruszająca obiekt gracza na podstawie id pola.
			Odbywa się to na podstawie matematycznego obliczenia pozycji.
		*/
		const int PROP_WIDTH = 81.5;
		const int PROP_HEIGHT = 132;
		const int GO_WIDTH = 135;
		const int PLAYER_SIZE = 20;
		int xPos, yPos;

		if (propId == 0) {
			xPos = SCREEN_WIDTH - GO_WIDTH / 2 - 15;
			yPos = SCREEN_HEIGHT - GO_WIDTH / 2 - 15;
		}

		else if (propId >= 1 && propId <= 9) {
			xPos = SCREEN_WIDTH - (GO_WIDTH / 2 + PROP_WIDTH * (propId + 1) - PLAYER_SIZE) + 10;
			yPos = SCREEN_HEIGHT - PROP_HEIGHT / 2 - 10;
		}
		else if (propId == 10) {
			xPos = GO_WIDTH / 2 - 20;
			yPos = SCREEN_HEIGHT - GO_WIDTH / 2 - 20;
		}
		else if (propId >= 11 && propId <= 19) {
			xPos = 45;
			yPos = SCREEN_HEIGHT - (GO_WIDTH / 2 + PROP_WIDTH * (propId - 9) - PLAYER_SIZE) + 10;
		}
		else if (propId == 20) {
			xPos = GO_WIDTH / 2 - 20;
			yPos = GO_WIDTH / 2 - 20;
		}
		else if (propId >= 21 && propId <= 29) {
			xPos = SCREEN_WIDTH - (GO_WIDTH / 2 + PROP_WIDTH * (31 - propId) - PLAYER_SIZE) + 10;
			yPos = PROP_HEIGHT / 2 - PLAYER_SIZE;
		}
		else if (propId == 30) {
			xPos = (SCREEN_WIDTH - GO_WIDTH / 2) - 15;
			yPos = GO_WIDTH / 2 - 20;
		}
		else if (propId >= 31 && propId <= 39) {
			xPos = (SCREEN_WIDTH - GO_WIDTH / 2) - 15;
			yPos = (GO_WIDTH / 2 + PROP_WIDTH * (propId - 30)) + 10;
		}

		pawn.setPosition(sf::Vector2f(xPos, yPos));
	}
};

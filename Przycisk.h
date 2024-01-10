#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"


struct KonfigPrzycisku {
	float x, y, szerokosc, wysokosc;
	sf::Font czcionka;
	std::string tekst;
	unsigned wielkoscLiter;
	sf::Color kolorTla;
	sf::Color kolorTekstu;
	
};

	
class Przycisk
{
private:
	// zmienne
	sf::RectangleShape przycisk;
	sf::Text tekst;
	sf::RenderWindow& okno;




public:

	Przycisk(const KonfigPrzycisku& config, sf::RenderWindow& window);
	virtual ~Przycisk();
	void rysuj();
	void czy_wcisniety(const sf::Event& event);
	

};


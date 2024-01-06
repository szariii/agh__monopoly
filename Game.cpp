#include "Game.h"

//Funkcje prywatne
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	/*
		Funkcja tworz¹ca okno.
	*/

	//Ustalenie wielkoœci okna programu.
	this->videoMode.width = 1280;
	this->videoMode.height = 720;

	//Tworzenie okna o danych parametrach.
	this->window = new sf::RenderWindow(this->videoMode, "Monopoly AGH");
}

//Konstruktory i destruktory
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//Pomocnicze funkcje
const bool Game::running() const
{
	/*
		Funkcja sprawdzaj¹ca czy okno jest otwarte.
	*/
	return this->window->isOpen();
}

//Funkcje g³ówne
void Game::pollEvents()
{
	/*
		Obs³uga zdarzeñ okna.
	*/

	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			//Zamkniêcie programu po zamkniêciu okna
			this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	/*
		Tworzenie obiektów gry.
	*/

	this->window->clear(sf::Color::Cyan);

	//Tu dzia³anie gry

	this->window->display();
}





#include "Game.h"

//Funkcje prywatne
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	/*
		Funkcja tworz�ca okno.
	*/

	//Ustalenie wielko�ci okna programu.
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
		Funkcja sprawdzaj�ca czy okno jest otwarte.
	*/
	return this->window->isOpen();
}

//Funkcje g��wne
void Game::pollEvents()
{
	/*
		Obs�uga zdarze� okna.
	*/

	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			//Zamkni�cie programu po zamkni�ciu okna
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
		Tworzenie obiekt�w gry.
	*/

	this->window->clear(sf::Color::Cyan);

	//Tu dzia�anie gry

	this->window->display();
}





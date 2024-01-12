#include <cstdlib>
#include "Game.h"
#include "Graphic.h"

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
	this->videoMode.width = 1000;
	this->videoMode.height = 1000;

	//Tworzenie okna o danych parametrach.
	this->window = new sf::RenderWindow(this->videoMode, "Monopoly AGH");

	//Zablokowanie klatek na 60
	this->window->setFramerateLimit(60);
}

void Game::initPlayer(){
	
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

//Funkcje
/*
sf::Sprite createBoard() {
	sf::Texture boardTexture;
	if (!boardTexture.loadFromFile("Textures/board.png")) {
		// Obs³uga b³êdu ³adowania obrazu
		// return EXIT_FAILURE;
	}

	sf::Sprite boardSprite(boardTexture);
	return boardSprite;
}*/

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

	//wczytanie planszy
	sf::Texture boardTexture;
	if (!boardTexture.loadFromFile("Textures/board.png")) {
		// Obs³uga b³êdu ³adowania obrazu
		// return EXIT_FAILURE;
	}
	sf::Sprite boardSprite(boardTexture);

	Player player1;

	this->window->clear(sf::Color::Cyan);

	//Tu dzia³anie gry
	player1.movePlayer(20);

	this->window->draw(boardSprite); //rysowanie planszy
	this->window->draw(player1.pawn);

	this->window->display();
}





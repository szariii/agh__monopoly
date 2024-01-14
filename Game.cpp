//Biblioteki C++
#include <cstdlib>
#include <iostream>
#include <sstream>

//Pliki klas
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
		Funkcja tworz�ca okno.
	*/

	//Ustalenie wielko�ci okna programu.
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
		Funkcja sprawdzaj�ca czy okno jest otwarte.
	*/
	return this->window->isOpen();
}

//Funkcje

void Game::displayText(const std::string& mainText, const std::string& topText, const sf::Vector2f& position, unsigned int characterSize, const sf::Color& textColor)
{
    const float windowPadding = 20.0f; // sta�a dla wielko�ci odst�pu mi�dzy lew� a praw� kraw�dzi� okna
    const float textSpacing = 10.0f; // sta�a dla odst�pu mi�dzy tekstem "SZANSA" a g��wnym tekstem

    // Rysowanie jasno��tego okna
    sf::RectangleShape windowRect(sf::Vector2f(400.f, 200.f));
    windowRect.setFillColor(sf::Color(255, 255, 153)); // Jasno��ty kolor
    windowRect.setPosition(position.x - windowPadding, position.y);
    windowRect.setSize(sf::Vector2f(windowRect.getSize().x + 2 * windowPadding, windowRect.getSize().y));

    // Rysowanie ramki okna
    windowRect.setOutlineColor(sf::Color::Black); // Kolor ramki
    windowRect.setOutlineThickness(5.f); // Grubo�� ramki

    this->window->draw(windowRect);

    // Wy�wietlanie tekstu na g�rze okna
    sf::Font font;
    if (!font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Error loading font!" << std::endl;
        return;
    }

    sf::Text topTextObj;
    topTextObj.setFont(font);
    topTextObj.setString(sf::String::fromUtf8(topText.begin(), topText.end()));
    topTextObj.setCharacterSize(characterSize);
    topTextObj.setFillColor(textColor);

    // Pogrubienie tekstu
    topTextObj.setStyle(sf::Text::Bold);

    // Ustawienie punktu centralnego dla wy�rodkowania tekstu
    sf::FloatRect topTextBounds = topTextObj.getLocalBounds();
    topTextObj.setOrigin(topTextBounds.left + topTextBounds.width / 2.0f, topTextBounds.top + topTextBounds.height / 2.0f);
    topTextObj.setPosition(position.x + windowRect.getSize().x / 2.0f, position.y + windowPadding + topTextBounds.height / 2.0f); // Ustawienie wysoko�ci w oparciu o po�ow� wysoko�ci tekstu

    this->window->draw(topTextObj);

    // Wy�wietlanie g��wnego tekstu wewn�trz okna
    sf::Text displayText;
    displayText.setFont(font);
    displayText.setString(sf::String::fromUtf8(mainText.begin(), mainText.end())); // Konwersja polskich znak�w do formatu UTF-8
    displayText.setCharacterSize(characterSize);
    displayText.setFillColor(textColor);

    // Sprawd�, czy tekst przekracza szeroko�� okna
    sf::FloatRect textBounds = displayText.getLocalBounds();
    if (textBounds.width > windowRect.getSize().x - 2 * windowPadding)
    {
        // Je�li tekst jest zbyt szeroki, podziel go na wiersze
        std::string wrappedText;
        std::string word;
        std::istringstream stream(mainText);

        while (stream >> word)
        {
            sf::Text tempText(displayText);
            tempText.setString(sf::String::fromUtf8(wrappedText.begin(), wrappedText.end()) + sf::String::fromUtf8(word.begin(), word.end()) + " ");
            sf::FloatRect tempBounds = tempText.getLocalBounds();

            if (tempBounds.width <= windowRect.getSize().x - 2 * windowPadding)
            {
                wrappedText += word + " ";
            }
            else
            {
                wrappedText += "\n" + word + " ";
            }
        }

        displayText.setString(sf::String::fromUtf8(wrappedText.begin(), wrappedText.end()));
        textBounds = displayText.getLocalBounds(); // Zaktualizuj wymiary tekstu
    }

    // Wy�rodkuj g��wny tekst wewn�trz okna, uwzgl�dniaj�c odst�p od ramki
    float mainTextXOffset = position.x + windowPadding;
    float mainTextYOffset = position.y + windowPadding + topTextObj.getGlobalBounds().height + textSpacing; //wysoko�� topText i odst�p

    displayText.setPosition(mainTextXOffset, mainTextYOffset);
    this->window->draw(displayText);
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

	//wczytanie planszy
	sf::Texture boardTexture;
	if (!boardTexture.loadFromFile("Textures/board.png")) {
		// Obs�uga b��du �adowania obrazu
		// return EXIT_FAILURE;
	}
	sf::Sprite boardSprite(boardTexture);

	Player player1;

	this->window->clear(sf::Color::Cyan);

	//Tu dzia�anie gry
	player1.movePlayer(0);

	this->window->draw(boardSprite); //rysowanie planszy
	this->window->draw(player1.pawn);
    displayText("W nocy twojemu wykladowcy zalalo pokoj przez gniazdko elektryczne, i musi odespac - idziesz X pol do przodu.", "CIʯKIE �YCIE STUDENTA", sf::Vector2f(100.f, 100.f), 20, sf::Color::Black);


	this->window->display();
}

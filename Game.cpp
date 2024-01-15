//Pliki klas
#include "Game.h"

//Funkcje prywatne
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	/*
		Funkcja tworząca okno.
	*/

	//Ustalenie wielkości okna programu.
	this->videoMode.width = 1000;
	this->videoMode.height = 1000;

	//Tworzenie okna o danych parametrach.
	this->window = new sf::RenderWindow(this->videoMode, "Monopoly AGH");

	//Zablokowanie klatek na 60
	this->window->setFramerateLimit(60);
}

//Konstruktory i destruktory
Game::Game()
{
	this->initVariables();
	this->initWindow();
    this->createPlayers(4); //HARDCODE
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	/*
		Funkcja sprawdzająca czy okno jest otwarte.
	*/
	return this->window->isOpen();
}

//Funkcje
void Game::loadBoardTexture(const std::string& filePath)
{
    if (!boardTexture.loadFromFile(filePath))
    {
        std::cerr << "Error loading board texture from file: " << filePath << std::endl;
    }

    boardSprite.setTexture(boardTexture);
}

void Game::createPlayers(int numPlayers)
{
    // Dodaj numPlayers graczy o różnych kolorach i pozycjach startowych
    for (int i = 0; i < numPlayers; ++i)
    {
        sf::Color playerColor;

        //  Przypisanie kolorów dla pierwszych trzech graczy
        if (i == 0)
            playerColor = sf::Color::Red;
        else if (i == 1)
            playerColor = sf::Color::Green;
        else if (i == 2)
            playerColor = sf::Color::Blue;
        else
            playerColor = sf::Color::Yellow; // Dla reszty graczy żółty kolor

        sf::Vector2f startPosition;
        //  Pozycje startowe
        if(i == 0 || i == 1) {
            startPosition = sf::Vector2f(885.f + i * 55.f, 890.f);
        }
        else if (i == 2 || i == 3) {
            startPosition = sf::Vector2f(885.f + (i-2) * 55.f, 945.f);
        }
        
        Player player(startPosition, playerColor);
        players.push_back(player);
    }
}

void Game::movePlayer(int playerId, int propId)
{
    if (playerId >= 0 && playerId < players.size())
    {
        players[playerId].movePlayer(propId);
    }
}

void Game::displayText(const std::string& mainText, const std::string& topText, const sf::Vector2f& position, unsigned int characterSize, const sf::Color& textColor)
{
    const float windowPadding = 10.0f; // stała dla wielkości odstępu między lewą a prawą krawędzią okna
    const float textSpacing = 30.0f; // stała dla odstępu między tekstem "SZANSA" a głównym tekstem

    // Rysowanie jasnożółtego okna
    sf::RectangleShape windowRect(sf::Vector2f(400.f, 200.f));
    windowRect.setFillColor(sf::Color(255, 255, 153)); // Jasnożółty kolor
    windowRect.setPosition(position.x - windowPadding, position.y);
    windowRect.setSize(sf::Vector2f(windowRect.getSize().x + 2 * windowPadding, windowRect.getSize().y));

    // Rysowanie ramki okna
    windowRect.setOutlineColor(sf::Color::Black); // Kolor ramki
    windowRect.setOutlineThickness(5.f); // Grubość ramki

    this->window->draw(windowRect);

    // Wyświetlanie tekstu na górze okna
    sf::Font font;
    if (!font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Error loading font!" << std::endl;
        return;
    }

    sf::Text topTextObj;
    topTextObj.setFont(font);
    topTextObj.setString(sf::String::fromUtf8(topText.begin(), topText.end()));
    topTextObj.setCharacterSize(24);
    topTextObj.setFillColor(textColor);

    // Pogrubienie tekstu
    topTextObj.setStyle(sf::Text::Bold);

    // Ustawienie punktu centralnego dla wyśrodkowania tekstu
    sf::FloatRect topTextBounds = topTextObj.getLocalBounds();
    topTextObj.setOrigin(topTextBounds.left + topTextBounds.width / 2.0f, topTextBounds.top + topTextBounds.height / 2.0f);
    topTextObj.setPosition(position.x + windowRect.getSize().x / 2.0f, position.y + windowPadding + topTextBounds.height / 2.0f); // Ustawienie wysokości w oparciu o połowę wysokości tekstu

    this->window->draw(topTextObj);

    // Wyświetlanie głównego tekstu wewnątrz okna
    sf::Text displayText;
    displayText.setFont(font);
    displayText.setString(sf::String::fromUtf8(mainText.begin(), mainText.end())); // Konwersja polskich znaków do formatu UTF-8
    displayText.setCharacterSize(characterSize);
    displayText.setFillColor(textColor);

    // Sprawdź, czy tekst przekracza szerokość okna
    sf::FloatRect textBounds = displayText.getLocalBounds();
    if (textBounds.width > windowRect.getSize().x - 2 * windowPadding)
    {
        // Jeśli tekst jest zbyt szeroki, podziel go na wiersze
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

    // Wyśrodkuj główny tekst wewnętrz okna, uwzględniając odstęp od ramki
    float mainTextXOffset = position.x + windowPadding;
    float mainTextYOffset = position.y + windowPadding + topTextObj.getGlobalBounds().height + textSpacing; //wysokość topText i odstęp

    displayText.setPosition(mainTextXOffset, mainTextYOffset);
    this->window->draw(displayText);
}

void Game::displayPlayerBalance(int playerId, float balance) {
    sf::Font font;
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return;
    }

    sf::Text balanceText;
    balanceText.setFont(font);

    // zaokrąglenie do dwóch miejsc po przecinku
    std::stringstream balanceStream; 
    balanceStream << "Gracz " << (playerId + 1) << " - " << std::fixed << std::setprecision(2) << balance << " zł.";
    balanceText.setString(balanceStream.str());

    balanceText.setCharacterSize(20);
    balanceText.setFillColor(sf::Color::Black);

    balanceText.setPosition(145.f, 145.f + playerId * 30.f); // Ustawienie pozycji na podstawie id gracza.
    this->window->draw(balanceText);
}


//Funkcje renderujące
void Game::renderBoard()
{
    // Rysuj planszę Monopoly
    window->draw(boardSprite);
}

void Game::renderPlayers()
{
    // Rysowanie wszystkich graczy
    for (const auto& player : players)
    {
        this->window->draw(player.pawn);
    }
}

void Game::renderPlayerBalance() {
    for (int i = 0; i < playerNumber; i++) {
        displayPlayerBalance(i, 150.0f);
    }
}

//Funkcje główne
void Game::pollEvents()
{
	/*
		Obsługa zdarzeń okna.
	*/

	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			//Zamknięcie programu po zamknięciu okna
			this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();

    movePlayer(0, 31);
    movePlayer(1, 34);
    movePlayer(2, 37);
    movePlayer(3, 39);
}

void Game::render()
{
	/*
		Tworzenie obiektów gry.
	*/

	//wczytanie planszy
    loadBoardTexture("Textures/board.png");

	this->window->clear(sf::Color::Cyan);

    //wczytywanie elementów gry
    renderBoard();
    renderPlayers();
    renderPlayerBalance();

    //displayText("W nocy twojemu wykladowcy zalalo pokoj przez gniazdko elektryczne, i musi odespac - idziesz X pol do przodu.", "CIEZKIE ZYCIE STUDENTA", sf::Vector2f(300.f, 400.f), 20, sf::Color::Black);

	this->window->display();
}

//Pliki gry
#include "Game.h"

//Funkcje prywatne
void GameGraphic::initVariables() {
	this->window = nullptr;
    this->hoveredFieldId = -1; //-1 oznacza, że mysz nie najechała na żadne pole
    
    //Inicjalizacja czcionki
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    //Inicjalizacja własności pól
    fieldRectangles.resize(40);
    for (int i = 0; i < 40; ++i) {
        fieldRectangles[i].setSize(sf::Vector2f(20.f, 20.f)); //Rozmiar prostokąta
        fieldRectangles[i].setFillColor(sf::Color::Transparent);    //Biały kolor prostokąta
    }
    fieldColors.resize(40, sf::Color::Transparent);

    //Stany konta
    playerBalances.resize(playerNumber, 150.f);
}



void GameGraphic::initWindow() {
	/*
		Funkcja tworząca okno.
	*/

	//Ustalenie wielkości okna programu.
	this->videoMode.width = 1000;
	this->videoMode.height = 1000;

	//Tworzenie okna o danych parametrach.
	this->window = new sf::RenderWindow(this->videoMode, "Monopoly AGH");

    //Pozycja
    this->window->setPosition(sf::Vector2i(0, 0));

    //Ikona
    sf::Image icon;
    icon.loadFromFile("Textures/logo_agh.png");
    //Ustaw ikony dla okna
    this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	//Zablokowanie klatek na 60
	this->window->setFramerateLimit(60);
}

//Konstruktory i destruktory
GameGraphic::GameGraphic() {
	this->initVariables();
	this->initWindow();
    this->createPlayers(playerNumber);
}

GameGraphic::~GameGraphic() {
	delete this->window;
}

const bool GameGraphic::running() const {
	/*
		Funkcja sprawdzająca czy okno jest otwarte.
	*/
	return this->window->isOpen();
}

//Funkcje
void GameGraphic::loadBoardTexture(const std::string& filePath) {
    if (!boardTexture.loadFromFile(filePath))
    {
        std::cerr << "Error loading board texture from file: " << filePath << std::endl;
    }

    boardSprite.setTexture(boardTexture);
}

void GameGraphic::createPlayers(int numPlayers) {
    //Dodaj numPlayers graczy o różnych kolorach i pozycjach startowych
    for (int i = 0; i < numPlayers; ++i)
    {
        sf::Color playerColor;

        // Przypisanie kolorów dla pierwszych trzech graczy
        if (i == 0)
            playerColor = sf::Color::Red;
        else if (i == 1)
            playerColor = sf::Color(150,75,0);
        else if (i == 2)
            playerColor = sf::Color::Blue;
        else if (i == 3)
            playerColor = sf::Color::Magenta;
        else
            playerColor = sf::Color::Black;

        sf::Vector2f startPosition;
        // Pozycje startowe
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

void GameGraphic::movePlayer(int playerId, int propId) {
    if (playerId >= 0 && playerId < players.size())
    {
        players[playerId].movePlayer(playerId, propId);
    }
}

void GameGraphic::handleHover() {
    //Pobierz aktualną pozycję myszki względem okna
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

    //Ustaw domyślnie brak najechania na pole
    hoveredFieldId = -1;

    //Sprawdź, czy mysz znajduje się nad polem planszy
    for (size_t i = 0; i < 40; ++i)
    {
        sf::FloatRect fieldRect;

        //Sprawdź, czy mysz znajduje się nad polem planszy
        if (i >= 1 && i <= 9)
        {
            //Pola na dolnej krawędzi
            fieldRect = sf::FloatRect(787.f - 82.f * (i - 1), 869.f, 82.f, 131.f);
        }
        else if (i >= 11 && i <= 19)
        {
            //Pola na lewej krawędzi
            fieldRect = sf::FloatRect(0.f, 787.f - 82.f * (i - 11), 131.f, 82.f);
        }
        else if (i >= 21 && i <= 29)
        {
            //Pola na górnej krawędzi
            fieldRect = sf::FloatRect(131.f + 82.f * (i - 21), 0.f, 82.f, 131.f);
        }
        else if (i >= 31 && i <= 39)
        {
            //Pola na prawej krawędzi
            fieldRect = sf::FloatRect(869.f, 131.f + 82.f * (i - 31), 131.f, 82.f);
        }
        if (i == 2 || i == 7 || i == 12 || i == 17 || i == 22 || i == 28 || i == 33 || i == 17 || i == 36) {
            fieldRect = sf::FloatRect(0.f, 0.f, 0.f, 0.f);
        }

        if (fieldRect.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
        {
            //Jeżeli mysz jest nad nowym polem, wczytaj karty i zaktualizuj hoveredFieldId
            hoveredFieldId = i;
            std::cout << hoveredFieldId << std::endl;
            break;
        }
    }
}

void GameGraphic::displayFieldOwner() {
    for (size_t i = 0; i < fieldRectangles.size(); ++i) {
        //Ustaw pozycję i rozmiar prostokąta nad polem
        fieldRectangles[i].setPosition(sf::Vector2f(0.f, 0.f));

        if (i >= 1 && i <= 9) {
            //Pola na dolnej krawędzi
            fieldRectangles[i].setSize(sf::Vector2f(82.f, 6.f));
            fieldRectangles[i].setPosition(787.f - 82.f * (i - 1), 869.f - 6.f);
        }
        else if (i >= 11 && i <= 19) {
            //Pola na lewej krawędzi
            fieldRectangles[i].setSize(sf::Vector2f(6.f, 82.f));
            fieldRectangles[i].setPosition(131.f, 787.f - 82.f * (i - 11));
        }
        else if (i >= 21 && i <= 29) {
            //Pola na górnej krawędzi
            fieldRectangles[i].setSize(sf::Vector2f(82.f, 6.f));
            fieldRectangles[i].setPosition(131.f + 82.f * (i - 21), 131.f);
        }
        else if (i >= 31 && i <= 39) {
            //Pola na prawej krawędzi
            fieldRectangles[i].setSize(sf::Vector2f(6.f, 82.f));
            fieldRectangles[i].setPosition(869.f - 6.f, 131.f + 82.f * (i - 31));
        }
        if (i == 2 || i == 4|| i == 7 || i == 12 || i == 17 || i == 22 || i == 28 || i == 33 || i == 17 || i == 36 || i == 38) {
            fieldRectangles[i].setSize(sf::Vector2f(0, 0));
        }

        window->draw(fieldRectangles[i]);
    }
}

void GameGraphic::setFieldColor(int fieldId, int playerId) {
    if (fieldId >= 0 && fieldId < static_cast<int>(fieldColors.size()) && playerId == -1) {
        fieldColors[fieldId] = sf::Color::Transparent;
    }
    if (fieldId >= 0 && fieldId < static_cast<int>(fieldColors.size()) && playerId >= 0 && playerId < playerNumber) {
        fieldColors[fieldId] = players[playerId].color;
    }
}

void GameGraphic::updatePlayerBalance(int playerId, float newBalance) {
    if (playerId >= 0 && playerId < playerNumber)
    {
        playerBalances[playerId] = newBalance;
    }
}

void GameGraphic::displayPlayerBalances() {
    sf::Text balancesTitle;
    balancesTitle.setFont(font);
    balancesTitle.setString("Stan konta:");
    balancesTitle.setCharacterSize(24);
    balancesTitle.setFillColor(sf::Color::Black);
    balancesTitle.setPosition(140.f, 140.f);

    this->window->draw(balancesTitle);

    for (int i = 0; i < playerNumber; ++i)
    {
        sf::Text playerBalanceText;
        playerBalanceText.setFont(font);

        std::ostringstream balanceStream;
        balanceStream << "Gracz " << i + 1 << ": " << std::fixed << std::setprecision(2) << playerBalances[i] << " zl";

        playerBalanceText.setString(balanceStream.str());
        playerBalanceText.setCharacterSize(19);
        playerBalanceText.setFillColor(players[i].color);
        playerBalanceText.setPosition(140.f, 172.f + i * 32.f);

        this->window->draw(playerBalanceText);
    }
}

void GameGraphic::minusPlayerBalance(int playerId, float newBalance) {
    if (playerId >= 0 && playerId < playerNumber)
    {
        playerBalances[playerId] = playerBalances[playerId] - newBalance;
    }
}

//GameGraphic.cpp
void GameGraphic::showCard(const std::string& title, const std::string& content) {
    Card.showCard(title, content);
}

void GameGraphic::showButton(const std::string& title, const std::string& content) {
    Button.showButton(title, content);

}

void GameGraphic::showButton2(const std::string& title, const std::string& content, const std::string& content2) {
    Button.showButton2(title, content, content2);

}


//Funkcje renderujące
void GameGraphic::renderBoard() {
    //Rysuj planszę Monopoly
    window->draw(boardSprite);
}

void GameGraphic::renderPlayers() {
    //Rysowanie wszystkich graczy
    for (const auto& player : players)
    {
        this->window->draw(player.pawn);
    }
}

void GameGraphic::renderFieldOwnerColor() {
    for (size_t i = 0; i < fieldRectangles.size(); ++i)
    {
        fieldRectangles[i].setFillColor(fieldColors[i]);
    }
}

//Funkcje główne
void GameGraphic::pollEvents() {
	/*
		Obsługa zdarzeń okna.
	*/

	while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
        case sf::Event::Closed:
            //Zamknięcie programu po zamknięciu okna
            this->window->close();
            break;
        case sf::Event::MouseMoved:
            //Obsługa najechania myszką na pole planszy
            handleHover();
            break;
        }
	}
}

void GameGraphic::update() {
	this->pollEvents();

    //movePlayer(0, 31);
    //movePlayer(1, 34);
    //movePlayer(2, 37);
    //movePlayer(3, 39);
}

void GameGraphic::render() {
	/*
		Tworzenie obiektów gry.
	*/

	//wczytanie planszy
    loadBoardTexture("Textures/board.png");

	this->window->clear();

    //wczytywanie elementów gry
    renderBoard(); //Plansza
    renderPlayers(); //Gracze
    renderFieldOwnerColor(); //Nadaje polom kolory
    displayFieldOwner(); //Wyświetla kolory kupionych pól
    displayPlayerBalances(); //Wyświetla stany konta graczy

	this->window->display();
}

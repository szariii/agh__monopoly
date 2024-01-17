//Pliki klas
#include "Game.h"

//Funkcje prywatne
void GameGraphic::initVariables()
{
	this->window = nullptr;
    this->hoveredFieldId = -1; // -1 oznacza, że mysz nie najechała na żadne pole
    
    // Inicjalizacja czcionki
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    //Inicjalizacja własności pól
    fieldRectangles.resize(40);
    for (int i = 0; i < 40; ++i) {
        fieldRectangles[i].setSize(sf::Vector2f(20.f, 20.f)); // Rozmiar prostokąta
        fieldRectangles[i].setFillColor(sf::Color::Transparent);    // Biały kolor prostokąta
    }
    fieldColors.resize(40, sf::Color::Transparent);

    //Stany konta
    playerBalances.resize(playerNumber, 150.f);
}

void GameGraphic::initWindow()
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
GameGraphic::GameGraphic()
{
	this->initVariables();
	this->initWindow();
    this->createPlayers(playerNumber);
}

GameGraphic::~GameGraphic()
{
	delete this->window;
}

const bool GameGraphic::running() const
{
	/*
		Funkcja sprawdzająca czy okno jest otwarte.
	*/
	return this->window->isOpen();
}

//Funkcje
void GameGraphic::loadBoardTexture(const std::string& filePath)
{
    if (!boardTexture.loadFromFile(filePath))
    {
        std::cerr << "Error loading board texture from file: " << filePath << std::endl;
    }

    boardSprite.setTexture(boardTexture);
}

void GameGraphic::createPlayers(int numPlayers)
{
    // Dodaj numPlayers graczy o różnych kolorach i pozycjach startowych
    for (int i = 0; i < numPlayers; ++i)
    {
        sf::Color playerColor;

        //  Przypisanie kolorów dla pierwszych trzech graczy
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

void GameGraphic::movePlayer(int playerId, int propId)
{
    if (playerId >= 0 && playerId < players.size())
    {
        players[playerId].movePlayer(playerId, propId);
    }
}

void GameGraphic::displayText(const std::string& mainText, const std::string& topText)
{
    const float windowPadding = 10.0f; // stała dla wielkości odstępu między lewą a prawą krawędzią okna
    const float textSpacing = 30.0f; // stała dla odstępu między tekstem "SZANSA" a głównym tekstem

    // Rysowanie jasnożółtego okna
    sf::RectangleShape windowRect(sf::Vector2f(400.f, 200.f));
    windowRect.setFillColor(sf::Color(255, 255, 153)); // Jasnożółty kolor
    windowRect.setPosition(300.f - windowPadding, 400.f);
    windowRect.setSize(sf::Vector2f(windowRect.getSize().x + 2 * windowPadding, windowRect.getSize().y));

    // Rysowanie ramki okna
    windowRect.setOutlineColor(sf::Color::Black); // Kolor ramki
    windowRect.setOutlineThickness(5.f); // Grubość ramki

    this->window->draw(windowRect);

    // Wyświetlanie tekstu na górze okna

    sf::Text topTextObj;
    topTextObj.setFont(font);
    topTextObj.setString(sf::String::fromUtf8(topText.begin(), topText.end()));
    topTextObj.setCharacterSize(24);
    topTextObj.setFillColor(sf::Color::Black);

    // Pogrubienie tekstu
    topTextObj.setStyle(sf::Text::Bold);

    // Ustawienie punktu centralnego dla wyśrodkowania tekstu
    sf::FloatRect topTextBounds = topTextObj.getLocalBounds();
    topTextObj.setOrigin(topTextBounds.left + topTextBounds.width / 2.0f, topTextBounds.top + topTextBounds.height / 2.0f);
    topTextObj.setPosition(300.f + windowRect.getSize().x / 2.0f, 400.f + windowPadding + topTextBounds.height / 2.0f); // Ustawienie wysokości w oparciu o połowę wysokości tekstu

    this->window->draw(topTextObj);

    // Wyświetlanie głównego tekstu wewnątrz okna
    sf::Text displayText;
    displayText.setFont(font);
    displayText.setString(sf::String::fromUtf8(mainText.begin(), mainText.end())); // Konwersja polskich znaków do formatu UTF-8
    displayText.setCharacterSize(20);
    displayText.setFillColor(sf::Color::Black);

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
    float mainTextXOffset = 300.f + windowPadding;
    float mainTextYOffset = 400.f + windowPadding + topTextObj.getGlobalBounds().height + textSpacing; //wysokość topText i odstęp

    displayText.setPosition(mainTextXOffset, mainTextYOffset);
    this->window->draw(displayText);
}

void GameGraphic::handleHover()
{
    // Pobierz aktualną pozycję myszki względem okna
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

    // Ustaw domyślnie brak najechania na pole
    hoveredFieldId = -1;

    // Sprawdź, czy mysz znajduje się nad polem planszy
    for (size_t i = 0; i < 40; ++i)
    {
        sf::FloatRect fieldRect;

        // Sprawdź, czy mysz znajduje się nad polem planszy
        if (i >= 1 && i <= 9)
        {
            // Pola na dolnej krawędzi
            fieldRect = sf::FloatRect(787.f - 82.f * (i - 1), 869.f, 82.f, 131.f);
        }
        else if (i >= 11 && i <= 19)
        {
            // Pola na lewej krawędzi
            fieldRect = sf::FloatRect(0.f, 787.f - 82.f * (i - 11), 131.f, 82.f);
        }
        else if (i >= 21 && i <= 29)
        {
            // Pola na górnej krawędzi
            fieldRect = sf::FloatRect(131.f + 82.f * (i - 21), 0.f, 82.f, 131.f);
        }
        else if (i >= 31 && i <= 39)
        {
            // Pola na prawej krawędzi
            fieldRect = sf::FloatRect(869.f, 131.f + 82.f * (i - 31), 131.f, 82.f);
        }
        if (i == 2 || i == 7 || i == 12 || i == 17 || i == 22 || i == 28 || i == 33 || i == 17 || i == 36) {
            fieldRect = sf::FloatRect(0.f, 0.f, 0.f, 0.f);
        }

        if (fieldRect.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
        {
            // Jeżeli mysz jest nad nowym polem, wczytaj karty i zaktualizuj hoveredFieldId
            hoveredFieldId = i;
            std::cout << hoveredFieldId << std::endl;
            break;
        }
    }

}

void GameGraphic::displayFieldCard()
{
    // Sprawdź, czy mysz znajduje się nad polem planszy
    if (hoveredFieldId != -1)
    {
        std::string fieldName = "/* pobierz nazwę pola planszy */";
        std::string fieldDescription = "/* pobierz opis pola planszy */";

        // Wyświetl kartę z danymi o polu
        displayText(fieldName, fieldDescription);
    }
}

void GameGraphic::displayFieldOwner() {
    for (size_t i = 0; i < fieldRectangles.size(); ++i) {
        // Ustaw pozycję i rozmiar prostokąta nad polem
        fieldRectangles[i].setPosition(sf::Vector2f(0.f, 0.f));

        if (i >= 1 && i <= 9) {
            // Pola na dolnej krawędzi
            fieldRectangles[i].setSize(sf::Vector2f(82.f, 6.f));
            fieldRectangles[i].setPosition(787.f - 82.f * (i - 1), 869.f - 6.f);
        }
        else if (i >= 11 && i <= 19) {
            // Pola na lewej krawędzi
            fieldRectangles[i].setSize(sf::Vector2f(6.f, 82.f));
            fieldRectangles[i].setPosition(131.f, 787.f - 82.f * (i - 11));
        }
        else if (i >= 21 && i <= 29) {
            // Pola na górnej krawędzi
            fieldRectangles[i].setSize(sf::Vector2f(82.f, 6.f));
            fieldRectangles[i].setPosition(131.f + 82.f * (i - 21), 131.f);
        }
        else if (i >= 31 && i <= 39) {
            // Pola na prawej krawędzi
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

void GameGraphic::updatePlayerBalance(int playerId, float newBalance){
    if (playerId >= 0 && playerId < playerNumber)
    {
        playerBalances[playerId] = newBalance;
    }
}

void GameGraphic::displayPlayerBalances()
{
    sf::Text balancesTitle;
    balancesTitle.setFont(font);
    balancesTitle.setString("Balances:");
    balancesTitle.setCharacterSize(20);
    balancesTitle.setFillColor(sf::Color::Black);
    balancesTitle.setPosition(140.f, 140.f);

    this->window->draw(balancesTitle);

    for (int i = 0; i < playerNumber; ++i)
    {
        sf::Text playerBalanceText;
        playerBalanceText.setFont(font);

        std::ostringstream balanceStream;
        balanceStream << "Player " << i + 1 << ": " << std::fixed << std::setprecision(2) << playerBalances[i] << " zl";

        playerBalanceText.setString(balanceStream.str());
        playerBalanceText.setCharacterSize(16);
        playerBalanceText.setFillColor(players[i].color);
        playerBalanceText.setPosition(140.f, 170.f + i * 30.f);

        this->window->draw(playerBalanceText);
    }
}

void GameGraphic::minusPlayerBalance(int playerId, float newBalance) {
    if (playerId >= 0 && playerId < playerNumber)
    {
        playerBalances[playerId] = playerBalances[playerId] - newBalance;
    }
}

//Funkcje renderujące
void GameGraphic::renderBoard() {
    // Rysuj planszę Monopoly
    window->draw(boardSprite);
}

void GameGraphic::renderPlayers()
{
    // Rysowanie wszystkich graczy
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
void GameGraphic::pollEvents()
{
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
            // Obsługa najechania myszką na pole planszy
            handleHover();
            break;
        }
	}
}

void GameGraphic::update()
{
	this->pollEvents();

    //movePlayer(0, 31);
    //movePlayer(1, 34);
    //movePlayer(2, 37);
    //movePlayer(3, 39);
}

void GameGraphic::render()
{
	/*
		Tworzenie obiektów gry.
	*/

	//wczytanie planszy
    loadBoardTexture("Textures/board.png");

	this->window->clear(sf::Color::Cyan);

    //wczytywanie elementów gry
    renderBoard(); //Plansza
    renderPlayers(); //Gracze
    renderFieldOwnerColor(); //Nadaje polom kolory
    displayFieldOwner(); //Wyświetla kolory kupionych pól
    displayPlayerBalances(); // Wyświetla stany konta graczy

    //displayText("W nocy twojemu wykladowcy zalalo pokoj przez gniazdko elektryczne, i musi odespac - idziesz X pol do przodu.", "CIEZKIE ZYCIE STUDENTA", sf::Vector2f(300.f, 400.f), 20, sf::Color::Black);

	this->window->display();
}

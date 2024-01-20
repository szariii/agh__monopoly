//Pliki gry
#include "Card.h"

Card::Card() {
}

Card::~Card() {
}

void Card::showCard(const std::string& title, const std::string& content) {
    //Tworzenie nowego okna o wymiarach 500x300
    window.create(sf::VideoMode(500, 300), "Karta");
    window.setPosition(sf::Vector2i(250, 350));

    //Ikona
    sf::Image icon;
    icon.loadFromFile("Textures/card.png");
    //Ustaw ikony dla okna
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Inicjalizacja czcionki
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    //Inicjalizacja prostok¹ta karty
    cardRect.setSize(sf::Vector2f(500.f, 300.f));
    cardRect.setFillColor(sf::Color(255, 255, 153));
    cardRect.setPosition(0.f, 0.f);

    //Inicjalizacja tekstu tytu³u
    titleText.setFont(font);
    titleText.setCharacterSize(24);
    titleText.setFillColor(sf::Color::Black);
    titleText.setStyle(sf::Text::Bold);
    titleText.setString(title);

    //Inicjalizacja tekstu treœci
    contentText.setFont(font);
    contentText.setCharacterSize(20);
    contentText.setFillColor(sf::Color::Black);
    contentText.setString(content);

    //Ustawienia pozycji tekstu na œrodku pionowo
    titleText.setPosition(cardRect.getSize().x / 2.0f, cardRect.getSize().y / 4.0f);
    contentText.setPosition(cardRect.getSize().x / 2.0f, cardRect.getSize().y / 2.0f);

    //Ustawienia pozycji dodatkowego przesuniêcia dla d³u¿szego tekstu
    float yOffset = 0.f;

    //Ustawienie zawijania tekstu
    unsigned int maxCharactersPerLine = 40;  //Maksymalna liczba znaków w jednej linii
    std::string wrappedContent;
    std::istringstream stream(content);

    while (stream.good()) {
        std::string line;
        std::getline(stream, line);

        //Dzielimy linie na mniejsze fragmenty, które mieszcz¹ siê w oknie
        while (line.size() > maxCharactersPerLine) {
            std::size_t pos = line.rfind(' ', maxCharactersPerLine);
            if (pos == std::string::npos)
                pos = maxCharactersPerLine;

            wrappedContent += line.substr(0, pos) + '\n';
            line = line.substr(pos + 1);
        }

        //Dodajemy przesuniêcie tylko dla nowo dodanych linii tekstu
        contentText.setString(wrappedContent);
        float lineOffset = contentText.getLocalBounds().top - yOffset;
        contentText.setPosition(cardRect.getSize().x / 2.0f, cardRect.getSize().y / 2.0f + yOffset + lineOffset);
        yOffset += lineOffset;

        wrappedContent += line + '\n';
    }

    //SprawdŸ, czy tekst nie wychodzi poza dolny kraniec okna
    float totalTextHeight = yOffset + contentText.getLocalBounds().top + contentText.getLocalBounds().height;
    if (totalTextHeight > cardRect.getSize().y / 2.0f) {
        //Jeœli tekst jest zbyt d³ugi, przewijaj go w oknie
        yOffset = 0.f;
    }

    //Ustawienia pozycji tekstu na œrodku poziomo
    float xOffset = (cardRect.getSize().x - contentText.getLocalBounds().width) / 2.0f;
    contentText.setPosition(xOffset, cardRect.getSize().y / 2.0f + yOffset);

    //Ustawienia pozycji tytu³u na œrodku poziomo
    float titleXOffset = (cardRect.getSize().x - titleText.getLocalBounds().width) / 2.0f;
    titleText.setPosition(titleXOffset, cardRect.getSize().y / 4.0f);

    contentText.setString(wrappedContent);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(cardRect);
        window.draw(titleText);
        window.draw(contentText);
        window.display();
    }
}

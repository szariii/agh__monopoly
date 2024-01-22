//Pliki gry
#include "Przycisk.h"

Button::Button() {
}

Button::~Button() {
}

void Button::showButton(const std::string& title, const std::string& content) {
    //Tworzenie nowego okna o wymiarach 500x300
    window.create(sf::VideoMode(500, 300), "Monopoly AGH");
    window.setPosition(sf::Vector2i(300, 200));


    //Inicjalizacja czcionki
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    
    //Inicjalizacja prostok¹ta przycisku
    buttonRect.setSize(sf::Vector2f(500.f, 300.f));
    buttonRect.setFillColor(sf::Color(255, 255, 153));
    


    //Inicjalizacja prostokata OK
    sf::Vector2f WindowSize(window.getSize().x, window.getSize().y);
    sf::Vector2f OKrectSize(70.f, 40.f);
    OKrect.setSize(OKrectSize);
    OKrect.setOrigin(OKrectSize.x / 2, OKrectSize.y / 2);
    OKrect.setFillColor(sf::Color(255, 255, 153));
    OKrect.setPosition(WindowSize.x / 2, (WindowSize.y / 5)*3);
    OKrect.setFillColor(sf::Color(255, 255, 50));
    OKrect.setOutlineThickness(0.5f);
    OKrect.setOutlineColor(sf::Color::Black);


    contentText3.setFont(font);
    contentText3.setCharacterSize(24);
    contentText3.setFillColor(sf::Color::Black);
    contentText3.setStyle(sf::Text::Bold);
    contentText3.setString("OK");
    sf::FloatRect textBounds = contentText3.getLocalBounds();
    contentText3.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    contentText3.setPosition(OKrect.getPosition().x, OKrect.getPosition().y);

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
    titleText.setPosition(buttonRect.getSize().x / 2.0f, buttonRect.getSize().y / 4.0f);
    contentText.setPosition(buttonRect.getSize().x / 2.0f, buttonRect.getSize().y / 2.0f);

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
        contentText.setPosition(buttonRect.getSize().x / 2.0f, buttonRect.getSize().y / 2.0f + yOffset + lineOffset);
        yOffset += lineOffset;

        wrappedContent += line + '\n';
    }

    //SprawdŸ, czy tekst nie wychodzi poza dolny kraniec okna
    float totalTextHeight = yOffset + contentText.getLocalBounds().top + contentText.getLocalBounds().height;
    if (totalTextHeight > buttonRect.getSize().y / 2.0f) {
        //Jeœli tekst jest zbyt d³ugi, przewijaj go w oknie
        yOffset = 0.f;
    }

    //Ustawienia pozycji tekstu na œrodku poziomo
    float xOffset = (buttonRect.getSize().x - contentText.getLocalBounds().width) / 2.0f;
    contentText.setPosition(xOffset, buttonRect.getSize().y / 2.0f + yOffset);

    //Ustawienia pozycji tytu³u na œrodku poziomo
    float titleXOffset = (buttonRect.getSize().x - titleText.getLocalBounds().width) / 2.0f;
    titleText.setPosition(titleXOffset, buttonRect.getSize().y / 4.0f);

    contentText.setString(wrappedContent);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(buttonRect);
        window.draw(titleText);
        window.draw(contentText);
        window.draw(OKrect);
        window.draw(contentText3);
        window.display();
    }
}



void Button::showButton2(const std::string& title, const std::string& content, const std::string& content2) {
    //Tworzenie nowego okna o wymiarach 500x300
    window.create(sf::VideoMode(500, 300), "Monopoly AGH");
    window.setPosition(sf::Vector2i(300, 200));


    //Inicjalizacja czcionki
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    //Inicjalizacja prostok¹ta karty
    buttonRect.setSize(sf::Vector2f(500.f, 300.f));
    buttonRect.setFillColor(sf::Color(255, 255, 153));
    buttonRect.setPosition(0.f, 0.f);

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

    //I drugiego
    contentText2.setFont(font);
    contentText2.setCharacterSize(20);
    contentText2.setFillColor(sf::Color::Black);
    contentText2.setString(content2);


    //Ustawienia pozycji tekstu na œrodku pionowo
    titleText.setPosition(buttonRect.getSize().x / 2.0f, buttonRect.getSize().y / 4.0f);
    contentText.setPosition(buttonRect.getSize().x / 2.0f, buttonRect.getSize().y / 2.0f);
    contentText2.setPosition(buttonRect.getSize().x / 2.0f, (buttonRect.getSize().y / 2.0f) +20.0f);
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
        contentText.setPosition(buttonRect.getSize().x / 2.0f, buttonRect.getSize().y / 2.0f + yOffset + lineOffset);
        yOffset += lineOffset;

        wrappedContent += line + '\n';
    }

    //SprawdŸ, czy tekst nie wychodzi poza dolny kraniec okna
    float totalTextHeight = yOffset + contentText.getLocalBounds().top + contentText.getLocalBounds().height;
    if (totalTextHeight > buttonRect.getSize().y / 2.0f) {
        //Jeœli tekst jest zbyt d³ugi, przewijaj go w oknie
        yOffset = 0.f;
    }

    //Ustawienia pozycji tekstu na œrodku poziomo
    float xOffset = (buttonRect.getSize().x - contentText.getLocalBounds().width) / 2.0f;
    contentText.setPosition(xOffset, buttonRect.getSize().y / 2.0f + yOffset);

    //Ustawienia pozycji tytu³u na œrodku poziomo
    float titleXOffset = (buttonRect.getSize().x - titleText.getLocalBounds().width) / 2.0f;
    titleText.setPosition(titleXOffset, buttonRect.getSize().y / 4.0f);

    contentText.setString(wrappedContent);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(buttonRect);
        window.draw(titleText);
        window.draw(contentText);
        window.draw(contentText2);
        window.display();
    }
}

void Button::closeButton()
{



}

void Button::showOptions()
{
}

void Button::chooseOptions()
{
}

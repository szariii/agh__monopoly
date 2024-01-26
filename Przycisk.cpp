//Pliki gry
#pragma once
#include "Przycisk.h"
#include"Game.h"

Button::Button() {
}

Button::~Button() {
}

void Button::showButton(const std::string& title) {
    //Tworzenie nowego okna o wymiarach 500x300
    window.create(sf::VideoMode(500, 300), "Monopoly AGH");
    window.setPosition(sf::Vector2i(250, 350));
   
    //Ikona
    
    icon1.loadFromFile("Textures/beer.png");
    //Ustaw ikony dla okna
    window.setIcon(icon1.getSize().x, icon1.getSize().y, icon1.getPixelsPtr());

    //Inicjalizacja czcionki
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
    sf::Vector2f WindowSize(window.getSize().x, window.getSize().y);
    
    //Inicjalizacja prostok¹ta przycisku
    buttonRect3.setSize(sf::Vector2f(500.f, 300.f));
    buttonRect3.setFillColor(sf::Color(255, 255, 153));
   
    //Inicjalizacja tekstu tytu³u
    titleText.setFont(font);
    titleText.setCharacterSize(24);
    titleText.setFillColor(sf::Color::Black);
    titleText.setStyle(sf::Text::Bold);
    titleText.setString(title);
    sf::FloatRect textBounds = titleText.getLocalBounds();
    titleText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    titleText.setPosition(WindowSize.x / 2, (WindowSize.y / 5));

    //Inicjalizacja prostokata 1 - buduj h/a

    sf::Vector2f Rect1size(205.f, 40.f);
    Rect1.setSize(Rect1size);
    Rect1.setOrigin(Rect1size.x / 2, Rect1size.y / 2);
    Rect1.setFillColor(sf::Color(255, 255, 50));
    Rect1.setPosition((WindowSize.x / 5) * 1.2, (WindowSize.y / 5) * 3);
    Rect1.setFillColor(sf::Color(255, 255, 50));
    Rect1.setOutlineThickness(0.5f);
    Rect1.setOutlineColor(sf::Color::Black);

    //Init tekstu dla prostokata 1 - buduj h/a

    TextR1.setFont(font);
    TextR1.setCharacterSize(15);
    TextR1.setFillColor(sf::Color::Black);
    TextR1.setStyle(sf::Text::Bold);
    TextR1.setString("Kup Hotel/Apartament");
    sf::FloatRect textR1Bounds = TextR1.getLocalBounds();
    TextR1.setOrigin(textR1Bounds.left + textR1Bounds.width / 2.0f, textR1Bounds.top + textR1Bounds.height / 2.0f);
    TextR1.setPosition(Rect1.getPosition().x, Rect1.getPosition().y);


    //Init prostokata 2  - sprzedaj h/a
    sf::Vector2f Rect2size(205.f, 40.f);
    Rect2.setSize(Rect2size);
    Rect2.setOrigin(Rect2size.x / 2, Rect2size.y / 2);
    Rect2.setFillColor(sf::Color(255, 255, 50));
    Rect2.setPosition((WindowSize.x / 5) * 3.8, (WindowSize.y / 5) * 3);
    Rect2.setFillColor(sf::Color(255, 255, 50));
    Rect2.setOutlineThickness(0.5f);
    Rect2.setOutlineColor(sf::Color::Black);

    //Init tekstu 2 = sprzedaj h/a
    TextR2.setFont(font);
    TextR2.setCharacterSize(15);
    TextR2.setFillColor(sf::Color::Black);
    TextR2.setStyle(sf::Text::Bold);
    TextR2.setString("Sprzedaj Hotel/Apartament");
    sf::FloatRect textR2Bounds = TextR2.getLocalBounds();
    TextR2.setOrigin(textR2Bounds.left + textR2Bounds.width / 2.0f, textR2Bounds.top + textR2Bounds.height / 2.0f);
    TextR2.setPosition(Rect2.getPosition().x, Rect2.getPosition().y);



    //Init prostokata 3  - sprzedaj Pole
    sf::Vector2f Rect3size(205.f, 40.f);
    Rect3.setSize(Rect3size);
    Rect3.setOrigin(Rect3size.x / 2, Rect3size.y / 2);
    Rect3.setFillColor(sf::Color(255, 255, 50));
    Rect3.setPosition((WindowSize.x / 5) * 1.2, (WindowSize.y / 5) * 4);
    Rect3.setFillColor(sf::Color(255, 255, 50));
    Rect3.setOutlineThickness(0.5f);
    Rect3.setOutlineColor(sf::Color::Black);

    //Init tekstu 3 = sprzedaj Pole
    TextR3.setFont(font);
    TextR3.setCharacterSize(15);
    TextR3.setFillColor(sf::Color::Black);
    TextR3.setStyle(sf::Text::Bold);
    TextR3.setString("Sprzedaj Pole");
    sf::FloatRect textR3Bounds = TextR3.getLocalBounds();
    TextR3.setOrigin(textR3Bounds.left + textR3Bounds.width / 2.0f, textR3Bounds.top + textR3Bounds.height / 2.0f);
    TextR3.setPosition(Rect3.getPosition().x, Rect3.getPosition().y);
  
    //Init prostokata 4  - Zakoncz kolejke
    sf::Vector2f Rect4size(205.f, 40.f);
    Rect4.setSize(Rect4size);
    Rect4.setOrigin(Rect4size.x / 2, Rect4size.y / 2);
    Rect4.setFillColor(sf::Color(255, 255, 50));
    Rect4.setPosition((WindowSize.x / 5) * 3.8, (WindowSize.y / 5) * 4);
    Rect4.setFillColor(sf::Color(255, 255, 50));
    Rect4.setOutlineThickness(0.5f);
    Rect4.setOutlineColor(sf::Color::Black);

    //Init tekstu 4 = Zakoncz kolejke
    TextR4.setFont(font);
    TextR4.setCharacterSize(15);
    TextR4.setFillColor(sf::Color::Black);
    TextR4.setStyle(sf::Text::Bold);
    TextR4.setString("Zakoncz ture / dublet");
    sf::FloatRect textR4Bounds = TextR4.getLocalBounds();
    TextR4.setOrigin(textR4Bounds.left + textR4Bounds.width / 2.0f, textR4Bounds.top + textR4Bounds.height / 2.0f);
    TextR4.setPosition(Rect4.getPosition().x, Rect4.getPosition().y);







    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect Rect1Pos = Rect1.getGlobalBounds();
                sf::FloatRect Rect2Pos = Rect2.getGlobalBounds();
                sf::FloatRect Rect3Pos = Rect3.getGlobalBounds();
                sf::FloatRect Rect4Pos = Rect4.getGlobalBounds();

                if (Rect1Pos.contains(static_cast<sf::Vector2f>(MousePosition)))
                {
                    Rect1.setFillColor(sf::Color(255, 255, 150));
                }
                else if (Rect2Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {

                    Rect2.setFillColor(sf::Color(255, 255, 150));
                }
                else if (Rect3Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {

                    Rect3.setFillColor(sf::Color(255, 255, 150));
                }
                else if (Rect4Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {

                    Rect4.setFillColor(sf::Color(255, 255, 150));
                }
                
                else
                {
                    Rect1.setFillColor(sf::Color(255, 255, 50));
                    Rect2.setFillColor(sf::Color(255, 255, 50));
                    Rect3.setFillColor(sf::Color(255, 255, 50));
                    Rect4.setFillColor(sf::Color(255, 255, 50));
                }
                            
            }

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect Rect1Pos = Rect1.getGlobalBounds();
                sf::FloatRect Rect2Pos = Rect2.getGlobalBounds();
                sf::FloatRect Rect3Pos = Rect3.getGlobalBounds();
                sf::FloatRect Rect4Pos = Rect4.getGlobalBounds();   

                if (event.mouseButton.button == sf::Mouse::Left) {
                  
                    if (Rect1Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {

                        Pressed1 = 1;
                        window.close();
                    }
                    else if (Rect2Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {
                        Pressed1 = 2;
                        window.close();
                    }
                    else if (Rect3Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {
                        Pressed1 = 3;
                        window.close();
                    }
                    else if (Rect4Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {
                        Pressed1 = 4;
                        window.close();
                    }




                }
            }
        }

        window.clear();
        window.draw(buttonRect3);
        window.draw(titleText);
        window.draw(Rect1);
        window.draw(TextR1);
        window.draw(Rect2);
        window.draw(TextR2);
        window.draw(Rect3);
        window.draw(TextR3);
        window.draw(Rect4);
        window.draw(TextR4);
        window.display();
    }
}


//Przycisk do rzutu kostk¹
void Button::showButton2(const std::string& title, const std::string& content, const std::string& content2) {
    //Tworzenie nowego okna o wymiarach 500x300
    window1.create(sf::VideoMode(500, 300), "Monopoly AGH");
    window1.setPosition(sf::Vector2i(250, 350));
    

    //Inicjalizacja czcionki
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }


    icon3.loadFromFile("Textures/beer.png");
    //Ustaw ikony dla okna
    window.setIcon(icon3.getSize().x, icon3.getSize().y, icon3.getPixelsPtr());

    sf::Vector2f WindowSize(window1.getSize().x, window1.getSize().y);
    sf::Vector2f OKrectSize(70.f, 40.f);
    OKrect.setSize(OKrectSize);
    OKrect.setOrigin(OKrectSize.x / 2, OKrectSize.y / 2);
    OKrect.setFillColor(sf::Color(255, 255, 153));
    OKrect.setPosition(WindowSize.x / 2, (WindowSize.y / 5) * 4);
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

    while (window1.isOpen()) {
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window1.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i MousePosition = sf::Mouse::getPosition(window1);
                    sf::FloatRect OKPos = OKrect.getGlobalBounds();

                        if (OKPos.contains(static_cast<sf::Vector2f>(MousePosition))) {
                            window1.close();
                        }

                }
                
            }
            else if(event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i MousePosition = sf::Mouse::getPosition(window1);
                sf::FloatRect OKPos = OKrect.getGlobalBounds();

                if (OKPos.contains(static_cast<sf::Vector2f>(MousePosition)))
                {
                    OKrect.setFillColor(sf::Color(255, 255, 150));
                }
                else
                {
                    OKrect.setFillColor(sf::Color(255, 255,50));
                }
            }
        
        
        }
        window1.clear();
        window1.draw(buttonRect);
        window1.draw(titleText);
        window1.draw(contentText);
        window1.draw(contentText2);
        window1.draw(OKrect);
        window1.draw(contentText3);

        window1.display();
    }
}

//Przycisk 3

void Button::showButton3(const std::string& title) {
    //Tworzenie nowego okna o wymiarach 500x300
    window.create(sf::VideoMode(500, 300), "Monopoly AGH");
    window.setPosition(sf::Vector2i(250, 350));

    //Ikona
    
    icon.loadFromFile("Textures/beer.png");
    //Ustaw ikony dla okna
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Vector2f WindowSize(window.getSize().x, window.getSize().y);

    //Inicjalizacja prostok¹ta przycisku
    buttonRect1.setSize(sf::Vector2f(500.f, 300.f));
    buttonRect1.setFillColor(sf::Color(255, 255, 153));
    buttonRect1.setPosition(0.f, 0.f);
    //Inicjalizacja tekstu tytu³u
    titleText.setFont(font);
    titleText.setCharacterSize(24);
    titleText.setFillColor(sf::Color::Black);
    titleText.setStyle(sf::Text::Bold);
    titleText.setString(title);
    sf::FloatRect textBounds = titleText.getLocalBounds();
    titleText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    titleText.setPosition(WindowSize.x / 2, (WindowSize.y / 5));

    //Inicjalizacja prostokata 1 sprzedaj pola

    sf::Vector2f Rect1size(205.f, 40.f);
    Rect1_3.setSize(Rect1size);
    Rect1_3.setOrigin(Rect1size.x / 2, Rect1size.y / 2);
    Rect1_3.setFillColor(sf::Color(255, 255, 50));
    Rect1_3.setPosition((WindowSize.x / 5) * 1.2, (WindowSize.y / 5) * 3);
    Rect1_3.setFillColor(sf::Color(255, 255, 50));
    Rect1_3.setOutlineThickness(0.5f);
    Rect1_3.setOutlineColor(sf::Color::Black);

    //Init tekstu dla prostokata 1 sprzedaj pola

    TextR1_3.setFont(font);
    TextR1_3.setCharacterSize(15);
    TextR1_3.setFillColor(sf::Color::Black);
    TextR1_3.setStyle(sf::Text::Bold);
    TextR1_3.setString("Sprzedaj pola");
    sf::FloatRect textR1_3Bounds = TextR1_3.getLocalBounds();
    TextR1_3.setOrigin(textR1_3Bounds.left + textR1_3Bounds.width / 2.0f, textR1_3Bounds.top + textR1_3Bounds.height / 2.0f);
    TextR1_3.setPosition(Rect1_3.getPosition().x, Rect1_3.getPosition().y);


    //Init prostokata 2  - sprzedaj h/a
    sf::Vector2f Rect2_3size(205.f, 40.f);
    Rect2_3.setSize(Rect2_3size);
    Rect2_3.setOrigin(Rect2_3size.x / 2, Rect2_3size.y / 2);
    Rect2_3.setFillColor(sf::Color(255, 255, 50));
    Rect2_3.setPosition((WindowSize.x / 5) * 3.8, (WindowSize.y / 5) * 3);
    Rect2_3.setFillColor(sf::Color(255, 255, 50));
    Rect2_3.setOutlineThickness(0.5f);
    Rect2_3.setOutlineColor(sf::Color::Black);

    //Init tekstu 2 = sprzedaj h/a
    TextR2_3.setFont(font);
    TextR2_3.setCharacterSize(15);
    TextR2_3.setFillColor(sf::Color::Black);
    TextR2_3.setStyle(sf::Text::Bold);
    TextR2_3.setString("Sprzedaj Apartamenty/Hotele");
    sf::FloatRect textR2_3Bounds = TextR2_3.getLocalBounds();
    TextR2_3.setOrigin(textR2_3Bounds.left + textR2_3Bounds.width / 2.0f, textR2_3Bounds.top + textR2_3Bounds.height / 2.0f);
    TextR2_3.setPosition(Rect2_3.getPosition().x, Rect2_3.getPosition().y);



    //Init prostokata 3  - Poddaj sie || NIGDY SIE NIE PODDAWAJ!!!!
    sf::Vector2f Rect3_3size(205.f, 40.f);
    Rect3_3.setSize(Rect3_3size);
    Rect3_3.setOrigin(Rect3_3size.x / 2, Rect3_3size.y / 2);
    Rect3_3.setFillColor(sf::Color(255, 255, 50));
    Rect3_3.setPosition((WindowSize.x / 2), (WindowSize.y / 5) * 4);
    Rect3_3.setFillColor(sf::Color(255, 255, 50));
    Rect3_3.setOutlineThickness(0.5f);
    Rect3_3.setOutlineColor(sf::Color::Black);

    //Init tekstu 3 - poddaj sie || NIGDY!!!!!!!!!
    TextR3_3.setFont(font);
    TextR3_3.setCharacterSize(15);
    TextR3_3.setFillColor(sf::Color::Black);
    TextR3_3.setStyle(sf::Text::Bold);
    TextR3_3.setString("Sprzedaj Pole");
    sf::FloatRect textR3_3Bounds = TextR3.getLocalBounds();
    TextR3_3.setOrigin(textR3_3Bounds.left + textR3_3Bounds.width / 2.0f, textR3_3Bounds.top + textR3_3Bounds.height / 2.0f);
    TextR3_3.setPosition(Rect3_3.getPosition().x, Rect3_3.getPosition().y);



    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect Rect1_3Pos = Rect1_3.getGlobalBounds();
                sf::FloatRect Rect2_3Pos = Rect2_3.getGlobalBounds();
                sf::FloatRect Rect3_3Pos = Rect3_3.getGlobalBounds();
               

                if (Rect1_3Pos.contains(static_cast<sf::Vector2f>(MousePosition)))
                {
                    Rect1_3.setFillColor(sf::Color(255, 255, 150));
                }
                else if (Rect2_3Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {

                    Rect2_3.setFillColor(sf::Color(255, 255, 150));
                }
                else if (Rect3_3Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {

                    Rect3_3.setFillColor(sf::Color(255, 255, 150));
                }
            
                else
                {
                    Rect1_3.setFillColor(sf::Color(255, 255, 50));
                    Rect2_3.setFillColor(sf::Color(255, 255, 50));
                    Rect3_3.setFillColor(sf::Color(255, 255, 50));
                    
                }

            }

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect Rect1_3Pos = Rect1_3.getGlobalBounds();
                sf::FloatRect Rect2_3Pos = Rect2_3.getGlobalBounds();
                sf::FloatRect Rect3_3Pos = Rect3_3.getGlobalBounds();

                if (event.mouseButton.button == sf::Mouse::Left) {

                    if (Rect1_3Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {

                        Pressed3 = 1;
                        window.close();
                    }
                    else if (Rect2_3Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {
                        Pressed3 = 2;
                        window.close();
                    }
                    else if (Rect3_3Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {
                        Pressed3 = 3;
                        window.close();
                    }
                }
            }
        }

        window.clear();
        window.draw(buttonRect1);
        window.draw(titleText);
        window.draw(Rect1_3);
        window.draw(TextR1_3);
        window.draw(Rect2_3);
        window.draw(TextR2_3);
        window.draw(Rect3_3);
        window.draw(TextR3_3);
     
        window.display();
    }
}

void Button::showButton4(const std::string& title, const std::string& title2)
{
    //Tworzenie nowego okna o wymiarach 500x300
    window2.create(sf::VideoMode(300, 200), "Monopoly AGH");
    window2.setPosition(sf::Vector2i(370, 400));

    sf::Vector2f WindowSize2(window2.getSize().x, window2.getSize().y);
    //Ikona
    icon2.loadFromFile("Textures/beer.png");
    //Ustaw ikony dla okna
    window.setIcon(icon2.getSize().x, icon2.getSize().y, icon2.getPixelsPtr());
 
        //Inicjalizacja prostok¹ta przycisku
    buttonRect2.setSize(WindowSize2);
    buttonRect2.setFillColor(sf::Color(255, 255, 153));
    buttonRect2.setPosition(0.f, 0.f);
    
    //Inicjalizacja tekstu tytu³u
    titleText.setFont(font);
    titleText.setCharacterSize(15);
    titleText.setFillColor(sf::Color::Black);
    titleText.setStyle(sf::Text::Bold);
    titleText.setString(title);
    sf::FloatRect textBounds = titleText.getLocalBounds();
    titleText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    titleText.setPosition(WindowSize2.x / 2, (WindowSize2.y / 5));
    
    titleText2.setFont(font);
    titleText2.setCharacterSize(15);
    titleText2.setFillColor(sf::Color::Black);
    titleText2.setStyle(sf::Text::Bold);
    titleText2.setString(title2);
    sf::FloatRect textBounds2 = titleText2.getLocalBounds();
    titleText2.setOrigin(textBounds2.left + textBounds2.width / 2.0f, textBounds2.top + textBounds2.height / 2.0f);
    titleText2.setPosition(WindowSize2.x / 2, (WindowSize2.y / 5)*2);

    //Inicjalizacja prostokata 1 Tak kupuje

    sf::Vector2f Rect1_4size(120.f, 50.f);
    Rect1_4.setSize(Rect1_4size);
    Rect1_4.setOrigin(Rect1_4size.x / 2, Rect1_4size.y / 2);
    Rect1_4.setFillColor(sf::Color(255, 255, 50));
    Rect1_4.setPosition((WindowSize2.x / 5) * 1.2, (WindowSize2.y / 5) * 3);
    Rect1_4.setFillColor(sf::Color(255, 255, 50));
    Rect1_4.setOutlineThickness(0.5f);
    Rect1_4.setOutlineColor(sf::Color::Black);

    //Init tekstu dla prostokata 1 Tak, kupuje

    TextR1_4.setFont(font);
    TextR1_4.setCharacterSize(15);
    TextR1_4.setFillColor(sf::Color::Black);
    TextR1_4.setStyle(sf::Text::Bold);
    TextR1_4.setString("Tak, kupuje");
    sf::FloatRect textR1_4Bounds = TextR1_4.getLocalBounds();
    TextR1_4.setOrigin(textR1_4Bounds.left + textR1_4Bounds.width / 2.0f, textR1_4Bounds.top + textR1_4Bounds.height / 2.0f);
    TextR1_4.setPosition(Rect1_4.getPosition().x, Rect1_4.getPosition().y);


    //Init prostokata 2  - nie, rezygnuje
    sf::Vector2f Rect2_4size(120.f, 50.f);
    Rect2_4.setSize(Rect2_4size);
    Rect2_4.setOrigin(Rect2_4size.x / 2, Rect2_4size.y / 2);
    Rect2_4.setFillColor(sf::Color(255, 255, 50));
    Rect2_4.setPosition((WindowSize2.x / 5) * 3.8, (WindowSize2.y / 5) * 3);
    Rect2_4.setFillColor(sf::Color(255, 255, 50));
    Rect2_4.setOutlineThickness(0.5f);
    Rect2_4.setOutlineColor(sf::Color::Black);

    //Init tekstu 2 - nie, rezygnuje
    TextR2_4.setFont(font);
    TextR2_4.setCharacterSize(15);
    TextR2_4.setFillColor(sf::Color::Black);
    TextR2_4.setStyle(sf::Text::Bold);
    TextR2_4.setString("Nie, rezygnuje");
    sf::FloatRect TextR2_4Bounds = TextR2_4.getLocalBounds();
    TextR2_4.setOrigin(TextR2_4Bounds.left + TextR2_4Bounds.width / 2.0f, TextR2_4Bounds.top + TextR2_4Bounds.height / 2.0f);
    TextR2_4.setPosition(Rect2_4.getPosition().x, Rect2_4.getPosition().y);


    while (window2.isOpen()) {
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window2.close();
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i MousePosition = sf::Mouse::getPosition(window2);
                sf::FloatRect Rect1_4Pos = Rect1_4.getGlobalBounds();
                sf::FloatRect Rect2_4Pos = Rect2_4.getGlobalBounds();



                if (Rect1_4Pos.contains(static_cast<sf::Vector2f>(MousePosition)))
                {
                    Rect1_4.setFillColor(sf::Color(255, 255, 150));
                }
                else if (Rect2_4Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {

                    Rect2_4.setFillColor(sf::Color(255, 255, 150));
                }

                else
                {
                    Rect1_4.setFillColor(sf::Color(255, 255, 50));
                    Rect2_4.setFillColor(sf::Color(255, 255, 50));

                }

            }

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i MousePosition = sf::Mouse::getPosition(window2);
                sf::FloatRect Rect1_4Pos = Rect1_4.getGlobalBounds();
                sf::FloatRect Rect2_4Pos = Rect2_4.getGlobalBounds();

                if (event.mouseButton.button == sf::Mouse::Left) {

                    if (Rect1_4Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {

                        Pressed4 = 1;
                        window2.close();
                    }

                    else if (Rect2_4Pos.contains(static_cast<sf::Vector2f>(MousePosition))) {

                        Pressed4 = 0;
                        window2.close();
                    }
                    
                }
            }
        }

        window2.clear();
        window2.draw(buttonRect2);
        window2.draw(titleText);
        window2.draw(titleText2);
        window2.draw(Rect1_4);
        window2.draw(TextR1_4);
        window2.draw(Rect2_4);
        window2.draw(TextR2_4);
        window2.display();


    }
}










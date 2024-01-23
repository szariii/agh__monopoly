#include "StartWindow.h"

StartWindow::StartWindow()
{
    window.create(sf::VideoMode(800, 800), "Monopoly Start", sf::Style::Close);

    if (!backgroundTexture.loadFromFile("Textures/money_background.jpg"))
    {
        std::cerr << "Error loading start background texture!" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

    if (!font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Error loading font!" << std::endl;
    }

    titleText.setFont(font);
    titleText.setString("MONOPOLY AGH");
    titleText.setCharacterSize(70);
    titleText.setStyle(sf::Text::Bold);
    titleText.setOutlineColor(sf::Color::Black);
    titleText.setOutlineThickness(3.f);
    titleText.setPosition(400.f - titleText.getLocalBounds().width / 2, 50.f);

    playButton.setFont(font);
    playButton.setString("Graj");
    playButton.setCharacterSize(40);
    playButton.setStyle(sf::Text::Bold);
    playButton.setOutlineColor(sf::Color::Black);
    playButton.setOutlineThickness(3.f);
    playButton.setPosition(400.f - playButton.getLocalBounds().width / 2, 300.f);

    exitButton.setFont(font);
    exitButton.setString("Wyjdz");
    exitButton.setCharacterSize(40);
    exitButton.setStyle(sf::Text::Bold);
    exitButton.setOutlineColor(sf::Color::Black);
    exitButton.setOutlineThickness(3.f);
    exitButton.setPosition(400.f - exitButton.getLocalBounds().width / 2, 400.f);

    defaultTextColor = playButton.getFillColor();
}

StartWindow::~StartWindow()
{
}

void StartWindow::handleMouseEvents()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    // SprawdŸ, czy mysz jest nad przyciskiem "Graj"
    if (playButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        playButton.setFillColor(sf::Color::Red); // Ustaw kolor tekstu na czerwony
    }
    else
    {
        playButton.setFillColor(defaultTextColor); // Przywróæ domyœlny kolor tekstu
    }

    // SprawdŸ, czy mysz jest nad przyciskiem "WyjdŸ"
    if (exitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        exitButton.setFillColor(sf::Color::Red); // Ustaw kolor tekstu na czerwony
    }
    else
    {
        exitButton.setFillColor(defaultTextColor); // Przywróæ domyœlny kolor tekstu
    }
}

int StartWindow::run()
{
    while (window.isOpen())
    {
        handleMouseEvents(); // Obs³uga zdarzeñ myszy

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 1; // Wyjœcie z gry
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (playButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    window.close();
                    return 0; // Rozpocznij grê
                }

                if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    window.close();
                    return 1; // Wyjœcie z gry
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(titleText);
        window.draw(playButton);
        window.draw(exitButton);
        window.display();
    }

    return 1; // Wyjœcie z gry (teoretycznie nie powinno nigdy dojœæ do tego miejsca)
}
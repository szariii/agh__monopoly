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
        playButton.setFillColor(sf::Color::Cyan); // Ustaw kolor tekstu na czerwony
    }
    else
    {
        playButton.setFillColor(defaultTextColor); // Przywróæ domyœlny kolor tekstu
    }

    // SprawdŸ, czy mysz jest nad przyciskiem "WyjdŸ"
    if (exitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        exitButton.setFillColor(sf::Color::Cyan); // Ustaw kolor tekstu na czerwony
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
        handleMouseEvents();

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
                    return choosePlayerCount(); // Wywo³aj now¹ funkcjê dla wyboru iloœci graczy
                    window.close();
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
}

int StartWindow::choosePlayerCount()
{
    sf::Text playerCountText;
    playerCountText.setFont(font);
    playerCountText.setString("Wybierz ilosc graczy (2 - 4):");
    playerCountText.setCharacterSize(40);
    playerCountText.setStyle(sf::Text::Bold);
    playerCountText.setOutlineColor(sf::Color::Black);
    playerCountText.setOutlineThickness(3.f);
    playerCountText.setFillColor(sf::Color::White);

    playerCountText.setPosition(400.f - playerCountText.getLocalBounds().width / 2, 200.f);

    sf::Text confirmButton;
    confirmButton.setFont(font);
    confirmButton.setString("Zatwierdz");
    confirmButton.setCharacterSize(30);
    confirmButton.setStyle(sf::Text::Bold);
    confirmButton.setOutlineColor(sf::Color::Black);
    confirmButton.setOutlineThickness(3.f);
    confirmButton.setFillColor(sf::Color::White);
    confirmButton.setPosition(400.f - confirmButton.getLocalBounds().width / 2, 500.f);

    sf::RectangleShape playerCountRectangle(sf::Vector2f(200.f, 60.f));
    playerCountRectangle.setFillColor(sf::Color::White);
    playerCountRectangle.setPosition(400.f - playerCountRectangle.getSize().x / 2, 300.f);

    int selectedPlayerCount = 2;

    sf::Text plusButton;
    plusButton.setFont(font);
    plusButton.setString("+");
    plusButton.setCharacterSize(40);
    plusButton.setStyle(sf::Text::Bold);
    plusButton.setOutlineColor(sf::Color::Black);
    plusButton.setOutlineThickness(3.f);
    plusButton.setFillColor(sf::Color::White);
    plusButton.setPosition(playerCountRectangle.getPosition().x + playerCountRectangle.getSize().x + 30.f, 300.f + 5.f); // Przesuniêcie w prawo

    sf::Text minusButton;
    minusButton.setFont(font);
    minusButton.setString("-");
    minusButton.setCharacterSize(40);
    minusButton.setStyle(sf::Text::Bold);
    minusButton.setOutlineColor(sf::Color::Black);
    minusButton.setOutlineThickness(3.f);
    minusButton.setFillColor(sf::Color::White);
    minusButton.setPosition(playerCountRectangle.getPosition().x - 50.f, 300.f + 5.f); // Przesuniêcie w lewo

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 1; // Wyjœcie z gry
            }

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (plusButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            {
                plusButton.setFillColor(sf::Color::Green);
            }
            else
            {
                plusButton.setFillColor(sf::Color::White);
            }

            // SprawdŸ, czy najechano na przycisk "-"
            if (minusButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            {
                minusButton.setFillColor(sf::Color::Red);
            }
            else
            {
                minusButton.setFillColor(sf::Color::White);
            }

            // SprawdŸ, czy najechano na przycisk "ZatwierdŸ"
            if (confirmButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                confirmButton.setFillColor(sf::Color::Cyan);
            }
            else
            {
                confirmButton.setFillColor(sf::Color::White);
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (confirmButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    window.close();
                    return selectedPlayerCount; // Zwróæ iloœæ graczy po zatwierdzeniu
                }

                // SprawdŸ, czy klikniêto w obszar z liczb¹ graczy
                if (plusButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                {
                    // Klikniêto na przycisk "+" - zwiêksz iloœæ graczy
                    if (selectedPlayerCount < 4)
                    {
                        selectedPlayerCount++;
                    }
                }
                else if (minusButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                {
                    // Klikniêto na przycisk "-" - zmniejsz iloœæ graczy
                    if (selectedPlayerCount > 2)
                    {
                        selectedPlayerCount--;
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(playerCountText);

        // Rysuj prostok¹t z liczb¹ graczy
        window.draw(playerCountRectangle);
        sf::Text selectedPlayerCountText;
        selectedPlayerCountText.setFont(font);
        selectedPlayerCountText.setString(std::to_string(selectedPlayerCount));
        selectedPlayerCountText.setCharacterSize(30);
        selectedPlayerCountText.setFillColor(sf::Color::Black);
        selectedPlayerCountText.setPosition(playerCountRectangle.getPosition().x + playerCountRectangle.getSize().x / 2 - selectedPlayerCountText.getLocalBounds().width / 2,
            playerCountRectangle.getPosition().y + playerCountRectangle.getSize().y / 2 - selectedPlayerCountText.getLocalBounds().height / 2);
        window.draw(selectedPlayerCountText);

        // Rysuj przyciski z napisami "+" i "-"
        window.draw(plusButton);
        window.draw(minusButton);

        window.draw(confirmButton);

        window.display();
    }

    return 1; // Wyjœcie z gry
}

int StartWindow::getSelectedPlayerCount() const
{
    return selectedPlayerCount;
}
#include "OknoStartowe.h"
#include <iostream>
void OknoStartowe::initOkno()
{
	videoMode.height = 1000;
	videoMode.width = 1500;
	okno_start.create(videoMode, "MONOPOLY AGH", sf::Style::Close | sf::Style::Titlebar);
}

void OknoStartowe::initZmienne()
{
	N_czcionka.loadFromFile("C:/Users/jrumi/OneDrive/Pulpit/PROJEKT/MONOPOLYPROBA2/Raleway-Bold.ttf");
	sf::Color kolor_czcionki(128, 128, 128, 255);
	Tekstura_n1.loadFromFile("C:\Users\jrumi\OneDrive\Pulpit\PROJEKT\MONOPOLYPROBA2\Kasa-tekstura.jpg");
	
	if (!Tekstura_n1.loadFromFile("C:/Users/jrumi/OneDrive/Pulpit/PROJEKT/MONOPOLYPROBA2/Kasa-tekstura.jpg")) {
		// B³¹d ³adowania tekstury
		std::cout << "Nie udalo sie zaladowac tekstury!" << std::endl;
	}
	
	sf::IntRect rect_tekstury(szerokosc_n, wysokosc_n, 0, 0);
	//Zmienne naglowka	
	x_n = 1250;
	y_n = 200;
	
	szerokosc_n = 300;
	wysokosc_n = 50;
	N_napis.setString("MONOPOLY AGH");			// string tekstu w naglowku
	N_napis.setFont(N_czcionka);				//Przypisanie czcionki
	N_napis.setCharacterSize(40);				// wielkosc czcionki
	N_napis.setFillColor(kolor_czcionki);		// no przeciez umiesz czytac
	N_napis.setOutlineColor(sf::Color::Black);
	N_napis.setOutlineThickness(5);
	sf::FloatRect textBounds = N_napis.getLocalBounds();
	N_napis.setOrigin(sf::Vector2f(textBounds.width / 2.0f, textBounds.height / 2.0f));
	N_napis.setPosition(sf::Vector2f(x_n, y_n));
										
	Naglowek.setTexture(Tekstura_n1);
	Naglowek.setTextureRect(rect_tekstury);
	Naglowek.setOrigin(sf::Vector2f( szerokosc_n / 2.0f, wysokosc_n / 2.0f));
	Naglowek.setPosition(sf::Vector2f(x_n, y_n));
								
							

	//Podpisy
	P_napis;
	P_kolorTekstu;
	P_czcionka;
	x_p, y_p;

	

}

void OknoStartowe::rysuj()
{
	okno_start.draw(Naglowek);
	okno_start.draw(N_napis);
}

void OknoStartowe::render()
{
	okno_start.clear(sf::Color::Black);

	rysuj();

	okno_start.display();



}

void OknoStartowe::update()
{
}

OknoStartowe::OknoStartowe()
{
	initOkno();
	initZmienne();

}

OknoStartowe::~OknoStartowe()
{
}

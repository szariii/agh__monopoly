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
	//Tekstura_n1.loadFromFile("C:/Users/jrumi/OneDrive/Pulpit/PROJEKT/MONOPOLYPROBA2/Kasa-tekstura.jpg");
	
	if (!Tekstura_n1.loadFromFile("C:/Users/jrumi/OneDrive/Pulpit/PROJEKT/MONOPOLYPROBA2/Grosze.jpg")) {
		// B³¹d ³adowania tekstury
		std::cout << "Nie udalo sie zaladowac tekstury!" << std::endl;
	}


	if (!Tekstura_m.loadFromFile("C:/Users/jrumi/OneDrive/Pulpit/PROJEKT/MONOPOLYPROBA2/board.png")) {
		// B³¹d ³adowania tekstury
		std::cout << "Nie udalo sie zaladowac tekstury!" << std::endl;
	}
	
	

	//Zmienne naglowka	
	x_n = 1250;
	y_n = 200;

	x_g = 1250;
	y_g = 400;

	szerokosc_n = 350;
	wysokosc_n = 80;
	
	szerokosc_g = 400;
	wysokosc_g = 50;

	sf::IntRect rect_tekstury (0, 0, szerokosc_n, wysokosc_n + 10.f);
	sf::IntRect rect_tekstury_g (0, 0, szerokosc_g, wysokosc_g + 5.f);

	N_napis.setString("MONOPOLY AGH");			// string tekstu w naglowku
	N_napis.setFont(N_czcionka);				//Przypisanie czcionki
	N_napis.setCharacterSize(40);				// wielkosc czcionki
	N_napis.setFillColor(kolor_czcionki);		// no przeciez umiesz czytac
	N_napis.setOutlineColor(sf::Color::Black);
	N_napis.setOutlineThickness(4);
	sf::FloatRect textBounds = N_napis.getLocalBounds();
	N_napis.setOrigin(sf::Vector2f(textBounds.width / 2.0f, textBounds.height / 2.0f));
	N_napis.setPosition(sf::Vector2f(x_n, y_n));
										
	Naglowek.setTexture(Tekstura_n1);
	Naglowek.setTextureRect(rect_tekstury);
	Naglowek.setOrigin(sf::Vector2f( szerokosc_n / 2.0f, wysokosc_n / 2.0f));
	Naglowek.setPosition(sf::Vector2f(x_n, y_n));
								
							

	//Podaj ilosc graczy
	G_napis.setString("Podaj ilosc graczy");
	G_napis.setFont(N_czcionka);				
	G_napis.setCharacterSize(30);				
	G_napis.setFillColor(kolor_czcionki);		
	G_napis.setOutlineColor(sf::Color::Black);
	G_napis.setOutlineThickness(4);
	sf::FloatRect textBounds_g = G_napis.getLocalBounds();
	G_napis.setOrigin(sf::Vector2f(textBounds_g.width / 2.0f, textBounds_g.height / 2.0f));
	G_napis.setPosition(sf::Vector2f(x_g, y_g));

	Naglowek_g.setTexture(Tekstura_n1);
	Naglowek_g.setTextureRect(rect_tekstury_g);
	Naglowek_g.setOrigin(sf::Vector2f( szerokosc_g / 2.0f, wysokosc_g / 2.0f));
	Naglowek_g.setPosition(sf::Vector2f(x_g, y_g));
	
	//Wpis graczy
	x_w = 1250;
	y_w = 500;
	szerokosc_w = 250;
	wysokosc_w = 30;

	
	
	okno_wpis.setOutlineColor(sf::Color::White);
	okno_wpis.setOutlineThickness(0.5f);
	okno_wpis.setSize(sf::Vector2f(szerokosc_w, wysokosc_w));
	okno_wpis.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
	okno_wpis.setOrigin(sf::Vector2f(szerokosc_w / 2, wysokosc_w / 2));
	okno_wpis.setPosition(sf::Vector2f(x_w, y_w));
	
	ilosc_graczy = '0';
	sf::Text ilosc_graczy_tekst;
	std::string Nazwy_graczy;
	std::string ilosc_graczy_string;
	bool wpisywanie = true;
	
	znacznik.setPosition(x_w - 150.f, y_w);
	znacznik.setSize(sf::Vector2f(5, 5));
	znacznik.setFillColor(sf::Color::Red);
	
	//wpis graczy zmienne do logiki 
	
	//ilosc_graczy_tekst.setString(ilosc_graczy_string);
	ilosc_graczy_tekst.setFont(N_czcionka);
	ilosc_graczy_tekst.setCharacterSize(30);
	ilosc_graczy_tekst.setFillColor(sf::Color::White);
	ilosc_graczy_tekst.setOutlineColor(sf::Color::Black);
	ilosc_graczy_tekst.setOutlineThickness(0.5f);
	//sf::FloatRect textBounds_l = ilosc_graczy_tekst.getLocalBounds();
	//ilosc_graczy_tekst.setOrigin(sf::Vector2f(textBounds_g.width / 2.0f, textBounds_g.height / 2.0f));
	ilosc_graczy_tekst.setPosition(sf::Vector2f(x_w - 100, y_w));
	bool czy_wpisywac;
	

	//mapka - rezta okna
	Mapa.setTexture(Tekstura_m);
	Mapa.setPosition(0, 0);








	P_kolorTekstu;
	P_czcionka;
	x_p, y_p;
	
	

}

void OknoStartowe::rysuj_default()
{
	okno_start.draw(Naglowek);
	okno_start.draw(N_napis);
	
	okno_start.draw(Naglowek_g);
	okno_start.draw(G_napis);

	
	okno_start.draw(Mapa);
//	ilosc_graczy_tekst.setString("japiedoleeeee");
	//okno_start.draw(ilosc_graczy_tekst);
}

void OknoStartowe::render()
{
	okno_start.clear(sf::Color::Black);

	rysuj_default();

}

void OknoStartowe::funkcjePrzyciskow()
{
	while (okno_start.pollEvent(wydarzenie))
	{
		if (wydarzenie.type == sf::Event::MouseButtonPressed)
		{
			if (wydarzenie.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2f mousePosition = sf::Vector2f(wydarzenie.mouseButton.x, wydarzenie.mouseButton.y);
				if (Naglowek.getGlobalBounds().contains(mousePosition))
				{
					okno_start.close();
				}
				else if (Naglowek_g.getGlobalBounds().contains(mousePosition))
				{
					czr_wpis = true;
				}
				else if (okno_wpis.getGlobalBounds().contains(mousePosition))
				{
					 czy_wpisywac = true;
					 wpisywanie = true;
				}
				else
				{
					czy_wpisywac = false;
				}
				
			}
		}
		else if (wydarzenie.type == sf::Event::MouseMoved)
		{
			sf::Vector2f mousePosition = sf::Vector2f(wydarzenie.mouseMove.x, wydarzenie.mouseMove.y);
			if (Naglowek.getGlobalBounds().contains(mousePosition))
			{
				N_napis.setFillColor(sf::Color::White);
			}
			else if (Naglowek_g.getGlobalBounds().contains(mousePosition))
			{
				G_napis.setFillColor(sf::Color::White);
			}
			else if (okno_wpis.getGlobalBounds().contains(mousePosition))
			{
				okno_wpis.setFillColor(sf::Color(140.f, 140.f, 140.f, 255.f));
			}
			
			else
			{
				N_napis.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
				G_napis.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
				okno_wpis.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
			}
		}
		else if (wydarzenie.type == sf::Event::TextEntered && czy_wpisywac)
		{
			bool wpisywanie = true;
			// SprawdŸ, czy tekst nie jest pusty
			if (wydarzenie.text.unicode >= 32 && wydarzenie.text.unicode < 128)
			{
				// Dodaj znak do ci¹gu
				ilosc_graczy_string += static_cast<char>(wydarzenie.text.unicode);
			}
			else if (wydarzenie.text.unicode == 8 && !ilosc_graczy_string.empty())
			{
				// Usuñ ostatni znak z ci¹gu (backspace)
				ilosc_graczy_string.pop_back();
			}



			ilosc_graczy_tekst.setString(ilosc_graczy_string);
			std::cout << sratata() << std::endl;
			std::cout << ilosc_graczy_string << std::endl;
			//okno_start.draw(ilosc_graczy_tekst);
		}

		
	}
}

std::string OknoStartowe::sratata() {
	return ilosc_graczy_tekst.getString();
}


void OknoStartowe::wpis_graczy_rysuj()
{
	if (czr_wpis == true)
	{
		sf::RectangleShape* wsk_wpis = new sf::RectangleShape(okno_wpis);
		okno_start.draw(*wsk_wpis);
		if (czr_wpis == false)
		{
			delete wsk_wpis;
		}
	}

	if (czy_wpisywac == true)
	{
		sf::RectangleShape* wsk_znacznik = new sf::RectangleShape(znacznik);
		okno_start.draw(*wsk_znacznik);
		

		if (czy_wpisywac == false)
		{
			delete wsk_znacznik;
		}
	}
	if (wpisywanie == true)
	{
		sf::Text* wsk_wpisywanie = new sf::Text(ilosc_graczy_tekst);
		okno_start.draw(*wsk_wpisywanie);
		

		if (wpisywanie == false)
		{
			delete wsk_wpisywanie;
		}

	}
}
void OknoStartowe::wpis_graczy_logika()
{
	if (czy_wpisywac == true)
	{

	}
	

}





void OknoStartowe::wyswietl()
{
	okno_start.display();
}




bool OknoStartowe::running() const
{
	return okno_start.isOpen();
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


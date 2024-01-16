#pragma once
#include "Game.h"
#include "Przycisk.h"
#include <iostream>
#include <string>


class OknoStartowe
{
private:
	//Naglowek
	
	int szerokosc_n, wysokosc_n;
	sf::Texture Tekstura_n1;
	sf::Text N_napis;
	sf::Sprite Naglowek;
	sf::Font N_czcionka;
	sf::Color N_kolorTekstu;
	float x_n, y_n;
	
	//Naglowek ilosc graczy
	int szerokosc_g, wysokosc_g;
	sf::Text G_napis;
	sf::Sprite Naglowek_g;
	float x_g, y_g;
	
	
	//Wpis ilosc graczy
	
	char ilosc_graczy;
	sf::Text ilosc_graczy_tekst;
	std::string ilosc_graczy_string;
	std::string Nazwy_graczy;
	/*
	std::string nazwa_gracza1;
	std::string nazwa_gracza2;
	std::string nazwa_gracza3;
	std::string nazwa_gracza4;
	std::string nazwa_gracza5;
	std::string nazwa_gracza6;
	*/
	
	int szerokosc_w, wysokosc_w;
	sf::RectangleShape okno_wpis;
	sf::String wejscie_w;
	sf::Text wypis_w;
	float x_w, y_w;
	bool czr_wpis = false;



	//Tekstura mapy
	sf::Sprite Mapa;
	sf::Texture Tekstura_m;
	
	//Podpisy
	sf::Text P_napis;
	sf::Color P_kolorTekstu;
	sf::Font P_czcionka;
	float x_p, y_p;

	//Okno
	sf::VideoMode videoMode;
	sf::RenderWindow okno_start;
	sf::Texture tlo;
	//wpisywanie gracyz
	bool czy_wpisywac;
	sf::RectangleShape znacznik;
	bool wpisywanie;

	std::string sratata();
	//Do funkcji

	sf::Event wydarzenie;

	//Inicjacja zmiennych

	void initOkno();
	void initZmienne();
	






public:
	
	void rysuj_default();
	void render();
	void update();
	void funkcjePrzyciskow();
	bool running() const;
	void wpis_graczy_rysuj();
	void wpis_graczy_logika();
	void wyswietl();
	
	OknoStartowe();
	~OknoStartowe();








};


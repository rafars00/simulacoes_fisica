#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;



class CargaPontual
{
protected:
	long double m;
	sf::Vector2f v;
	sf::Vector2f a;
	sf::Vector2f forcaR;
	sf::RectangleShape corpo;
	long double q;

public:
	CargaPontual();
	~CargaPontual();

	sf::Vector2f getPosicao();
	void setPosicao(sf::Vector2f D);
	sf::Vector2f getForcaR() { return forcaR; }
	void setForcaR(sf::Vector2f Fr) { forcaR = Fr; }
	long double getQ() { return q; }
	void setQ(long double Q) { q = Q; }

	void setColor(sf::Color c) { corpo.setFillColor(c); }

	void setSize(sf::Vector2f s) { corpo.setSize(s); }
	void draw(sf::RenderWindow& window) { window.draw(corpo); }

	void update();

};


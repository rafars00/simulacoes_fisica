#pragma once
#include <SFML/Graphics.hpp>

class CargaPontual
{
protected:
	sf::RectangleShape* corpo;
	//sf::Vector2f d;
	float q;


public:
	CargaPontual();
	~CargaPontual();
	void setQ(float Q) { q = Q; }
	float getQ() { return q; }

	void setPosicao(sf::Vector2f D);
	sf::Vector2f getPosicao() { return corpo->getPosition(); }

	void setSize(sf::Vector2f tam) { corpo->setSize(tam); }
	sf::RectangleShape& getCorpo() { return (*corpo); }
	void Draw(sf::RenderWindow& window) { window.draw(*corpo); }
};


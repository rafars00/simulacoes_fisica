#include "CargaPontual.h"

CargaPontual::CargaPontual()
{
	q = 0.01f;
	d.x = 0.0f;
	d.y = 0.0f;

	corpo = new sf::RectangleShape();
	corpo->setSize(sf::Vector2f(30.0f, 30.0f));
	corpo->setPosition(d);
	corpo->setOrigin(corpo->getSize() / 2.0f);
	corpo->setFillColor(sf::Color::White);
}

CargaPontual::~CargaPontual()
{
}

void CargaPontual::setPosicao(sf::Vector2f D)
{
	d = D;
	corpo->setPosition(d);
}
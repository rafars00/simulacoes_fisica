#include "CargaPontual.h"

CargaPontual::CargaPontual()
{
	m = 1;
	q = 0.5f;
	
	corpo.setSize(sf::Vector2f(30.0f, 30.0f));
	corpo.setPosition(sf::Vector2f(0.0f, 0.0f));
	corpo.setOrigin(corpo.getSize() / 2.0f);
	corpo.setFillColor(sf::Color::White);
}

CargaPontual::~CargaPontual()
{
}

sf::Vector2f CargaPontual::getPosicao()
{
	return corpo.getPosition();
}

void CargaPontual::setPosicao(sf::Vector2f D)
{
	corpo.setPosition(D);
}

void CargaPontual::update()
{
	float deltatime = 0.4f;
	float ga = 0.001f;

	a.x = forcaR.x / m - ga*v.x/m;
	a.y = forcaR.y / m - ga*v.y/m;

	v.x += a.x * deltatime;
	v.y += a.y * deltatime;

	if (corpo.getPosition().x < 700.0f && corpo.getPosition().x > 100.0f)  //só pra não sair sair da tela
		corpo.move(v * deltatime);

}

#pragma once

#include "CargaPontual.h"
#include "FioCarregado.h"

class CargaDeProva: public CargaPontual
{
private:
	float m;
//	const float g;
	sf::Vector2f v;
	sf::Vector2f a;
	sf::Vector2f forca;

public:
	CargaDeProva(float M);
	~CargaDeProva();

	void Update();

	void CalculaForca(FioCarregado* fio);
	void CalculaForcaQPontual(CargaPontual* q0);
	void setMassa(float M) { m = M; }
	float getMassa() { return m; }

	void setVelocidade(sf::Vector2f V) { v = V; }
	sf::Vector2f getVelocidade() { return v; }

	void setAceleracao(sf::Vector2f A) { a = A; }
	sf::Vector2f getAceleracao() { return a; }
};


#include "Simulacao.h"

Simulacao::Simulacao():
	fio(5)
{
}

Simulacao::~Simulacao()
{
}

void Simulacao::simulacao()
{
}

sf::Vector2f Simulacao::ForcaInteracao(CargaDeProva* carga_p, CargaPontual* carga)
{
	sf::Vector2f forca;
	sf::Vector2f r;
	sf::Vector2f versor_r;
	float norma_r;

	//calcula r
	r.x = (carga_p->getD().x - carga->getD().x);
	r.y = (carga_p->getD().y - carga->getD().y);

	//calcula norma de r
	norma_r = sqrt(r.x * r.x + r.y + r.y);

	//calcula versor r
	versor_r.x = r.x / norma_r;
	versor_r.y = r.y / norma_r;

	//calcula vetor forca
	forca.x = carga_p->getQ() * carga->getQ() * versor_r.x / norma_r * norma_r;
	forca.y = carga_p->getQ() * carga->getQ() * versor_r.y / norma_r * norma_r;

	//retorna vetor forca
	return forca;
}

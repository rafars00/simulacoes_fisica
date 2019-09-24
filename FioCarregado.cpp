#include "FioCarregado.h"

FioCarregado::FioCarregado(int n_cargas)
{
	qtd_cargas = n_cargas;
	setFio();
}

FioCarregado::~FioCarregado()
{
	for (int i = 0; i < qtd_cargas; i++)
	{
		CargaPontual* temp_carga = NULL;
		temp_carga = carga[i];
		delete(temp_carga);
	}
	carga.clear();
}

void FioCarregado::setFio()
{
	sf::Vector2f d;
	d.x = 50.0f;
	d.y = 510.0f;

	for (int i = 0; i < qtd_cargas; i++)
	{
		CargaPontual* nova_carga = new CargaPontual();
		nova_carga->setPosicao(d);
		nova_carga->setSize(sf::Vector2f(1.0f, 2.0f));
		d.x += 1.0f;
		carga.push_back(nova_carga);
		//cout << "carga fio x: " << d.x << " carga fio y: " << d.y << endl << endl;
	}
}

void FioCarregado::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < qtd_cargas; i++)
	{
		CargaPontual* c = carga[i];
		c->Draw(window);
	}
}

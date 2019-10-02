#include "FioCarregado.h"

FioCarregado::FioCarregado(int n_cargas)
{
	qtd_cargas = n_cargas;
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

void FioCarregado::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < qtd_cargas; i++)
	{
		CargaPontual* c = carga[i];
		c->draw(window);
	}
}

void FioCarregado::setFioHorizontal()
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

void FioCarregado::setFioHorizontalAleatorio()
{
	sf::Vector2f d;
	int limiteEsq, limiteDir;
	int k = 1;
	limiteEsq = 50;
	limiteDir = 650;

	for (int i = 0; i < qtd_cargas; i++)
	{
		CargaPontual* nova_carga = new CargaPontual();
		nova_carga->setPosicao(sf::Vector2f(110.0f + i * 4.0f, 300.0f));
		nova_carga->setSize(sf::Vector2f(2.0f, 10.0f));
		if(k==1)
		{
			nova_carga->setColor(sf::Color::Red);
			k++;
		}
		else if (k == 2)
		{
			nova_carga->setColor(sf::Color::Yellow);
			k++;
		}
		else if (k == 3)
		{
			nova_carga->setColor(sf::Color::Green);
			k = 1;
		}
		carga.push_back(nova_carga);
	}
}

void FioCarregado::update()
{
	for (int i = 0; i < qtd_cargas; i++)
	{
		CargaPontual* c = carga[i];
		c->update();
	}
}

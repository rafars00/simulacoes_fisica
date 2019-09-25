#pragma once
#include <vector>
#include <iostream>
#include "CargaPontual.h"

using namespace std;

class FioCarregado
{
private:
	vector<CargaPontual*> carga;
	int qtd_cargas;

public:
	FioCarregado(int n_cargas);
	~FioCarregado();

	vector<CargaPontual*> getCargas() { return carga; }

	void Draw(sf::RenderWindow& window);
	void setFioHorizontal();
	void setFioHorizontalAleatorio();
	void update();

	int getQtdCargas() { return qtd_cargas; }
};


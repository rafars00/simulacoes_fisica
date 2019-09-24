#pragma once

#include <vector>
#include <iostream>
using namespace std;
#include "CargaPontual.h"


class FioCarregado
{
private:
	vector<CargaPontual*> carga;
	int qtd_cargas;

public:
	FioCarregado(int n_cargas);
	~FioCarregado();

	void setFio();

	vector<CargaPontual*> getCargas() { return carga; }

	void Draw(sf::RenderWindow& window);

	int getQtdCargas() { return qtd_cargas; }
};


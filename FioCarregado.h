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
	float min_esq;
	float max_dir;
	float ponto_medio;

public:
	FioCarregado(int n_cargas, float min, float max);
	~FioCarregado();

	vector<CargaPontual*> getCargas() { return carga; }

	void Draw(sf::RenderWindow& window);
	void setFioHorizontal();
	void setFioHorizontalAleatorio();
	void update();

	int getQtdCargas() { return qtd_cargas; }
};


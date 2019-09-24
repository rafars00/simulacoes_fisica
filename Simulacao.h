#pragma once
#include "FioCarregado.h"
#include "CargaDeProva.h"

class Simulacao
{
private:
	sf::RenderWindow* window;

	FioCarregado* fio;
	CargaDeProva* carga;
	CargaPontual* carga0;

public:
	Simulacao();
	~Simulacao();

	void executar();

};


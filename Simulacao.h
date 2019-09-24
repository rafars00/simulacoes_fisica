#pragma once
#include "FioCarregado.h"
#include "CargaDeProva.h"

class Simulacao
{
private:
	sf::RenderWindow* window;

	FioCarregado* fio;
	CargaDeProva* carga;

public:
	Simulacao();
	~Simulacao();

	void executar();

};


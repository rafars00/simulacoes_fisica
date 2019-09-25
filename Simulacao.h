#pragma once

#include "Interacao.h"

class Simulacao
{
private:
	sf::RenderWindow* window;

	FioCarregado* fio;
	CargaPontual* carga;
	Interacao* interacao;

public:
	Simulacao();
	~Simulacao();

	void executar();
};

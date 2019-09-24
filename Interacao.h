#pragma once
#include "FioCarregado.h"
#include "CargaDeProva.h"

class Simulacao
{
private:
	FioCarregado fio;
	CargaDeProva carga;

public:
	Simulacao();
	~Simulacao();

	void simulacao();

	sf::Vector2f ForcaInteracao(CargaDeProva* carga_p, CargaPontual* carga);

};


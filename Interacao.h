#pragma once
#include "FioCarregado.h"


class Interacao
{
private:


public:
	Interacao();
	~Interacao();
	void calculaForcaCondutor(FioCarregado* Fio); // entre as cargas i x j do fio
	void correnteEletrica(FioCarregado* fio);
};


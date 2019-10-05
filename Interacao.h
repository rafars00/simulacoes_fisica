#pragma once
#include "FioCarregado.h"
#include "SuperficieEquipotencial.h"


class Interacao
{
private:


public:
	Interacao();
	~Interacao();
	void calculaForcaCondutor(FioCarregado* Fio); // entre as cargas i x j do fio
	void correnteEletrica(FioCarregado* fio);

	float calculaPotencial(FioCarregado* fio, sf::Vector2f posicao);
	void calculaSuperficiesEquipotenciais(FioCarregado* fio, float alto, float baixo, float esq, float dir,
										SuperficieEquipotencial* sup);

};


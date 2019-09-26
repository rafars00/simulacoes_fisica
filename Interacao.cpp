#include "Interacao.h"

Interacao::Interacao()
{
}

Interacao::~Interacao()
{
}

void Interacao::calculaForcaCondutor(FioCarregado* Fio)
{
	sf::Vector2f r;
	sf::Vector2f Forca;
	sf::Vector2f versor_r;
	long double norma_r;

	for (int i = 0; i < Fio->getCargas().size(); i++)
	{
		Forca.x = Forca.y = versor_r.x = versor_r.y = r.x = r.y = norma_r = 0.0f;

		for (int j = 0; j < Fio->getCargas().size(); j++)
		{
			
			if (i != j)
			{
				//calcula vetor r (vetor distancia da carga de prova até a origem subtraido
				//do vetor distancia da carga pontual até a origem)
				r.x = ((Fio->getCargas())[i]->getPosicao().x - (Fio->getCargas())[j]->getPosicao().x);
				r.y = ((Fio->getCargas())[i]->getPosicao().y - (Fio->getCargas())[j]->getPosicao().y);

				//calcula norma do vetor r
				norma_r = sqrt(r.x * r.x + r.y * r.y);

				//calcula versor do vetor r
				versor_r = sf::Vector2f(r.x / norma_r, r.y / norma_r);

				//calcula vetor forca
				Forca.x += Fio->getCargas()[i]->getQ() * Fio->getCargas()[j]->getQ() * versor_r.x / (norma_r * norma_r);
				Forca.y += Fio->getCargas()[i]->getQ() * Fio->getCargas()[j]->getQ() * versor_r.y / (norma_r * norma_r);
			}
			

			
		}

		Fio->getCargas()[i]->setForcaR(Forca);
	}



}

void Interacao::correnteEletrica(FioCarregado * fio)
{
	for (int i = 0; i < fio->getQtdCargas(); i++)
	{
		if (fio->getCargas()[i]->getPosicao().x >= 699.0f && fio->getCargas()[i]->getPosicao().x <= 701.0f)
		{
			fio->getCargas()[i]->setPosicao(sf::Vector2f(100.5f,fio->getCargas()[i]->getPosicao().y));
		}
	}
}

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

float Interacao::calculaPotencial(FioCarregado* fio, sf::Vector2f posicao)
{
	float v = 0;
	long double r;

	cout << "ENTREI NO CALCULAPOTENCIAL" << endl;

	for (int i = 0; i < fio->getQtdCargas(); i++)
	{
		//calcula norma do vetor r (distancia entre uma carga do fio e o ponto especificado)
		r = sqrt((posicao.x - fio->getCargas()[i]->getPosicao().x) * (posicao.x - fio->getCargas()[i]->getPosicao().x) +
			(posicao.y - fio->getCargas()[i]->getPosicao().y) * (posicao.y - fio->getCargas()[i]->getPosicao().y));

		//calcula diferenca de potencial no ponto especificado, tomando o infinito como referencia
		v += (fio->getCargas()[i])->getQ() / r;
	}

	cout << "SAI DO FOR" << endl;

	return v;
}

void Interacao::calculaSuperficiesEquipotenciais(FioCarregado* fio, float alto, float baixo, float esq, float dir,
												SuperficieEquipotencial* sup)
{
	//sf::RectangleShape ponto;
	float v;

	cout << "ENTREI AQUI" << endl;

	for (int i = (int) esq; i < (int) dir; i++)
	{
		for (int j = (int) alto; j < (int) baixo; j++)
		{
			v = calculaPotencial(fio, sf::Vector2f(i, j));

			cout << "AGORA AQUI" << endl;

			if (v >= 0.0797f && v <= 0.0803)
			{

				cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
				//sf::RectangleShape ponto
				//aparentemente eu vou ter que criar uma classe "superficie equipotencial" porque
				//eu vou ter que criar ela e ficar dando update até que eu escolha que ela nao apareça mais
				//beleza vamo la

				sup->setPonto(sf::Vector2f(i, j), sf::Color::Yellow);

			}
			else if (v >= 0.0707 && v <= 0.0713)
			{
				sup->setPonto(sf::Vector2f(i, j), sf::Color::Green);
			}
			else if (v >= 0.0847 && v <= 0.0853)
			{
				sup->setPonto(sf::Vector2f(i, j), sf::Color::Red);
			}

		}
	}
}

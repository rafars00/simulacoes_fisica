#include "CargaDeProva.h"

CargaDeProva::CargaDeProva(float M) :
	CargaPontual()
	//g(10.0f)
{
	v = sf::Vector2f(0.0f, 0.0f);
	a = sf::Vector2f(0.0f, 0.0f);
	forca.x = forca.y = 0;
	m = M;
}

CargaDeProva::~CargaDeProva()
{
}

void CargaDeProva::Update()
{
	float deltatime = 1.0f;
	cout << "f.x: " << forca.x << " f.y: " << forca.y << endl;

	a.x = forca.x / m;
	a.y = forca.y / m;

	v.x += a.x * deltatime;
	v.y += a.y * deltatime;
	cout << "a.x: " << a.x << "a.y: " << a.y << endl;
	if (corpo->getPosition().y < 500.0f && corpo->getPosition().y > 5.0f)
		corpo->move(v * deltatime);

	//corpo->move(sf::Vector2f(1.0f, 1.0f));
	//this->setPosicao(d);

}

void CargaDeProva::CalculaForca(FioCarregado* fio)
{
	sf::Vector2f r;
	sf::Vector2f versor_r;
	float norma_r;
	float g = 10.0f;
	int tam = fio->getQtdCargas();
	//float k = 9 * 1000000000;
	forca.x = forca.y = 0.0f;

	for (int i = 0; i < tam; i++)
	{
		//calcula vetor r (vetor distancia da carga de prova até a origem subtraido
		//do vetor distancia da carga pontual até a origem)
		r.x = (corpo->getPosition().x - (fio->getCargas())[i]->getPosicao().x);
		r.y = (corpo->getPosition().y - (fio->getCargas())[i]->getPosicao().y);

		//calcula norma do vetor r
		norma_r = sqrt(r.x * r.x + r.y * r.y);

		//calcula versor do vetor r
		versor_r = sf::Vector2f(r.x / norma_r, r.y / norma_r);

		//calcula vetor forca
		forca.x += q * fio->getCargas()[i]->getQ() * versor_r.x / (norma_r * norma_r);
		forca.y += q * fio->getCargas()[i]->getQ() * versor_r.y / (norma_r * norma_r);

		//cout << "f.x: " << forca.x << " f.y: " << forca.y << endl;
	}

	//criar variavel 'forca' para guardar esse valor lá e depois
	//usar para calcular aceleração
	//no update: atualizar aceleração, velocidade e posição e
	//recalcular força
}

void CargaDeProva::CalculaForcaQPontual(CargaPontual* q0)
{
	sf::Vector2f r;
	sf::Vector2f versor_r;
	float norma_r;
	//float g = 10.0f;
	//int tam = fio->getQtdCargas();
	//double k = 9 * 1000000000;
	forca.x = forca.y = 0.0f;

	r.x = (corpo->getPosition().x - (q0->getPosicao().x));
	r.y = (corpo->getPosition().y - (q0->getPosicao().y));

	//calcula norma do vetor r
	norma_r = sqrt(r.x * r.x + r.y * r.y);

	//calcula versor do vetor r
	versor_r = sf::Vector2f(r.x / norma_r, r.y / norma_r);

	cout << "norma vr: " << norma_r << endl;


	//calcula vetor forca
	forca.x = q * q0->getQ() * versor_r.x / (norma_r * norma_r);
	forca.y = q * q0->getQ() * versor_r.y / (norma_r * norma_r);

	cout << " q: " << q << " q0: " << q0->getQ() << " vrx: " << versor_r.x <<
		" vry: " << versor_r.y << " norma r: " << norma_r << endl;
}

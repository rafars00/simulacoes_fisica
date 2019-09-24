#include "CargaDeProva.h"

CargaDeProva::CargaDeProva(float M):
	CargaPontual(),
	g(0.0f)
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
	float deltatime = 0.001f;

	cout << "f.x: " << forca.x << " f.y: " << forca.y << endl;

	a.x = forca.x / m;
	a.y = forca.y / m + g;

	v.x += a.x;
	v.y += a.y;

	if ( d.y < 500.0f)
		d += sf::Vector2f(v);

	//corpo->move(d*deltatime);
	this->setPosicao(d);
}

void CargaDeProva::CalculaForca(FioCarregado* fio)
{
	sf::Vector2f r;
	sf::Vector2f versor_r;
	float norma_r;
	int tam = fio->getQtdCargas();
	float k = 9 * 1000000000;
	forca.x = forca.y = 0.0f;

	for (int i = 0; i < tam; i++)
	{
		//calcula vetor r (vetor distancia da carga de prova até a origem subtraido
		//do vetor distancia da carga pontual até a origem)
		r.x = (d.x - (fio->getCargas())[i]->getPosicao().x);
		r.y = (d.y - (fio->getCargas())[i]->getPosicao().y);

		//calcula norma do vetor r
		norma_r = sqrt(r.x * r.x + r.y * r.y);

		//calcula versor do vetor r
		versor_r = sf::Vector2f(r.x / norma_r, r.y / norma_r);

		//calcula vetor forca
		forca.x += k * q * fio->getCargas()[i]->getQ() * versor_r.x / norma_r * norma_r;
		forca.y += k * q * fio->getCargas()[i]->getQ() * versor_r.y / norma_r * norma_r;

		//cout << "f.x: " << forca.x << " f.y: " << forca.y << endl;
	}

	//criar variavel 'forca' para guardar esse valor lá e depois
	//usar para calcular aceleração
	//no update: atualizar aceleração, velocidade e posição e
	//recalcular força
}

#include "SuperficieEquipotencial.h"

SuperficieEquipotencial::SuperficieEquipotencial()
{
	cout << "size vector: " << pontos.size() << endl;
}

SuperficieEquipotencial::~SuperficieEquipotencial()
{
	for (int i = 0; i < pontos.size(); i++)
	{
		sf::RectangleShape* t = NULL;
		t = pontos[i];
		delete(t);
	}
	pontos.clear();
}

void SuperficieEquipotencial::setPonto(sf::Vector2f posicao, sf::Color cor)
{
	//if (pontos.size() != 0)
	//{

	//}

	cout << "entrei aqui" << endl;

	sf::RectangleShape* novo_ponto = new sf::RectangleShape();
	novo_ponto->setFillColor(cor);
	novo_ponto->setPosition(posicao);
	novo_ponto->setSize(sf::Vector2f(2.0f, 2.0f));
	novo_ponto->setOrigin(novo_ponto->getSize() / 2.0f);

	pontos.push_back(novo_ponto);
}

void SuperficieEquipotencial::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < pontos.size(); i++)
	{
		window.draw(*pontos[i]);
	}
}

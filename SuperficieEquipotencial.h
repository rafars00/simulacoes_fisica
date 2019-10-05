#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;

class SuperficieEquipotencial
{
private:
	vector<sf::RectangleShape*> pontos;
	//float v;

public:
	SuperficieEquipotencial();
	~SuperficieEquipotencial();

	vector<sf::RectangleShape*> getPontos() { return pontos; }
	void setPonto(sf::Vector2f posicao, sf::Color cor);

	void Draw(sf::RenderWindow& window);
};


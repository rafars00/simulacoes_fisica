#include <SFML/Graphics.hpp>
#include "CargaDeProva.h"
#include "FioCarregado.h"
#include "Simulacao.h"


int main()
{
	/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.0f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/

	//sf::Vector2f forca;

	//CargaDeProva* carga_de_prova;
	//CargaPontual* cargas[2];

	//forca = ForcaInteracao(carga_de_prova, cargas[1]);

	Simulacao simulacao;

	simulacao.executar();

	return 0;
}
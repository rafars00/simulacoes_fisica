#include "Simulacao.h"

Simulacao::Simulacao()
{
	//fio = NULL;
	//carga = NULL;

	window = new sf::RenderWindow(sf::VideoMode(640, 520), "Simulação fio carregado", sf::Style::Close);
	fio = new FioCarregado(500);
	carga = new CargaDeProva(1.0f);
	carga->setQ(0.01f);
}

Simulacao::~Simulacao()
{
}

void Simulacao::executar()
{
	bool pause = false;
	carga->setPosicao(sf::Vector2f(250.0f, 210.0f)); //r.y ~ 300

	while (window->isOpen())
	{
		sf::Event evnt;

		//ver sfml tutorial
		//acho que tem que mexer em coisa de fps
		//ele ta atualizando a posicao em blocos e o bloco ta teleportando

		while (window->pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			default:
				//cout << "eu chego aqui" << endl;
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			pause = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			pause = false;
		}

		if (!pause)
		{
			carga->CalculaForca(fio);
			carga->Update();
			window->clear();
			carga->Draw(*window);
			fio->Draw(*window);
			window->display();
		}
	}

	delete(carga);
	delete(fio);
}



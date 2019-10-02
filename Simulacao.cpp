#include "Simulacao.h"
#include <chrono>
#include <thread>

Simulacao::Simulacao()
{
	carga = NULL;
	interacao = new Interacao();

	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Simulação fio carregado", sf::Style::Close);
	fio = new FioCarregado(40);
}

Simulacao::~Simulacao()
{
}

void Simulacao::executar()
{
	bool pause = false;
	bool corrente = false;
	fio->setFioHorizontalAleatorio();

	while (window->isOpen())
	{
		sf::Event evnt;

		//fio->setFioHorizontalAleatorio();

		while (window->pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				//cout << "eu chego aqui pora" << endl;
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{
			pause = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L))
		{
			corrente = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			corrente = false;
		}

		if (!pause)
		{
			window->clear();
			//carga->draw(*window);


			// Calcula força entre cargas do condutor
			interacao->calculaForcaCondutor(fio);
			
			if(corrente)
				interacao->correnteEletrica(fio);
			
			fio->update();

			cout << "ultima carga: " << fio->getCargas()[24]->getPosicao().x <<
				" segunda carga: " << fio->getCargas()[1]->getPosicao().x << endl;

			fio->Draw(*window);

			window->display();

			//using namespace std::this_thread;
			//using namespace std::chrono_literals;
			//using std::chrono::system_clock;
		}
	}

	cout << "cabei" << endl;

	//delete(carga);
	delete(interacao);
	delete(fio);
}



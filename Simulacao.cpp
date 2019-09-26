#include "Simulacao.h"
#include <chrono>
#include <thread>

Simulacao::Simulacao()
{
	carga = NULL;
	interacao = new Interacao();

	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Simulação fio carregado", sf::Style::Close);
	fio = new FioCarregado(25);
}

Simulacao::~Simulacao()
{
}

void Simulacao::executar()
{
	bool pause = false;
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
				cout << "eu chego aqui pora" << endl;
				window->close();
				break;
			default:
				cout << "eu chego aqui" << endl;
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

		if (!pause)
		{
			window->clear();
			//carga->draw(*window);


			// Calcula força entre cargas do condutor
			interacao->calculaForcaCondutor(fio);
			interacao->correnteEletrica(fio);
			fio->update();

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



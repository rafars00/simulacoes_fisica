#include "Simulacao.h"
#include <chrono>
#include <thread>

Simulacao::Simulacao()
{
	carga = NULL;
	interacao = new Interacao();

	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Simulação fio carregado", sf::Style::Close);
	fio = new FioCarregado(20);
	sup = new SuperficieEquipotencial();
}

Simulacao::~Simulacao()
{
}

void Simulacao::executar()
{
	bool pause = false;
	bool corrente = false;
	bool superficies = false;
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V))
		{
			superficies = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			superficies = false;
		}

		if (!pause)
		{
			window->clear();
			//carga->draw(*window);


			// Calcula força entre cargas do condutor
			interacao->calculaForcaCondutor(fio);
			cout << "pot: " << interacao->calculaPotencial(fio, sf::Vector2f(400.0f, 200.0f)) << endl;
			
			if(corrente)
				interacao->correnteEletrica(fio);

			fio->update();

			if (superficies)
			{
				delete(sup);
				sup = new SuperficieEquipotencial();
				interacao->calculaSuperficiesEquipotenciais(fio, 170.0f, 430.0f, 100.0f, 700.0f, sup);
				sup->Draw(*window);
			}

			//cout << "ultima carga: " << fio->getCargas()[24]->getPosicao().x <<
				//" segunda carga: " << fio->getCargas()[1]->getPosicao().x << endl;

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
	delete(sup);
	delete(window);
}



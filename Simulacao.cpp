#include "Simulacao.h"
#include <chrono>
#include <thread>

Simulacao::Simulacao()
{
	//fio = NULL;
	//carga = NULL;
	
	window = new sf::RenderWindow(sf::VideoMode(640, 520), "Simulação fio carregado", sf::Style::Close);
	fio = new FioCarregado(500);
	carga = new CargaDeProva(1.0f);
	carga->setQ(5.0f);
	carga0 = new CargaPontual();


}

Simulacao::~Simulacao()
{
}

void Simulacao::executar()
{
	bool pause = false;
	carga->setPosicao(sf::Vector2f(360.0f, 410.0f)); //r.y ~ 300
	carga->setSize(sf::Vector2f(5.0f, 5.f));
	carga0->setPosicao(sf::Vector2f(300.f, 220.0f));
	carga0->setSize(sf::Vector2f(4.0f, 4.0f));
	carga0->getCorpo().setFillColor(sf::Color::Blue);
	sf::RectangleShape t;
	t.setPosition(sf::Vector2f(300.0f, 400.0f));
	t.setFillColor(sf::Color::Blue);
	t.setSize(sf::Vector2f(5.f, 50.0f));
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
			//window->draw(t);
			window->draw(carga->getCorpo());
			carga->Draw(*window);
			//carga0->Draw(*window);
			fio->Draw(*window);
			window->display();
			
			using namespace std::this_thread;
			using namespace std::chrono_literals;
			using std::chrono::system_clock;
			//sleep_for(1s);
			//sleep_until(system_clock::now() + 1s);
		}
	}

	delete(carga);
	delete(fio);
}



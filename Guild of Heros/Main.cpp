#include <SFML/Graphics.hpp>
#include "Level.h"
#include "TexturePool.h"
#include "Player.h"
#include "BasicEnemy.h"
#include "Entity.h"

#include <vector>

int main()
{
	int height = 1024, width = 1024;


	sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
	
	TexturePool texPool;
	texPool.loadFromFile("resources/level/textureNames.txt");


	Level *level = new OverworldLevel(&texPool, 50, 50);
	level->generate("resources/level/Overworld.txt");

	Player p(texPool.get("player"), 1, 1);
	p.setLevel(level);
	
	std::vector<Entity*> enemyVec;
	for (int i = 0; i < 5; i++) {
		Entity *e = new BasicEnemy(texPool.get("enemy"), 1, 1);
		e->setLevel(level);
		enemyVec.push_back(e);
	}

	sf::View view;
	view.setSize(width/2, height/2);
	view.setCenter(p.getWindowPosition());

	sf::Clock clock;
	long prevTime = clock.getElapsedTime().asMilliseconds();
	long currentTime;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		//Update
		currentTime = clock.getElapsedTime().asMilliseconds();
		long dt = currentTime - prevTime;
		prevTime = currentTime;

		bool status = p.update(dt);
		view.setCenter(p.getWindowPosition());
		if (status) {
			for (int i = 0; i < enemyVec.size(); i++) {
				enemyVec[i]->update(dt);
			}
		}

		
		//Render

		window.setView(view);

		window.clear();
		level->render(window);
		for (int i = 0; i < enemyVec.size(); i++) {
			enemyVec[i]->render(window);
		}
		p.render(window);
		window.display();
	}

	return 0;
}
#include <SFML/Graphics.hpp>
#include "Headers/Config.h"
#include "Headers/SelectionSort.h"
#include <iostream>

int main() {
	
	float deltaTime = 0.0f;
	int n;
	std::cin >> n;
	SelectionSort sort(n);
	sort.printHeights();
	sf::RenderWindow window(sf::VideoMode({ WIN_WIDTH, WIN_HEIGHT }), "TestWindow", sf::Style::Close);
	window.setFramerateLimit(WIN_FPS);

	while (window.isOpen()) {

		while (std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
				window.close();
		}
		window.clear(sf::Color::Black);
		sort.sortArray();
		sort.render(&window);
		window.display();
	}


}
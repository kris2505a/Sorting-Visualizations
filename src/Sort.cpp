#include "Headers/Sort.h"
#include "Headers/Config.h"
#include <iostream>
#include <random>
#include <algorithm>


Sort::Sort(int n) {
	this->size = n;
	this->width = WIN_WIDTH / this->size;
	this->generateHeight();
	this->generateRectangles();
}

void Sort::generateHeight() {
	float maxHeight = WIN_HEIGHT;
	float minHeight = 50.0f;
	float deltaHeight = (maxHeight) / this->size;
	for (size_t i{ 1 }; i <= this->size; i++) {
		this->heights.push_back(deltaHeight * i);
	}
	std::random_device randdev;
	std::mt19937 seq(randdev());
	std::shuffle(this->heights.begin(), this->heights.end(), seq);
}

void Sort::printHeights() {
	for (auto i : this->rectangles) {
		std::cout << i->getSize().y << ", ";
	}
	std::cout << std::endl << std::endl << "Width : " << this->width << std::endl;
}

void Sort::generateRectangles() {
	float deltaX = 0;
	for (size_t i{ 0 }; i < this->size; i++) {
		auto rect = new sf::RectangleShape({ this->width, this->heights.at(i) });
		rect->setFillColor(sf::Color::Red);
		rect->setOutlineColor(sf::Color::White);
		rect->setOutlineThickness(1.0f);
		this->rectangles.push_back(rect);
		rect->setPosition({ deltaX + 1.0f, WIN_HEIGHT - this->heights.at(i) });
		deltaX += this->width;
	}
}

void Sort::render(sf::RenderWindow* window) {
	for (auto i : rectangles) {
		window->draw(*i);
	}
}

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Sort {

protected:
	int size{ 0 };
	std::vector <float> heights;
	std::vector <sf::RectangleShape*> rectangles;

	float width{ 0.0f };
	size_t index1{ 0 }, index2{ 1 };

public:
	Sort(int);
	void generateHeight();
	void generateRectangles();
	void printHeights();
	void render(sf::RenderWindow*);
	virtual void sortArray() = 0;
};
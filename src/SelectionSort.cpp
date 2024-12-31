#include "Headers/SelectionSort.h"


void SelectionSort::sortArray() {
	if (this->index1 >= this->size) {
		return;
	}

	if (this->index2 < this->size &&
		this->rectangles.at(index1)->getSize().y > this->rectangles.at(index2)->getSize().y) {
		sf::Vector2f tmp1 = rectangles.at(index1)->getPosition();
		sf::Vector2f tmp2 = rectangles.at(index2)->getPosition();
		std::swap(tmp1.x, tmp2.x);
		rectangles.at(index1)->setPosition(tmp1);
		rectangles.at(index2)->setPosition(tmp2);
		std::swap(rectangles.at(index1), rectangles.at(index2));
	}

	index2++;
	if (index2 >= this->size) {
		index2 = index1 + 1;
		index1++;
	}

	this->printHeights();
}

SelectionSort::SelectionSort(int n) 
	: Sort(n){}
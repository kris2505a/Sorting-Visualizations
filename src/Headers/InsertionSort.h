#pragma once
#include "Sort.h"

class InsertionSort : public Sort {
private:
	int ind1, ind2;

public:
	InsertionSort(int);
	virtual void sortArray();
};

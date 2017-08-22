#include "PQHeap.h"
#include <vector>
#include <iostream>
#include "enemy.h"
#include <math.h>
#include <iomanip>

using namespace std;

PQHeap::PQHeap(int initialCapacity)
{
    heapArray.reserve(++initialCapacity);
	heapArray.push_back(nullptr); //as the 0th element won't be used
}

PQHeap::~PQHeap(){}

void PQHeap::insert_enemy (enemy* enemyptr)
{
    if (empty_heap()){
        heapArray.push_back(enemyptr);
    }
    else {
        heapArray.push_back(enemyptr);
		int i;
		for (i = heap_count(); i > 1; i /= 2) {
			if (heapArray[i] > heapArray[i/2])
				swap_elements(i, i / 2);
			else
				return;
		}
    }
}

bool PQHeap::empty_heap()
{
    if (heapArray.size() == 1) //as the 0th element is just a null pointer
        return true;
    else
        return false;
}

int PQHeap::heap_count()
{
    return heapArray.size()-1; //ignore the 0th element
}

void PQHeap::swap_elements(int ind1, int ind2) 
{
	enemy* temp = heapArray[ind1];
	heapArray[ind1] = heapArray[ind2];
	heapArray[ind2] = temp;
}

void PQHeap::print_heap()
{
	int max = heap_count();
	int levels = (int)log2(max);
	for (int i = 0; i <= levels; i++) {
		for (int j = (int)pow(2, i); j < pow(2, i + 1) && j <= max; j++) {
			if (j == 1)
				cout << heapArray[j]->priority << '\t';
			else
				cout << heapArray[j]->priority << '(' << heapArray[j/2]->priority << ')' << "     ";
		}
		cout << endl;
	}
	cout << endl;
}

enemy* PQHeap::get_max()
{
	return heapArray[1];
}

enemy* PQHeap::delete_max()
{
	enemy* temp = heapArray[1];
	heapArray[1] = heapArray[heap_count()];
	heapArray.pop_back();



	return temp;
}
#include <iostream>
#include "PQHeap.h"
#include "enemy.h"

using namespace std;

int main()
{
    PQHeap x(10);

	vector<enemy> enem(21);
	for (int i = 1; i <= 1; i++) {
		enem[i].priority = (float)i;
		x.insert_enemy(&enem[i]);
	}

	x.print_heap();

	cout << x.delete_max()->priority<<endl<<endl;

	x.print_heap();
}

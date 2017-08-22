#include <iostream>
#include "PQHeap.h"
#include "enemy.h"

using namespace std;

int main()
{
    PQHeap x(10);

	vector<enemy> enem(25);
	for (int i = 1; i <= 22; i++) {
		enem[i].priority = (float)i;
		x.insert_enemy(&enem[i]);
	}
	enem[23].priority = 0;
	x.insert_enemy(&enem[23]);

	x.print_heap();

	cout << x.delete_max()->priority<<endl<<endl;
	cout << x.delete_enem(&enem[22])->priority << endl << endl;

	x.print_heap();
}

#include "stdafx.h"
#include "Data.h"
#include <iostream>
#include <stack>
#include "Tree.h"

using namespace std;

int main()
{	// values: 0 - wall, 1 - standard, 2 - border, 3 - road;
	Data* ss = new Data(5, 5, 8);
	//implementing our map
	ss->add(1, 2, 0, 0);
	ss->add(1, 2, 0, 1);
	ss->add(1, 2, 0, 2);
	ss->add(1, 2, 0, 3);
	ss->add(0, 2, 0, 4);

	ss->add(1, 2, 1, 1);
	ss->add(2, 1, 1, 2);
	ss->add(2, 1, 2, 3);
	ss->add(1, 1, 3, 4);
	ss->add(0, 2, 3, 5);

	ss->add(2, 2, 4, 2);
	ss->add(2, 2, 1, 3);
	ss->add(2, 1, 2, 4);
	ss->add(2, 2, 3, 5);
	ss->add(0, 1, 5, 6);

	ss->add(1, 2, 2, 3);
	ss->add(1, 2, 2, 4);
	ss->add(1, 2, 2, 5);
	ss->add(2, 2, 6, 6);
	ss->add(0, 1, 5, 7);

	ss->add(2, 0, 7, 4);
	ss->add(1, 0, 6, 5);
	ss->add(1, 0, 6, 6);
	ss->add(2, 0, 6, 7);
	ss->add(0, 2, 5, 8);
//ss->print();
	ss->expanding_tree();
	//ss->iterativeDFS();
	cout << endl;
	//ss->printStatus();
	//ss->path();
	//ss->check();
	getchar();

}//
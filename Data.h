#pragma once
#include "Tree.h"
#include <iostream>
#include <stack>
using namespace std;
class Data
{
	Tree* tree;
	int i = 0;
	int width;
	int height;
	int column = 0;
	int country_num = 0;
	stack <int> stos;
	int arr[999];
	int z = 0;
	// values: 0 - wall, 1 - standard, 2 - border, 3 - road standard , 4 - road border;
	struct block
	{
		int country_id;
		int block_id;
		int status; // 0 - pusty, 1 - odwiedzony, 2 - zakonczony 
		int level; // poziom na którym znajduje siê wierzcholek
		bool road = false;
		block* top;
		block* right;
		block* bottom;
		block* left;
		block* parrent;
		int top_value;
		int right_value;
		int bottom_value;
		int left_value;

		int row;
		int number;
	}*head, *last;
public:
	Data(int wid, int hei, int num_country);
	~Data();
	int check();
	void clearStatus();
	void printStatus();
	void iterativeDFS();
	void recursiveDFS(block *root, int depth);
	void printStack();
	int searchfor(int value);
	void print();
	void expanding_tree();
	void rec_tree(block* current);
	int lookforrow(block* temp);
	void add(int value, int value_2, int country, int level);
	void path();
};

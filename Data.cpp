#include "stdafx.h"
#include "Data.h"
#include <iostream>

using namespace std;
Data::Data(int wid, int hei, int num_country)
{
	tree = new Tree();
	this->width = wid;
	this->height = hei;
	this->head = nullptr;
	this->last = nullptr;
	this->country_num = num_country;
}
Data::~Data()
{

}
int Data::check()
{
	block* checker = head;
	block* start = head;
	int checked_country[25];
	for (int i = 0; i < country_num; i++)
	{
		checked_country[i] = 0;
	}
	while (start != nullptr)
	{
		while (checker != nullptr)
		{
			cout << "Node:" << checker->block_id << endl;
			if (checker->road == false)
			{
				if ((checker->left != nullptr) && (checker->left->road == false) && (checker->left_value == 2))
				{
					cout << "Border left" << endl;
					return 1;
				}
				if ((checker->bottom != nullptr) && (checker->bottom->road == false) && (checker->bottom_value == 2))
				{
					cout << "Border bottom" << endl;
					return 1;
				}
				if ((checker->right != nullptr) && (checker->right->road == false) && (checker->right_value == 2))
				{
					cout << "Border right" << endl;
					return 1;
				}
				if ((checker->top != nullptr) && (checker->top->road == false) && (checker->top_value == 2))
				{
					cout << "Border top" << endl;
					return 1;
				}

			}

			if (checker->left_value == 4)
			{
				checked_country[checker->country_id]++;
			}

			if (checker->bottom_value == 4)
			{
				checked_country[checker->country_id]++;
			}

			if (checker->right_value == 4)
			{
				checked_country[checker->country_id]++;
			}

			if (checker->top_value == 4)
			{
				checked_country[checker->country_id]++;
			}
			checker = checker->right;
		}
		start = start->bottom;
		checker = start;
	}
	cout << "-----" << endl;
	for (int x = 0; x < country_num; x++)
	{
		cout << checked_country[x] << endl;
		if (checked_country[x] != 2)
		{
			cout << "out of range" << endl;
			return 1;
		}

	}
	return 0;

}
void Data::clearStatus()
{
	block *vertical = head;
	block *horizontal = vertical;

	while (vertical != nullptr)
	{
		while (horizontal != nullptr)
		{
			horizontal->status = 0;
			horizontal = horizontal->right;
		}
		vertical = vertical->bottom;
		horizontal = vertical;
	}
}
void Data::printStatus()
{
	block *vertical = head;
	block *horizontal = vertical;

	while (vertical != nullptr)
	{
		while (horizontal != nullptr)
		{
			cout << horizontal->status << " ";
			horizontal = horizontal->right;
		}
		cout << endl;
		vertical = vertical->bottom;
		horizontal = vertical;
	}
}
void Data::iterativeDFS()
{
	block *start = head;
	int min = 0;
	int max = 5;

	for (int i = min + 1; i <= max; i++)
	{
		this->clearStatus();
		cout << "LEVEL: " << i << endl;
		this->recursiveDFS(start, i);
		cout << endl;
		this->printStack();
		cout << endl;
		cout << "**";
		cout << endl;
	}
}
void Data::recursiveDFS(block *root, int depth)
{
	block *start = root;
	block *horizontal = root;

	//cout << horizontal->block_id << "- ";

	if (horizontal->level <= depth)
	{
		cout << horizontal->block_id << " ";
		if (horizontal->bottom != nullptr && horizontal->bottom->level <= depth && horizontal->bottom->status != 2)
		{

			if (horizontal->status == 0)
			{
				horizontal->status = 1; // ustawiamy status na 1 - w trakcie
			}
			stos.push(horizontal->block_id);
			horizontal->bottom->parrent = horizontal; // Wierzcho³ek posiada dzieci, na które mo¿emy przejœæ. Jego dziecku ustawiamy rodzica
			horizontal = horizontal->bottom; // przechodzimy na dziecko;

			this->recursiveDFS(horizontal, depth);
		}
		else if (horizontal->right != nullptr && horizontal->right->level <= depth && horizontal->right->status != 2)
		{
			if (horizontal->status == 0)
			{
				horizontal->status = 1;
			}

			stos.push(horizontal->block_id);
			horizontal->right->parrent = horizontal;
			horizontal = horizontal->right;
			this->recursiveDFS(horizontal, depth);
		}
		else if (horizontal->top != nullptr && (horizontal->parrent != horizontal->top || horizontal->top == root))
		{
			if (horizontal->top == root)
			{
			}
			else
			{
				stos.push(horizontal->block_id);
				horizontal->status = 2;
				horizontal->parrent->status = 2;
				horizontal->parrent = horizontal->top;

				horizontal = horizontal->top;
				this->recursiveDFS(horizontal, depth);
			}

		}
		else if (horizontal->left != nullptr && (horizontal->parrent != horizontal->left || horizontal->left == root))
		{
			if (horizontal->left == start)
			{

			}
			else
			{
				stos.push(horizontal->block_id);
				horizontal->status = 2;
				horizontal->parrent = horizontal->left;

				horizontal = horizontal->left;
				this->recursiveDFS(horizontal, depth);
			}
		}
		else if (horizontal->parrent != nullptr && horizontal->parrent != horizontal)
		{
			if (horizontal->parrent->block_id == 0)
			{
				horizontal->status = 2;

			}
			else
			{
				stos.push(horizontal->block_id);
				horizontal->status = 2;

				horizontal = horizontal->parrent;
				horizontal->status = 2;
				this->recursiveDFS(horizontal, depth);
			}
		}

	}
	else
		cout << "Brak";

}
void Data::printStack()
{
	int size = stos.size();

	while (stos.empty() == false)
	{
		cout << stos.top() << " <- ";
		stos.pop();
	}
}


int Data::searchfor(int value)
{
	for (int a = 0; a < z; a++)
	{
		if (arr[a] == value)
			return 1;
	}
	return 0;
}
void Data::print()
{
	block* temp;
	block* start;
	temp = head;
	start = temp;
	while (start != nullptr)
	{
		while (temp != nullptr)
		{
			cout << "o ";
			if (temp->right_value == 2)
				cout << "-+- ";
			else if (temp->right_value == 1)
				cout << "--- ";
			else if (temp->right_value == 2)
			{

			}
			temp = temp->right;

		}
		cout << endl;
		temp = start;
		while (temp != nullptr && temp->bottom != nullptr)
		{
			if (temp->bottom_value == 1)
			{
				cout << "|";
				if (temp->right != nullptr)
				{
					cout << " --- ";
				}
			}
			if (temp->bottom_value == 2)
			{
				cout << "+";
				if (temp->right != nullptr)
				{
					cout << " --- ";
				}
			}
			temp = temp->right;
		}


		cout << endl;

		temp = start->bottom;
		start = temp;
	}

}
void Data::expanding_tree()
{
	block* current = head;
	arr[z] = current->block_id;
	current = current->bottom;
	z++;
	arr[z] = current->block_id;
	z++;
	int idofchilds[3];
	idofchilds[0] = -1;
	idofchilds[1] = -1;
	idofchilds[2] = -1;
	int t = 0;
	//if (current->left != nullptr && searchfor(current->left->block_id) != 1)
	if (current->left != nullptr && current->left != head)
	{
		idofchilds[t] = current->left->block_id;
		t++;
	}
	if (current->bottom != nullptr && current->bottom != head)
	{
		idofchilds[t] = current->bottom->block_id;
		t++;
	}
	if (current->right != nullptr && current->right != head)
	{
		idofchilds[t] = current->right->block_id;
		t++;
	}
	if (current->top != nullptr && current->top != head)
	{
		idofchilds[t] = current->top->block_id;
		t++;
	}
	tree->addRoot(current->block_id, idofchilds[0], idofchilds[1], idofchilds[2]);
	last = head;
	this->rec_tree(current);
}
void Data::rec_tree(block* current)
{
	
	int z = tree->proccess();
	cout << "Our proccess value: " << z << endl;
	if (z == 377)
		return;
//	cout << " Proccess value: "<< z << endl;
	if (current->left != nullptr && current->left != last)
	{
		tree->addForCurrent(current->left->block_id);
	}
	if (current->bottom != nullptr&& current->bottom != last)
	{
		tree->addForCurrent(current->bottom->block_id);
	}
	if (current->right != nullptr&& current->right != last)
	{
		tree->addForCurrent(current->right->block_id);
	}
	if (current->top != nullptr&& current->top != last)
	{
		tree->addForCurrent(current->top->block_id);
	}
	last = current;


	if (current->left != nullptr && current->left->block_id == z)
	{
		current = current->left;
		cout << "left" << endl;
	}
	if (current->bottom != nullptr && current->bottom->block_id == z)
	{
		current = current->bottom;
		cout << "bottom" << endl;
	}
	if (current->right != nullptr && current->right->block_id == z)
	{
		current = current->right;
		cout << "right" << endl;
	}
	if (current->top != nullptr && current->top->block_id == z)
	{
		current = current->top;
		cout << "top" << endl;
	}

	this->rec_tree(current);
	

}
int Data::lookforrow(block* temp)
{
	block* finder = head;
	block* start = head;
	int row = 0;
	while (start != nullptr)
	{
		while (finder != nullptr)
		{
			if (finder == temp)
				return row;

			finder = finder->right;
		}
		start = start->bottom;
		row++;
	}
	return -1;

}
void Data::add(int value, int value_2, int country, int level)
{
	block *temp = new block;

	temp->parrent = nullptr;
	temp->country_id = country;
	temp->block_id = i;
	i++;
	temp->right_value = value;
	temp->bottom_value = value_2;
	temp->bottom = nullptr;
	temp->right = nullptr;
	temp->level = level;
	if (head == nullptr) // we are adding head block - postiion (0,0)
	{
		temp->top_value = 0;
		temp->left_value = 0;
		temp->right_value = value;
		temp->bottom_value = value_2;
		temp->top = nullptr;
		temp->right = nullptr;
		temp->bottom = nullptr;
		temp->left = nullptr;
		last = temp;
		head = temp;
		column = 1;
		return;
	}
	if (column == this->width)
	{
		block *finder;
		finder = last;
		last->right_value = 0;
		while (finder->left != nullptr)
		{
			finder = finder->left;
		}
		finder->bottom = temp;
		temp->top = finder;
		temp->bottom = nullptr;
		temp->right = nullptr;
		temp->right_value = value;
		temp->bottom_value = value_2;
		temp->left = nullptr;
		temp->left_value = 0;
		last = temp;
		column = 1;
		finder = nullptr;
	}
	else
	{
		last->right = temp;
		temp->left = last;

		temp->left_value = last->right_value;
		if (last->top != nullptr)
		{
			temp->top = last->top->right;
			last->top->right->bottom = temp;
			temp->top_value = last->top->right->bottom_value;
		}
		else
		{
			temp->top = nullptr;
			temp->top_value = 0;
		}
		last = temp;
		this->column++;
		return;
	}
}
void Data::path()
{
	///values: 0 - wall, 1 - standard, 2 - border, 3 - road standard, 4 - road border;
	//example correct path for checking check() function
	block* roader = head;
	roader->road = true;
	roader->right_value = 3;
	cout << roader->block_id << endl;

	roader = roader->right;
	roader->left_value = 3;
	roader->right_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->right;
	roader->left_value = 3;
	roader->right_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->right;
	roader->left_value = 3;
	roader->right_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->right;
	roader->left_value = 3;
	roader->bottom_value = 4;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->bottom;
	roader->top_value = 4;
	roader->left_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->left;
	roader->right_value = 3;
	roader->bottom_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->bottom;
	roader->top_value = 3;
	roader->right_value = 4;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->right;
	roader->left_value = 4;
	roader->bottom_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->bottom;
	roader->top_value = 3;
	roader->left_value = 4;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->left;
	roader->right_value = 4;
	roader->bottom_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->bottom;
	roader->top_value = 3;
	roader->left_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->left;
	roader->right_value = 3;
	roader->left_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->left;
	roader->right_value = 3;
	roader->left_value = 4;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->left;
	roader->right_value = 4;
	roader->top_value = 4;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->top;
	roader->bottom_value = 4;
	roader->top_value = 4;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->top;
	roader->bottom_value = 4;
	roader->right_value = 4;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->right;
	roader->left_value = 4;
	roader->top_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->top;
	roader->bottom_value = 3;
	roader->left_value = 3;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->left;
	roader->right_value = 3;
	roader->top_value = 4;
	roader->road = true;
	cout << roader->block_id << endl;

	roader = roader->top;
	roader->bottom_value = 4;
	cout << roader->block_id << endl;


}


// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Data
{
	int width;
	int height;
	int row = 0;
	// values: 0 - wall, 1 - standard, 2 - border, 3 - road;
	struct block
	{

		block* top; //1
		block* right; //2
		block* bottom; // 3
		block* left; //4
		int top_value;
		int right_value;
		int bottom_value;
		int left_value;

		int number;
	}*head, *last;
public:
	Data(int wid, int hei)
	{
		this->width = wid;
		this->height = hei;
		this->head = nullptr;
		this->last = nullptr;
	}
	~Data()
	{

	}
	void print()
	{
		block* temp;
		temp = head;
		cout << "0-";
		while (temp != nullptr)
		{
			cout << "X-" << temp->right_value << "-";
			temp = temp->right;
		}
		cout << endl;
		temp = head->bottom;
		cout << "0-";
		while (temp != nullptr)
		{
			cout << "X-" << temp->right_value << "-";
			temp = temp->right;
		}
		cout << endl;

		std::cout << last->top->left_value;
	}
	void add(int value, int value_2)
	{
		block *temp = new block;
		temp->right_value = value;
		temp->bottom_value = value_2;
		temp->bottom = nullptr;
		temp->right = nullptr;
		temp->right_value = value;
		temp->bottom_value = value_2;
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
			row = 1;
			return;
		}
		if (row == this->width)
		{
			block *finder;
			finder = last;
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
			row = 1;
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
			this->row++;
			return;
		}
	}
};

using namespace std;
int main()
{	// values: 0 - wall, 1 - standard, 2 - border, 3 - road;
	Data* ss = new Data(5, 5);
	ss->add(1, 2);
	ss->add(1, 2);
	ss->add(1, 2);
	ss->add(1, 2);
	ss->add(0, 2);

	ss->add(1, 2);
	ss->add(2, 1);
	ss->add(2, 1);
	ss->add(1, 1);
	ss->add(0, 2);

	ss->add(2, 2);
	ss->add(2, 2);
	ss->add(2, 1);
	ss->add(2, 2);
	ss->add(0, 1);

	ss->add(1, 2);
	ss->add(1, 2);
	ss->add(1, 2);
	ss->add(2, 2);
	ss->add(0, 1);

	ss->add(2, 0);
	ss->add(1, 0);
	ss->add(1, 0);
	ss->add(2, 0);
	ss->add(0, 2);
	ss->print();
	getchar();

}

#include "stdafx.h"
#include "Tree.h"

using namespace std;
Tree::Tree()
{
	root = nullptr;
	current = nullptr;
}


Tree::~Tree()
{
}
void Tree::addRoot(int id, int a, int b, int c)
{
	Node* temp = new Node();
	root = temp;
	current = root;
	temp->first = nullptr;
	temp->second = nullptr;
	temp->third = nullptr;
	temp->id = id;
	temp->parent = nullptr;
	cout << a << " - first " << b <<" - second " << c << "- third "<< endl;
	temp->first_status = 0;
	temp->second_status = 0;
	temp->third_status = 0;
	if (a != -1)
	{
		Node* fir = new Node();
		fir->id = a;
		fir->first = nullptr;
		fir->second = nullptr;
		fir->third = nullptr;
		fir->first_status = 0;
		fir->second_status = 0;
		fir->third_status = 0;
		temp->first = fir;
		fir->parent = temp;

	}
	if (b != -1)
	{

		Node* sec = new Node();
		sec->id = b;
		sec->first = nullptr;
		sec->second = nullptr;
		sec->third = nullptr;
		sec->first_status = 0;
		sec->second_status = 0;
		sec->third_status = 0;
		temp->second = sec;
		sec->parent = temp;
	}
	if (c != -1)
	{
		Node* thi = new Node();
		thi->id = c;
		thi->first = nullptr;
		thi->second = nullptr;
		thi->third = nullptr;
		thi->first_status = 0;
		thi->second_status = 0;
		thi->third_status = 0;
		temp->third = thi;
		thi->parent = temp;
	}


}
int Tree::proccess()
{
	cout << current->id << "----------" << endl;
	if (current->first != nullptr && current->first_status != 1)
	{
		current->first_status = 1;
		current = current->first;
		return current->id;
	}
	else if (current->second != nullptr && current->second_status != 1)
	{
		current->second_status = 1;
		current = current->second;
		
		return current->id;
	}
	else if (current->third != nullptr && current->third_status != 1)
	{
		current->third_status = 1;
		current = current->third;
		
		return current->id;
	}
	return 377;
}
void Tree::addForCurrent(int x)
{
	cout << "Addding " << endl;
	Node* temp = new Node();
	temp->id = x;
	temp->first = nullptr;
	temp->second = nullptr;
	temp->third = nullptr;
	temp->first_status = 0;
	temp->second_status = 0;
	temp->third_status = 0;
	if (current->first == nullptr)
	{
		current->first = temp;
		temp->parent = current;
	}
	else if (current->second == nullptr)
	{
		current->second = temp;
		temp->parent = current;
	}
	else if (current->third == nullptr)
	{
		current->third = temp;
		temp->parent = current;
	}
	else
		cout << " All set" << endl;
}
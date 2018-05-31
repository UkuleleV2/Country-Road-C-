#pragma once
#include <iostream>
using namespace std;
class Tree
{
	struct Node
	{
		int id;
		Node* parent;

		Node* first;
		Node* second;
		Node* third;
		int first_status;
		int second_status;
		int third_status;
	}*root,*current;
public:
	Tree();
	~Tree();
	void addRoot(int id, int a, int b, int c);
	void modify(Node* temp, int a, int b, int c);
	int proccess();
	void addForCurrent(int x);
};


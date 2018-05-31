#pragma once
class tree
{
	struct node
	{
		node* first;
		node* second;
		node* third;
		int first_status;
		int second_status;
		int third_status;
	}*root;
};
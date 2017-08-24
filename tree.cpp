#include <iostream>

using namespace std;

struct Tree{
	int value;
	struct Tree *L, *R;
};

void add_left(struct Tree *root, int value)
{
	root->L=new Tree;
	root->L->value=value;
}

void add_right(struct Tree *root, int value)
{
	root->R=new Tree;
	root->R->value=value;
}

int main()
{
	struct Tree *root =  new Tree;

	return 0;
}
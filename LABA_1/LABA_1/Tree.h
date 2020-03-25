#pragma once
class Tree
{
protected:
	int value;
	Tree* left;
	Tree* right;

public:
	void addNode(int val, Tree** tree);
	void showTree(Tree* tree, int count);
	int childCount(Tree* tree, int count);
	void deleteSubTree(Tree* tree);
};


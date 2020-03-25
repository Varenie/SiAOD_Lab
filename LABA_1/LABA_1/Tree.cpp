#include "Tree.h"
#include <cstddef>
#include <cstdio>
#include <iostream>

using namespace std;

void Tree::addNode(int val, Tree **tree) {
	if ((*tree) == NULL) {
		(*tree) = new Tree;
		(*tree)->value = val;
		(*tree)->left = (*tree)->right = NULL;
		return;
	}
	else {
		if (val > (*tree)->value)
			addNode(val, &(*tree)->right);
		else addNode(val, &(*tree)->left);
	}
}

void Tree::showTree(Tree* tree, int count) {
	if (tree == NULL) return;
	else {
		showTree(tree->left, ++count);
		for (int i = 0; i < count; i++) {
			cout << "|";
		}
		cout << tree->value << endl;
	}
	showTree(tree->right, ++count);
}

int Tree::childCount(Tree* tree, int count) {
	if (tree == NULL) return count;
	if (tree->left == NULL) {
		if (tree->right == NULL) {
			return count;
		}
		else childCount(tree->right, ++count);
	}
	else {
		if (tree->right == NULL) {
			childCount(tree->left, ++count);
		}
		else {
			int left = childCount(tree->left, 0);
			int right = childCount(tree->right, 0);

			if (left > right) return count + left;
			else return count + right;
		}
	}
}

void Tree::deleteSubTree(Tree* tree){
	int left = childCount(tree->left, 0);
	int right = childCount(tree->right, 0);

	cout << "left " << left << endl;
	cout << "right " << right << endl;

	if (abs(left - right) != 2 && ( left != 0 && right != 0)) {
		cout << "Left" << endl;
		deleteSubTree(tree->left);

		cout << "Right" << endl;
		deleteSubTree(tree->right);
	}
	else if (abs(left - right) == 2) {
		free(tree);
	}
	
}

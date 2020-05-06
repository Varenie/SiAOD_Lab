#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace std;

struct Tree
{
    Tree* left;
    Tree* right;
    int value;
};

void addNode(int n, Tree** t)
{
    if (!(*t))
    {
        (*t) = new Tree;
        (*t)->value = n;
        (*t)->left = (*t)->right = nullptr;
        return;
    }
    if (n > (*t)->value)
        addNode(n, &(*t)->left);
    else
        addNode(n, &(*t)->right);
}

void showTree(Tree* tree, int count) {
    if (tree == NULL) return;
    else {
        showTree(tree->left, ++count);
        for (int i = 0; i < count; i++) {
            cout << "||";
        }
        cout << tree->value << endl;
    }
    showTree(tree->right, ++count);
}

int childCount(Tree* tree, int count) {
    if (tree == NULL) return count;
    if (tree->left == NULL) {
        if (tree->right == NULL) {
            return ++count;
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

Tree* deleteSubTree(Tree** t) {
    if ((*t) == NULL)
        return (*t);

    int left = childCount((*t)->left, 0);
    int right = childCount((*t)->right, 0);

    if (abs(left - right) == 2) {

        Tree* tmp;
        if ((*t)->right == NULL)
            tmp = (*t)->left;
        else {

            Tree* ptr = (*t)->right;
            if (ptr->left == NULL) {
                ptr->left = (*t)->left;
                tmp = ptr;
            }
            else {

                Tree* pmin = ptr->left;
                while (pmin->left != NULL) {
                    ptr = pmin;
                    pmin = ptr->left;
                }
                ptr->left = pmin->right;
                pmin->left = (*t)->left;
                pmin->right = (*t)->right;
                tmp = pmin;
            }
        }

        delete (*t);
        return tmp;
    }
    else
        (*t)->left = deleteSubTree(&(*t)->left);
        (*t)->right = deleteSubTree(&(*t)->right);
    return (*t);
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Tree *tree = NULL;
    int v;
    bool check = true;

    while (check) {
        cout << "1-Автоматиески создать дерево на 10 элементов из случайных чисел\n2-Задать размер и значения дерева\n";
        cin >> v;

        switch (v)
        {
        case 1:
            srand(time(NULL));

            for (int i = 0; i < 10; i++) {
                int a = rand() % 100 + 1;
                addNode(a, &tree);
            }

            cout << "Полученный результат:\n";
            showTree(tree, 0);
            cout << endl;

            cout << "Перестроенное дерево" << endl;
            deleteSubTree(&tree);
            showTree(tree, 0);


            check = false;
            break;
        case 2:
            cout << "Введите количество элементов: ";
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "Введите значение элемента: ";
                int a;
                cin >> a;

                addNode(a, &tree);
            }

            cout << "Полученный результат:\n";
            showTree(tree, 0);
            cout << endl;

            cout << "Перестроенное дерево" << endl;
            deleteSubTree(&tree);
            showTree(tree, 0);

            check = false;
            break;
        default:
            cout << "Неправильный ввод, попробуйте снова" << endl;
            break;
        }
    }
}
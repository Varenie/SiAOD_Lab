#include <conio.h>
#include <iostream>
#include "Tree.h"
#include <Windows.h>
#include <ctime>

using namespace std;

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
				(*tree).addNode(a, &tree);
			}
			
			cout << "Полученный результат:\n";
			(*tree).showTree(tree, 0);

			(*tree).deleteSubTree(tree);
			(*tree).showTree(tree, 0);


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

				(*tree).addNode(a, &tree);
			}

			cout << "Полученный результат:\n";
			(*tree).showTree(tree, 0);

			check = false;
			break;
		default:
			cout << "Неправильный ввод, попробуйте снова" << endl;
			break;
		}
	}
}
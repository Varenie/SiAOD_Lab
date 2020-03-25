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
		cout << "1-������������ ������� ������ �� 10 ��������� �� ��������� �����\n2-������ ������ � �������� ������\n";
		cin >> v;

		switch (v)
		{
		case 1:
			srand(time(NULL));

			for (int i = 0; i < 10; i++) {
				int a = rand() % 100 + 1;
				(*tree).addNode(a, &tree);
			}
			
			cout << "���������� ���������:\n";
			(*tree).showTree(tree, 0);

			(*tree).deleteSubTree(tree);
			(*tree).showTree(tree, 0);


			check = false;
			break;
		case 2:
			cout << "������� ���������� ���������: ";
			int n;
			cin >> n;

			for (int i = 0; i < n; i++) {
				cout << "������� �������� ��������: ";
				int a;
				cin >> a;

				(*tree).addNode(a, &tree);
			}

			cout << "���������� ���������:\n";
			(*tree).showTree(tree, 0);

			check = false;
			break;
		default:
			cout << "������������ ����, ���������� �����" << endl;
			break;
		}
	}
}
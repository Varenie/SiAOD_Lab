#include <iostream>
#include <Windows.h>

using namespace std;

int n, num;
int infinity = 99999;

int matrix[15][15];

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введите колическтво узлов: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Введите расстояние от " << i + 1 << " до " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << " X" << i + 1;
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << " X" << i + 1;
        for (int j = 0; j < n; j++) {
            cout << " " << matrix[i][j];
            matrix[j][i] = matrix[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = infinity;
            }
        }
    }

    cout << endl;
    int MIN;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                MIN = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    cout << "Главная медиана графа: " << MIN << endl;
    return 0;
}
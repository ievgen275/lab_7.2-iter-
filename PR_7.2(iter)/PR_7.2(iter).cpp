// Lab_7_2_1.cpp
// < Катрич Євген >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 6

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** a, const int n, const int k, const int Low, const int High);
void Print(int** a, const int n, const int k);
void SearchMinEven(int** a, const int n, const int k, int& minEven);

int main()
{
	srand((unsigned)time(NULL));

	int Low = 7;
	int High = 65;
	int n, k; // n - row k - col

	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];

	Create(a, n, k, Low, High);
	Print(a, n, k);

	int minEven;
	SearchMinEven(a, n, k, minEven);

	cout << "min value = " << minEven << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;

}

void Create(int** a, const int n, const int k, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n, const int k)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void SearchMinEven(int** a, const int n, const int k, int& minEven)
{
	minEven = INT_MAX;

	for (int i = 0; i < n; i++) {
		int maxElemRow = a[i][0];
		for (int j = 0; j < k; j++)
		{
			if (a[i][j] > maxElemRow) {
				maxElemRow = a[i][j];
			}
		}
		if (maxElemRow < minEven) {
			minEven = maxElemRow;
		}
	}
}
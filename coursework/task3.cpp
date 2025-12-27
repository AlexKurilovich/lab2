#include "task3.h"
#include <Windows.h>

void print_matrix(int a[MAX_SIZE][MAX_SIZE], int n, bool clear) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(*(a + i) + j) << "\t";
		}
		cout << endl;
	}
	if (clear) {
		Sleep(100);
		system("cls");
	}
}

void fill_rand(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(a + i) + j) = rand() % 100;
		}
	}
}

void simple_fill(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(a + i) + j) = rand() % 100;
			cout << *(*(a + i) + j) << "\t";
			Sleep(100);
		}
		cout << endl;
	}
}

void fill_zero(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(a + i) + j) = 0;
		}
	}
}

void fill_spiral(int a[MAX_SIZE][MAX_SIZE], int n) {

	int top = 0;
	int bottom = n - 1;
	int left = 0;
	int right = n - 1;

	while (top <= bottom && left <= right)
	{
		for (int i = left; i <= right; i++)
		{
			*(*(a + top) + i) = rand() % 100;
			print_matrix(a, n);
		}
		top++;

		for (int i = top; i <= bottom; i++)
		{
			*(*(a + i) + right) = rand() % 100;
			print_matrix(a, n);
		}
		right--;

		for (int i = right; i >= left; i--)
		{
			*(*(a + bottom) + i) = rand() % 100;
			print_matrix(a, n);
		}
		bottom--;

		for (int i = bottom; i >= top; i--)
		{
			*(*(a + i) + left) = rand() % 100;
			print_matrix(a, n);
		}
		left++;
	}
}

void fill_snake(int a[MAX_SIZE][MAX_SIZE], int n) {
	int row = 0;
	int col = 0;
	int counter = 0;

	while (counter < n * n)
	{
		*(*(a + row) + col) = rand() % 100;
		counter++;
		print_matrix(a, n);

		if (col % 2 == 0) {
			if (row == n - 1) {
				col++;
			}
			else {
				row++;
			}
		}
		else {
			if (row == 0) {
				col++;
			}
			else {
				row--;
			}
		}
	}
}

void swap_a(int a[MAX_SIZE][MAX_SIZE], int n) {
	int temp[MAX_SIZE / 2][MAX_SIZE / 2];

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			*(*(temp + i) + j) = *(*(a + i) + j);
		}
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			*(*(a + i) + j) = *(*(a + i + n / 2) + j);
		}
	}

	for (int i = n / 2; i < n; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			*(*(a + i) + j) = *(*(a + i) + j + n / 2);
		}
	}

	for (int i = n / 2; i < n; i++)
	{
		for (int j = n / 2; j < n; j++)
		{
			*(*(a + i) + j) = *(*(a + i - n / 2) + j);
		}
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = n / 2; j < n; j++)
		{
			*(*(a + i) + j) = *(*(temp + i) + j - n / 2);
		}
	}
}

void swap_b(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			int temp = *(*(a + i) + j);
			*(*(a + i) + j) = *(*(a + n / 2 + i) + n / 2 + j);
			*(*(a + n / 2 + i) + n / 2 + j) = temp;
		}
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = n / 2; j < n; j++)
		{
			int temp = *(*(a + i) + j);
			*(*(a + i) + j) = *(*(a + n / 2 + i) + j - n / 2);
			*(*(a + n / 2 + i) + j - n / 2) = temp;
		}
	}
}

void swap_c(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = *(*(a + i) + j);
			*(*(a + i) + j) = *(*(a + n / 2 + i) + j);
			*(*(a + n / 2 + i) + j) = temp;
		}
	}
}

void swap_d(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			int temp = *(*(a + i) + j);
			*(*(a + i) + j) = *(*(a + i) + j + n / 2);
			*(*(a + i) + j + n / 2) = temp;
		}
	}
}

void copy_matrix(int a[MAX_SIZE][MAX_SIZE], int d[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(d + i) + j) = *(*(a + i) + j);
		}
	}
}

void insert_sort(int* a, int n) {
	for (int* cur = a + 1; cur < a + n; cur++)
	{
		int t = *cur;
		int* pred = cur - 1;
		while (pred >= a && *pred > t)
		{
			*(pred + 1) = *pred;
			pred--;
		}
		*(pred + 1) = t;
	}
}

void sort_matrix(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n; i++)
	{
		insert_sort(*(a + i), n);
	}
}

void add_number(int a[MAX_SIZE][MAX_SIZE], int n, int number) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(a + i) + j) += number;
		}
	}
}

void transpose(int a[MAX_SIZE][MAX_SIZE], int copy_a[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int temp = *(*(a + i) + j);
			*(*(a + i) + j) = *(*(a + j) + i);
			*(*(a + j) + i) = temp;
			cout << "Source matrix" << endl;
			print_matrix(copy_a, n, false);
			cout << endl;
			cout << "Transpose matrix" << endl;
			print_matrix(a, n);
		}
	}

	cout << "Source matrix" << endl;
	print_matrix(copy_a, n, false);
	cout << endl;
	cout << "Transpose matrix" << endl;
	print_matrix(a, n, false);
}

void task3()
{
	setlocale(LC_ALL, "rus");

	int a[MAX_SIZE][MAX_SIZE];
	int b[MAX_SIZE][MAX_SIZE];
	int c[MAX_SIZE][MAX_SIZE];

	int n;
	cout << "¬ведите размер матрицы 6, 8 или 10: ";
	while (true)
	{
		cin >> n;
		if (n == 6 || n == 8 || n == 10) {
			break;
		}
		else {
			cout << "¬ведите правильный размер: ";
		}
	}

	fill_zero(a, n);
	simple_fill(a, n);

	system("cls");

	fill_zero(b, n);
	fill_spiral(b, n);

	fill_zero(c, n);
	fill_snake(c, n);

	print_matrix(a, n, false);

	int d[MAX_SIZE][MAX_SIZE];

	copy_matrix(a, d, n);
	cout << "\nSwap A" << endl;
	swap_a(d, n);
	print_matrix(d, n, false);

	copy_matrix(a, d, n);
	cout << "\nSwap B" << endl;
	swap_b(d, n);
	print_matrix(d, n, false);

	copy_matrix(a, d, n);
	cout << "\nSwap C" << endl;
	swap_c(d, n);
	print_matrix(d, n, false);

	copy_matrix(a, d, n);
	cout << "\nSwap D" << endl;
	swap_d(d, n);
	print_matrix(d, n, false);

	cout << "Sort matrix" << endl;
	copy_matrix(a, d, n);

	sort_matrix(d, n);
	print_matrix(d, n, false);

	cout << "Input number: ";
	int number;
	cin >> number;

	add_number(a, n, number);
	print_matrix(a, n, false);

	system("pause");

	int e[MAX_SIZE][MAX_SIZE];
	int copy_e[MAX_SIZE][MAX_SIZE];
	fill_rand(e, n);
	copy_matrix(e, copy_e, n);
	transpose(e, copy_e, n);

	system("pause");
}
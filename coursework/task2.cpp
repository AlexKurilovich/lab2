#include "task2.h"

void fill_array(int a[]) {
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 199 - 99;
	}
}

void print_array(int a[]) {
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void bubble_sort(int a[]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

void select_sort(int a[]) {
	for (int i = 0; i < N; i++)
	{
		int min = a[i];
		int imin = i;
		for (int j = i + 1; j < N; j++)
		{
			if (a[j] < min) {
				min = a[j];
				imin = j;
			}
		}
		if (i != imin) {
			int t = a[i];
			a[i] = a[imin];
			a[imin] = t;
		}
	}
}

void insert_sort(int a[]) {
	for (int i = 1; i < N; i++) {
		int t = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > t) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;

	}

}

void sheiker_sort(int a[]) {
	int left = 0, right = N - 1;
	while (left <= right) {

		for (int i = left; i < right; ++i) {
			if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
		}
		--right;


		for (int i = right; i > left; --i) {
			if (a[i] < a[i - 1]) swap(a[i], a[i - 1]);
		}
		++left;
	}
}

void quick_sort(int a[], int left, int right) {
	if (left >= right) {
		return;

	}
	int pivot = a[left + (right - left) / 2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (a[i] < pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}

		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (left < j) {
		quick_sort(a, left, j);
	}
	if (right > i) {
		quick_sort(a, i, right);
	}




}

void copy_array(int a[], int b[]) {
	for (int i = 0; i < N; i++)
	{
		b[i] = a[i];
	}
}

int find_max(int a[]) {
	int max = a[0];
	for (int i = 1; i < N; i++)
	{
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

int find_min(int a[]) {
	int min = a[0];
	for (int i = 1; i < N; i++)
	{
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

int find_max_sort(int a[]) {
	return a[N - 1];
}

int find_min_sort(int a[]) {
	return a[0];
}

void show_indexes(int a[], int avg) {
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == avg) {
			cout << i << " ";
			count++;
		}
	}
	cout << endl;
	cout << "Кол-во эл-тов равных среднему = " << count << endl;
}

int count_less_k(int a[], int k) {
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] < k) {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

int count_more_k(int a[], int k) {
	int count = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (a[i] > k) {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

bool bin_search(int a[], int k) {
	int left = 0;
	int right = N - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (k > a[mid]) {
			left = mid + 1;
		}
		else if (k < a[mid]) {
			right = mid - 1;
		}
		else {
			return true;
		}
	}
	return false;

}

bool linear_search(int a[], int k) {
	for (int i = 0; i < N; i++)
	{
		if (a[i] == k) {
			return true;
		}
	}
	return false;
}

void task2()
{
	srand(time(0));

	int a[N];
	int b[N];

	while (true)
	{
		cout << "1.Заполнить массив " << endl;

		cout << "2.Вывести массив " << endl;

		cout << "3.Сортировка массива " << endl;

		cout << "4.Поиск минимального и максимального эл-тов " << endl;

		cout << "5.Среднее значение максимального и минимального значения " << endl;

		cout << "6.Количество элементов в отсортированном массиве, которые меньше числа a " << endl;

		cout << "7.Количество элементов в отсортированном массиве, которые больше числа a " << endl;

		cout << "8.Поиск элемента " << endl;

		cout << "9.Поменять местами элементы " << endl;

		cout << "0.Выход " << endl;

		int choice;
		cin >> choice;

		if (choice == 0) {
			break;
		}

		switch (choice)
		{
		case 1:
			fill_array(a);
			copy_array(a, b);
			break;
		case 2:
			print_array(a);
			break;
		case 3:
		{
			cout << "Пузырьковая сортировка" << endl;
			auto start = chrono::high_resolution_clock::now();
			bubble_sort(a);
			auto end = chrono::high_resolution_clock::now();
			auto dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Время " << dmsf.count() << " наносек" << endl;
			print_array(a);
			copy_array(b, a);

			cout << "Сортировка выбором" << endl;
			start = chrono::high_resolution_clock::now();
			select_sort(a);
			end = chrono::high_resolution_clock::now();
			dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Время " << dmsf.count() << " наносек" << endl;
			print_array(a);
			copy_array(b, a);

			cout << "Сортировка вставками" << endl;
			start = chrono::high_resolution_clock::now();
			insert_sort(a);
			end = chrono::high_resolution_clock::now();
			dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Время " << dmsf.count() << " наносек" << endl;
			print_array(a);
			copy_array(b, a);

			cout << "Шейкерная сортировка" << endl;
			start = chrono::high_resolution_clock::now();
			sheiker_sort(a);
			end = chrono::high_resolution_clock::now();
			dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Время " << dmsf.count() << " наносек" << endl;
			print_array(a);
			copy_array(b, a);

			cout << "Быстрая сортировка" << endl;
			start = chrono::high_resolution_clock::now();
			quick_sort(a, 0, N - 1);
			end = chrono::high_resolution_clock::now();
			dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Время " << dmsf.count() << " наносек" << endl;
			print_array(a);
			copy_array(b, a);
			break;
		}
		case 4: {
			cout << "Поиск макс и мин в неотсортированном массиве" << endl;

			auto start = chrono::high_resolution_clock::now();
			int max = find_max(a);
			auto end = chrono::high_resolution_clock::now();
			auto dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Макс = " << max << endl;
			cout << "Время " << dmsf.count() << " наносек" << endl;

			start = chrono::high_resolution_clock::now();
			int min = find_min(a);
			end = chrono::high_resolution_clock::now();
			dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Мин = " << min << endl;
			cout << "Время " << dmsf.count() << " наносек" << endl;

			quick_sort(a, 0, N - 1);
			cout << "Поиск макс и мин в отсортированном массиве" << endl;

			start = chrono::high_resolution_clock::now();
			max = find_max_sort(a);
			end = chrono::high_resolution_clock::now();
			dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Макс = " << max << endl;
			cout << "Время " << dmsf.count() << " наносек" << endl;

			start = chrono::high_resolution_clock::now();
			min = find_min_sort(a);
			end = chrono::high_resolution_clock::now();
			dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Мин = " << min << endl;
			cout << "Время " << dmsf.count() << " наносек" << endl;
			break;
		}
		case 5: {
			cout << "Поиск среднего в неотсортированном массиве" << endl;

			auto start = chrono::high_resolution_clock::now();
			int max = find_max(a);
			int min = find_min(a);
			int avg = (max + min) / 2;
			cout << "Среднее = " << avg << endl;
			show_indexes(a, avg);
			auto end = chrono::high_resolution_clock::now();
			auto dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Время " << dmsf.count() << " наносек" << endl;

			quick_sort(a, 0, N - 1);
			cout << "Поиск среднего в отсортированном массиве" << endl;

			start = chrono::high_resolution_clock::now();
			max = find_max_sort(a);
			min = find_min_sort(a);
			avg = (max + min) / 2;
			cout << "Среднее = " << avg << endl;
			show_indexes(a, avg);
			end = chrono::high_resolution_clock::now();
			dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
			cout << "Время " << dmsf.count() << " наносек" << endl;
			break;
		}
		case 6: {
			quick_sort(a, 0, N - 1);

			int k;
			cout << "Введите число: ";
			cin >> k;
			int count = count_less_k(a, k);
			cout << "Кол-во = " << count << endl;
			break;
		}
		case 7: {
			quick_sort(a, 0, N - 1);

			int k;
			cout << "Введите число: ";
			cin >> k;
			int count = count_more_k(a, k);
			cout << "Кол-во = " << count << endl;
			break;
		}
		case 8: {
			quick_sort(a, 0, N - 1);
			int k;
			cout << "Введите число: ";
			cin >> k;

			cout << "Бинарный поиск" << endl;
			auto start = chrono::high_resolution_clock::now();
			bool check = bin_search(a, k);
			auto end = chrono::high_resolution_clock::now();
			auto dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);

			if (check) {
				cout << "Есть такой элемент" << endl;
			}
			else {
				cout << "Нет такого элемента" << endl;
			}
			cout << "Время " << dmsf.count() << " наносек" << endl;

			cout << "Поиск перебором" << endl;
			start = chrono::high_resolution_clock::now();
			check = linear_search(a, k);
			end = chrono::high_resolution_clock::now();
			dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);

			if (check) {
				cout << "Есть такой элемент" << endl;
			}
			else {
				cout << "Нет такого элемента" << endl;
			}
			cout << "Время " << dmsf.count() << " наносек" << endl;
			break;
		}
		case 9: {
			int ind1, ind2;
			cout << "Введите первый индекс: ";
			cin >> ind1;

			cout << "Введите второй индекс: ";
			cin >> ind2;

			if (ind1 >= 0 && ind1 < N && ind2 >= 0 && ind2 < N) {
				auto start = chrono::high_resolution_clock::now();
				int temp = a[ind1];
				a[ind1] = a[ind2];
				a[ind2] = temp;
				auto end = chrono::high_resolution_clock::now();
				auto dmsf = chrono::duration_cast<chrono::duration<double, nano>>(end - start);
				cout << "Время " << dmsf.count() << " наносек" << endl;
				print_array(a);
			}
			else {
				cout << "Некорректные индексы" << endl;
			}
			break;
		}
		}
	}
}
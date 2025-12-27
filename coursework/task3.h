#ifndef TASK3_H
#define TASK3_H

#include <iostream>

using namespace std;
#define MAX_SIZE 10

void print_matrix(int a[MAX_SIZE][MAX_SIZE], int n, bool clear = true);
void fill_rand(int a[MAX_SIZE][MAX_SIZE], int n);
void simple_fill(int a[MAX_SIZE][MAX_SIZE], int n);
void fill_zero(int a[MAX_SIZE][MAX_SIZE], int n);
void fill_spiral(int a[MAX_SIZE][MAX_SIZE], int n);
void fill_snake(int a[MAX_SIZE][MAX_SIZE], int n);
void swap_a(int a[MAX_SIZE][MAX_SIZE], int n);
void swap_b(int a[MAX_SIZE][MAX_SIZE], int n);
void swap_c(int a[MAX_SIZE][MAX_SIZE], int n);
void swap_d(int a[MAX_SIZE][MAX_SIZE], int n);
void copy_matrix(int a[MAX_SIZE][MAX_SIZE], int d[MAX_SIZE][MAX_SIZE], int n);
void insert_sort(int* a, int n);
void sort_matrix(int a[MAX_SIZE][MAX_SIZE], int n);
void add_number(int a[MAX_SIZE][MAX_SIZE], int n, int number);
void transpose(int a[MAX_SIZE][MAX_SIZE], int copy_a[MAX_SIZE][MAX_SIZE], int n);
void task3();

#endif // !1
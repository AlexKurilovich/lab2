#ifndef TASK2_H
#define TASK2_H

#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
#define N 100

void fill_array(int a[]);
void print_array(int a[]);
void bubble_sort(int a[]);
void select_sort(int a[]);
void insert_sort(int a[]);
void sheiker_sort(int a[]);
void quick_sort(int a[], int left, int right);
void copy_array(int a[], int b[]);
int find_max(int a[]);
int find_min(int a[]);
int find_max_sort(int a[]);
int find_min_sort(int a[]);
void show_indexes(int a[], int avg);
int count_less_k(int a[], int k);
int count_more_k(int a[], int k);
bool bin_search(int a[], int k);
bool linear_search(int a[], int k);
void task2();

#endif
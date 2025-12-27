#ifndef TASK4_H
#define TASK4_H

#include <iostream>
#include <fstream>
using namespace std;

void remove_extra_spaces(char* text);
bool is_punctuation_or_space(char c);
void remove_extra_punct(char* text);
void text_to_lower(char* text);
void sort_words(char words[50][11], int count_word);
void additional_task(char* text);
int est(char pattern[], int M, char c);
int boyer_moore(char arr[], char pattern[], int& n, int& M);
void task4();

#endif
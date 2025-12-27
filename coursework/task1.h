#ifndef TASK1_H
#define TASK1_H

#include <iostream>
#include <cstdint>
#include <iomanip>                                                                                                  
using namespace std;


bool problem();
void PrintBinInt(int num); // Задание 2,3
void PrintBinFloat(float num); // Задание 2,3
void PrintBinDouble(double num); // задание 4
void ReplaceBitsDouble();
void ReplaceBitsFloat();
void ReplaceBitsInt(int num);
void ChangeSignInt(int num);
void ChangeSignFloat(float num);
void ChangeSignDouble(double num);
int MenuForReplace();
void task1();

#endif
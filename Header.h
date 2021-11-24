#pragma once
#include <algorithm>
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

void SelectionSort(int n, int* a, ll& compare_count);
void CountingSort(int n, int* a, ll& compare_count);
void RadixSort(int n, int* a, ll& compare_count);

void execute();
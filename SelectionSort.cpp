#include "Header.h"

void Swap(int& a, int& b, ll& compare_count) {
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(int n, int* a, ll& compare_count) {
	int minTemp;
	for (int i = 0; i < n; ++i, ++compare_count) {
		minTemp = i;
		for (int j = i + 1; j < n; ++j, ++compare_count) if ((++compare_count) && (a[minTemp] > a[j])) {
			minTemp = j;
		}
		Swap(a[i], a[minTemp], compare_count);
	}
}
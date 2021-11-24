#include "Header.h"

void CountingSort(int n, int* a, ll& compare_count) {
	// Assuming that max and min value of set is not n - 1 and 0
	int maxValue = a[0], minValue = a[0], rangeValue;
	for (int i = 0; i < n; ++i, ++compare_count) {
		maxValue = maxValue < a[i] ? a[i] : maxValue;
		minValue = minValue > a[i] ? a[i] : minValue;
	}
	rangeValue = maxValue - minValue + 1;
	int* count = new int[rangeValue], * ans = new int[n];
	for (int i = 0; i < rangeValue; ++i, ++compare_count) count[i] = 0;
	for (int i = 0; i < n; ++i, ++compare_count) ans[i] = 0;

	for (int i = 0; i < n; ++i, ++compare_count) count[a[i] - minValue]++; // Count the appearance of the numbers

	for (int i = 1; i < rangeValue; ++i, ++compare_count) count[i] += count[i - 1]; // Generate the counting (?) array

	for (int i = n - 1; i >= 0; --i, ++compare_count) { // Generate the sorted array from the counting (?) array
		ans[count[a[i] - minValue] - 1] = a[i];
		count[a[i] - minValue]--;
	}

	for (int i = n - 1; i >= 0; --i, ++compare_count) a[i] = ans[i]; // And push it to the first array
}
#include "Header.h"

void CountingSort(int n, int* a, ll& compare_count) {
	// Assuming that max and min value of set is not n - 1 and 0
	int maxValue = a[0], minValue = a[0], rangeValue;
	for (int i = 0; (++compare_count) && (i < n); ++i) {
		maxValue = (++compare_count) && (maxValue < a[i]) ? a[i] : maxValue;
		minValue = (++compare_count) && (minValue > a[i]) ? a[i] : minValue;
	}
	rangeValue = maxValue - minValue + 1;
	int* count = new int[rangeValue], * ans = new int[n];
	for (int i = 0; (++compare_count) && (i < rangeValue); ++i) count[i] = 0;
	for (int i = 0; (++compare_count) && (i < n); ++i) ans[i] = 0;

	for (int i = 0; (++compare_count) && (i < n); ++i) count[a[i] - minValue]++; // Count the appearance of the numbers

	for (int i = 1; (++compare_count) && (i < rangeValue); ++i) count[i] += count[i - 1]; // Generate the counting (?) array

	for (int i = n - 1; (++compare_count) && (i >= 0); --i) { // Generate the sorted array from the counting (?) array
		ans[count[a[i] - minValue] - 1] = a[i];
		count[a[i] - minValue]--;
	}

	for (int i = n - 1; (++compare_count) && (i >= 0); --i) a[i] = ans[i]; // And push it to the first array
}
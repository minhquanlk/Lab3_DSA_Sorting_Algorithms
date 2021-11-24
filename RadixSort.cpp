#include "Header.h"

// If array have a minus value, we can consider it a digit and do the same

void CountingDigit(int n, int* a, int digit, ll& compare_count) { // Decrease pointer array create and delete step
	int* ans = new int[n], count[10];
	for (int i = 0; i < n; ++i, ++compare_count) ans[i] = 0;
	for (int i = 0; i < 10; ++i, ++compare_count) count[i] = 0;

	for (int i = 0; i < n; ++i, ++compare_count) count[a[i] / digit % 10]++;
	for (int i = 1; i < 10; ++i, ++compare_count) count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; --i, ++compare_count) {
		ans[count[a[i] / digit % 10] - 1] = a[i];
		count[a[i] / digit % 10]--;
	}

	for (int j = 0; j < n; ++j, ++compare_count) a[j] = ans[j];
}

void CountingSign(int n, int* a, ll& compare_count) {
	int* ans = new int[n], count[2];
	for (int i = 0; i < n; ++i, ++compare_count) ans[i] = 0;
	count[0] = 0;
	count[1] = 0;

	for (int i = 0; i < n; ++i, ++compare_count) count[a[i] < 0 ? 0 : 1]++;
	count[1] += count[0];
	for (int i = n - 1; i >= 0; --i, ++compare_count) {
		ans[count[a[i] < 0 ? 0 : 1] - 1] = a[i];
		count[a[i] < 0 ? 0 : 1]--;
	}

	for (int i = 0; i < n; ++i, ++compare_count) a[i] = ans[i];
}

void RadixSort(int n, int* a, ll& compare_count) {
	int max = a[0];
	for (int i = 0; i < n; ++i) max = max < a[i] ? a[i] : max; // Cannot find max function
	int k = int(log10(max)); // Digit's numbers of max

	for (int i = 1; int(log10(i)) <= k; i *= 10, ++compare_count) {
		CountingDigit(n, a, i, compare_count);
	}
	CountingSign(n, a, compare_count);
}

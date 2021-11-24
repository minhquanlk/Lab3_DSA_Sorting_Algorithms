#include "Header.h"

void RadixSort(int n, int* a, ll& compare_count) {
	int* ans = new int[n], count[10];

	int max = a[0];
	for (int i = 0; (++compare_count) && (i < n); ++i) max = (++compare_count) && (max < a[i]) ? a[i] : max; // Cannot find max function
	int k = int(log10(max)); // Digit's number of max

	for (int i = 1; (++compare_count) && (int(log10(i)) <= k); i *= 10) {
		for (int j = 0; (++compare_count) && (j < 10); ++j) count[j] = 0;

		for (int j = 0; (++compare_count) && (j < n); ++j) count[a[j] / i % 10]++;
		for (int j = 1; (++compare_count) && (j < 10); ++j) count[j] += count[j - 1];
		for (int j = n - 1; (++compare_count) && (j >= 0); --j) {
			ans[count[a[j] / i % 10] - 1] = a[j];
			count[a[j] / i % 10]--;
		}

		for (int j = 0; (++compare_count) && (j < n); ++j) a[j] = ans[j];
	}
}

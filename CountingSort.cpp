#include "Header.h"

void CountingSort(int n, int* a, ll& compare_count) {
	int* count = new int[n], * ans = new int[n];
	for (int i = 0; (++compare_count) && (i < n); ++i) count[i] = 0; // Gán giá trị của mảng động về 0

	for (int i = 0; (++compare_count) && (i < n); ++i) count[a[i]]++; // Đếm số lần xuất hiện của các phần tử

	for (int i = 1; (++compare_count) && (i < n); ++i) count[i] += count[i - 1]; // Làm mảng giới hạn trên (tổng các phần tử trước nó) từ mảng đếm

	for (int i = n - 1; (++compare_count) && (i >= 0); --i) { // Làm mảng sắp xếp từ mảng giới hạn trên
		ans[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = n - 1; (++compare_count) && (i >= 0); --i) a[i] = ans[i]; // Gán lại cho mảng chính
}
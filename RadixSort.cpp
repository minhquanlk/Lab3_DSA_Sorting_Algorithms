#include "Header.h"

void RadixSort(int n, int* a, ll& compare_count) {
	int* ans = new int[n], count[10];

	int max = a[0];
	for (int i = 0; (++compare_count) && (i < n); ++i) if ((++compare_count) && (max < a[i])) { // Tìm phần tử lớn nhất của mảng
		max = a[i];
	}
	int k = int(log10(max)); // Số chữ số của phần tử lớn nhất

	for (int i = 1; (++compare_count) && (int(log10(i)) <= k); i *= 10) { // Sắp xếp dựa theo chữ số, bắt đầu từ chữ số phải cùng của các phần tử
		for (int j = 0; (++compare_count) && (j < 10); ++j) count[j] = 0; // Gán lại giá trị mảng count

		for (int j = 0; (++compare_count) && (j < n); ++j) count[a[j] / i % 10]++; // Đếm số lần xuất hiện của các phần tử có chữ số tương ứng
		for (int j = 1; (++compare_count) && (j < 10); ++j) count[j] += count[j - 1]; // Làm mảng giới hạn trên (tổng các phần tử trước nó) từ mảng đếm
		for (int j = n - 1; (++compare_count) && (j >= 0); --j) { // Làm mảng sắp xếp từ mảng giới hạn trên
			ans[count[a[j] / i % 10] - 1] = a[j];
			count[a[j] / i % 10]--;
		}

		for (int j = 0; (++compare_count) && (j < n); ++j) a[j] = ans[j]; // Gán lại cho mảng chính
	}
}

#include "DataGenerator.h"

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void quickSort(int* arr, int left, int right, unsigned long long& countcmp) {
      int i = left, j = right;
      int pivot = arr[(left + right) / 2];
      while (++countcmp && i <= j) {
            while (++countcmp && arr[i] < pivot)
                  i++;
            while (++countcmp && arr[j] > pivot)
                  j--;
            if (++countcmp && i <= j) {
                  swap(arr[i], arr[j]);
                  i++;
                  j--;
            }
      };

      if (++countcmp && left < j)
            quickSort(arr, left, j, countcmp);
      if (++countcmp && i < right)
            quickSort(arr, i, right, countcmp);
}

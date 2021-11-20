#include "Header.h"
// ghép 2 phần con sau khi tách
void merge(int* arr, int left, int midIndex, int right, unsigned long long& countcmp)
{
	int nArr1 = midIndex - left + 1; //Số phần tử của mảng con 1
	int nArr2 = right - midIndex; //Số phần tử của mảng con 2
	int* Left = new int[nArr1];
	int* Right = new int[nArr2];
	//Lưu 2 phần con vào 2 mảng phụ
	for (int i = 0;++countcmp && i < nArr1; i++)
		Left[i] = arr[left + i];
	for (int j = 0; ++countcmp && j < nArr2; j++)
		Right[j] = arr[midIndex + 1 + j];
	//Tiến hành ghép, chọn phần tử nhỏ để đưa vào mảng chính
	int i = 0, j = 0, k = left;
	while ((++countcmp && i < nArr1) && (++countcmp && j < nArr2))
	{
		if (++countcmp && Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}
	//Nếu mảng 1 còn dư
	while (++countcmp && i < nArr1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}
	//Nếu mảng 2 còn dư
	while (++countcmp && j < nArr2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}

}
// Tách đôi dãy số thành 2 phần và tiếp tục tách 2 phần nhỏ của nó đến khi còn 1 phần tử
void mergeSort(int* arr, int left, int right, unsigned long long& countcmp)
{
	if (++countcmp && left < right) // Khi midIndex trùng với left hoặc right thì dừng (1 phần tử)
	{
		int midIndex = (left + right) / 2; // Vị trí chặt đôi
		mergeSort(arr, left, midIndex, countcmp);	
		mergeSort(arr, midIndex + 1, right, countcmp);
		merge(arr, left, midIndex, right, countcmp);	// Ghép 2 mảng con
	}
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << A[i] << " ";

}

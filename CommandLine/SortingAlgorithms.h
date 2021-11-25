#pragma once
#include "DataGenerator.h"

//------------------------Bubble Sort---------------------------//
void bubbleSort(int arr[], int n, unsigned long long& countcmp)
{
    int i, j;
    bool Swap = false;
    for (i = 0; ++countcmp && i < n - 1; i++) {
        Swap = false;
        for (j = 0; ++countcmp && j < n - i - 1; j++) {
            if (++countcmp && arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                Swap = true; // Đổi chân trị biến Swap vì có swap
            }
        }
        // Nếu Swap không thay đổi chân trị thì mảng đã sắp xếp => dừng vòng lặp
        if (++countcmp && Swap == false) {
            break;
        }
    }
}

//------------------------Insertion Sort---------------------------//
void insertionSort(int arr[], int n, unsigned long long& countcmp)
{
    int i, key, j;
    for (i = 1; ++countcmp && i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Di chuyển các phần tử có giá trị lớn hơn giá trị key về sau một vị trí so với vị trí ban đầu của nó */
        while ( ++countcmp && j >= 0 && ++countcmp && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//------------------------Selection Sort---------------------------//
void selectionSort(int arr[], int n, unsigned long long& countcmp)
{
    int i, j, min_idx;
    // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
    for (i = 0; ++countcmp && i < n-1; i++)
    {
    // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
    min_idx = i;
    for (j = i+1; ++countcmp && j < n; j++)
        if (++countcmp && arr[j] < arr[min_idx])
        min_idx = j;
  
    // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        swap(arr[min_idx], arr[i]);
    }
}

//------------------------Heap Sort---------------------------//
void heapify(int a[], int n, int i,unsigned long long &countcmp)
{
    int largest = i,l = 2 * i + 1,r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
    {
        countcmp++;
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        countcmp++;
        largest = r;
    }
    if (largest != i)
    {
        countcmp++;
        swap(a[i],a[largest]);
        heapify(a, n, largest,countcmp);
    }
}
void heapSort(int a[], int n,unsigned long long &countcmp)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        countcmp++;
        heapify(a, n, i,countcmp);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        countcmp++;
        swap(a[0],a[i]);
        heapify(a, i, 0,countcmp);
    }
}

//------------------------Merge Sort---------------------------//
void merge(int* arr, int left, int midIndex, int right, unsigned long long & countcmp)
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

//------------------------Quick Sort---------------------------//
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

//------------------------Shaker Sort---------------------------//
/* source : https://www.sanfoundry.com/cplusplus-program-perform-shaker-sort/ */
// A function implementing shaker sort.
void shakerSort(int a[], int n,unsigned long long &countcmp)
{
    int i, j, k;
    for(i = 0;++countcmp && i < n;)
    {
        // First phase for ascending highest value to the highest unsorted index.
        for(j = i+1; ++countcmp && j < n; j++)
            if(++countcmp && a[j] < a[j-1])
                swap(a[j], a[j-1]);
        // Decrementing highest index.
        n--;
        // Second phase for descending lowest value to the lowest unsorted index.
        for(k = n-1;++countcmp && k > i; k--)
            if(++countcmp && a[k] < a[k-1])
                swap(a[k], a[k-1]);
        // Incrementing lowest index.
        i++;
    }
}


//------------------------Shell Sort---------------------------//
/* source : https://www.tutorialspoint.com/cplusplus-program-to-implement-shell-sort */

void shellSort(int a[], int n, unsigned long long &countcmp)
{
    int gap, j, k;
    for(gap = n/2; ++countcmp && gap > 0; gap = gap / 2)          //initially gap = n/2,decreasing by gap /2
    {
        for(j = gap;++countcmp && j<n; j++)
        {
            for(k = j-gap;++countcmp && k>=0; k -= gap)
            {
                if(++countcmp && a[k+gap] >= a[k])
                {
                    break;
                }
                else
                {
                    swap(a[k+gap], a[k]);
                }

            }
        }
    }
}

//------------------------Radix Sort---------------------------//
void CountingDigit(int n, int* a, int digit, unsigned long long& countcmp) { // Decrease pointer array create and delete step
	int* ans = new int[n], count[10];
	for (int i = 0;++countcmp && i < n; i++) ans[i] = 0;
	for (int i = 0;++countcmp && i < 10; i++) count[i] = 0;

	for (int i = 0;++countcmp && i < n; i++) count[a[i] / digit % 10]++;
	for (int i = 1;++countcmp && i < 10; i++) count[i] += count[i - 1];
	for (int i = n - 1;++countcmp && i >= 0; --i) {
		ans[count[a[i] / digit % 10] - 1] = a[i];
		count[a[i] / digit % 10]--;
	}

	for (int j = 0;++countcmp && j < n; ++j) a[j] = ans[j];
}

void CountingSign(int n, int* a, unsigned long long& countcmp) {
	int* ans = new int[n], count[2];
	for (int i = 0;++countcmp && i < n; i++) ans[i] = 0;
	count[0] = 0;
	count[1] = 0;

	for (int i = 0;++countcmp && i < n; i++){
         count[a[i] < 0 ? 0 : 1]++; countcmp++;
    }
	count[1] += count[0];
	for (int i = n - 1; ++countcmp && i >= 0; i--) {
		ans[count[a[i] < 0 ? 0 : 1] - 1] = a[i]; countcmp++;
		count[a[i] < 0 ? 0 : 1]--; countcmp++;
	}

	for (int i = 0;++countcmp && i < n; i++) a[i] = ans[i];
}

void RadixSort(int n, int* a, unsigned long long& countcmp) {
	int max = a[0];
	for (int i = 0;++countcmp && i < n; i++){
         max = max < a[i] ? a[i] : max; countcmp++;// Cannot find max function
    }
	int k = int(log10(max)); // Digit's numbers of max

	for (int i = 1;++countcmp && int(log10(i)) <= k; i *= 10) {
		CountingDigit(n, a, i, countcmp);
	}
	CountingSign(n, a, countcmp);
}

//------------------------Flash Sort---------------------------//
void flashSort(int a[], int n, unsigned long long& countcmp)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++countcmp && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++countcmp && i < n; i++)
	{
		if (++countcmp && a[i] < minVal)
			minVal = a[i];
		if (++countcmp && a[i] > a[max])
			max = i;
	}
	if (++countcmp && a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++countcmp && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++countcmp && i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++countcmp && nmove < n - 1)
	{
		while (++countcmp && j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (++countcmp && k < 0) break;
		while (++countcmp && j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(a, n, countcmp);
}
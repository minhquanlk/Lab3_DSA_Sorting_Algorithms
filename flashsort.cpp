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

//------------------------Flash Sort---------------------------//
void flashSort(int a[], int n, unsigned long long& countcmp)
{
	int minVal = a[0];
	int max = 0;
    // Số lớp phân ra
	int m = int(0.45 * n); //Chọn 0,45 để trường hợp tốt nhất thì số lượng phần tử của các lớp là 2 hoặc 3
	int* l = new int[m];
	for (int i = 0; ++countcmp && i < m; i++)
		l[i] = 0;
    //Tìm giá phần tử nhỏ nhất và vị trí của phần tử lớn nhất trong mảng
	for (int i = 1; ++countcmp && i < n; i++)
	{
		if (++countcmp && a[i] < minVal)
			minVal = a[i];
		if (++countcmp && a[i] > a[max])
			max = i;
	}
	if (++countcmp && a[max] == minVal) //Nếu mảng chỉ có một giá trị thì ko cần sắp xếp
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal); //Giá trị phân lớp, = số lượng lớp chia cho (max - min)
    // Tiến hành đếm số lượng phần tử của mỗi lớp
	for (int i = 0; ++countcmp && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal)); //Kiểm tra phần tử a[i] thuộc lớp nào
		++l[k]; //Tăng số lượng của lớp đó lên 1 đơn vị
	}
    //Tính vị trí kết thúc của mỗi lớp (Ví dụ lớp 1 2 phần tử lớp 2 3 phần tử thì giá trị l[1] = 5)
	for (int i = 1; ++countcmp && i < m; i++)
		l[i] += l[i - 1];
    //Tiến hành đưa phần tử về đúng lớp của nó bằng cách swap lên vị trí đầu của mảng
    //Sau đó trừ số lượng phần tử của lớp chứa nó đi 1
    //Nếu có vị trí cuối trùng với vị trí cuối của lớp trước đó chứng tỏ lớp đó đã đủ phần tử
	swap(a[max], a[0]); //Kiểm tra phần tử lớn nhất trước
	int nmove = 0; //Biến đếm số lần kiểm tra
	int j = 0; //Biến kiểm tra xem đã đủ phần tử chưa
	int k = m - 1; //Biến duyệt mảng lớp
	int t = 0;
	int flash;
	while (++countcmp && nmove < n - 1)
	{
		while (++countcmp && j > l[k] - 1) //Kiểm tra xem phần tử đó đã đúng phân lớp của nó chưa
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j]; //Gán flash = phần tử xét
		if (++countcmp && k < 0) break; //Nếu mảng chỉ có 2 phần tử -> có 0 lớp thì dừng vòng lặp
		while (++countcmp && j != l[k]) // Lặp lại tới khi nào phân lớp chứa flash đầy, khi đó phải đổi vị trí flash
		{
			k = int(c1*(flash - minVal)); //Kiểm tra lớp của phần tử đầu tiên thuộc về
			int hold = a[t = --l[k]]; //Biến tạm = vị trí của lớp mà flash thuộc về
			//swap phần tử đang xét với vị trí thuộc về của nó
            a[t] = flash; 
			flash = hold; 
			++nmove; //+1 lượt kiểm tra
		}
	}
	delete[] l;
	insertionSort(a, n, countcmp);
}

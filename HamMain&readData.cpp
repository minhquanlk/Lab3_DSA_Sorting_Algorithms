char* filePath(int dataCase, int dataSize)
{
	char* path = new char[41];
	switch (dataCase)
		{
		case 0:	// ngẫu nhiên
			strcat(path, "D:/THCTDL/Lab3/DataRun/DataRandom_");
			cout << "DataRandom - Size: ";
			break;
		case 1:	// có thứ tự
			strcat(path, "D:/THCTDL/Lab3/DataRun/DataSorted_");
			cout << "DataSorted - Size: ";
			break;
		case 2:	// có thứ tự ngược
			strcat(path, "D:/THCTDL/Lab3/DataRun/DataReverse_");
			cout << "DataReverse - Size: ";
			break;
		case 3:	// gần như có thứ tự
			strcat(path, "D:/THCTDL/Lab3/DataRun/DataNearlySorted_");
			cout << "DataNearlySorted - Size: ";
			break;
		default:
			printf("Error: unknown data type!\n");
		}
	cout << dataSize;
	char size[6];
	itoa(dataSize, size, 10);
	strcat(path, size);
	strcat(path, ".csv");
	return path;
}  

int main()
{
	ifstream inputData;
	clock_t start, end;
	unsigned long long countcmp = 0;
	int n[] = {10000,30000,50000,100000,300000,500000};
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 6; j++)
		{
			countcmp = 0;
			char* filepath = filePath(i, n[j]);
			inputData.open(filepath, ios::in);
			int* arr = new int[n[j]];
			for (int k = 0; k < n[j]; k++)
			{
				inputData >> arr[k]; 
			}
			start = clock();
			quickSort(arr, 0, n[j] - 1, countcmp);  //sort algorithm
			end = clock();
			double runtime = ((double)(end - start));
			cout << endl << countcmp << " " << runtime << endl;
		}
	//printArray(arr, n);
	

	inputData.close();
	return 0;
}

string filePath(int dataCase, int dataSize)
{
    char path[51] = "";
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
    cout << dataSize << endl;
    char size[7];
    itoa(dataSize, size, 10);
    strcat(path, size);
    strcat(path, ".csv");
    return path;
}
void printArray(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
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
			string filepath = filePath(i, n[j]);
			inputData.open(filepath, ios::in);
			int* arr = new int[n[j]];
			for (int k = 0; k < n[j]; k++)
			{
				inputData >> arr[k];
			}
			//printArray(arr, n[j]);
			countcmp = 0;
			start = clock();
			flashSort(arr, n[j], countcmp);
			end = clock();
			double runtime = ((double)(end - start));
			cout << endl << countcmp << " " << runtime << endl;
			inputData.close();
		}
	//printArray(arr, n);
	return 0;
}

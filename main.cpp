int main()
{
	clock_t start, end;
	unsigned long long countcmp = 0;
	int n[] = {10000,30000,50000,100000,300000,500000};
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 6; j++)
		{
			int* arr = new int[n[j]];
			ReadData(arr, i, n[j]);
			//printArray(arr, n[j]);
			countcmp = 0;
			start = clock();
			flashSort(arr, n[j], countcmp);
			end = clock();
			double runtime = ((double)(end - start));
			cout << endl << countcmp << " " << runtime << endl << endl;
		}
	//printArray(arr, n);
	return 0;
}

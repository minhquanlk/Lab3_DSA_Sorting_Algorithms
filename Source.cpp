#include "Header.h"

void execute()
{
	ll compare_count;
	clock_t begin, end, time;
	int size[] = {10000, 30000, 50000, 100000, 300000, 500000};
	string DataOrder[] = {"DataRandom", "DataSorted", "DataReverse", "DataNearlySorted"};
	ifstream fi;
	ofstream fo("ans.txt");
	int *a, n;
	for (int k = 0; k < 3; ++k)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				cout << k << " " << i << ' ' << j << ' ';
				n = size[j];
				a = new int[n + 10];
				fi.open("./Data/" + DataOrder[i] + "_" + to_string(n) + ".csv", ios::in);

				for (int l = 0; l < n; ++l)
					fi >> a[l];
				compare_count = 0;

				if (k == 0)
				{
					fo << "Selection sort (" << n << ", " << DataOrder[i] << "): ";
					begin = clock();
					/*SelectionSort(n, a, compare_count);*/
				}
				else if (k == 1)
				{
					fo << "Counting sort (" << n << ", " << DataOrder[i] << "): ";
					begin = clock();
					CountingSort(n, a, compare_count);
				}
				else
				{
					fo << "Radix sort (" << n << ", " << DataOrder[i] << "): ";
					begin = clock();
					RadixSort(n, a, compare_count);
				}
				end = clock();
				time = end - begin;
				cout << ' ' << time << '\n';
				fo << "CP - " << compare_count << ", Time - " << time << '\n';
				delete[] a;
				fi.close();
			}
		}
	}
	fo.close();
}
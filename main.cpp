#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <chrono>
#define TIMING
#ifdef TIMING
#endif // TIMING
#define INIT_TIMER auto start = chrono::high_resolution_clock::now();
#define START_TIMER  start = chrono::high_resolution_clock::now();
#define STOP_TIMER(name)  cout << "RUNTIME of " << name << ": " << \
    chrono::duration_cast<chrono::milliseconds>( \
            chrono::high_resolution_clock::now()-start \
    ).count() << " ms " << std::endl;
using namespace std;
string data_order[] = {"DataNearlySorted","DataRandom","DataReverse","DataSorted"};
int data_size[7] = {10000,30000,50000,100000,300000,500000};
int arr[500005],n;
int readInput(int a[],int nSize,const char *filename){
    fstream inputFile ;
    inputFile.open(filename,ios::in);
    if(!inputFile.is_open()){
        return -1;
    }
    int i = 0 ;
    while(!inputFile.eof())
    {
        inputFile >> a[i];
        i++;
    }
    return 1 ;
   inputFile.close();
}
void swapping(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
/* source : https://www.tutorialspoint.com/cplusplus-program-to-sort-an-array-of-10-elements-using-heap-sort-algorithm */
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
        swapping(a[0],a[i]);
        heapify(a, i, 0,countcmp);
    }
}

/* source : https://www.sanfoundry.com/cplusplus-program-perform-shaker-sort/ */
// A function implementing shaker sort.
void ShakerSort(int a[], int n,unsigned long long &countcmp)
{
    int i, j, k;
    for(i = 0; i < n;)
    {
        countcmp++;
        // First phase for ascending highest value to the highest unsorted index.
        for(j = i+1; j < n; j++)
        {
            countcmp++;
            if(a[j] < a[j-1])
            {
                countcmp++;
                swapping(a[j], a[j-1]);
            }
        }
        // Decrementing highest index.
        n--;

        // Second phase for descending lowest value to the lowest unsorted index.
        for(k = n-1; k > i; k--)
        {
            countcmp++;
            if(a[k] < a[k-1])
            {
                countcmp++;
                swapping(a[k], a[k-1]);
            }
        }
        // Incrementing lowest index.
        i++;
    }
}
/* source : https://www.tutorialspoint.com/cplusplus-program-to-implement-shell-sort */
void shellSort(int a[], int n,unsigned long long &countcmp)
{
    int gap, j, k;
    for(gap = n/2; gap > 0; gap = gap / 2)          //initially gap = n/2,decreasing by gap /2
    {
        countcmp++;
        for(j = gap; j<n; j++)
        {
            countcmp++;
            for(k = j-gap; k>=0; k -= gap)
            {
                countcmp++;
                if(a[k+gap] >= a[k])
                {
                    countcmp++;
                    break;
                }
                else
                {
                    countcmp++;
                    swapping(a[k+gap], a[k]);
                }

            }
        }
    }
}
string abc(int k )
{
    if(k==0)
        return "Heap Sort";
    else if(k==1)
        return "Shaker Sort";
    else
        return "Shell Sort";
}
void testing_sorted()
{
    for(int i = 0 ; i < 4; i++)
    {
        for(int j = 0 ; j <6; j++)
        {
            cout << data_order[i] << " " << data_size[j] << endl;
            memset(arr,0,sizeof(arr));
            n = data_size[j];
            string file_csv = data_order[i]+"_"+ to_string(data_size[j])+".txt";
           // cout << file_csv << endl;
            readInput(arr,n,file_csv.c_str());
            for(int k = 0 ; k < 3 ;k++)
            {
                unsigned long long countcmp = 0 ;
                string message = file_csv + " with algorithm " + abc(k);
                if(k==0){
                    INIT_TIMER;
                    START_TIMER;
                    heapSort(arr,n,countcmp);
                    STOP_TIMER(message + " and countcmp: " + to_string(countcmp));
                }
                else if(k==1){
                    INIT_TIMER;
                    START_TIMER;
                    ShakerSort(arr,n,countcmp);
                    STOP_TIMER(message + " and countcmp: " + to_string(countcmp));
                }
                else{
                    INIT_TIMER;
                    START_TIMER;
                    shellSort(arr,n,countcmp);
                    STOP_TIMER(message + " and countcmp: " + to_string(countcmp));
                }
            }

        }
    }

}
void printArr(int arr[],int n)
{
    for(int i = 0 ; i < n;i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
    int arr1[] = {3,7,6,5,4,2,9,10,1,8};
    int n = 10;
    int countcmp = 0;
    INIT_TIMER;
    START_TIMER;
    heapSort(arr1,n,countcmp);
    STOP_TIMER("heapSort");
    printArr(arr1,n);
    cout << countcmp << endl;
    */
    testing_sorted();
    return 0;
}

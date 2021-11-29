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
int readInput(int a[],int nSize,const char *filename)
{
    fstream inputFile ;
    inputFile.open(filename,ios::in);
    if(!inputFile.is_open())
    {
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
// xây dựng heap thỏa tính chất cây nhị phân đầy đủ a[i] >= a[2*i+1] , a[2*i+2] với i là nút gốc
void heapify(int a[], int n, int i,unsigned long long &countcmp)
{
    int largest = i,l = 2 * i + 1,r = 2 * i + 2; // i là nút gốc , l là nút con bên trái , r là nút con bên phải

    // nếu nút gốc bé hơn nút con thì t cho nút gốc bằng nút con
    if (++countcmp && l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (++countcmp && r < n && a[r] > a[largest])
    {
        largest = r;
    }
    // kiểm tra nút gốc đã thay đổi thì t swap  giá trị
    if (++countcmp && largest != i)
    {
        swap(a[i],a[largest]);
        heapify(a, n, largest,countcmp);
    }
}
void heapSort(int a[], int n,unsigned long long &countcmp)
{
    // xây dựng heap từ mảng
    for (int i = n / 2 - 1;++countcmp && i >= 0; i--)
    {
        heapify(a, n, i,countcmp);
    }
    // sắp xếp lại mảng đã được xây dựng heap
    for (int i = n - 1; ++countcmp && i >= 0; i--)
    {
        swapping(a[0],a[i]);
        heapify(a, i, 0,countcmp);
    }
}

/* source : https://www.sanfoundry.com/cplusplus-program-perform-shaker-sort/ */
void ShakerSort(int a[], int n,unsigned long long &countcmp)
{
    int i, j, k;
    for(i = 0; ++countcmp && i < n;)
    {
        // tìm phần tử nhỏ nhất cho về đầu dãy
        for(j = i+1;++countcmp && j < n; j++)
        {

            if(++countcmp && a[j] < a[j-1])
            {
                swapping(a[j], a[j-1]);
            }
        }
        // giảm n
        n--;

        // tìm phần tử lớn nhất cho về đầu dãy
        for(k = n-1; ++countcmp && k > i; k--)
        {
            if(++countcmp && a[k] < a[k-1])
            {
                swapping(a[k], a[k-1]);
            }
        }
        // tang i
        i++;
    }
}
/* source : https://www.tutorialspoint.com/cplusplus-program-to-implement-shell-sort */
void shellSort(int a[], int n,unsigned long long &countcmp)
{
    int gap, j, k;
    for(gap = n/2; ++countcmp && gap > 0; gap = gap / 2)          //gap = n/2 , sau đó gap = h/2
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
            for(int k = 0 ; k < 3 ; k++)
            {
                unsigned long long countcmp = 0 ;
                string message = file_csv + " with algorithm " + abc(k);
                if(k==0)
                {
                    INIT_TIMER;
                    START_TIMER;
                    heapSort(arr,n,countcmp);
                    STOP_TIMER(message + " and countcmp: " + to_string(countcmp));
                }
                else if(k==1)
                {
                    INIT_TIMER;
                    START_TIMER;
                    ShakerSort(arr,n,countcmp);
                    STOP_TIMER(message + " and countcmp: " + to_string(countcmp));
                }
                else
                {
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
    for(int i = 0 ; i < n; i++)
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

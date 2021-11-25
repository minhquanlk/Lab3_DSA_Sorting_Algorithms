#include "DataGenerator.h"
#include "SortingAlgorithms.h"
#include <string.h>

//-----Kiểm tra là số hay là file-----
bool checkInteger(char* argv)
{
    for (int i = 0; i < strlen(argv); i++)
    {
        if (argv[i] < '0' || argv[i] > '9') return 0;
    }
    return 1;
}
//-----Lấy tên của kiểu dữ liệu-----
char* nameOfCase(int Case)
{
    if (Case == 0) 
    {
        char* nameCase = "Randomize";
        return nameCase;
    }
    if (Case == 3) 
    {
        char* nameCase = "Nearly Sorted";
        return nameCase;
    }
    if (Case == 1)  
    {
        char* nameCase = "Sorted";
        return nameCase;
    }
    if (Case == 2) 
    {
        char* nameCase = "Reversed";
        return nameCase;
    }
    return "Error Case";
}
//-----Trả kiểu dữ liệu về số cho dễ xử lý-----
int caseData(char* argv)
{
    if (strcmp(argv, "-rand") == 0) return 0;
    if (strcmp(argv, "-sorted") == 0) return 1;
    if (strcmp(argv, "-rev") == 0) return 2;
    if (strcmp(argv, "-nsorted") == 0) return 3;
    return -1;
}
//-----In kết quả ra màn hình-----
void outPar(char* argv, unsigned long long& countcmp, double& runTime)
{
    if (strcmp(argv, "-comp") == 0) cout << "Comparison: " << countcmp << endl;
    else if (strcmp(argv, "-time") == 0) cout << "Running time: " << runTime << endl;
    else if (strcmp(argv, "-both") == 0) 
    {
        cout << "Running time: " << runTime << endl;
        cout << "Comparison: " << countcmp << endl;
    } else {
        cout << "Error output parameters" << endl << endl;
        cout << "3 Output parameters in program:" << endl;
        cout << "-comp :  Number of comparisons in Algorithm" << endl;
        cout << "-time :  Algorithms's running time" << endl;
        cout << "-both :  Both above options" << endl;
        exit(0);
    }
    cout << endl;            
}
//-----11 Trường hợp thuật toán sắp xếp-----
void sorting(char* argv, int* arr, int n, unsigned long long& countcmp, double& runTime)
{
    clock_t start;
    countcmp = 0;
    if (strcmp(argv, "bubble-sort") == 0)
    {
        cout << "Bubble Sort";
        start = clock();
        bubbleSort(arr, n, countcmp);
        runTime = (double)(clock() - start);
    }
    else if (strcmp(argv, "insertion-sort") == 0)
    {
        cout << "Insertion Sort";
        start = clock();
        insertionSort(arr, n, countcmp);
        runTime = (double)(clock() - start);
    }
    else if (strcmp(argv, "selection-sort") == 0)
    {
        cout << "Selection Sort";
        start = clock();
        selectionSort(arr, n, countcmp);
        runTime = (double)(clock() - start);
    }
    else if (strcmp(argv, "heap-sort") == 0)
    {
        cout << "Heap Sort";
        start = clock();
        heapSort(arr, n, countcmp);
        runTime = (double)(clock() - start);
    }
    else if (strcmp(argv, "merge-sort") == 0)
    {
        cout << "Merge Sort";
        start = clock();
        mergeSort(arr, 0, n-1, countcmp);
        runTime = (double)(clock() - start);
    }
    else if (strcmp(argv, "quick-sort") == 0)
    {
        cout << "Quick Sort";
        start = clock();
        quickSort(arr, 0, n - 1, countcmp);
        runTime = (double)(clock() - start);
    }
    else if (strcmp(argv, "shaker-sort") == 0)
    {
        cout << "Shaker Sort";
        start = clock();
        shakerSort(arr, n, countcmp);
        runTime = (double)(clock() - start);
    }
    else if (strcmp(argv, "shell-sort") == 0)
    {
        cout << "Shell Sort";
        start = clock();
        shellSort(arr, n, countcmp);
        runTime = (double)(clock() - start);
    }
    else if (strcmp(argv, "radix-sort") == 0)
    {
        cout << "Radix Sort";
        start = clock();
        RadixSort(n, arr, countcmp);
        runTime = (double)(clock() - start);
    }
    else if (strcmp(argv, "counting-sort") == 0)
    {
        cout << "Counting Sort";
        start = clock();
        runTime = (double)(clock() - start);
    }
    else if (strcmp(argv, "flash-sort") == 0)
    {
        cout << "Flash Sort";
        start = clock();
        flashSort(arr, n, countcmp);
        runTime = (double)(clock() - start);
    }
    else {
        cout << "Error Algorithm" << endl << endl;
        cout << "11 Algorithms in program: " << endl << endl;
        cout << "bubble-sort   :    Bubble Sort" << endl;
        cout << "insertion-sort:    Insertion Sort" << endl;
        cout << "selection-sort:    Selection Sort" << endl;
        cout << "shaker-sort   :    Shaker Sort" << endl;
        cout << "shell-sort    :    Shell Sort" << endl;
        cout << "heap-sort     :    Heap Sort" << endl;
        cout << "merge-sort    :    Merge Sort" << endl;
        cout << "quick-sort    :    Quick Sort" << endl;
        cout << "radix-sort    :    Radix Sort" << endl;
        cout << "counting-sort :    Counting Sort" << endl;
        cout << "flash-sort    :    Flash Sort" << endl;
        exit(0);
    }
}
//-----Ghi Mảng sắp xếp ra file output.txt-----
void printSortedArray(int* arr, int n)
{
    ofstream output;
    output.open("output.txt", ios::out);
    if (!output.is_open()) cout << "Error When open file write" << endl;
    else {
        output << n << endl;
        for (int i = 0; i < n; i++){
            output << arr[i] << " ";
        }
        output.close();
    }
}
//-----Ghi mảng dữ liệu ra file input-----
void printGeneratedArray(int* arr, int n, int dataCase, int check)
{
    ofstream output;
    char path[12] = "input";
    if (check == 4) // Nếu là command 3
    {
        strcat(path, "_");
        char Case[6];
        itoa(dataCase, Case, 10);
        strcat(Case, ".txt");
        strcat(path, Case);
    }
    else if (check != 4) //Nếu là command 2 và 5
    {
        strcat(path, ".txt");
    }
    output.open(path, ios::out);
    if (!output.is_open()) cout << "Error When open file write" << endl;
    else {
        output << n << endl;
        for (int i = 0; i < n; i++){
            output << arr[i] << " ";
        }
        output.close();
    }
}
//-----In các thông tin ra cmd trong ALGORITHM MODE-----
void coutModeAlgorithm(int arr[], int n, int dataCase, char* argvAlg, unsigned long long& countcmp, double& runTime, char* argvPar)
{
    cout << "Algorithm: ";
    if (dataCase == 4) //Nếu là command 3
    {
        for (int i = 0; i < 4; i++)
        {
            GenerateData(arr, n, i);
            printGeneratedArray(arr, n, i+1, dataCase);
            sorting(argvAlg, arr, n, countcmp, runTime);
            cout << endl;
            cout << "Input size: " << n << endl;
            cout << "Input order: " << nameOfCase(i) << endl;
            cout << "------------------------------" << endl;
            outPar(argvPar, countcmp, runTime);
        }
    }
    else if (dataCase != -1)  //Nếu là các command còn lại
    {
        GenerateData(arr, n, dataCase);
        printGeneratedArray(arr, n, 0, dataCase);
        sorting(argvAlg, arr, n, countcmp, runTime);
        printSortedArray(arr, n);
        cout << endl;
        cout << "Input size: " << n << endl;
        cout << "Input order: " << nameOfCase(dataCase) << endl;
        cout << "------------------------------" << endl;
        outPar(argvPar, countcmp, runTime);
    }
    else if (dataCase == -1) {
        cout << endl << "Error Input Order" << endl << endl;
        cout << "4 Data case in program:" << endl << endl;
        cout << "-rand   :  Randomize Data " << endl;
        cout << "-sorted :  Sorted Data" << endl;
        cout << "-nsorted:  Nearly Sorted Data" << endl;
        cout << "-rev    :  Reverse Data" << endl;
        exit(0);
    }
}
//-----In các thông tin ra cmd trong COMPARISON MODE-----
void coutModeComparison(int arr[], int n, int dataCase, char* alg1, char* alg2, unsigned long long& countcmp1, unsigned long long& countcmp2, double& runTime1, double& runTime2)
{
    cout << "Algorithm   :  ";
    int* arrTemp = new int[n];
    if (dataCase != -1) 
    {
        if (dataCase != 4) {
            GenerateData(arr, n, dataCase);
            printGeneratedArray(arr, n, 0, 0);
        }
        for (int i = 0; i < n; i++) arrTemp[i] = arr[i];
        sorting(alg1, arr, n, countcmp1, runTime1);
        cout << "  |  ";
        sorting(alg2, arrTemp, n, countcmp2, runTime2);
        cout << endl;
        if (dataCase != 4) {
            cout << "Input size  :  " << n << endl;
            cout << "Input order :  " << nameOfCase(dataCase) << endl;
            cout << "------------------------------" << endl;
        }
    }
    else if (dataCase == -1) {
        cout << endl << "Error Input Order" << endl << endl;
        cout << "4 Data case in program:" << endl;
        cout << "-rand   :  Randomize Data " << endl;
        cout << "-sorted :  Sorted Data" << endl;
        cout << "-nsorted:  Nearly Sorted Data" << endl;
        cout << "-rev    :  Reverse Data" << endl;
        exit(0);
    }
}
int main(int argc, char* argv[])
{
    if (argc > 3 && argc < 7)
    {
        if (strcmp(argv[1], "-a") == 0)
        {
            int n;
            int* arr;
            unsigned long long countcmp;
            double runTime;
            cout << "ALGORITHM MODE" << endl;
            if (checkInteger(argv[3]))
            {
                n = atoi(argv[3]);
                arr = new int[n];
                if (argc == 5)
                {
                    coutModeAlgorithm(arr, n, 4, argv[2], countcmp, runTime, argv[4]);
                }
                if (argc == 6)
                {
                    coutModeAlgorithm(arr, n, caseData(argv[4]), argv[2], countcmp, runTime, argv[5]);
                }
            }
            else
            {
                ifstream input;
                input.open(argv[3], ios::in);
                if (!input.is_open())
                {
                    cout << "Error open file" << endl;
                    return 0;
                }
                input >> n;
                arr = new int[n];
                for (int i = 0; i < n; i++)
                {
                    input >> arr[i];
                }
                cout << "Algorithm: ";
                sorting(argv[2], arr, n, countcmp, runTime);
                printSortedArray(arr, n);
                cout << endl << "Input file: " << argv[3] << endl;
                cout << "Input size: " << n << endl;
                cout << "------------------------------" << endl;
                outPar(argv[4], countcmp, runTime);
            }
        }
        else if (strcmp(argv[1], "-c") == 0)
        {
            cout << "COMPARISON MODE" << endl;
            if (checkInteger(argv[3])) {
                cout << "Miss one Algorithm" << endl;
                return 0;
            }
            int n;
            int* arr;
            unsigned long long countcmp1, countcmp2;
            double runTime1, runTime2;
            if (argc == 6)
            {
                n = atoi(argv[4]);
                arr = new int[n];
                coutModeComparison(arr, n, caseData(argv[5]), argv[2], argv[3], countcmp1, countcmp2, runTime1, runTime2);
                cout << "Running time:  " << runTime1 << "  |  " << runTime2 << endl;
                cout << "Comparison  :  " << countcmp1 << "  |  " << countcmp2 << endl;
            }
            else if (argc == 5)
            {
                ifstream input;
                input.open(argv[4], ios::in);
                if (!input.is_open())
                {
                    cout << "Error open file" << endl;
                    return 0;
                }
                input >> n;
                arr = new int[n];
                for (int i = 0; i < n; i++)
                {
                    input >> arr[i];
                }
                coutModeComparison(arr, n, 4, argv[2], argv[3], countcmp1, countcmp2, runTime1, runTime2);
                cout << "Input file  :  " << argv[4] << endl;
                cout << "Input size  :  " << n << endl;
                cout << "------------------------------" << endl;
                cout << "Running time:  " << runTime1 << "  |  " << runTime2 << endl;
                cout << "Comparison  :  " << countcmp1 << "  |  " << countcmp2 << endl;
            }
        }
        else
        {
            cout << "Error mode" << endl;
            cout << "Note:" << endl << " -a: is ALGORITHM MODE" << endl << " -c: is COMPARISON MODE" << endl;
            return 0;
        }
    }
    return 0;
}
#pragma once
#include "DataGenerator.h"
#include <cstring>

void ReadData(int* arr, int dataCase, int dataSize)
{
    ifstream inputData;
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
    cout << dataSize;
    char size[7];
    itoa(dataSize, size, 10);
    strcat(path, size);
    strcat(path, ".csv");
    inputData.open(path, ios::in);
    for (int i = 0; i < dataSize; i++)
    {
        inputData >> arr[i];
    }
    inputData.close();
}

/*
*   CSCI 41 - Introduction to Date Structures (Lab 9)
*   Done By: Saishnu Ramesh Kumar (300758706)
*   Q3b - Shell Sort
*
*/

#include <iostream>
#include <cmath>

using namespace std;

//Shell Sort Function
int shellSort(char arr[], int n)
{

    int h, i, j;
    char temp;
    int tempCount;

    for (tempCount = n - 1; tempCount >= 0; tempCount--)
    {
        if (tempCount == 0) //If tempCount is 0 declare h as 1 
        {
            h = 1;
        }

        else
        {
            h = (4 ^ (tempCount)) + (3 * 2 ^ (tempCount - 1)) + 1; //Otherwise it will use the formula
        }

        for (i = h; i < n; i += 1)
        {
            temp = arr[i];

            for (j = i; j >= h && temp < arr[j - h]; j -= h)
            {
                arr[j] = arr[j - h];
            }
            arr[j] = temp;
        }
    }
    return 0;
}

//Print Array Function
void printArray(char arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

//Main Function
int main()
{

    char arr[] = {'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};

    int i;

    int n = sizeof(arr) / sizeof(arr[0]); //Gets the length of the array

    cout << "Original: \nS O R T E X A M P L E\n";

    shellSort(arr, n);

    cout << "\nAfter Shell Sort: \n";
    printArray(arr, n); //Shows the sorted list

    return 0;
}
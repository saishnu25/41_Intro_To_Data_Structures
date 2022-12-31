/*
*   CSCI 41 - Introduction to Date Structures (Lab 9)
*   Done By: Saishnu Ramesh Kumar (300758706)
*   Q3a - Shell Sort
*
*/

#include <iostream>

using namespace std;

//Shell Sort Function
int shellSort(char arr[], int n)
{
    //Starts with a gap and reduces
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        //Insertion sort used for the gap size
        for (int i = gap; i < n; i += 1)
        {
            char temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
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
        cout << arr[i] << " ";
}

//Main Function
int main()
{
    char arr[] = {'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int i;
    int n = sizeof(arr) / sizeof(arr[0]); //Finding the length of the array
    cout << "Original: \n";
    printArray(arr, n); //Outputs the original list

    shellSort(arr, n);

    cout << "\n\nAfter Shell Sort: \n";
    printArray(arr, n); //Outputs the updated list
    return 0;
}
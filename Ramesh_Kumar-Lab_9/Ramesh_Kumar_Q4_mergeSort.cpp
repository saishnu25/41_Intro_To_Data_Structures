/*
*   CSCI 41 - Introduction to Date Structures (Lab 9)
*   Done By: Saishnu Ramesh Kumar (300758706)
*   Q4 - Mergesort
*
*/

#include <iostream>

using namespace std;

//Display Merge Function
void displayMerge(char arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " "; //Outputs the list of the array
    }
}

//Merge Function
void merge(char arr[], int low, int mid, int high)
{
    int number1 = mid - low + 1;
    int number2 = high - mid;
    int i, j, k;

    //Creating two temporary arrays
    int left[number1], right[number2];

    //Copy data arr[] to temporary arrays left
    for (i = 0; i < number1; i++){
        left[i] = arr[low + i];
    }

    //Copy data arr[] to temporary arrays right
    for (j = 0; j < number2; j++){
        right[j] = arr[mid + 1 + j];
    }

    i = 0;

    j = 0;

    k = low;

    while (i < number1 && j < number2)
    {
        //Compares the elements of the left and right arrays
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    if (j >= number2) //If all elements of the right array has be processed then
    {
        //Copying the remaining elements of the left array
        while (i < number1)
        {
            arr[k] = left[i];
            i++;
            k++;
        }
    }
    else //If all elements of the left array has been processed then
    {
        //Copying the remaining elements of the right array
        while (j < number2)
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
}

//Merge Sort Function
void mergeSort(char arr[], int low, int high)
{
    int mid;
    if (low >= high) //If low is >= high, return
    {
        return;
    }

    //Only if low is < high then proceed
    mid = low + (high - low) / 2; // Finding the mid point

    mergeSort(arr, low, mid); //Calling the mergeSort Function to left side of the array
    mergeSort(arr, mid + 1, high); //Calling mergeSort Function to right side of the array

    merge(arr, low, mid, high); //Calling the function to merge the 2 subarrays
}

//Main Function
int main()
{

    char arr[] = {'M', 'E', 'R', 'G', 'E', 'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};

    int arr_length = sizeof(arr) / sizeof(arr[0]); //Finding the length of the array

    cout << "Original:"<<endl;
    displayMerge(arr, arr_length);

    mergeSort(arr, 0, arr_length - 1); //Calling the mergeSort Function

    cout << "\n\nAfter Mergesort:"<<endl;
    displayMerge(arr, arr_length); //The updated and sorted list of array

    return 0;
}

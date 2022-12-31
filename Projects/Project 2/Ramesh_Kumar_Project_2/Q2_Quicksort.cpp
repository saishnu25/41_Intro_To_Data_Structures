/*
*   Question 2 - Quicksort 
*   CSCI 41 - Introduction to Data Structures
*   Done By: Saishnu Ramesh Kumar (300758706)
*
*/

#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

#define NUM_ELEMENTS 1000000

//Partition Function
int partition(int arr[], int l, int r){
    int i, j;
    int pivot, temp;
    pivot = arr[l]; //The first element will be stored in the pivot
    i = l;
    j = r + 1;

    do{

        do{ //Increment of index
            i = i + 1;
        } while (arr[i] < pivot && i < r);

        do{ //Decrement of index
            j = j - 1;
        } while (arr[j] > pivot && j > l);

        //Swapping the index positions
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

    } while (i < j);

    //Undoing the last swap of i and j index elements
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    //Swapping the pivot element with the element in index j
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j;
}

//Quicksort Function
void quickSort(int arr[], int l, int r){
    int s;

    if (l < r){
        s = partition(arr, l, r); //Calling the partition function to partition the array
        quickSort(arr, l, s - 1); //Sorting the left side of the array
        quickSort(arr, s + 1, r); //Sorting the right side of the array
    }
}

//Main Function
int main(){

    int *arr = (int *)malloc(sizeof(int) * NUM_ELEMENTS);

    cout << "Creating " << NUM_ELEMENTS << " random numbers please wait..." << endl;
    for (int i = 0; i < NUM_ELEMENTS; i++){
        int randNumber;
        arr[i] = rand(); //Generates 1 million random integers
    }

    cout << endl;

    auto start_time = chrono::high_resolution_clock::now(); //Start time

    quickSort(arr, 0, NUM_ELEMENTS - 1); //Calls the quickSort Function

    auto end_time = chrono::high_resolution_clock::now(); //End time

    chrono::duration<double> elapsed = end_time - start_time; //Total time

    cout << "The 100 smallest elements from the array are: " << endl;
    for (int i = 0; i < 100; i++){
        cout << arr[i] << "\n"; //Outputs 100 random smallest integers in the array
    }

    cout << endl << "\nElapsed time is: " << elapsed.count() << endl;

    cout<<"\n\nThis program has ended..."<<endl;
    return 0;
}
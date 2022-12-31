/*
*   Question 3 - Dijkstra Partition
*   CSCI 41 - Introduction to Data Structures
*   Done By: Saishnu Ramesh Kumar (300758706)
*
*/

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <chrono>

using namespace std;

#define NUM_ELEMENTS 1000000

//Swap Function
void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

//Dijkstra Partition Function
void dijkstra_partition(int *arr, int left, int right){

    //If the number of elements are less than 1, return
    if (NUM_ELEMENTS <= 1){
        return;
    }

    //If the right and left are the same, return 
    if (right == left){
        return;
    }
 
    if (right - left + 1 == 2){
        if (arr[right] < arr[left]){

            swap(arr[right], arr[left]); //Swaps if the left number is larger than the right
        }
        return; //Otherwise return as there is no need to swap
    }

    int i = left + 1;
    int lo = left;
    int hi = right;

    while (i <= right){

        int pivot = arr[left];
        
        //If the i is equal to the pivot, update i
        if (arr[i] == pivot){
            i++;
        }

        //If i is less than the pivot, call the swap function for the left side
        else if (arr[i] < pivot){
            swap(arr[i], arr[left]); 
            left++;
            i++;
        }

        //If i is greater than the pivot, call the swap function for the right side 
        else if (arr[i] > pivot){
            swap(arr[i], arr[right]);
            right--;
        }
    }

    //If the left is greater than the right, return 
    if (left > right){
        return;
    }

    if (left - 1 >= 0){
        dijkstra_partition(arr, lo, left - 1); //This section through recursion will sort the left side of the list
    }

    if (right + 1 <= hi){
        dijkstra_partition(arr, right + 1, hi); //This section through recursion will sort the right side of the list
    }
}

//Main Function
int main(){

    int *arr = (int *)malloc(sizeof(int) * NUM_ELEMENTS);

    cout << "Creating " << NUM_ELEMENTS << " random numbers please wait..." << endl;

    for (int i = 0; i < NUM_ELEMENTS; i++){
        int randNumber;
        arr[i] = rand(); //Generates 1 million random numbers
    }

    cout << endl;

    auto start_time = chrono::high_resolution_clock::now(); //Start time

    dijkstra_partition(arr, 0, NUM_ELEMENTS - 1); //Calls the Dijkstra Partition Function

    auto end_time = chrono::high_resolution_clock::now(); //End time

    chrono::duration<double> elapsed = end_time - start_time; //Total time

    cout << "The 100 smallest elements from the array are: " << endl;
    for (int i = 0; i < 100; i++){
        cout << arr[i] << "\n"; //Outputs 100 random smallest integers in the array
    }

    cout << endl << "\nElapsed time is: " << elapsed.count() << endl;

    cout << "\n\nThis program has ended..." << endl;

    return 0;
}
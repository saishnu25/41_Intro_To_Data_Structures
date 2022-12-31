/*
*
*   CSCI 41 - Introduction to Data Structures (Lab 10)
*   Done By: Saishnu Ramesh Kumar (300758706)
*
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define N 100000
#define M 1000

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

    int arr[N];

    cout << "Creating " << N << " random numbers..." << endl;
    for (int i = 0; i < N; i++){
        arr[i] = rand(); //Generates 1 billion random integers
    }

    cout << endl;

    quickSort(arr, 0, N - 1);

    cout << "The " << M << " smallest elements from the array are: " << endl;
    for (int i = 0; i < M; i++){
        cout << arr[i] << " "; //Outputs 1000 random smallest integers in the array
    }

    cout<<"\n\nThis program has ended..."<<endl;
    return 0;
}
/*
*   CSCI 41 - Introduction to Date Structures (Lab 9)
*   Done By: Saishnu Ramesh Kumar (300758706)
*   Q5 - Quicksort
*
*/

#include <iostream>

using namespace std;

//Split Function
int split(char arr[], int start, int end){
    char p = arr[end];
    int small = (start - 1);

    for(int i = start; i <= end-1; i++){
        if(arr[i] <= p){
            small++;
            char temp;
            temp = arr[i];
            arr[i] = arr[small];
            arr[small] = temp;
        }
    }

    char temp;
    temp = arr[small + 1];
    arr[small + 1] = arr[end];
    arr[end] = temp;

    return(small + 1);
}

//Quicksort Function
void quickSort(char arr[], int start, int end){

    //If the start index does not overlap or passes the end index
    if(start < end){

        //Getting the split index
        int index = split(arr, start, end);

        //Sorting both the split arrays
        quickSort(arr, start, index - 1); //Checks the array list before
        quickSort(arr, index + 1, end); //Checks the array list after
    }
}

//Main Function
int main(){

    char arr[] = {'Q', 'U', 'I', 'C', 'K', 'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};

    
    int size = sizeof(arr)/sizeof(char); //Finding the length of the array

    cout << "Original:\nQ U I C K S O R T E X A M P L E" << endl;

    quickSort(arr, 0, size - 1); //Calling quickSort Function

    //Printing the array after Quicksort
    cout << "\nAfter Quicksort:" << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i]<< " ";
    }
    cout << endl;

    return 0;
}
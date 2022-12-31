/*
*   Question 4b - Priority Queue Using Heap Using Array/Vector
*   CSCI 41 - Introduction to Data Structures
*   Done By: Saishnu Ramesh Kumar (300758706)
*
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>

using namespace std;

#define NUM_ELEMENTS 1000000

//Insert into heap Function 
void insertIntoHeap(int *arr, int size, int element){
    
    arr[size] = element;

    if(size == 0){
        return;
    }

    int curr_index = size;
    int parent_index;

    //If current index is odd
    if(curr_index % 2 != 0){
        parent_index = (curr_index - 1) / 2;
    }   

    //If current index is even
    else{
        parent_index = (curr_index - 2) / 2;
    }
    
    while(arr[parent_index] > arr[curr_index]){ 

        //Swapping the child and parent nodes
        swap(arr[parent_index], arr[curr_index]);

        curr_index = parent_index;

        //If the current index is 0, break
        if(curr_index == 0){
            break;
        }

        //If current index is odd
        if (curr_index % 2 != 0){
            parent_index = (curr_index - 1) / 2;
        }

        //If current index is even
        else{
            parent_index = (curr_index - 2) / 2;
        }
    }

}

//Remove From Heap Function
int removeFromHeap(int *arr, int size){

    swap(arr[0], arr[size - 1]);
    int value = arr[size - 1];

    int curr_index = 0;
    int child_index;
    int child_1 = (curr_index * 2) + 1;
    int child_2 = (curr_index * 2) + 2;

    //Compares the child nodes
    if(arr[child_1] < arr[child_2]){
        child_index = child_1;
    }

    else{
        child_index = child_2;
    }

    //Min Heapify
    while(arr[curr_index] > arr[child_index]){
        swap(arr[curr_index], arr[child_index]);

        curr_index = child_index;

        if((curr_index * 2) + 1 >= size){
            break;
        }

        int child_1 = (curr_index * 2) + 1;
        int child_2 = (curr_index * 2) + 2;

        //Compares the child nodes
        if (arr[child_1] < arr[child_2]){
            child_index = child_1;
        }

        else{
            child_index = child_2;
        }
    }

    return value;

}

//Swap Function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b =temp;
}

//Main Function
int main(){

    int *numArray = (int *)malloc(sizeof(int) * NUM_ELEMENTS);

    cout << "Creating " << NUM_ELEMENTS << " random numbers please wait..." << endl;

    auto start_time = chrono::high_resolution_clock::now(); //Start time

    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        int rand_num = rand(); //Generates random numbers
        insertIntoHeap(numArray, i, rand_num); //Calling the insertIntoHeap Function
    }

    auto end_time = chrono::high_resolution_clock::now(); //End time

    chrono::duration<double> elapsed = end_time - start_time; //Total time

    cout << "The 100 smallest elements from the array are: " << endl;

    int size = NUM_ELEMENTS;
    for (int i = 0; i < 100; i++)
    {
        int value = removeFromHeap(numArray, size); //Calling the removeFromHeap Function
        size--;
        cout << value << endl; //Outputs 100 random smallest integers in the array
    }

    cout << endl << "\nElapsed time is: " << elapsed.count() << endl;

    cout << "\n\nThis program has ended..." << endl;

    return 0;
}
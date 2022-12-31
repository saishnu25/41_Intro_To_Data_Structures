/*
*   Question 4a - Priority Queue Using Ordered Array/Vector
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

//Insert into queue Function
void insertIntoQueue(int *arr, int size, int element){

    if (size == 0){
        arr[size] = element; //If the size is 0, return
        return;
    }

    int count = 0;
    while (count < NUM_ELEMENTS){ //While the count is less than 1 million

        if (arr[count] > element){ //If the array count is greater than the element

            int temp = arr[count];
            arr[count] = element; 

            while (count < size){ //While the count is less than size

                count++; //Updates count each iteration

                //Swapping occurs
                int temp2 = arr[count];
                arr[count] = temp;
                temp = temp2;
            }
            return;
        }
        count++; //Updates count each iteration
    }

    arr[size] = element;
}

//Main Function
int main(){

    int *numArray = (int *)malloc(sizeof(int) * NUM_ELEMENTS);

    cout << "Creating " << NUM_ELEMENTS << " random numbers please wait..." << endl;

    auto start_time = chrono::high_resolution_clock::now(); //Start time

    for (int i = 0; i < NUM_ELEMENTS; i++){
        int rand_num = rand(); //Generates random numbers
        insertIntoQueue(numArray, i, rand_num); //Calling Insert into queue Function
    }

    auto end_time = chrono::high_resolution_clock::now(); //End time

    chrono::duration<double> elapsed = end_time - start_time; //Total time

    cout << "The 100 smallest elements from the array are: " << endl;
    for (int i = 0; i < 100; i++){
        cout << numArray[i] << endl; //Outputs 100 random smallest integers in the array
    }

    cout << endl << "\nElapsed time is: " << elapsed.count() << endl;

    cout << "\n\nThis program has ended..." << endl;

    return 0;
}
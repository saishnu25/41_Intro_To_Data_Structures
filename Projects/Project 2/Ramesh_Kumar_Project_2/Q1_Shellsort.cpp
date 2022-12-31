/*
*   Question 1 - Shellsort 
*   CSCI 41 - Introduction to Data Structures
*   Done By: Saishnu Ramesh Kumar (300758706)
*
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <math.h>

#define NUM_ELEMENTS 1000000

using namespace std;

//Produce Gap Array Function
int *produceGapArray(int *size){

    int k = 1, h;
    int arrSize;
    while (true){
        if (k % 2 == 0){ //If it's even
            h = (9 * (pow(2, k) - pow(2, k / 2))) + 1;
        }
        else{ //If it's odd
            h = (8 * pow(2, k)) - (6 * pow(2, ((k + 1) / 2))) + 1;
        }

        if (h > NUM_ELEMENTS){ //If h is greater than 1 million, break
            break;
        }
        k++;
        arrSize++;
    }

    int count = 0;
    int *gapArray = (int *)malloc(sizeof(int) * (arrSize + 1));

    for (int i = arrSize; i >= 0; i--){
        int k = i;

        if (k == 0){

            h = 1;
        }
        else if (k % 2 == 0){ //If it's even

            h = (9 * (pow(2, k) - pow(2, k / 2))) + 1;
        }

        else{ //If it's odd

            h = (8 * pow(2, k)) - (6 * pow(2, ((k + 1) / 2))) + 1;
        }
        gapArray[count++] = h;
    }

    *size = arrSize + 1;
    return gapArray;
}

//Shell Sort Function
void shellSort(int arr[]){

    int h, i, j;
    int temp;
    int gap;
    int gapArrSize = 0;

    int *gapArray = produceGapArray(&gapArrSize); //Calls Gap Array Function

    for (int count = 0; count < gapArrSize; count++){

        gap = gapArray[count];
        for (i = gap; i < NUM_ELEMENTS; i++){ //Shellsort occurs here, the gap is introduced
        
            temp = arr[i];

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }

    free(gapArray);
}

//Main Function
int main(){

    int *numArray = (int *)malloc(NUM_ELEMENTS * sizeof(int));

    cout << "Creating " << NUM_ELEMENTS << " random numbers please wait..." << endl;
    for (int i = 0; i < NUM_ELEMENTS; i++){
        int randomNumber = rand(); //Generates 1 million random integers
        numArray[i] = randomNumber;
    }

    auto start_time = chrono::high_resolution_clock::now(); //Start time

    shellSort(numArray); //Calls the shellSort Function

    auto end_time = chrono::high_resolution_clock::now(); //End time

    chrono::duration<double> elapsed = end_time - start_time; //Total time

    cout << "The first smallest hundred elements are:" << endl;
    for (int i = 0; i < 100; i++){
        cout << numArray[i] <<endl; //Outputs 100 random smallest integers in the array
    }

    cout << "\nElapsed time: " << elapsed.count() << endl;

    cout << "\n\nThis program has ended..." << endl;

    free(numArray);

    return 0;
}
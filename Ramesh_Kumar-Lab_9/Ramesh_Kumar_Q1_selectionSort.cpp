/*
*   CSCI 41 - Introduction to Date Structures (Lab 9)
*   Done By: Saishnu Ramesh Kumar (300758706)
*   Q1 - Selection Sort
*
*/

#include <iostream>
#include <string.h>

using namespace std;

#define MAX_LEN 50

//Selection Sort Function
void selectionSort(char arr[][50], int n){
    int i, j, minIndex;

    //Moving through the boundary of the unsorted subarray one by one
    char minStr[50];

    for(i = 0; i < n-1; i++){
        //Determines the minimum element in the unsorted array
        int minIndex = i;
        strcpy(minStr, arr[i]);
        for(j = i + 1; j < n; j++){
            //Checks if the min is greater than arr[j]
            if(strcmp(minStr, arr[j]) > 0){
                //Making arr[j] as minStr and update min index
                strcpy(minStr, arr[j]);
                minIndex = j;
            }
        }
        
        //Swapping the minimum element with the first element
        if(minIndex != i){
            char temp[50];
            strcpy(temp, arr[i]); //Swap item[pos] and item[i]
            strcpy(arr[i], arr[minIndex]);
            strcpy(arr[minIndex], temp);
        }
    }
}

//Main Function
int main(){
    char arr[][50] = {"S", "O", "R", "T", "E", "X", "A", "M", "P", "L", "E"};

    int n = sizeof(arr)/sizeof(arr[0]);

    int i;

    cout<<"Original:\nS O R T E X A M P L E\n"<<endl; //Original List
    selectionSort(arr, n);

    cout<<"After Selection Sort:"<<endl;
    for(i = 0; i < n; i++){
        cout<<arr[i]<<" "; //Updated list in order
    }

    return 0;
}
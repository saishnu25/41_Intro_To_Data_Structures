/*
*   CSCI 41 - Introduction to Date Structures (Lab 9)
*   Done By: Saishnu Ramesh Kumar (300758706)
*   Q2 - Insertion Sort
*
*/

#include <iostream>
#include <cstring>

using namespace std;

//Main Function
int main(){
    char k[50], t[50];
    char a[50][50] = {"S", "O", "R", "T", "E", "X", "A", "M", "P", "L", "E"};
    char b[50][50];

    int i, j, f, p;
    cout<<"Original:\nS O R T E X A M P L E\n"<<endl; //Before the Insertion Sort

    strcpy(b[0], a[0]); //Copies the first character from array a to b
    for(j = 1; j < 11; j++)
    {
        i = j - 1;
        f = 1;
        strcpy(k, a[j]);
        while(f == 1)
        {   
            //String compares if >= to 0
            if(strcmp(b[i], k) >= 0)
            {
                i--;
                if(i == -1){
                    f = 0;
                }
            
            }

            //Otherwise f is 0
            else{
                f = 0;
            }
        }
            p = j;

            while(p > i+1){
                strcpy(b[p], b[p-1]);
                p--;
            }

            strcpy(b[i+1], k);
        }

    cout << "After Insertion Sort: \n";
    for (i = 0; i < 11; i++)
    {
        cout << b[i] << " "; //After the Insertion Sort
    }

    return 0;

}
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

//Recursion Function for sum
int sum(int n){

    if(n <= 0){ //If the number inputted is less than 0, return the number
        return n;
    }

    return n + sum(n - 1); //This will print the sum of numbers depending how many the user requests
}

//Recursion Function for power
int power(int base, int exp){

    if(exp != 0){ //If the exponential is not equal to one, this will calculate the power 
        return (base * power(base, exp - 1));
    }

    else{ //If the exponential is 0, it will output 1
        return 1;
    }
}

//Recursion Function for palindrome
bool palindrome(string word){

    int length = word.length(); //Checks the word length

    string first = word.substr(0,1);
    string last = word.substr((length - 1), 1);

    if(first == last){ 
        word = word.substr((0 + 1), (length - 2));

        if(word.length() <= 1){
            return true; //If the word length is less than one, print true
        }

        else{
            return palindrome(word); //Otherwise return the word
        }
    }

    else{
        return false;
    }

}

//Recursion function for reverse string
void reverseString(string reverse){

    if(reverse.size() == 0){
        return; //If size is equal to 0, return
    }

    reverseString(reverse.substr(1));
    cout<<reverse[0]; //This will output the reserve of the input string

}

//DLL struct
struct DLL{
    int data;
    DLL *next;
    DLL *prev;
};

//CLL struct
struct CLL{
    int data;
    CLL *next;
};

//SLL struct
struct SLL{
    int data;
    SLL *next;
};

//DLL to delete all nodes
void deleteAll(DLL *node){

    if(node == NULL){ //If the node equals NULL, return
        return;
    }

    node->prev = NULL;
    deleteAll(node->next); //Recursion to link the next node together
    node->next = NULL;
    delete node; //Deletes the node
}

//CLL to check content clockwise
void clockwise(CLL *node, CLL *head){
    if(node-> next == head){
        cout<<node->data<<" "; 
        return;
    }

    cout<<node->data<<" ";
    clockwise(node->next, head); //Recursion to access the nodes to print in a clockwise order

}

//CLL to check content counter clockwise
void antiClockwise(CLL *node, CLL *head){
    if(node->next == head){
        cout<<node->data<<" ";
        return;
    }

    antiClockwise(node->next, head); //Recursion to access the nodes to print in a counter clockwise order
    cout<<node->data<<" ";

}

//SLL to reverse order
void reverseSLL(SLL *node){
    if(node == NULL){ //If node equals NULL, return
        return;
    }

    reverseSLL(node->next); //Recursion to reverse the order
    cout<<node->data<<" ";
}


//Start of Main Function
int main(){
    
    int choice, n, base, exp, result; 
    string word, reverse;
    bool loop = true;
    DLL *dll;
    CLL *cll;
    SLL *sll;

    while(loop = true){
        cout<<"Welcome to the Menu, please input a number between 1 to 7 "<<endl;
        cout<<"1. Sum of integers "<<endl;
        cout<<"2. Calculate the power of a integer " << endl;
        cout<<"3. Check if string is a palindrome" << endl;
        cout<<"4. Reverse the inputted string" << endl;
        cout<<"5. DLL to delete all nodes" << endl;
        cout<<"6. CLL to check if contents read the same in clockwise and counter-clockwise" << endl;
        cout<<"7. SLL to print all contents in reverse order" << endl;
        cout<<"8. To clear the terminal "<<endl;
        cout<<"To exit, press 0"<<endl;
        cin>>choice;

        switch(choice){

            //Sum of integers
            case 1:
                cout << "Enter how many number you would like to sum together >> " << endl;
                cin >> n;

                cout << "Sum of numbers from 0 to n: " << endl;
                cout << sum(n) << endl;
                cout<<"\n"<<endl;

                break;

            //Power of an integer
            case 2:
                cout << "Enter base number >> " << endl;
                cin >> base;

                cout << "Enter power number >>" << endl;
                cin >> exp;

                result = power(base, exp);
                cout << "The output is: " << base << "^" << exp << " = " << result;
                cout<<"\n"<<endl;

                break;

            //Palindrome string
            case 3:
                cout<<"Enter the string >> "<<endl;
                cin>>word;

                if(palindrome(word) == true){
                    cout<<"\nString is a palindrome"<<endl;
                }

                else{
                    cout<<"\nString is NOT a palindrome"<<endl;
                }
                cout<<"\n"<< endl;
                
                break;

            //Reverse string
            case 4:
                cout<<"Enter string to reverse >>"<<endl;
                cin>>reverse;

                cout<<"Reverse String: "<<endl;
                reverseString(reverse);
                cout<<"\n"<<endl;

                break;

            //DLL to delete all nodes
            case 5:
                cout<<"Deleting all nodes using DLL"<<endl;
                deleteAll(dll);
                cout<<"\n"<<endl;

                break;

            //CLL to check contents clockwise and counter-clockwise
            case 6:
                cout<<"Checking the contents using CLL, both clockwise and counter-clockwise"<<endl;
                clockwise(cll, cll);
                antiClockwise(cll, cll);
                cout<<"\n"<<endl;

                break;

            //SLL to print contents in reverse
            case 7:
                cout<<"SLL to print out contents in reverse order"<<endl;
                reverseSLL(sll);
                cout<<"\n"<<endl;

                break;

            //Clears the terminal
            case 8:
                system("clear");

                break;

            //Exit the program
            case 0:
                cout<<"You have exited the program..."<<endl;

                return 0;

            //Default to catch input errors
            default:
                cout<<"ERROR, please input a number from 0 to 7!"<<endl;
                cout<<"\n"<<endl;

                break;
        }
    }

    return 0;
} 
//End of Main Function
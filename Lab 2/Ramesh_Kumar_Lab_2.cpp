/*
*
* CSCI 41 - Introduction to Data Structures (Lab 2)
* Done By: Saishnu Ramesh Kumar (Student ID: 300758706)
*
* This program will do/solve different tasks. 
*/
#include<iostream>
#include<vector>

using namespace std;

//Function 1 - Calculate volume of box 
int volume(int length, int width, int height)
{ //Start of Function 1

    int volume1 = length * width * height; //Formula to calculate the volume
    return volume1; //Returns the volume to the main function 
   
} //End of Function 1

//Function 2 - Call-By-Reference: Compute the square of an integer
void square(int &x)
{ //Start of Function 2

    int result = x * x; //Square's the number inputted
    cout<<result<<endl; //Output's square of number

} //End of Function 2

//Function 3 - Call-By-Pointer: Compute the square of an integer
void square1(int x)
{ //Start of Function 3

    int result = x * x; //Square's the number inputted
    cout<<result<<endl; //Output's the square of number

} //End of Function 3

//Function 4 - Introducing a integer vector then reversing it
void reverseVector(vector<int> &vector1)
{ //Start of Function 4
    int i = 0;
    int j = vector1.size()-1;
    int temporary;

    //Loop introduced to go through list of numbers
    while(i<j){ 
        //Reversing of numbers take place
        temporary = vector1[i]; 
        vector1[i] = vector1[j];
        vector1[j] = temporary;
        i++;
        j--;

    }
} //End of Function 4

//Function 5 - Introducing a integer vector to check if it's a palindrome
bool palindromeVector(vector<int> vector1)
{ //Start of Function 5
    int i = 0;
    int j = vector1.size()-1;

    //Loop introduced to go through number
    while(i<j){
        if(vector1[i] != vector1[j]){
            return false; //Returns if number is false
        }
        i++;
        j--;
    }
    return true; //Returns if number if true 
} //End of Function 5

int main(){ //Start of Main Function

    bool loop = true;
    int choice;

    //Continuous loop of menu 
    while(loop == true){
        cout<<"Welcome to the Menu Prompt!"<<endl;
        cout<<"Enter a number from 1 to 7, press 0 to exit >> "<<endl;
        cout<<"1. Calculate volume of box"<<endl;
        cout<<"2. Call-By-Reference: Compute the square of an integer"<<endl;
        cout<<"3. Call-By-Pointer: Compute the square of an integer"<<endl;
        cout<<"4. Introducing a integer vector then reversing it"<<endl;
        cout<<"5. Introducing a integer vector to check if it's a palindrome"<<endl;
        cout<<"6. Source Code about Pointers from Lab 2 document"<<endl;
        cout<<"7. Clear Terminal/Command Prompt screen"<<endl;
        cout<<"\n0. Exit the Program"<<endl;
        cin>>choice;

        //User's inputted choice goes through switch to determine which choice is selected
        switch(choice){

            //Case 1 - Calculate volume of box
             case 1: 
            { //Start of Case 1
                int length, width, height;

                cout<<"\nEnter the length, width and height of the box respectively >> "<<endl;
                cin >> length >> width >> height; //User inputs the details required 
                int box = volume(length, width, height); //Calls volume function
                cout<<"\nThe volume of the box is = "<<box<<"\n"<<endl;

                break;
            } //End of Case 1

            //Case 2 - Call-By-Reference: Compute the square of an integer
            case 2:
            { //Start of Case 2
                int number;

                cout<<"\nEnter the number you would like to square >> "<<endl;
                cin>>number; //User inputs the number
                cout<<"\nThe square of "<<number<<" is:"<<endl;
                square(number); //Calls call-by-reference function and outputs the square number
                cout<<"\n"<<endl;

                break;
            } //End of Case 2

            //Case 3 - Call-By-Pointer: Compute the square of an integer 
            case 3:
            { //Start of Case 3
                void(*square1_ptr)(int) = &square1; //Uses the call-by-pointer function
                int number;
                cout<<"\nEnter the number you would like to square >> "<<endl;
                cin>>number; //User inputs the number
                cout << "\nThe square of " << number << " is:" << endl;
                (*square1_ptr)(number); //Outputs the square number
                cout << "\n"<< endl;
                break;
            } //End of Case 3

            //Case 4 - Introducing a integer vector then reversing it
            case 4:
            { //Start of Case 4
                vector<int>vector1;
                for(int i = 0; i <= 10; i++){ //Numbers set to display from 0 to 10
                    vector1.push_back(i);
                }

                cout<<"\nOriginal Vector: "<<endl;
                for(int i = 0; i <= 10; i++){
                    cout<<vector1[i]<<" "; //Outputs the original list from 0 to 10
                }

                cout<<"\nReversed Vector: "<<endl;
                    reverseVector(vector1);
                    for(int i = 0; i <= 10; i++){
                        cout<<vector1[i]<<" "; //Outputs the reversed list from 10 to 0
                    }
                cout<<"\n"<<endl;
                break;
            } //End of Case 4

            //Case 5 - Introducing a integer vector to check if it's a palindrome
            case 5:
            { //Start of Case 5
                vector<int>vector2;
                //Checks the number 20002 if it's a palindrome
                vector2.push_back(2);
                vector2.push_back(0);
                vector2.push_back(0);
                vector2.push_back(0);
                vector2.push_back(2);

                if(palindromeVector(vector2)){
                    cout <<"\n20002 is a palindrome\n"<<endl; //If number is a palindrome
                }
                else{
                    cout<<"\n20002 is NOT a palindrome\n"<<endl; //If number is not a palindrome
                }
                break;
            } //End of Case 5

            //Case 6 - Source Code about Pointers from Lab 2 document
            case 6:
            { //Start of Case 6
                int a = 5; //assume that a is located at 1000. a’s pointer is located at 5000
                int &b = a;
                a = 10;
                cout << &b << endl; //Prints out 1000 as &b is a reference from a
                int *c = &b;
                cout << c << endl; //Prints out 1000 because it is a pointer to b and b holds the value of a hence c is also 1000
                int **cPtrPtr = &c; 
                cout << *c << endl; //Outputs the value of 10 which is stored in a
                cout << cPtrPtr << endl; //Prints out the location of c
                int d = 20;
                int *dPtr = &d;
                int **dPtrPtr = &dPtr;
                dPtr = *cPtrPtr;
                cout << *dPtr << endl; //Prints out the same value that *cPtrPtr holds, 10
                cout << dPtrPtr << endl; //Prints out the location of d
                cout << d << endl; //Prints out 20 because d has been assigned 20

                cout<<"\n"<<endl;
                break;
            } //End of Case 6

            //Clear the Terminal/Command Prompt screen
            case 7:
                system("clear");
                break;
             
            //Exit the program
            case 0:
                cout<<"\nYou've now exited the program..."<<endl;
                return 0;

            //Catches if a user inputs a invalid number
            default:
                cout<<"\nError! Please input a number from 0 to 7!"<<endl;
                break;

        }// End of switch
     
    } //End of while loop
} //End of Main Function
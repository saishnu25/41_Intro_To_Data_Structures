/*
* 
* CSCI 41 - Introduction to Data Structures (Lab 1)
* Done By: Saishnu Ramesh Kumar (Student ID: 300758706)
*
* This is a menu based program conducted to do/solve multiple tasks.
*/

#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<ctime>
#include<fstream> //Contains the file stream objects
#include<math.h>
#include<map> //Contains the map object used for the frequency word count

using namespace std;

//Function 1 - Finding the Minimum Number
int findMin(int a[], int size){
	int temporary = a[0]; //Temporarily stores the data
	for(int i = 0; i < size; i++){
		if(temporary > a[i]){
			temporary = a[i];
		}
	}
	return temporary; //This will return the minimum value to the main function
} //End of Function 1

//Function 2 - Compute the Average in a 2D array
double computeAvg(vector<vector<int>>&v){
	double average = 0;
	int count = 0;
	for(auto&row: v){ //auto used to deduce from its initializer
		for(auto column: row){
		average += column;
		++count;
		}
	}
	return average/count; //This will return the average value to the main function

} //End of Function 2
	
//Function 3 - Determining a Leap Year
bool isLeapYear(int year){
	
	bool leapYear = false;
	if(year % 4 == 0){ //nested if statements to make sure user's inputted year is a leap year
		if(year % 100 == 0){
			if(year % 400 == 0){
				leapYear = true;
			}
		}
		else{
			leapYear = true;
		}
	}
	return leapYear; //This will return the leap year to the main function
} //End of Function 3

//Function 4 - Calculating a String Expression 
int calculate(string exp){
	bool addition = false, subtraction = false, multiplication = false, division = false;
	int index = -1;
	int result = 0;
	
	//If expression finds addition
	if(exp.find('+') != -1){
		index = exp.find('+');
		addition = true;
	}
	
	//If expression finds subtraction
	else if(exp.find('-') != -1){
		index = exp.find('-');
		subtraction = true;
	}
	
	//If expression finds multiplication
	else if(exp.find('*') != -1){
		index = exp.find('*');
		multiplication = true;
	}	
	
	//If expression finds division
	else if(exp.find('/') != -1){
		index = exp.find('/');
		division = true;
	}	
	
	else{
		return 0;
	}	
	
	int number1 = 0, number2 = 0;
	
	for(int i = 0; i < index; i++){
		number1 = ((number1 * 10) + (exp.at(i) - '0')); //Identifies first number
	}
	
	for(int i = index + 1; i < exp.size(); i++){
		number2 = ((number2 * 10) + (exp.at(i) - '0')); //Identifies second number
	}
	
	if(addition){
		result = number1 + number2; //Result for addition
	}
	else if(subtraction){
		result = number1 - number2; //Result for subtraction
	}
	else if(multiplication){
		result = number1 * number2; //Result for multiplication
	}
	else if(division){
		result = number1 / number2; //Result for division
	}
	
	return result; //This will return the result into the main function
} //End of Function 4 

//Function 5 - Getting the File Content 
void getFileContent(string filename, vector<string> &words){
	fstream file;
	file.open(filename);
	
	if(!file.is_open()){ //When file cannot be opened
		cout<<"File could not be opened"<<endl; 
		return;
	}

	char ch;
	string temporary = "";
	file.get(ch); 
	if(ch ==' ' || ch == '\n'){ //Nested if statement
		if(temporary.length() >= 1 && (temporary[0] != ' ')){
			words.push_back(temporary);
		}
		temporary = "";
	}

	else{
		temporary += ch;
	}
	
} //End of Function 5

//Function 6 - Count the Frequency of Words
void frequencyCount(vector<string>&words){
	map<string, int> dictionary; 
	
	for(const auto&word:words){
		if(dictionary.find(word) == dictionary.end()){ //If a word isn't found in the map it creates it with the 1 value
			dictionary.insert(make_pair(word,1)); //Locates similar words
		}
		else{
			dictionary[word]++; //Else moves onto next word
		}
	}
	for(const auto&i:dictionary){
		cout<<"\n"<<i.first<<" was used: "<<i.second<<" time(s)"<<endl;
	}
} //End of Function 6

//Function 7 - Remove Stopwords (which are: a, an, the , we i, they) 
void stopWordRemoval(vector<string>&words){
	for (int i = 0; i < words.size(); ++i){
		if(words[i] == "a" || words[i] == "an" || words[i] == "the" || words[i] == "we" || words[i] == "i" || words[i] == "they"){ //If statement to detect stopwords
			for (int j = i; j < words.size() - 1; ++j){
				words[j] = words[j + 1];
			}
			words.pop_back(); //Removes the element from the back of the list
			i -= 1;
		}
	}
} //End of Function 7

//Start of Main Function
int main()
{
	int loop = true; //Allows the menu to repeat itself until user decides to exit
	int choice; //The user's inputted choice of task
	
	//For a continuos menu system
	while(loop == true){
	
	//This is the Menu Prompt for the user to input a choice
	cout<<"\nWelcome to the Lab 1 Menu for CSCI 41!"<<endl;
	cout<<"Enter a number from 1 to 8, to exit press -1:"<<endl;
	cout<<"1. Finding the Minimum Number"<<endl; //DONE!
	cout<<"2. Compute the Average in a 2D array"<<endl; //DONE!
	cout<<"3. Determining a Leap Year"<<endl; //DONE!
	cout<<"4. Calculating a String Expression"<<endl;
	cout<<"5. Getting the File Content"<<endl;
	cout<<"6. Count the Frequency of Words"<<endl; //DONE!
	cout<<"7. Remove Stopwords (which are: a, an, the, we, i, they) "<<endl;
	cout<<"8. Clear Terminal/Command Prompt screen\n"<<endl; //DONE!
	cout<<"-1. Exit the Program.\n"<<endl; //DONE!
	cout<<"Enter your choice here >> "<<endl; //User enters their choice here
	cin>>choice;
	
		switch(choice){
			
			//Case 1 - Finding the Minimum Number 
			case 1:
			{ //Start of case 1 block
				
				int size;
				cout<<"Enter the size of the array >> "<<endl; //User enters array size
				cin>>size; int a[size-1];
				cout<<"Enter elements of the array >> "<<endl; //User enters elements of array
				for(int i = 0; i < size; i++){
					cin>>a[i];
				}			
				
				int minimum = findMin(a, size); //Calling from Function 1
				cout<<"\nMinimum element of array is = "<<minimum<<"\n"<<endl; //Display's minimum number

			} //End of case 1 block
				break;	
			
			//Case 2 - Computing the Average in a 2D array
			case 2:
			{ //Start of case 2 block
			
				int row = 0;
				cout<<"Enter the number of rows for array >>"<<endl; //User enters row numbers
				cin>>row; 
				vector<vector<int>> v(row,vector<int>(3,0)); //Column number is 3
				srand(time(nullptr)); //Randomized numbers will be entered by the program
				for(int i = 0; i < v.size(); i++){
					for(int j = 0; j < v[i].size(); j++){
						v[i][j] = rand()%100 + 1;
					}
				}

				cout<<"\nThe average of the 2D array is: "<<computeAvg(v)<<endl; //Displays the average
			}//End of case 2 block
				break;
		    
			//Case 3 - Determining a leap year
			case 3:
			{ //Start of case 3 block
				
				int year;
				cout<<"Enter year >> "<<endl; //User enters year
				cin>>year;
				
				bool flag = isLeapYear(year); 
				if(flag == true){ //If year is true
					cout<<"\n"<<year<<" is a leap year"<<endl;
				}
				else{ //If year is false
					cout<<"\n"<<year<<" is NOT a leap year"<<endl;
				}

			} //End of case 3 block
				break;

			//Case 4 - Calculating a String Expression 
			case 4:
			{ //Start of case 4 block

				cout << "\n6799 + 231 = " << calculate("6799 + 231") << endl;	  //Addition
				cout << "10079 - 900 = " << calculate("10079 - 900") << endl; //Subtraction
				cout << "180 * 22 = " << calculate("180 * 22") << endl;		  //Multiplication
				cout << "1500 / 15 = " << calculate("1500 / 15") << endl;	  //Division
				
			} //End of case 4 block
				break;
			
			//Case 5 - Getting the File Content 
			case 5:
			{ //Start of case 5 block
				string fileName;
				cout<<"Enter the name for your file >> "<<endl; //User enters file name
				cin>>fileName;
				vector<string> words;
				getFileContent(fileName, words); //Calls Function 5

				for(auto i:words){
					cout<<i<<endl; 
				}		

			} //End of case 5 block
				break;

			//Case 6 - Count the Frequency of Words 
			case 6:
			{ //Start of case 6 block
				int size = 0;
				cout << "Enter the number of words >> " << endl; //User enters the number of words
				cin >> size;
				vector<string> words;
				cout << "Enter each word >> " << endl; //User enters word(s)
				for (int i = 0; i < size; i++)
				{
					string word;
					cin >> word;
					words.push_back(word);
				}
				frequencyCount(words); //Calls Function 6

			} //End of case 6 block
				break;

			//Case 7  - Remove Stopwords (which are: a, an, the, we, i, they)
			case 7:
			{ //Start of case 7 block
				int size = 0;
				cout << "Enter the number of words you would like to enter >> " << endl; //User inputs number of words to enter
				cin >> size;
				vector<string> words;
				cout << "Enter your words >> " << endl; //User inputs their words
				for (int i = 0; i < size; i++)
				{
					string word;
					cin >> word; //Detects the words entered
					words.push_back(word);
				}
				stopWordRemoval(words); //Calls Function 7

			} //End of case 7 block
				break;
			
			//Case 8 - Clear the Terminal/Command Prompt screen
			case 8:
				system("clear");
				break;

			//Case -1 - Exit Case to allow the user to exit the program 
			case -1:
				cout << "\nYou have now exited the program..." << endl;
				return 0;

			//Default case - To request the user to input a valid number 
			default:
				cout<<"\nError! Please enter a number between 1 to 8, to exit press -1."<<endl;
				break;		
		}
		
	}
	return 0; //System exit
} //End of Main Function
/*
*
*   CSCI 41 - Introduction to Data Structures (Lab 6)
*   Done By: Saishnu Ramesh Kumar (300758706)
*
*/

#include <iostream>
using namespace std;

//Start of DNode Class
class DNode{

    //Public Data Members
    public:
        int data;    //Stores the item
        DNode *next; //Helps to move to the next node
        DNode *prev; //Helps to go back to the previous node
};
//End of DNode Class

//Start of DLL Class - This class will work as a Circular DLL class
class DLL{

    //Private Data Members
    private:
        DNode *front;

    //Public Data Members
    public:
        //DLL Constructor
        DLL(){
            front = NULL;
        }

        //DLL Destructor
        ~DLL(){
            delete front;
        }

    //Length Function
    int length(){

        if (front == NULL){
            cout<<"\nList is empty"<<endl;
            return 0;
        }

        //Storing the address of the first node
        DNode *temp = front;
        int count = 0;
        while (temp != NULL){
            temp = temp->next;
            count++; //Counts the elements in the list
        }
        cout<<"\n"<<endl;
        return count;
    }
    //End of Length Function

    //Start of insertToFront Function
    void insertToFront(int item){

        DNode *newNode = new DNode(); //Creating a new node

        if (front == NULL){ //Traverses list in one direction

            newNode->data = item;
            newNode->prev = NULL;
            newNode->next = NULL;
            front = newNode;
        }

        else{ //Traverses list in the other direction
            newNode->data = item;
            newNode->next = front;
            newNode->prev = NULL;
            front->prev = newNode;
            front = newNode;
        }
    }
    //End of insertToFront Function

    //Start of deleteFromFront Function
    void deleteFromFront(){

        if (front == NULL){
            cout<<"\nList is empty"<<endl;
            return;
        }

        DNode *remove = front;
        cout<<"\nDeleted data"<<front->data;
        front = front->next;
        front->prev = NULL;
        delete remove;
    }
    //End of deleteFromFront Function

    //Start of printAll Function
    void printAll(){

        if (front == NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        cout<<"\nValues of DLL:"<<endl;
        //Traverses and prints out all inputted nodes
        DNode *temp = front;
        while (temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<"\n"<<endl;
    }
    //End of printAll Function

    //Start of deleteLast Function
    void deleteLast(){ 

        DNode *temp = front; //Stores the front address into *temp
        if (front == NULL){
            cout<<"\nList is empty"<<endl;
        }

        else if (front->next == NULL){
            cout<<"\nDeleted Node: "<<front->data;
            delete temp;
            front = NULL;
        }

        else{
            while (temp->next != NULL){
                temp = temp->next;
            }
        }

        //Delinking the last node from the second last node
        cout<<"\nDeleted data: "<<temp->data;
        temp->prev->next = NULL;
        temp->prev = NULL;
        delete temp; //Deleting the last node
    }
    //End of deleteLast Function

    //Start of insertToMiddle Function
    void insertToMiddle(int position, int item){

        if (front == NULL){
            cout<<"\nList is empty, data can't be stored in the middle"<<endl;
            return;
        }

        DNode *temp = front;
        DNode *newNode = new DNode();
        newNode->data = item;

        for (int i = 1; i < position - 1; i++){
            temp = temp->next;
        }

        if (temp == NULL){
            cout<<"Not enough data in the list"<<endl;
            return;
        }

        //Traverses the list to add the new middle node
        newNode->prev = temp;
        newNode->next = temp->next;
        newNode->next->prev = newNode;
        temp->next = newNode;
    }
    //End of insertToMiddle Function

    //Start of deleteMiddle Function
    void deleteMiddle(int position){

        if (front == NULL){
            cout << "\nList is empty" << endl;
            return;
        }

        DNode *temp = front;
        if (temp->next == NULL){ //If the list contains only one element, next will return NULL
            delete temp;
            front = NULL;
            return;
        }

        //If the list contains more than one element
        for (int i = 1; i < position - 1; i++){
            temp = temp->next;
        }

        DNode *remove = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete remove;
    }
    //End of deleteMiddle Function

    //Start of deleteLastNode Function
    void deleteLastNode(){

        DNode *temp = front;
        if (front == NULL){
            cout << "\nList is empty" << endl;
        }

        else if (front->next == NULL){
            cout << "\nDeleted Node: " << front->data;
            delete temp;
            front = NULL;
        }

        else{
            while (temp->next != NULL){
                temp = temp->next;
            }
        }

        //Delinking the last node from the second last node
        cout << "\nDeleted data: " << temp->data;
        temp->prev->next = NULL;
        temp->prev = NULL;
        delete temp; //Deleting temp
    }
    //End of deleteLastNode Function

    //Start of insertInOrder Function
    void insertInOrder(int item){

        // If item is smaller than first element insert to front or list is empty
        if (front == NULL || item < front->data){
            this->insertToFront(item);
            return;
        }

        DNode *temp = front;

        int counter = 0;

        while (temp->next != NULL){
            if (item < temp->next->data){

                DNode *newNode = new DNode();
                newNode->data = item;
                newNode->next = temp->next;
                newNode->prev = temp;

                temp->next->prev = newNode;
                temp->next = newNode;
                break;
            }

            temp = temp->next;
        }

        // If item is largest then insert to back
        if (temp->next == NULL){
            DNode *lastNode = new DNode();
            lastNode->data = item;
            lastNode->next = NULL;
            lastNode->prev = temp;

            temp->next = lastNode;
        }

        temp = NULL;
        free(temp);

        return;
    }
    //End of insertInOrder Function

    //Start of removeOneTargetNode Function
    void removeOneTargetNode(DNode *head, int target){

        if (head == NULL){ //If list is empty, nothing can be deleted
            return;
        }

        DNode *temp = head;
        if (temp->data == target){ //To delete the node
            head = temp->next; //Head will point to the next node
            free(temp);
        }

        while (temp->next != NULL && temp->next->data != target){ //Locating the first target element
            temp = temp->next;
        }

        if (temp->next->data == target){ //First target element is found

            DNode *newTemp = temp->next; //Storing the address of the target node
            temp->next = temp->next->next;
            delete (newTemp);
        }
    }
    //End of removeOneTargetNode Function
    //To include for when traversing thru prev 
    //temp->next = temp->next->next
    //temp->next->prev = temp;

    //Start of removeAllTargetNodes Function
    void removeAllTargetNodes(DNode *head, int target){

        if (head == NULL){
            return;
        }
        DNode *temp = head;
        while (temp != NULL){ //Used to delete multiple target values

            temp = head;
            while (temp != NULL && temp->data != target){ //Checking at least one target element exists
                temp = temp->next;
            }

            if (temp != NULL && temp->data == target){ //A target element exists
                removeOneTargetNode(head, target); //Using the function above to help with the deletion
            }
        }
    }
    //End of removeAllTargetNodes Function

    //Start of isDuplicate Function
    bool isDuplicate(){

        DNode *temp = front;
        DNode *temp2 = NULL;

        while (temp != NULL){

            temp2 = temp->next;

            while (temp2 != NULL){
                if (temp->data == temp2->data){

                    temp = temp2 = NULL;
                    free(temp);
                    free(temp2);
                    return true; //If duplicates found, return true
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        free(temp);
        free(temp2);
        return false; //If no duplicate nodes are found return false
    }
    //End of isDuplicate Function
};
//End of DLL Class

//Start of Main Function
int main()
{

    DNode *head = NULL;

    int loop = 1, choice, item, target, position;

    DLL link = DLL();

    while (loop = 1)
    {
        //Menu to allow user to decide what they would like to do
        cout << "\n1. Enter 1 to insertToFront" << endl;
        cout << "2. Enter 2 to deleteFromFront" << endl;
        cout << "3. Enter 3 to printAll" << endl;
        cout << "4. Enter 4 to deleteLast" << endl;
        cout << "5. Enter 5 to insertToMiddle" << endl;
        cout << "6. Enter 6 to deleteMiddle" << endl;
        cout << "7. Enter 7 to deleteLastNode" << endl;
        cout << "8. Enter 8 to insertInOrder" << endl;
        cout << "9. Enter 9 to isDuplicate" << endl;
        cout << "10. Enter 10 to removeONeTargetNode" << endl;
        cout << "11. Enter 11 to removeAllTargetNodes" << endl;
        cout << "0. Press 0 to exit the program" << endl;
        cout << "\nEnter choice: " << endl;
        cin >> choice;

        //User's choice will go to each respective case listed below
        switch (choice){

        //insertToFront Function
        case 1:
            cout << "Insert nodes to the front: " << endl;
            cin >> item;
            link.insertToFront(item);
            break;

        //deleteFromFront Function
        case 2:
            link.deleteFromFront();
            break;

        //printAll Function
        case 3:
            cout << "List of all nodes: " << endl;
            link.printAll();
            break;

        //deleteLast Function
        case 4:
            link.deleteLast();
            break;

        //insertToMiddle Function
        case 5:
            cout << "Insert nodes to the middle: " << endl;
            cin >> item;
            link.insertToMiddle(position, item);
            break;

        //deleteMiddle Function
        case 6:
            link.deleteMiddle(position);
            break;

        //deleteLastNode Function
        case 7:
            link.deleteLastNode();
            break;

        //insertInOrder Function
        case 8:
            cout << "Enter item to insert: " << endl;
            cin >> item;
            link.insertInOrder(item);
            break;

        //isDuplicate Function
        case 9:
            if (link.isDuplicate()){
                cout << "Duplicates are present!" << endl;
            }

            else{
                cout << "No duplicates present!" << endl;
            }
            break;

        //removeOneTargetNode Function
        case 10:
            link.removeOneTargetNode(head, target);
            break;

        //removeAllTargetNodes Function
        case 11:
            link.removeAllTargetNodes(head, target);
            break;

        //Exit Statement
        case 0:
            exit(0);

        //Default Case
        default:
            cout <<"Error! Please enter a number from 0 to 11..."<<endl;

        } //End of switch statement
    } //End of while loop

    return 0;
}
//End of Main Function
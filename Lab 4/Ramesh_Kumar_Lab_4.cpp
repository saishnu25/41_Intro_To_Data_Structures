/*
*
*   CSCI 41 - Intro to Data Structures (Lab 4)
*   Done By: Saishnu Ramesh Kumar (300758706)
*
*/

#include<iostream>

using namespace std;

//Start of Node Class 
class Node{

    //Public data members
    public:
        int data;
        Node *next;

        //Node Constructor
        Node(int data1){

            data = data1;
            next = NULL;
        }

}; //End of Node Class

//Start of Print List Function
void print(Node *head){

    while(head != NULL){ //To put a space in between each number on the list
        cout<<head-> data<<" ";
        head = head-> next;
    }

    cout<<endl;
} //End of Print List Function

//Start of SLL Class
class SLL{

    private:
        Node *front; //Front private data member

    public:
        //SLL constructor
        SLL(){ 

            front = NULL;
        }

        //SLL destructor
        ~SLL(){ 

            delete front;
        }

        //Calculate The Length Function
        int length(){ 
            
            int len = 0;
            Node *head = front;
            while(head){

                len++;
                head = head-> next; //Checks the length according to the number of nodes in the program
            }

            return 1;
        }

        //Insert To Front Function
        void insertToFront(int data){ 

            //Inserts the front node
            Node *n = new Node(data);
            n-> next = front;
            front = n; 

        }

        //Insert At Last Function
        void insertAtLast(int data){

            //Inserts the node at the end
            Node *n = new Node(data);
            Node *temporary = front;
            if(temporary == NULL){

                front = n; //n stores the first node value into front
            }

            else{
                //Otherwise will proceed along the list
                while(temporary-> next != NULL){
                    temporary = temporary-> next;
                }
                temporary-> next = n;
            }
        }

        //Delete From Front Function
        void deleteFromFront(){

            if(front != NULL){ //If node is not equal to NULL
 
                front = front-> next; //Deletes the front node
            }
        }

        //Print All Function
        void printAll(){

            Node *head = front;
            while(head != NULL){ //While the head is not equal to NULL

                cout<<head-> data<<" "; //Adds the space between each number
                head = head-> next; //Helps print out the nodes
            }

            cout<<endl;
        }

        //Delete Last Function
        void deleteLast(){

            if(!front){ //If node is not front, return
                return;
            }

            //Deletes the last node
            Node *temporary = front;
            while((temporary-> next)-> next != NULL){
                temporary = temporary-> next;
            }

            temporary-> next = NULL;
        }

        //Insert To Middle Function
        void insertToMiddle(int position, int data){

            Node *n = new Node(data);
            Node *temporary = front;

            if(position = 0){

                insertToFront(data); //If the position is at 0, insert to the front 
            }
            else if(position > length()){

                insertAtLast(data); //If the position is greater than the length, insert to the end
            }

            else{
                
                //Inserts the middle node
                while(position-1){ 
                    temporary = temporary-> next;
                    position--;
                }

                n-> next = temporary-> next;
                temporary-> next = n;
            }
        }

        //Delete Front Node Function
        void deleteFront(){

            if(!front){ //If node is not front, return
                return;
            }

            front = front-> next; //Deletes the front node
        }

        //Delete End Node Function
        void deleteEnd(){

            if(!front){ //If node is not front, return
                return;
            }

            //Deletes the end
            Node *temporary = front; 
            while((temporary-> next)-> next != NULL){
                temporary = temporary-> next;
            }

            temporary-> next = NULL;
        }

        //Delete Middle Node Function
        void deleteMiddle(int position){

            Node *temporary = front;
            if(position = 0){

                deleteFront(); //If position equals 0, deletes the front node 
            }

            else if(position > length()){

                deleteEnd(); //If position is greater than node length, deletes the last node
            }

            else{

                //Deletes the middle node
                while(position-1){

                    temporary = temporary-> next;
                    position--;
                }

                temporary-> next = (temporary-> next)-> next;
            }
        } 
}; //End of SLL Class

//Start of Main Function
int main(){

    int nodeTracker = 0; //Helps tracker the number of nodes in the program

    Node *head = NULL;

    //Creating 5 nodes
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    //Tracker shows 5 nodes
    nodeTracker = 5;

    //Connecting each node together
    head = node1;
    node1-> next = node2;
    node2-> next = node3;
    node3-> next = node4;
    node4-> next = node5;

    //Inserting a node in front of the first node
    Node *frontNode = new Node(25);
    frontNode-> next = head;
    head = frontNode;

    //Tracker shows 6 nodes
    nodeTracker = 6; 

    //Inserting a node in the middle
    Node *middleNode = new Node(70);
    middleNode-> next = node3;
    node2-> next = middleNode;

    //Tracker shows 7 nodes
    nodeTracker = 7; 

    //Printing all nodes
    cout<<"\nList of all nodes: "<<endl;
    print(head);

    //Deleting the last node
    node4-> next = NULL;

    //Tracker goes back to 6 nodes
    nodeTracker--;

    //Deleting the middle node
    node2-> next = node3;

    //Tracker goes back to 5 nodes
    nodeTracker--;

    //Deleting the nodes from the beginning
    head = head-> next;

    cout<<"End Outcome (after deleting the front, middle and end nodes): "<<endl;
    print(head);

    delete head; //Deletes all remaining nodes

    //Tracker will show that all nodes have been terminated
    nodeTracker = 0;

    cout<<"\nAll nodes deleted, remaining nodes: "<<nodeTracker<<endl;
    
    return 0;

} //End of Main Function
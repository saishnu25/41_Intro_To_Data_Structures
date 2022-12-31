/*
*
*   CSCI 41 - Intro to Data Structures (Lab 5)
*   Done By: Saishnu Ramesh Kumar (300758706)
*
*/

#include<iostream>
using namespace std;

//Start of Node Class
class Node
{

    //Public data members
    public:
        int data;
        Node *next;

}; //End of Node Class

//Start of Print List Function
void print(Node **head)
{

    Node *temp = *head;
    while (temp != NULL)
    {
        cout<<temp->data << "  ";
        temp = temp->next;
    }
    cout<<endl;
} //End of Print List Function

//Start of SLL class
class SLL
{
    
    public:
        //Start of InsertFront Function
        void InsertFront(Node **head, int key)
        {
            Node *newNode = new Node(); //Creating a new node
            newNode-> data = key;
            newNode-> next = *head;
            *head = newNode; //Head will become the created node now
        } //End of InsertFront Function

        //Start of DeleteFront Function
        void DeleteFront(Node **head)
        {
            if(*head == NULL)
            {
                return;
            }

            Node *temp = *head;
            *head = temp-> next; //Head points to the next node on the list
            free(temp); //Deletes the previous head node
        } //End of DeleteFront Function

        //Start of DeleteLast Function
        void DeleteLast(Node **head)
        {
            Node *temp = *head;
            if(temp == NULL) //List is already empty 
            {
                return;
            }

            else if(temp-> next == NULL) //List will contain only one node
            {
                free(temp); //Delete the node
                *head = NULL;
            }

            else
            {
                while(temp-> next-> next != NULL) //Reaches the second last node
                {
                    temp = temp-> next;
                }
                free(temp-> next); //Delete the node
                temp-> next = NULL; //Turning the new last node to point to NULL
            }
        } //End of DeleteLast Function

        
        //Start of InsertInOrder Function
        void InsertInOrder(Node **head, int key)
        {
            Node *newNode = new Node();
            newNode-> data = key;
            Node *temp = *head;
            if(*head == NULL)
            {
                *head = newNode;
                newNode-> next = NULL;
            }

            else if(temp-> data >= key) //Key is the least element, so it will be inserted as the head
            {
                *head = newNode;
                newNode-> next = temp-> next;
            }

            else
            {
                while(temp-> next != NULL && temp-> data <= key) //Key is greater than the current node
                {
                    temp = temp-> next;
                }

                if (temp-> next == NULL && temp-> data < key) //Inserting the node at the end, key is the maximum
                {
                    temp-> next = newNode;
                    newNode-> next = NULL;
                }
                
                else //Need to insert before temp node, so this will traverse the list once again
                {
                    Node *newTemp = *head;
                    while(newTemp-> next != temp)
                    {
                        newTemp = newTemp-> next;
                    }
                    newTemp-> next = newNode;
                    newNode-> next = temp; //newNode is inserted in the right position
                }
            }
        } //End of InsertInOrder Function


        //Start of removeOneTargetNode Function
        void removeOneTargetNode(Node **head, int target)
        {
            if(*head == NULL){ //If list is empty, nothing can be deleted
                return;
            }

            Node *temp = *head;
            if(temp-> data == target) //To delete the node
            {
                *head = temp-> next; //Head will point to the next node
                free(temp);
            }

            while(temp-> next != NULL && temp-> next-> data != target) //Locating the first target element
            {
                temp = temp-> next;
            }
            
            if(temp->next-> data == target) //First target element is found
            {
                Node *newTemp = temp-> next; //Storing the address of the target node
                temp-> next = temp-> next-> next; //The node previous to target node points to the node that's next to the target node
                delete(newTemp);
            }
        } //End of removeOneTargetNode Function

        //Start of removeAllTargetNodes Function
        void removeAllTargetNodes(Node **head, int target)
        {
            if(*head == NULL)
            {
                return;
            }
            Node *temp = *head;
            while(temp != NULL) //Used to delete multiple target values
            {
                temp = *head;
                while(temp != NULL  && temp-> data != target) //checking at least one target element exists
                { 
                    temp = temp-> next;
                }

                if(temp != NULL && temp-> data == target) //A target element exists
                {
                    removeOneTargetNode(head, target); //Using the function above to help with the deletion
                }
            }
        } //End of removeAllTargetNodes Function

        //Start of isDuplicate Function
        bool isDuplicate(Node ** head)
        {
            Node *temp = *head;
            while(temp-> next != NULL)
            {
                //Starts from the next node
                Node *ptr = temp-> next;
                while(ptr != NULL)
                {
                    //If duplicate nodes are found
                    if(temp-> data == ptr-> data)
                    {
                        return true;
                    }

                    ptr = ptr-> next;
                }

                temp = temp-> next; //Checks if duplicate value exists for the next node
            }

            return false; //If no duplicate nodes are found return false
        } //End of isDuplicate Function

}; //End of SLL Class

//Main Function
int main(){

    SLL linkedClass = SLL(); //Creating an instance for the class 
    Node *head = NULL;

    //Outputs the inputted nodes
    cout<<"After InsertFront Function: "<<endl;
    linkedClass.InsertFront(&head, 3);
    linkedClass.InsertFront(&head, 1);
    print(&head);
    cout<<"\n"<<endl; 

    //Outputs the nodes in ascending order
    cout<<"After InsertInOrder Function: "<<endl;
    linkedClass.InsertInOrder(&head, 2);
    linkedClass.InsertInOrder(&head, 2);
    linkedClass.InsertInOrder(&head, 3);
    print(&head);
    cout<<"\n"<<endl;

    //Checks if there are duplicates
    cout<<"After isDuplicate Function: "<<endl;
    if(linkedClass.isDuplicate(&head))
    {
        cout<<"Duplicates are present in this node list"<<endl;
    }

    else
    {
        cout<<"No duplicates were present"<<endl;
    }
    cout<<"\n"<<endl;

    //Removes one target nodes
    cout<<"After removeOneTargetNode Function: "<<endl;
    linkedClass.removeOneTargetNode(&head, 3);
    print(&head);
    cout<<"\n"<<endl;

    //Removes all the target nodes
    cout<<"After removeAllTargetNodes Function: "<<endl;
    linkedClass.removeAllTargetNodes(&head, 2);
    print(&head);
    cout<<"\n"<<endl;

    cout<<"End of Program..."<<endl;
    
    return 0;
    
} //End of Main Function
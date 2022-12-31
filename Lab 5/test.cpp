#include <iostream>
using namespace std;
// defining the node class
class Node
{
public:
    int data;   //data part of the node
    Node *next; //to store address of the next node
};

class SLL{
    public:
    void InsertFront(Node **head, int key)
    {
        Node *new_node = new Node(); //creating a new node
        new_node->data = key;        //writing the value of key in the node
        new_node->next = *head;
        *head = new_node; //now head is the created node
    }
    void DeleteFront(Node **head)
    {
        if (*head == NULL) // if list is empty we can't delete anything
            return;
        Node *temp = *head;
        *head = temp->next; // head now pointing to the next node
        free(temp);         // deleting the previous head node
    }
    void DeleteLast(Node **head)
    {
        Node *temp = *head;
        if (temp == NULL) //list is already empty
            return;
        if (temp->next == NULL) //list contains only one node
        {
            free(temp); //deleting the node
            *head = NULL;
        }
        else
        {
            while (temp->next->next != NULL) //reaching to the second last node
                temp = temp->next;
            free(temp->next);  //deleting the last node
            temp->next = NULL; //making the second last node(now the last node) to point to NULL
        }
    }
    void InsertInOrder(Node **head, int key)
    {
        Node *new_node = new Node(); //creating a new node
        new_node->data = key;        //writing the value of key in the node
        Node *temp = *head;
        if (*head == NULL) //list is empty
        {
            *head = new_node;
            new_node->next = NULL;
        }
        else if (temp->data >= key) //the key is the least element,so it has to be inserted at the head
        {
            *head = new_node;
            new_node->next = temp->next;
        }
        else
        {
            while (temp->next != NULL && temp->data <= key) //key is greater than the current node
                temp = temp->next;
            if (temp->next == NULL && temp->data < key) //we have to insert the node at the end(the key is the maximum among all)
            {
                temp->next = new_node;
                new_node->next = NULL;
            }
            else //now we have to insert before temp node so we have travese the list again
            {
                Node *new_temp = *head;
                while (new_temp->next != temp)
                    new_temp = new_temp->next;
                new_temp->next = new_node;
                new_node->next = temp; //new_node is inserted at the right position
            }
        }
    }
    void removeOneTargetNode(Node **head, int target)
    {
        if (*head == NULL) // if list is empty we can't delete anything
            return;
        Node *temp = *head;
        if (temp->data == target) // now we have to delete the head node
        {
            *head = temp->next; // head now pointing to the next node
            free(temp);         // deleting the previous head node
        }
        while (temp->next != NULL && temp->next->data != target) //finding the first target element
            temp = temp->next;
        if (temp->next->data == target) //first target element found
        {
            Node *new_temp = temp->next;   //storing the address of the target node
            temp->next = temp->next->next; //the node previous to target node now points to the node next to target node
            delete (new_temp);             //deleting the target node
        }
    }
    void removeAllTargetNodes(Node **head, int target)
    {
        if (*head == NULL) // if list is empty we can't delete anything
            return;
        Node *temp = *head;
        while (temp != NULL) //this while loop is used to delete multiple target values
        {
            temp = *head;
            while (temp != NULL && temp->data != target) //checking if there exists atleast one target element
            {
                temp = temp->next;
            }
            if (temp != NULL && temp->data == target) //there exist a target element
                removeOneTargetNode(head, target);    //using the above created function we delete one target element
        }
    }
    bool isduplicate(Node **head)
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            // Starting from the next node
            Node *ptr = temp->next;
            while (ptr != NULL)
            {

                // If some duplicate node is found
                if (temp->data == ptr->data)
                {
                    return true;
                }
                ptr = ptr->next;
            }

            temp = temp->next; //checking if the duplicate value exists for the next node
        }

        // If we reach here this means there is no duplicate node.
        return false;
    }
};

void print(Node **head)
{
    Node *temp = *head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    SLL linkedClass =  SLL(); //Creating an instance (object) of the class
    Node *head = NULL;
    
    linkedClass.InsertFront(&head, 3);   //inserting 3 at head //using linkedClass. to call them from the SLL class
    linkedClass.InsertFront(&head, 1);   //inserting 1 at head or beginning
    print(&head);            //printing the list
    linkedClass.InsertInOrder(&head, 2); //insert 2 in order
    print(&head);
    linkedClass.InsertInOrder(&head, 2);
    print(&head);
    linkedClass.InsertInOrder(&head, 3);
    print(&head);
    if (linkedClass.isduplicate(&head)) //checking if duplicate elements exists
        cout << "Duplicates are present" << endl;
    else
        cout << "No Duplicates present" << endl;
    linkedClass.removeOneTargetNode(&head, 2); // removing one node which has 2 as value
    print(&head);
    linkedClass.removeAllTargetNodes(&head, 3); //removing all nodes which have 3 as value
    print(&head);
}
/*
*   
*   CSCI 41 - Introduction to Data Structures (Lab 11)
*   Done By: Saishnu Ramesh Kumar (300758706)
*
*/

#include <bits/stdc++.h>

using namespace std;

//Creating a class template to help store the data, left and right children
template <class T>

//Node Class
class Node{
    public:
        T data;
        Node *left;
        Node *right;

        Node(T data1){ //Constructor to initialize data, left and right
            data = data1;
            left = NULL;
            right = NULL;
        }
};

//Creating a class template for Binary Tree
template <class T>

//Binary Tree Class
class BinaryTree{

    public:
        //Build Tree Function
        Node<T> *buildTree(){
            T x; //Input x if x is NULL and that means there is no node otherwise there is a node with the data x
            cout<<"\nEnter data (enter 0 if no data): "<<endl;
            cin>>x;

            if(x == 0){
                return NULL;
            }

            Node<T> *p = new Node<T>(x);

            cout<<"Enter left child: \n"<<x;
            p->left = buildTree(); //Recursion used for left child
            
            cout<<"Enter right child: \n"<<x;
            p->right = buildTree(); //Recursion used for right child

            return p;
        }

        //Count Leaf Function
        int countLeaf(Node<T> *root){

            if(!root){
                return 0;
            }

            //Recursion to count both left and right subtrees
            int left = countLeaf(root->left);
            int right = countLeaf(root->right);

            if(!root->left && !root->right){ //If the root is leaf node, return 1 + left + right
                return 1 + left + right;
            }

            return left + right; //Otherwise return left + right
        }

        //Size of Binary Tree Function
        int sizeOfBT(Node<T> *root){

            if(root){
                
                //Recursion to count both subtrees of the nodes' size
                int left = sizeOfBT(root->left);
                int right = sizeOfBT(root->right);

                return left + right + 1;
            }

            return 0;
        }

        //Level Order Scan Function
        void levelOrderScan(Node<T> *root){
            queue<Node<T> *> q;

            if(!root){
                return;
            }

            q.push(root);

            while(!q.empty()){ //Each time, taking a node out of its queue to print its data and checks both left and right

                Node<T> *temp = q.front();
                q.pop();
                cout<<temp->data<<" ";

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }
        }

        //Depth Function
        int depth(Node<T> *root){
            if(root == NULL){
                return 0;
            }

            else{

                //Finding the depth of both subtrees
                int left = depth(root->left);
                int right = depth(root->right);

                //If left is greater, return the max of the left
                if(left > right){
                    return (left + 1);
                }

                //Otherwise, return the right + 1 for the node
                else{
                    return (right + 1);
                }
            }
        }

        //Lookup Function
        bool lookup(int data1, Node<T> *root){

            //If is not the root, return false
            if(!root){
                return false;
            }

            //If found return true
            if(root->data == data1){
                return true;
            }

            //Otherwise search both left and right of the tree
            bool left = lookup(data1, root->left);
            return left;

            bool right = lookup(data1, root->right);
            return right;
        }

};

//Main Function
int main(){
    
    BinaryTree<int> BT; //Creating an object of type binaryTree
    Node<int> *root = BT.buildTree();
    int choice;
    while(true){

        cout<<"Enter a number below to get started "<<endl;
        cout<<"1. Count the leaf nodes "<<endl;
        cout<<"2. Find the depth of the tree "<<endl;
        cout<<"3. Level Order Scan of the tree "<<endl;
        cout<<"4. Lookup an element "<<endl;
        cout<<"5. Find the size of the tree "<<endl;
        cout<<"6. Exit Program "<<endl;
        cout<<"\n";

        cin>>choice; //User enters their choice

        switch(choice){

            //Case 1 - Calls Count Leaf Function
            case 1:
            cout<< BT.countLeaf(root)<<endl;
            break;

            //Case 2 - Calls the Depth Function
            case 2:
            cout<< BT.depth(root)<<endl;
            break;

            //Case 3 - Calls Level Order Scan Function
            case 3:
            BT.levelOrderScan(root);
            break;
            
            //Case 4 - Calls Lookup Function
            case 4:
            cout<<"Enter elements you would like to find\n"<<endl;
            int data1;
            cin>>data1;

            if(BT.lookup(data1, root)){ //If the element entered exists
                cout<<"Yes, the element does exists!"<<endl;
            }

            else{ //Otherwise if the element entered doesn't exist
                cout<<"No, the element does NOT exist!"<<endl;
            }
            break;

            //Case 5 - Calls Size of BT Function
            case 5:
            cout<< BT.sizeOfBT(root)<<endl;
            break;

            //Case 6 - Exits the program
            case 6:
            cout<<"You've exited the program"<<endl;
            return 0;
            break;
        }

    }
    return 0;
}
#include <iostream>

using namespace std;

//Node Class
class Node{

    //Public data members
    public:
        char data;
        Node *left;
        Node *right;
        Node *parent;
    
};

//BST Class
class BST{

    //Private data members
    private:
        BST *root;

    //Public data members
    public:

        //BST Constructor
        BST(){
            root = NULL;
        }

        //Calling all the functions used into the BST class
        Node *createNode(char);

        Node *put(Node *, char);

        Node *get(Node *, char);

        bool isBST(Node *, Node *, Node *);

        void inOrder(Node *);

        Node *deleteNode(Node *, char);

};

//Create Node Function
Node *BST:: createNode(char item){

    Node *temp = new Node;

    temp->data = item;

    temp->left = temp->right = NULL; //Both sides equal NULL

    temp->parent = NULL; //Parent node equals NULL

    return temp;
}

//Put Function
Node *BST:: put(Node *root, char key){

    //If the tree is empty, return new Node
    if(root == NULL){
        return createNode(key);
    }

    //For left subtree
    if(key < root->data){

        Node *leftChild = put(root->left, key);

        root->left = leftChild;

        //Setting the parent root of the left subtree
        leftChild->parent = root;
    }

    //For right subtree
    else if(key > root->data){

        Node *rightChild = put(root->right, key);

        root->right = rightChild;

        //Setting the parent root of the right subtree
        rightChild->parent = root;
    }

    return root;
}

//Get Function
Node *BST:: get(Node *root, char key){

    //If the root is NULL or the key is at the root, return root
    if(root == NULL || root->data == key){
        return root;
    }

    //If key is greater than the root key
    if(root->data < key){

        return get(root->right, key);
    }

    //Otherwise if key is smaller than root key
    return get(root->left, key);

}

//isBST Function
bool BST:: isBST(Node *root, Node *left = NULL, Node *right = NULL){

    //If the root is NULL, return true
    if(root == NULL){
        return true;
    }

    //If left node exists, then check for the correct data and if it's less than the root's data
    if(left != NULL && root->data <= left->data){
        return false;
    }

    //If right node exists, then check for the correct data and if it's greater than the root's data
    if(right != NULL && root->data >= right->data){
        return false;
    }

    //Using recursion, check each node
    return (isBST(root->left, left, root) && isBST(root->right, root, right));

}

//inOrder Function
void BST:: inOrder(Node *root){

    if(root != NULL){

        inOrder(root->left);

        //Outputs the list of nodes
        cout<<"Node = "<<root->data<<" , ";

        //If parent node is NULL
        if(root->parent == NULL){

            cout<<"Parent Node = NULL"<<endl;
        }

        //Otherwise output the list of parent nodes
        else{
            cout<<"Parent Node = "<<root->parent->data<<endl;
        }

        //Recursion to call function within itself
        inOrder(root->right);
    }
}

//deleteNode Function
Node *BST:: deleteNode(Node *root, char k){

    //If the root is NULL, return the root
    if(root == NULL){
        return root;
    }

    //For left nodes to get deleted
    if(root->data > k){

        root->left = deleteNode(root->left, k);

        return root;
    }

    //For right nodes to get deleted
    else if(root->data < k){

        root->right =deleteNode(root->right, k);

        return root;
    }

    if(root->left == NULL){

        Node *temp = root->right;

        delete root;
        return temp;
    }

    else if(root->right == NULL){
        Node *temp = root->left;

        delete root;
        return temp;
    }

    else{

        Node *succParent = root;

        //Find the successor
        Node *succ = root->right;

        while(succ->left != NULL){

            succParent = succ;
            succ = succ->left;
        }

        //If there's no successor, assign the right to the left
        if(succParent != root){
            succParent->left = succ->right;
        }

        else{
            succParent->right = succ->right;
        }

        //Copying the successor data to the root
        root->data = succ->data;

        //Deleting the successor and returns the root
        delete succ;

        return root;

    }
}

//Main Function
int main(){

    BST obj;
    Node *root = NULL;

    //Inserting into put function
    root = obj.put(root, 'S');

    obj.put(root, 'E');
    
    obj.put(root, 'X');
    
    obj.put(root, 'A');
    
    obj.put(root, 'R');
    
    obj.put(root, 'C');
    
    obj.put(root, 'H');
    
    obj.put(root, 'M');

    //Retrieving the values from the BST
    obj.get(root, 'A');
    
    obj.get(root, 'Z');

    //isBST to check if function is a binary tree or not
    if(obj.isBST(root, NULL, NULL)){

        cout<<"This IS a Binary Tree\n"<<endl;
    }

    else{

        cout<<"This is NOT a Binary Tree\n"<<endl;
    }

    //Calling the inOrder Function
    obj.inOrder(root);

    //Calling the deleteNode Function
    obj.deleteNode(root, 'A');
    cout<<"\nNode = A has been deleted "<<endl; 

    cout<<"\nThis program has ended..."<<endl;
    return 0;
}
/*
*   Question 4c - Priority Queue Using Binary Tree
*   CSCI 41 - Introduction to Data Structures
*   Done By: Saishnu Ramesh Kumar (300758706)
*
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>

using namespace std;

#define NUM_ELEMENTS 10000

typedef struct tree tree_t;

//Tree struct
struct tree{
    int value;
    tree_t *left;
    tree_t *right;
    tree_t *parent;
    bool completed;
};

//Function Prototypes
void insert_into_heap(tree_t *root, int element);
int remove_from_heap(tree_t *root);
tree_t *create_new_tree(tree_t *parent, int value);
void heapify(tree_t *tree_node);
void swap(int *a, int *b);
tree_t *get_last_node(tree_t *root, int level);
int height(tree_t *root);
void printAllNodes(tree_t *root);

//Print All Nodes Function
void printAllNodes(tree_t *root){
    
    if (root != NULL){
        printAllNodes(root->left); //Prints nodes in left subtree

        cout << root->value << " ";
        printAllNodes(root->right); //Prints nodes in right subtree
    }
}

//Insert To Heap Function
void insert_into_heap(tree_t *root, int element){
    
    if (root->value == -1){
        root->value = element;
        return;
    }

    tree_t *temp = root;
    tree_t *new_node;

    //Will be inserted continously into the BST until completed
    while (true){
        
        if (temp->left == NULL && temp->right == NULL){
            
            tree_t *new_tree = create_new_tree(temp, element);
            temp->left = new_tree;
            new_node = new_tree;
            break;
        }
        
        else if (temp->left != NULL && temp->right == NULL)
        {
            tree_t *new_tree = create_new_tree(temp, element);
            temp->right = new_tree;
            new_node = new_tree;
            break;
        }
        
        else{
            
            if (temp->completed == true){   
                temp = temp->left;
            }
            
            else if (temp->completed != true && temp->left->completed == true){
                temp = temp->right;
            }
            
            else if (temp->left->completed != true){
                temp = temp->left;
            }
        }
    }

    while (temp != NULL){
        
        if (temp->left != NULL && temp->right != NULL){

            //If both of them are NOT leaf nodes
            if ((temp->left->left != NULL && temp->left->right != NULL) && (temp->right->left != NULL && temp->right->right != NULL)){
                temp->completed = (temp->left->completed && temp->right->completed);
            }

            //If both of them are leaf nodes
            else if (temp->left->left == NULL && temp->right->left == NULL){
                temp->completed = true;
            }

            //If one of them are leaf nodes
            else{
                temp->completed = false;
            }
        }

        else{
            temp->completed = false;
        }

        temp = temp->parent;
    }

    heapify(new_node); //Calls the Heapify Function
}

//Remove From Heap Function
int remove_from_heap(tree_t *root){

    if (root->left == NULL && root->right == NULL){
        int val = root->value;
        root = NULL;
        return val;
    }

    tree_t *deepest = NULL;
    int min_val = root->value;
    int level = height(root);
    deepest = get_last_node(root, level);

    //Swapping for the deepest value
    int temp = root->value;
    root->value = deepest->value;
    deepest->value = temp;

    int deepest_val = deepest->value;
    deepest = deepest->parent;

    //If the deepest left value is NULL
    if (deepest->left != NULL && deepest->left->value == deepest_val){
        deepest->left = NULL;
    }

    //If the deepest right value is NULL
    else if (deepest->right != NULL && deepest->right->value == deepest_val){
        deepest->right = NULL;
    }

    heapify(root); //Calls the Heapify Function

    return min_val;
}

//Swap Function
void swap(tree_t *node1, tree_t *node2){
    
    int temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

//Heapify Function
void heapify(tree_t *tree_node){
    
    tree_t *parent = tree_node->parent;
    int temp;

    //This will be going from the bottom to the top apporach for the Binary Tree
    if (parent != NULL){
        while (parent != NULL){
            
            int left_val = -1, right_val = -1;
            if (parent->left != NULL){
                left_val = parent->left->value;
            }
            if (parent->right != NULL){
                right_val = parent->right->value;
            }

            if (right_val != -1 && left_val != -1){
                if (left_val < right_val && left_val < parent->value){

                    temp = parent;
                    parent = parent->left;
                    parent->left = temp;
                    //swap(parent, parent->left); //Calls Swap Function 
                    free(temp);
                }
                else if (right_val < left_val && right_val < parent->value){
                
                    temp = parent;
                    parent = parent->left;
                    parent->left = temp;
                    //swap(parent, parent->right); //Calls Swap Function
                    free(temp);
                }
            }
            else if (left_val != -1){
                if (left_val < parent->value){

                    temp = parent;
                    parent = parent->left;
                    parent->left = temp;
                    //swap(parent, parent->left); //Calls Swap Function
                    free(temp);
                }
            }

            parent = parent->parent;
        }
    }

    //This will go from the top to bottom of the Bianry Tree 
    else if (parent == NULL)
    {
        tree_t *temp = tree_node;
        int count = 0;
        int temp1;
        while (temp->left != NULL || temp->right != NULL)
        {
            if (temp->left != NULL && temp->right != NULL){

                //Gets the minimum and swaps accordingly
                tree_t *min_node;
                if (temp->left->value < temp->right->value){
                    min_node = temp->left;
                }

                else if (temp->right->value < temp->left->value){
                    min_node = temp->right;
                }

                if (min_node->value < temp->value){
                    
                    temp1 = min_node;
                    min_node = temp;
                    temp = temp1;
                    //swap(min_node, temp);
                    //temp = min_node;
                    free(temp1);
                }

                else{
                    break;
                }

                count++; //Count updates
            }

            else if (temp->left != NULL){
                if (temp->left < temp){

                    temp1 = temp->left;
                    temp->left = temp;
                    temp = temp1;

                    //swap(temp->left, temp);
                    //temp = temp->left;
                    free(temp1);
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
    }
}

//Get Last Node Typedef
tree_t *get_last_node(tree_t *root, int level)
{
    tree_t *deepest;
    if (level == 1){
        deepest = root; //The deepest will become the root node
    }

    else if (level > 1){

        if (root->left != NULL){
            deepest = get_last_node(root->left, level - 1); //Checks the left
        }

        if (root->right != NULL){
            deepest = get_last_node(root->right, level - 1); //Checks the right
        }
    }

    return deepest;
}

//Height Function
int height(tree_t *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int left_height = height(root->left); //Checks height of left subtree
    int right_height = height(root->right); //Checks height of right subtree
 
    return max(left_height, right_height) + 1;
}

//Create New Tree Typedef
tree_t *create_new_tree(tree_t *parent, int value)
{
    tree_t *new_tree = new tree_t();
    new_tree->parent = parent;
    new_tree->value = value;
    new_tree->left = NULL;
    new_tree->right = NULL;
    new_tree->completed = true;
    return new_tree;
}

//Main Function
int main(int argc, char *argv[]){

    tree_t *root = new tree_t();
    root->value = -1;
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;
    root->completed = true;

    auto start_time = chrono::high_resolution_clock::now(); //Start time

    cout << "Creating " << NUM_ELEMENTS << " random numbers please wait..." << endl;
    for (int i = 0; i < NUM_ELEMENTS; i++){
        int rand_num = rand() % 100; //Generates 100 random integers
        insert_into_heap(root, rand_num);
    }

    cout << endl;
    auto end_time = chrono::high_resolution_clock::now(); //End time

    chrono::duration<double> elapsed = end_time - start_time; //Total time 

    cout<<"Output of Priority Queue Heap Sort: "<<endl;
    int size = NUM_ELEMENTS;
    for (int i = 0; i < 100; i++){
        int value = remove_from_heap(root);
        size--;
        cout << value << endl; //Outputs 100 random integers in the heap
    }

    cout << endl << "Elapsed time: " << elapsed.count() << " seconds" << endl;

    return 0;
}

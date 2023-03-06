#include <iostream>

// Define struct IntListNode, which will represent each node in the list
// Each node has two fields:
// val: to hold a value in the node
// next: to point to the next node (or to NULL)
struct IntListNode{
    int val;
    IntListNode* next;
};

int main(){
    // Define a pointer l that points to the first element of the list
    // Initially set to NULL, indicating an empty list
    IntListNode* l;
    l = NULL;

    // Define a temporary pointer tmp that will be used to create new nodes and adding them to the list
    IntListNode* tmp;

    // Create a new node, assign it a value of 2, and add it to the beginning of the list
    tmp = new IntListNode;
    (*tmp).val = 2;
    (*tmp).next = l;
    l = tmp;

    // Create another new node, assign it a value of 3, and add it to the beginning of the list
    tmp = new IntListNode;
    (*tmp).val = 3;
    (*tmp).next = l;
    l = tmp;

    // Create another new node, assign it a value of 5, and add it to the beginning of the list
    tmp = new IntListNode;
    (*tmp).val = 5;
    (*tmp).next = l;
    l = tmp;

    // Now the list l points to the node containing 5
    // which in turn points to the node containing 3
    // which in turn points to the node containing 2
    // which in turn points to NULL


    // Iterate through the list, starting from the first element
    // Print the value of each node until it reaches the end of the list (NULL)
    IntListNode* lit;
    lit = l;
    while(lit != NULL){
        std::cout << (*lit).val << std::endl;
        lit = (*lit).next;
    }

    // Deallocate the memory used by the nodes, by deleting the nodes one by one
    // Starting from the first element until the end of the list is reached
    lit = l;
    while(lit != NULL){
        tmp = (*lit).next;
        delete lit;
        lit = tmp;
    }
}
#include <iostream>

// Create an alias for the type int called "list_t"
typedef int list_t;

// Define the structure of a node in the linked list
struct ListNode{
    list_t val;   // Integer value of the node
    ListNode* next; // Pointer to the next node
};

// Function to create a new node and add it to the head of the list
ListNode* cons_list(list_t e, ListNode* l){
    ListNode* tmp;
    // Allocate memory for the new node
    tmp = new ListNode;
    // Assign the given value to the new node
    tmp->val = e;
    // Link the new node to the head of the list
    tmp->next = l;
    // Return a pointer to the new node (now the head of the list)
    return tmp;
}

// Function to print the values of all the nodes in the list
void print_list(ListNode* l){
    // Iterate through the list
    while(l != NULL){
        // Print the value of the current node
        std::cout << l->val << std::endl;
        // Move on to the next node
        l = l->next;
    }
}

// Function to deallocate the memory used by the list
void deallocate_list(ListNode* l){
    ListNode* tmp;
    // Iterate through the list
    while(l != NULL){
        // Save a pointer to the next node
        tmp = l->next;
        // Delete the current node
        delete l;
        // Move on to the next node
        l = tmp;
    }
}

int main(){
    // Create an empty linked list
    ListNode* l = NULL;
    // Add a new node with value 2 to the head of the list
    l = cons_list(2, l);
    // Add a new node with value 3 to the head of the list
    l = cons_list(3, l);
    // Print the values of the nodes in the list
    print_list(l);
    // Deallocate the memory used by the list
    deallocate_list(l);
}

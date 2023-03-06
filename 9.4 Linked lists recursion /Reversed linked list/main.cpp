#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

typedef std::string  list_t;

// using typedef we can change the type only in one line
// if we want a linked list implementation
// that works for a different type

struct ListNode{
    list_t val;
    ListNode* next;
};

ListNode* cons_list(list_t e, ListNode* l){
    ListNode* tmp;

    tmp = new ListNode;

    tmp->val = e;
    tmp->next = l;

    return tmp;

}

void print_list(ListNode* l){
    while(l != NULL){
        std::cout << l->val << std::endl;
        l = l->next;
    }
}

ListNode* reversed_copy_list(ListNode* l) {
    ListNode* tmp = NULL;
//    tmp = new ListNode;

    while(l !=NULL){
        tmp = cons_list(l->val, tmp);
//        tmp=l->next;
//        tmp->val=l->val;
        l=l->next;

    }
    // Initialize pointers for the reversed copy
    return tmp;
}



void deallocate_list(ListNode* l){
    ListNode* tmp;

    while(l != NULL){
        tmp = l->next;
        delete l;
        l = tmp;
    }
}

int length_list(ListNode* l){
    int count=0;
    while(l != NULL){
        count++;
        l=l->next;
    }
    std::cout<<"The length of the list is : "<<count<<std::endl;

}

int main(){
    ListNode* newlist;
    std::ifstream infile;

    infile.open("data.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    ListNode* l = NULL;

    std::string tmp;


    
    while(infile >> tmp){
        l = cons_list(tmp, l);
    }

    infile.close();

    newlist=reversed_copy_list(l);
    print_list(newlist);
    length_list(l);
    deallocate_list(l);


}
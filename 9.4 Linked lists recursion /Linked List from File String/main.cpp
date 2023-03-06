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
bool search_list(list_t e, ListNode* l){
    bool cond= false;
    while (l != NULL){
        if(e==l->val){
            cond=true;
        }
        l=l->next;

    }
    return cond;

}

void print_list(ListNode* l){
    while(l != NULL){
        std::cout << l->val << std::endl;
        l = l->next;
    }
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
    std::ifstream infile;

    infile.open("data.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    bool cond;
    ListNode* l = NULL;
    std::string tmp,search;
    std::cout<<"What value would you like to search the list for ?"<<std::endl;
    std::cin>>search;
    while(infile >> tmp){
        l = cons_list(tmp, l);
        cond= search_list(search,l);


    }

    infile.close();
    print_list(l);
    length_list(l);
    deallocate_list(l);

    if(cond==0){
        std::cout<<"Not present in list"<<std::endl;
    }
    else{
        std::cout<<"Present in list"<<std::endl;
    }
}
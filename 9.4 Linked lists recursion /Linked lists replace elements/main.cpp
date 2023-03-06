#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

typedef int  list_t;

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
bool replace_list(list_t e, list_t n, ListNode* l, bool all){
    int count;
    while(l!= NULL){
        if(e==l->val){
            count=count+1;

        }
        l=l->next;
    }
    if(count==1){
        all=false;
    }
    else{
        all=true;
    }
    std::cout<<"Condition is "<<count<<std::endl;

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
    bool cond,all;
    ListNode* l = NULL;

    int tmp,replace,replacement;


    std::cout<<"What value would you like to replace in the list for ?"<<std::endl;
    std::cout<<"What value would you like to replace this for ?"<<std::endl;

    std::cin>>replace>>replacement;

    while(infile >> tmp){
        l = cons_list(tmp, l);

    }

    infile.close();
    std::cout<<"Original list:"<<std::endl;
    print_list(l);
    std::cout<<"Replacing list... :"<<std::endl;
    replace_list(replace,replacement,l,all);
    length_list(l);
    deallocate_list(l);

}
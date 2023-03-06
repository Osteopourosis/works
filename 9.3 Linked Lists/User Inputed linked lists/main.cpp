#include <iostream>

struct IntListNode{
    int val ;
    IntListNode* next ;
};

int main(){
    IntListNode* l;
    l=NULL;

    IntListNode* tmp;

    int n,q,ind,flag=0;
    std::cout<<"How many numbers would you like your list to contain?"<<std::endl;
    std::cin>>n;

    for(int i=0;i<n;i++){
        std::cout<<"What number would you like to add?"<<std::endl;
        std::cin>>q;
        tmp=new IntListNode;
        tmp->val=q;
        tmp->next=l;
        l=tmp;
    }
    l = tmp;

    IntListNode* lit;
    lit = l;

    std::cout<<"What number would you like to search the linked list for?"<<std::endl;
    std::cin>>ind;



    while(lit != NULL){
        std::cout << lit->val << std::endl;
        if(lit->val==ind){
            flag=1;
        }
        lit = lit->next;
    }


    lit = l;

    while(lit != NULL){
        tmp = lit->next;
        delete lit;
        lit = tmp;
    }
    std::cout<<""<<std::endl;
    if(flag==1){
        std::cout<<"The number is in the list"<<std::endl;
    }
    else{
        std::cout<<"The number is not in the list"<<std::endl;
    }




}

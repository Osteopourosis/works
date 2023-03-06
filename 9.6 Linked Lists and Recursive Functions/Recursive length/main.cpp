#include <iostream>

typedef int list_t;

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

int length_list_rec(ListNode* l){
    int len;
    if(l==NULL){
        len=0;
    }
    if(l!=NULL){
        len=1+length_list_rec(l->next);
    }
    return len;
}

bool search_ordered_list_rec(list_t e, ListNode* l){
    bool cond;
    if(l==NULL){
        cond=false;
    }

    if(l != NULL && e>= l->val){


        if(e==l->val) {

            cond = true;
        }
        if(e!=l->val){
            std::cout<<"checking "<< l->val<<std::endl;
            cond=search_ordered_list_rec(e,l->next);
        }
    }


    return cond;

}



void print_list_rec(ListNode* l){
    if(l != NULL){
        std::cout << l->val << std::endl;
        // we print the first element
        print_list_rec(l->next);
        // then the rest of the list
    }
}

void deallocate_list_rec(ListNode* l){
    ListNode* tmp;

    if(l != NULL){
        tmp = l->next;
        delete l;
        deallocate_list_rec(tmp);
    }
}
ListNode* ordered_insertion_list(list_t e, ListNode* l){
    if(l == NULL){
        return cons_list(e, l);
    }
    else if(e < l->val){
        return cons_list(e, l);
    }
    else{
        l->next=ordered_insertion_list(e, l->next);
        return l;
    }
}

ListNode* ordered_copy_list(ListNode* l){
    ListNode* tmp;
    tmp = NULL;
    while(l!=NULL){
        tmp=ordered_insertion_list(l->val,tmp);
        l=l->next;
    }

    return tmp;


}

int main(){
    int searchval,add;
    ListNode* l = NULL;



    l = cons_list(2, l);
    l = cons_list(7, l);
    l = cons_list(10, l);
    l = cons_list(15, l);




//    std::cout<<"What value would you like to search the list for?: "<<std::endl;
//    std::cin>>searchval;
//    std::cout<<"What value would you like to add to the  list ?: "<<std::endl;
//    std::cin>>add;


    print_list_rec(l);
    l=ordered_copy_list(l);
    std::cout<<"Ordered List : "<<std::endl;
    print_list_rec(l);


    //   if(search_ordered_list_rec(searchval,l)){
    //       std::cout<<searchval<<" is in the list"<<std::endl;
    //   }

    //   else{
    //       std::cout<<searchval<<" is not in the list"<<std::endl;
    //   }

    std::cout<<"Length of List is: "<<length_list_rec(l)<<std::endl;

    deallocate_list_rec(l);

}
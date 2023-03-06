#include <iostream>
#include <cstdlib>
#include <fstream>

typedef int tree_t;

struct TreeNode{
    tree_t val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* cons_tree(tree_t e, TreeNode* l, TreeNode* r){
    TreeNode* tmp;
    tmp = new TreeNode;
    tmp->val = e;
    tmp->left = l;
    tmp->right = r;
    return tmp;
}

TreeNode* ordered_insertion_tree(tree_t e, TreeNode* t){
    if(t == NULL){
        return cons_tree(e, NULL, NULL);
    }
    else if(e < t->val){
        t->left = ordered_insertion_tree(e, t->left);
        return t;
    }
    else{
        t->right = ordered_insertion_tree(e, t->right);
        return t;
    }
}

TreeNode* min_element_tree(TreeNode* t){
    if(t == NULL){
        return NULL;
    }
    while(t->left != NULL){
        t = t->left;
    }
    return t;
}






void print_tree(TreeNode* t){
    if(t != NULL){
        print_tree(t->left);
        std::cout << t->val << std::endl;
        print_tree(t->right);
    }
}

void deallocate_tree(TreeNode* t){
    if(t != NULL){
        deallocate_tree(t->left);
        deallocate_tree(t->right);
        delete t;
    }
}

bool search_ordered_tree(tree_t e, TreeNode* t){
    if (t == NULL) {
        return false;
    }
    if (e == t->val) {
        return true;
    } else if (e < t->val) {
        std::cout << "Trying left: " << std::endl;
        return search_ordered_tree(e, t->left);
    } else {
        std::cout << "Trying right: " << std::endl;
        return search_ordered_tree(e, t->right);
    }


}
int count_occurrences_tree(tree_t e, TreeNode* t){
    int count;
    if(t == NULL){
        return 0;
    }
    else {
        if (e == t->val) {
            count++;
        }
        count += count_occurrences_tree(e, t->left);

    }
    return count;
}

int replace_tree(tree_t e, tree_t r, TreeNode* t, int n) {
    if (t == NULL) {
        return 0;
    }
    int occur = 0;
    if (t->val == e) {
        occur ++;
        t->val = r;
    }
    int left_occurrences = replace_tree(e, r, t->left, n - occur);
    int right_occurrences = replace_tree(e, r, t->right, n - occur);
    return occur + left_occurrences + right_occurrences;
}





int main(){
    TreeNode* t;
    t = NULL;
    std::ifstream infile;
    infile.open("num.txt");
    tree_t n;
    int occur,g;

    while(infile >> n){
        t=ordered_insertion_tree (n, t);
    }
    infile.close();

    print_tree(t);

    occur=count_occurrences_tree(73,t);
    g = replace_tree(73,5,t,occur);

    std::cout<<"There have been "<<g<<" replacements"<<std::endl;
    print_tree(t);


    if(search_ordered_tree(73,t)){
        std::cout<<"Present in list"<<std::endl;
    }
    else{
        std::cout<<"Not present in list"<<std::endl;
    }

    t=min_element_tree(t);

    if(t!=NULL){
        std::cout<<"Smallest element in list is :"<< t->val<<std::endl;
    }
    if(t==NULL){
        std::cout<<"Empty Tree"<<std::endl;
    }


    deallocate_tree(t);

}
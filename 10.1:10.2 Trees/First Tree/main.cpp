#include <iostream>

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

int main(){
    TreeNode* t;
    t = NULL;

    t = ordered_insertion_tree(15, t);
    t = ordered_insertion_tree(20, t);
    t = ordered_insertion_tree(6, t);
    t = ordered_insertion_tree(1, t);
    t = ordered_insertion_tree(4, t);
    t = ordered_insertion_tree(18, t);
    t = ordered_insertion_tree(9, t);

    print_tree(t);

    std::cout<<search_ordered_tree(5,t)<<std::endl;

    deallocate_tree(t);

}
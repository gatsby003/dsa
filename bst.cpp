

#include <iostream>

using namespace std;

struct node {
    int value;
    node* left;
    node* right;

    node(int val){
        value = val;

        left = NULL;
        right = NULL;
    }
};


class Btree{
public: 
    node *root;
    Btree(){
        root = NULL;
    };
    Btree(int x){
        root = new node(x);
    };
    void insert(int key, node *leaf);
    void insert(int key);
    void InOrder(node *tree);
    node* search(node* tree, int key);
    int height(node* tree);
    node* min_node(node* tree);
    void swapTree(node* tree);
};


void Btree::insert(int key, node *leaf){
    if (key < leaf->value){
        if (leaf -> left != NULL){
            insert(key, leaf -> left);
        } else {
            leaf -> left = new node(key);
        }
    }else {
        if (leaf -> right != NULL){
            insert(key, leaf -> right); 
        } else {
            leaf -> right = new node(key);
        }
    }
}

void Btree::insert(int key){
    if (root != NULL){
        insert(key, root);
    }else {
        root = new node(key);
    }
}

node* Btree::search(node* tree, int key){
    if (tree == NULL){
        return NULL;
    }

    if (tree -> value == key){
        return tree;
    }

    if (key > tree->value){
        return search(tree->right, key);
    }

    return search(tree->left, key);
}

void Btree::InOrder(node* tree){
    if (tree == NULL){
        return;
    }
    InOrder(tree->left);
    cout << tree -> value;
    InOrder(tree->right);
}

int Btree::height(node* tree){
    if (tree == NULL){
        return 1;
    }else {
        int left_height = height(tree->left);
        int right_height = height(tree->right);

        if (left_height > right_height){
            return left_height + 1;
        }else {
            return right_height + 1;
        }
    }
}

node* Btree::min_node(node* tree){

    if (tree->left == NULL){
        return tree;
    }
    return min_node(tree->left);
} 

void Btree::swapTree(node* tree){
    if (tree == NULL){
        return;
    }
    node* temp = tree -> left;
    tree->left = tree->right;
    tree->right = temp;

    swapTree(tree -> left);
    swapTree(tree -> right);



}

int main(void){
    Btree b;
    b.insert(4);
    b.insert(6);
    b.insert(5);
    b.insert(1);
    b.insert(2);
    b.insert(3);

    // search functionality
    // node* a = b.search(b.root, 5);
    // if (a == NULL){
    //     cout << "key does not exist" << " ";
    // }else {
    //     cout << "key exists" << " ";
    // }

    // traversing 

    // b.InOrder(b.root);

    // cout << "Height is : "<< b.height(b.root) << '\n';

    // cout << "Min Node is" << b.min_node(b.root)->value << '\n';


    // cout << "Before swapping" << '\n';
    // b.InOrder(b.root);

    // b.swapTree(b.root);
    
    // cout <<'\n' << "After swapping" << '\n';
    // b.InOrder(b.root);

    // cout << '\n';

};
// basic point of tbt is eliminate the need for 
// recursion and stack by using reverse pointers

#include <iostream>

using namespace std;

struct node {
    int value;
    node* left;
    node* right;
    bool lthread;
    bool rthread;

    node(int val){
        value = val;

        left = NULL;
        right = NULL;

        lthread = true;
        rthread = true;
    }
};

class TBtree{
public: 
    node *root;
    TBtree(){
        root = NULL;
    };
    void insert(int key, node *leaf);
    void insert(int key);
    node *search(int key);
};



node* insert(node* root, int key){
    node* ptr = root;
    node* par = NULL;

    while (ptr != NULL){
        if (key == ptr -> value){
            return 0;
        }

        par = ptr;

        if (key < ptr->value){
            if (ptr -> lthread == false)
                ptr = ptr -> left;
            else 
                break;
        }

        else {
            if (ptr -> rthread == false)
                ptr = ptr -> right;
            else 
                break;
        }
    }

    node *new_node = new node(key);

    if (par == NULL){
        root = new_node;
        new_node -> right = NULL;
        new_node -> left = NULL;
    }
    else if (key < par -> value){
        new_node -> left = par -> left;
        new_node -> right = par;
        par -> lthread = false;
        par -> left = new_node;
    }
    else {
        new_node -> left = par;
        new_node -> right = par -> right;
        par -> rthread = false;
        par -> right = new_node;
    }

    return root;

}

node* nextInOrder(node* tree){
    if (tree -> rthread == true){
        return tree -> right;
    }

    tree = tree -> right;

    while (tree -> lthread == false){
        tree = tree -> left;
    }
    return tree;
}

void inorder(node *root)
{
    if (root == NULL)
        printf("Tree is empty");
 
    // Reach leftmost node
    node *ptr = root;
    while (ptr -> lthread == false)
        ptr = ptr -> left;
 
    // print successors
    while (ptr != NULL)
    {
        cout << ptr -> value << '\n';
        ptr = nextInOrder(ptr);
    }
}

int main(void){
    TBtree b;
    // creating 
    b.root = insert(b.root, 20);
    b.root = insert(b.root, 10);
    b.root = insert(b.root, 30);
    b.root = insert(b.root, 5);
    b.root = insert(b.root, 16);
    b.root = insert(b.root, 17);
    b.root = insert(b.root, 14);
    b.root = insert(b.root, 13);
    b.root = insert(b.root, 2);

    inorder(b.root);

    return 0;
};
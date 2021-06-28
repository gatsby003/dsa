// basic algorithm
// 1. Push root to first stack.
// 2. Loop while first stack is not empty
//    2.1 Pop a node from first stack and push it to second stack
//    2.2 Push left and right children of the popped node to first stack
// 3. Print contents of second stack

#include <iostream>
#include <stack>

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
    node *search(int key);
    void printTree(int x);
    void PreOrder(node *root);
    void InOrder(node *root);
    void PostOrder(node *root);
    void printNonRecursive(node *root);
    void printPre(node* tree);
    node* search(node* tree, int key);
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

void Btree::printTree(int x){
    if (x == 1){
        cout << "prorder" << " ";
        PreOrder(root);
    } else if (x == 2){
        cout << "post" << " ";
        PostOrder(root);
    } else {
        cout << "inorder" << " ";
        InOrder(root);
    }
    cout << '\n';
}

void Btree::PreOrder(node* tree){
    if (tree == NULL){
        return;
    }
    cout << tree -> value ;
    PreOrder(tree->left);
    PreOrder(tree->right);
}

void Btree::PostOrder(node* tree){
    if (tree == NULL){
        return;
    }
    PostOrder(tree->left);
    PostOrder(tree->right);
    cout << tree -> value;
}

void Btree::InOrder(node* tree){
    if (tree == NULL){
        return;
    }
    InOrder(tree->left);
    cout << tree -> value;
    InOrder(tree->right);
}

void Btree::printNonRecursive(node* tree){
    // inorder
    stack<node *> s;
    node* tmp = tree;
    while (tmp != NULL || s.empty() == false){
        while (tmp != NULL){
            s.push(tmp);
            tmp = tmp->left;
        }
        tmp = s.top();
        s.pop();
        cout << tmp->value << " ";

        tmp = tmp -> right;

    }

    cout << '\n';
}


void Btree::printPre(node* tree){
    // inorder
    stack<node *> s1;
    stack<node *> s2;
    node* tmp;
    s1.push(tree);
    while (s1.empty() == false){
        tmp = s1.top();
        s1.pop();
        s2.push(tmp);
    
        if (tmp -> left){
            s1.push(tmp->left);
        }
        if (tmp -> right){
            s1.push(tmp -> right);
        }
    }

    while (s2.empty() == false){
        tmp = s2.top();
        s2.pop();
        cout << tmp->value + " ";
    }

    cout << '\n' ;
}





int main(void){
    Btree b;
    // creating 
    b.insert(4);
    b.insert(6);
    b.insert(5);
    b.insert(1);
    b.insert(2);
    b.insert(3);

    

    b.printTree(1);
    b.printTree(2);
    b.printTree(3);
    b.printNonRecursive(b.root);

};








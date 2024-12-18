#include <iostream>
#include <queue>
#include <iomanip> // for std::setw
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

// Function to get the height of the tree
int height(node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

// Function to print nodes at a given level
void printLevel(node* root, int level, int indentSpace) {
    if (root == nullptr) {
        return;
    }
    if (level == 1) {
        std::cout << std::setw(indentSpace) << root->data;
    } else if (level > 1) {
        printLevel(root->left, level - 1, indentSpace / 2);
        std::cout << std::setw(indentSpace / 2) << " ";
        printLevel(root->right, level - 1, indentSpace / 2);
    }
}

// Function to print the tree in a structured format
void printTree(node* root) {
    int h = height(root);
    int indentSpace = 4 * (h - 1);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i, indentSpace);
        std::cout << std::endl;
    }
}


void PreOrder(struct node *root)
{
    if( root == nullptr )
        return;

    cout << root -> data << " ";

    PreOrder(root -> left);
    PreOrder(root -> right);
}   

void InOrder( struct node *root )
{
    if( root == nullptr )
        return;
    
    InOrder( root -> left);

    cout << root -> data << " ";
    
    InOrder( root -> right );
}

void PostOrder( struct node *root )
{
    if( root == nullptr )
        return;

    PostOrder( root -> left );
    PostOrder( root -> right );

    cout << root -> data << " ";
}



int main() {
    // Creating the tree structure
    node* root = new node();
    root->data = 4;

    root->left = new node();
    root->left->data = 5;

    root->right = new node();
    root->right->data = 10;

    root->left->left = new node();
    root->left->left->data = 7;

    root->left->right = new node();
    root->left->right->data = 8;

    root->right->right = new node();
    root->right->right->data = 1;

    //initialize all the child pointers
    root->right->left = nullptr;
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;
    root->right->right->left = nullptr;
    root->right->right->right = nullptr;

    // Print the tree
    printTree(root);


    cout << "PreOrder is : ";
    PreOrder(root); cout << endl;

    cout << "InOrder is : ";
    InOrder(root); cout << endl;

    cout << "Postorder is : ";
    PostOrder(root); cout << endl;

    delete root->left;
    delete root->right;
    delete root;


    return 0;
}
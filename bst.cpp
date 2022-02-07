#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
    int key;
    struct node *left, *right;
} Node;

// A utility function to create a new BST node
node *newNode(int item)
{
    node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

node *subTreeTraversal(node *root, node *temp)
{
    if (root != NULL && temp != NULL)
    {
        subTreeTraversal(root->left, temp->left);
        // printf("%d \n", root->key);

        // cout<<"root = "<< root->key<<"\ttemp = "<<temp->key<<endl;

        int tempStore = root->key;

        root->key = temp->key;

        temp->key = tempStore;

        // cout<<endl<<"root = "<< root->key<<"\ttemp = "<<temp->key<<endl;

        subTreeTraversal(root->right, temp->right);
    }

    return root;
}

/* A utility function to insert
   a new node with given key in
 * BST */
node *insert(node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

node *Flip(node *root)
{

    node *temp = root->right;

    subTreeTraversal(root->left, temp);

    // cout<<endl<<"Printing temp which is root->right..."<<endl;
    // inorder(temp);

    // cout<<endl<<"Printing root->left..."<<endl;

    // inorder(root->left);

    root->right = temp;

    // cout<<endl<<"Printing root->right..."<<endl;

    // inorder(root->right);

    return root;
}

// Driver Code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    // inorder(root);

    root = Flip(root);

    cout << endl
         << "Printing root->left..." << endl;

    inorder(root->left);

    cout << endl
         << "Printing root->right..." << endl;

    inorder(root->right);

    return 0;
}
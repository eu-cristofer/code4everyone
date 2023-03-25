
/*
  Read a file of integer pairs into an array
  and places these values into a binary tree
  structure.

  coded by Cristofer
*/

#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in a binary tree.
typedef struct node {
    int value;          // The value stored in the node.
    struct node *left;  // A pointer to the left child node.
    struct node *right; // A pointer to the right child node.
} node;

// Insert a new node with the given value into the binary tree rooted at root.
void insert(node **root, int value) {
    // If the root is NULL, create a new node with the given value and set it as the root.
    if (*root == NULL) {
        *root = malloc(sizeof(node));
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    // If the root is not NULL, recursively insert the new node into the appropriate subtree.
    else {
        if (value < (*root)->value) {
            insert(&((*root)->left), value);
        }
        else {
            insert(&((*root)->right), value);
        }
    }
}

// Traverse the binary tree rooted at root in-order and print each node's value to the screen.
void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

int main(int argc, char *argv[]) {
    // Check that the filename is provided as a command line argument.
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    // Open the input file.
    FILE* fp = fopen(argv[1], "r");
    int count, i;

    // Read the first integer in the file to get the number of integers to read.
    fscanf(fp, "%d", &count);
    
    // Allocate an array to store the integers.
    int data[count];
    
    // Read each integer in the file into the array.
    for (i = 0; i < count; i++) {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
    
    node *root = NULL;
    
    // Insert each integer from the array into the binary tree.
    for (i = 0; i < count; i++) {
        insert(&root, data[i]);
    }
    
    // Traverse the binary tree in-order and print each node's value to the screen.
    inorder(root);
    return 0;
}

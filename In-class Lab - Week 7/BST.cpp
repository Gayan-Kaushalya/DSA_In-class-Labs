#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL){       
      traverseInOrder(root -> left);  // Traversing left tree
      cout << root -> key <<" ";      // Printing the value of current node
      traverseInOrder(root -> right); // Traversing right tree
  }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
      // If the tree is empty, the new node is the root node.
      if (root == NULL){   
          // Creating a new Node containing the new element        
          node* newNode;
          newNode = (node*)malloc(sizeof(node));
          newNode -> left = NULL;
          newNode -> right = NULL;
          newNode -> key = key;
          return newNode;
      }
         
      // If the new key < the root node key, we assign the new node to be its left child.
      if (key > root -> key){
          root -> right = insertNode(root -> right, key);
      } 

      // If the new key > the root node key, we assign the new node to be its right child.
      else {
          root -> left = insertNode(root -> left, key);
      }
        return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    // If the tree is empty, nothing is returned.
    if (root == NULL){
      return NULL;
    }

    // If the key to be deleted < the key of the root, it is in the left tree.
    if (key < root -> key){
        root -> left = deleteNode(root -> left, key);
    }

    // If the key to be deleted > the key of the root, it is in right tree.
    else if (key > root -> key){
        root -> right = deleteNode(root -> right, key);
    }

    // If the key to be deleted = the key of the root, it is in root node.
    else {
        // Case 1: Root has no children.
        if (root -> left == NULL and root -> right == NULL){
            return NULL;
        }

        // Case 2: Root has only one child.
        else if (root -> left == NULL) {
            struct node* temp = root -> right;
            free(root);
            return temp;
        }        
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // Case 3: Root has two children.
        else{
        // We should find the leftmost child of the right tree
        struct node* temp = root->right;

        while (temp && temp -> left != NULL){
          temp = temp ->left;
        }

        // Then we replace that child with root node.
        root -> key = temp -> key;
 
        // Finally we have to delete the leftmost leaf of right tree.
        root -> right = deleteNode(root -> right, temp -> key);
        }
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
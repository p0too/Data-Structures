#include<stdio.h>
#include<stdlib.h>

/* 
   Binary Search Tree
 */

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *create_node(int val) {
  struct Node *node = (struct Node*) malloc(sizeof(struct Node));
  node->left = NULL;
  node->right = NULL;
  node->data = val;

  return node;
}

struct Node *insert_node(struct Node *root, int val) {
  if(root == NULL) {
    root = create_node(val);
  } else {
    struct Node *temp = root;
    while(1) {
      if(temp->data > val) {
        if(temp->left != NULL)
          temp = temp->left;
        else {
          temp->left = create_node(val);
          break;
        }
      } else { //if(temp->data < val) {
        if(temp->right != NULL)
          temp = temp->right;
        else {
          temp->right = create_node(val);
          break;
        }
      }
    }
  }
  return root;
}


struct Node *search(struct Node *root, int val) {
  if(root == NULL) 
    return root;
  else if(root->data == val)
    return root;
  else if(val < root->data)
    search(root->left, val);
  else search(root->right, val);
}


void preorder(struct Node *root) {
  if(root==NULL) return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}


void inorder(struct Node *root) {
  if(root==NULL) return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}


/* use postorder to free memory allocated to bst */
void postorder_free(struct Node *root) {
  if(root==NULL) return;
  postorder_free(root->left);
  postorder_free(root->right);
  free(root);
}

int main(void) {

  struct Node *bst = NULL;
  bst = insert_node(bst, 8);
  insert_node(bst, 6);
  insert_node(bst, 2);
  insert_node(bst, 4);
  insert_node(bst, 9);
  insert_node(bst, 12);
  insert_node(bst, 7);
  insert_node(bst, 11);

  /*
  struct Node *temp = search(bst, 8);
  printf("%d\n", temp->data);
  */

  preorder(bst);
  printf("\n");
  /*
  inorder(bst);
  printf("\n");
  */

  postorder_free(bst);  // free memory 
  return 0;
}

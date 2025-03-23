#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node *left;
  int data;
  struct Node *right;
};

void preorder(struct Node *root){
  if(root==NULL) return;
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}
void inorder(struct Node *root){
  if(root==NULL) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}
void postorder(struct Node *root){
  if(root==NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->data);
}

int main(){

  struct Node a;
  struct Node b;
  struct Node c;
  struct Node d;
  struct Node e;
  struct Node f;

  a.data = 1;
  b.data = 2;
  c.data = 3;
  d.data = 4;
  e.data = 5;
  f.data = 6;
  
  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.left  = &f;
  //leaf node
  c.right = NULL;
  d.left = NULL;
  d.right = NULL;
  e.left = NULL;
  e.right = NULL;
  f.left = NULL;
  f.right = NULL;

  struct Node *root = &a;

  preorder(root);  
  printf("\n");
  inorder(root);  
  printf("\n");
  postorder(root); 

return 0;
}
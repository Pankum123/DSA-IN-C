#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node *left;
  int data;
  struct Node *right;
};

struct Node* newNode(int value){
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = value;
  temp->left = temp->right = NULL;
  return temp;
}

void createTree(struct Node * root){
  struct Node *b =  newNode(2);
  struct Node *c =  newNode(3);
  struct Node *d =  newNode(4);
  struct Node *e =  newNode(5);
  struct Node *f =  newNode(6);
  struct Node *g =  newNode(7);
  struct Node *h =  newNode(8);

  root->left = b;
  root->right = c;
  b->right = d;
  c->left  = e;
  d->left = f;
  d->right = g;
 // e->right = h;
}

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

int level(struct Node* root){
  if(root==NULL) return 0;
  int leftL = level(root->left);
  int rightL = level(root->right);
  if(leftL>rightL) return (1+leftL);
  else return (1+rightL);
}

int main(){
  struct Node* root = newNode(1);
  createTree(root);
  preorder(root);  //1 2 4 6 7 3 5 8
  printf("\n");
  inorder(root);   //2 6 4 7 1 5 8 3 
  printf("\n"); 
  postorder(root); //6 7 4 2 8 5 3 1
  printf("\nlevel = %d ",level(root));
  printf("\nlevel = %d ",level(root->left));
  printf("\nlevel = %d ",level(root->right));

return 0;
}
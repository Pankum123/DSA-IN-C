#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node *left;
  int data;
  struct Node *right;
  int isThreaded; // 1 if right pointer is a thread, 0 otherwise
};

struct Node* newNode(int value){
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = value;
  temp->left = temp->right = NULL;
  temp->isThreaded = 0;
  return temp;
}

void createTree(struct Node* root){

  struct Node *b = newNode(5);
  struct Node *c = newNode(20);
  struct Node *d = newNode(1);
  struct Node *e = newNode(8);
  struct Node *f = newNode(15);
  struct Node *g = newNode(25);
  
  root->left = b;
  root->right = c;
  b->left = d;
  b->right = e;
  c->left  = f;
  c->right = g;
}

void inorder(struct Node *root){
  if(root==NULL) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}

void convertSingleThread(struct Node *root){

  if(root==NULL) return;
  
  static struct Node *prev = NULL;
  convertSingleThread(root->left);
  

  if(prev && (prev)->right==NULL){
    (prev)->right = root;
    (prev)->isThreaded = 1;
  }
  
  prev = root;
  convertSingleThread(root->right);

}

struct Node* leftMost(struct Node *node){
  while(node && node->left){
    node = node->left;
  }
  return node;
}

void inorderTraversal(struct Node *root){
  struct Node * current = leftMost(root);
  while(current){
    printf("%d ",current->data);
    if(current->isThreaded){
      current  = current-> right;
    }
    else{
      current = leftMost(current->right);
    }
  }
}


int main(){

  struct Node *root = newNode(10);
  createTree(root);
  
  inorder(root);     
  printf("\n");
  

  convertSingleThread(root);
  inorderTraversal(root);

return 0;
}
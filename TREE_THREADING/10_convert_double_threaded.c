#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node *left;
  int data;
  struct Node *right;
  int isLeftThread, isRightThread;
};

struct Node* newNode(int value){
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = value;
  temp->left = temp->right = NULL;
  temp->isLeftThread = temp->isRightThread = 0;
  return temp;
}

void create(struct Node* root){
  
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


void convertDoubleThread(struct Node *root){
  if(root==NULL) return;

  static struct Node *prev = NULL;

  convertDoubleThread(root->left);

  if(root->left==NULL){
    root->left = prev;
    root->isLeftThread = 1;
  }
  else{
    root->isLeftThread = 0;
  }

  if(prev!=NULL && prev->right==NULL){
    prev->right = root;
    prev->isRightThread = 1;
  }

  prev = root;

  convertDoubleThread(root->right);

}

struct Node* leftMost(struct Node *node){
  while(node  && node->isLeftThread==0){
    node = node->left;
  }
  return node;
}

void inorderTraversal(struct Node *root){
  struct Node *current = leftMost(root);
  while(current != NULL){
    printf("%d ",current->data);
    if(current->isRightThread){
      current  = current-> right;
    }
    else{
      current = leftMost(current->right);
    }
  }
}


int main(){

  struct Node *root = newNode(10);
  create(root);
  
  inorder(root);     
  printf("\n");

  convertDoubleThread(root);
  inorderTraversal(root);

return 0;
}
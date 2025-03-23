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

void inorder(struct Node *root){
  if(root==NULL) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}


struct Node* insertBST(struct Node* root,int value){
  
  if(root==NULL){
    return newNode(value);
  }
  if(root->data > value) 
    root->left = insertBST(root->left,value);
  else
    root->right = insertBST(root->right,value);
  return root;
}

void deleteBST(struct Node *root,int value){
  struct Node* prev = NULL;
  struct Node* temp = root;
  while(temp && temp->data != value){
    if(value < temp->data){
      prev = temp;
      temp = temp->left;
    }
    else{
      prev = temp;
      temp = temp->right;
    }
  }
  if(!temp->right && !temp->left){
    if(prev->left==temp) prev->left = NULL;
    else prev->right = NULL;
  }
  else if(!temp->left || !temp->right){
    if(prev->left==temp){
      if(temp->left) prev->left = temp->left;
      else prev->left = temp->right;
    }
    else{
      if(temp->left) prev->right = temp->left;
      else prev->right = temp->right;
    }
  }
  else{
    struct Node *succ = temp->right;
    prev = temp;
    while(succ->left){
      prev = succ;
      succ = succ->left;
    }
    temp->data = succ->data;

    temp = succ;

    if(!temp->right && !temp->left){
      if(prev->left==temp) prev->left = NULL;
      else prev->right = NULL;
    }
    else if(!temp->left || !temp->right){
      if(prev->left==temp){
        if(temp->left) prev->left = temp->left;
        else prev->left = temp->right;
      }
      else{
        if(temp->left) prev->right = temp->left;
        else prev->right = temp->right;
      }
    }
  }
}

int main(){

  struct Node *root = NULL;
  root = insertBST(root,7);
  root = insertBST(root,8);
  root = insertBST(root,4);
  root = insertBST(root,5);
  root = insertBST(root,1);
  root = insertBST(root,3);
  root = insertBST(root,6);
  root = insertBST(root,30);
  root = insertBST(root,20);

  inorder(root);
  deleteBST(root,5);
  printf("\n");
  inorder(root);
  

return 0;
}
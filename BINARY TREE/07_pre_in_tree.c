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

struct Node* createPreInTree(int *pre,int pres,int pree,int *in,int ins,int ine){
  if (pres > pree) return NULL;
  struct Node *root = (struct Node*) malloc(sizeof(struct Node));
  root->data = pre[pres];
  root->left = NULL;
  root->right= NULL;
  if(pres==pree) return root;
  int root_idx = 0;
  for(int i = ins;i<=ine;i++){
    if(pre[pres]==in[i]){
      root_idx = i;
      break;
    }
  }
  int left_subtree_size = root_idx - ins;
  root->left = createPreInTree(pre, pres+1, pres+left_subtree_size, in, ins, root_idx-1);
  root->right = createPreInTree(pre, pres+left_subtree_size+1, pree,in, root_idx+1, ine);
  return root;
}

int main(){

 
  int pre[]={75,69,36,45,72,91,18,90,12,4,3,15};
  int in[]={36,69,72,45,18,91,75,12,3,4,90,15};

  struct Node *root = createPreInTree(pre,0,11,in,0,11);
  
  preorder(root);  
  printf("\n");
  inorder(root);   
  printf("\n");
  postorder(root); 

return 0;
}
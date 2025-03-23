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

struct Node* createPostInTree(int *post,int posts,int poste,int *in,int ins,int ine){
  if (poste < posts) return NULL;
  struct Node *root = (struct Node*) malloc(sizeof(struct Node));
  root->data = post[poste];
  root->left = NULL;
  root->right= NULL;
  if(posts==poste) return root;
  int root_idx = 0;
  for(int i = ins;i<=ine;i++){
    if(post[poste]==in[i]){
      root_idx = i;
      break;
    }
  }
  int left_subtree_size = root_idx - ins;
  
  root->left = createPostInTree(post, posts, posts+left_subtree_size-1, in, ins, root_idx-1);
  root->right = createPostInTree(post, posts+left_subtree_size, poste-1, in, root_idx+1,ine);
  
  return root;
}

int main(){

 
  int post[]={36,72,18,91,45,69,3,4,12,15,90,75};
  int in[]={36,69,72,45,18,91,75,12,3,4,90,15};

  struct Node *root = createPostInTree(post,0,11,in,0,11);
  
  preorder(root);  
  printf("\n");
  inorder(root);   
  printf("\n");
  postorder(root); 

return 0;
}
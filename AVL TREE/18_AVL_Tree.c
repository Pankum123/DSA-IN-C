#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node *left;
  int data;
  struct Node *right;
  int height;
};

struct Node* newNode(int value){
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = value;
  temp->left = temp->right = NULL;
  temp->height = 1;
  return temp;
}

int getheight(struct Node* root){
  if(root==NULL)
  return 0;

  return root->height;
}

int getbalance(struct Node* root){
  return (getheight(root->left)-getheight(root->right));
}

struct Node*rightRotation(struct Node* root){
  struct Node* child = root->left;
  struct Node *childRight = child->right;

  child->right = root;
  root->left = childRight;

  // Update the height

  root->height = 1 + (getheight(root->left) > getheight(root->right) ? getheight(root->left) : getheight(root->right));
  child->height = 1 + (getheight(child->left) > getheight(child->right) ? getheight(child->left) : getheight(child->right));


  return child;

}

struct Node* leftRotation(struct Node* root){
  struct Node* child = root->right;
  struct Node *childLeft = child->left;

  child->left = root;
  root->right = childLeft;

  // Update the height

  root->height = 1 + (getheight(root->left) > getheight(root->right) ? getheight(root->left) : getheight(root->right));
  child->height = 1 + (getheight(child->left) > getheight(child->right) ? getheight(child->left) : getheight(child->right));


  return child;

}


struct Node* createAVL(struct Node* root,int value){

  if(root==NULL) //Dosen't exist
  return newNode(value);
  
  if(root->data > value) 
  root->left = createAVL(root->left,value); // Left side
  else if(root->data < value)
  root->right = createAVL(root->right,value); // Righr side
  else return root; //duplicate are not allowed

  // update Height
  root->height = 1 + (getheight(root->left) > getheight(root->right) ? getheight(root->left) : getheight(root->right));

  //Balancing check
  int balance = getheight(root->left) - getheight(root->right);

  //LL
  if(balance > 1 && value < root->left->data)
    return rightRotation(root);

  //RR
  else if(balance < -1 && value > root->right->data)
    return leftRotation(root);

  //LR
  else if(balance > 1 && value > root->left->data){
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }

  //RL
  else if(balance < -1 && value < root->right->data){
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }

  //No Unbalancing
  else{
    return root;
  }
   
}

struct Node* deleteNode(struct Node* root,int key){
  if(!root)
  return NULL;

  if(key<root->data) //left side
  root->left = deleteNode(root->left,key);
  else if(key>root->data) //right side
  root->right = deleteNode(root->right,key);
  else
  {
    //Leaf Node
    if(!root->left&&!root->right){
      free(root);
      return NULL;
    }
    //Only one child
    else if(root->left&&!root->right){
      struct Node *temp = root->left;
      free(root);
      return temp;
    }
    else if(!root->left&&root->right){
      struct Node *temp = root->right;
      free(root);
      return temp;
    }
    //both child exist
    else{
      // Right side smallest element
      struct Node *curr = root->right;
      while(root->left){
        curr = curr->left;
      }
      root->data = curr->data;
      root->right = deleteNode(root->right,curr->data);
    }
  }

  //Update the height
  root->height = 1 + (getheight(root->left) > getheight(root->right) ? getheight(root->left) : getheight(root->right));

  //Check the balance
  int balance = getbalance(root);

  //Left side
  if(balance>1){
    //LL
    if( getbalance(root->left)>=0){
      return rightRotation(root);
    }
    //LR
    else{
      root->left = leftRotation(root->left);
      return rightRotation(root);
    }
  }
  //Right side
  else if(balance<-1){
    //RR
    if(getbalance(root->right)<=0)
    return leftRotation(root);
    //RL
    else{
      root->right = rightRotation(root->right);
      return leftRotation(root);
    }
  }
  else
  return root;
  

}

void inorder(struct Node *root){
  if(root==NULL) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}

void preorder(struct Node *root){
  if(root==NULL) return;
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}

int main(){

  struct Node *root = NULL;
  root = createAVL(root,64);
  root = createAVL(root,1);
  root = createAVL(root,44);
  root = createAVL(root,26);
  root = createAVL(root,13);
  root = createAVL(root,110);
  root = createAVL(root,98);
  root = createAVL(root,85);

  printf("\n");
  preorder(root);
  deleteNode(root,26);
  printf("\n");
  preorder(root);

return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFLEN 15

typedef struct TreeNode{
  int data;
  struct TreeNode *right;
  struct TreeNode *left;
}TreeNode ;

void print(TreeNode *node){
  if (!node) {
    return;
  }
  print(node->left);
  printf("%d\n", node->data);
  print(node->right);
}

TreeNode *
createNode(int value){

  TreeNode *new_node = malloc(sizeof(TreeNode));
  if (!new_node) {
    printf("Error allocating memory for new node\n");
    exit(1);
  }

  new_node->data = value;
  new_node->right = NULL;
  new_node->left = NULL;
  return new_node;
}

TreeNode *
add(TreeNode *root, int data){
  
  if (root == NULL) {
    return createNode(data);
  }

  if(data < root->data){
    root->left = add(root->left, data);
  }
  else if (data > root->data) {
    root->right = add(root->right, data);
  }

  return root;
}

void freetree(TreeNode *node){
  if(!node){
    return;
  }
  freetree(node->right);
  freetree(node->left);
  free(node);
}
   
int
main(){
  
  srand(time(NULL));
  TreeNode *root = createNode(100);
 
  for (int i = 0;i < DEFLEN; i++) {
    root = add(root, rand() % 200);
  }

  print(root);

  freetree(root);

  return 0;
}

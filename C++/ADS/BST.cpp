#include <iostream>
using namespace std;
struct node{
  int val;
  struct node* left,right;
};
void inorder_traverse(struct node* root){
  if(root!=NULL){
    inorder_traverse(root->left);
    cout<<root->val<<"\t";
    inorder_traverse(root->right);
  }
}
struct node* search_node(struct node* root,int val){
  if(root==NULL || root->val==val)
    return root;
  return root->val>val?search_node(root->right,val):search_node(root->left,val);
}
int main(int argc, char *argv[])
{
  
  return 0;
}

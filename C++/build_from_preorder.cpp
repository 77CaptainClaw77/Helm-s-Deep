#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder,int l,int h){
    if(l>h)
      return NULL;
    TreeNode* newn=new TreeNode(preorder[l]);
    int ele=preorder[l],pos=l+1;
    while(pos<=h){
      if(preorder[pos]>ele)
	break;
      pos++;
    }
    if(pos>l)
      newn->left=buildTree(preorder,l+1,pos-1);
    if(pos<=h)
      newn->right=buildTree(preorder,pos,h);
    return newn;
  }
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return buildTree(preorder,0,preorder.size()-1);
  }
};
int main(int argc,char* argv[]){
  vector<int> p={4,2};
  Solution s;
  TreeNode* root=s.bstFromPreorder(p);
  return 0;
}

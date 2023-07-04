/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    unordered_map<int, int>u;

    TreeNode* build(vector<int>post, int &postidx, int si, int ei){
      if(postidx < 0 || si > ei)
      return NULL;

      TreeNode* root =new TreeNode(post[postidx]);
      postidx--;

      int rootidx = u[root->val];
      root ->right = build(post, postidx, rootidx+1,ei);
      root ->left = build(post, postidx, si, rootidx-1);

      return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       for(int i =0; i< inorder.size(); i++){
         u[inorder[i]] =i;
       }

       int postidx = postorder.size()-1;
       return build(postorder, postidx,0,postorder.size()-1);
       
    }
};
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
      int maxDia= 0;
      int GetDepth(TreeNode* node){
        if(!node) return 0;

        int left = GetDepth(node->left);
        int right = GetDepth(node->right);

        maxDia = max(maxDia, left + right);
        return max(left, right) + 1;
      }

    int diameterOfBinaryTree(TreeNode* root) {
       int t = GetDepth(root);
       return maxDia;
    }

  
};
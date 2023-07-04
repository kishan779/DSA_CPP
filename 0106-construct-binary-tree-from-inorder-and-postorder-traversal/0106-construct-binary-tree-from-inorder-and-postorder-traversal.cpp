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
    int findpos(vector<int> &inorder, int ele,int n){
         for(int i=0;i<n;i++){
             if(inorder[i]==ele){
                 return i;
             }
         }
         return -1;
    }
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder,int &index,int start,int end,int n){
        if(index< 0 || start>end) return nullptr;
        int ele = postorder[index--];
        int pos = findpos(inorder,ele,n);

        TreeNode* temp = new TreeNode(ele);
          temp->right = solve(inorder,postorder,index,pos+1,end,n);

        temp->left = solve(inorder,postorder,index,start,pos-1,n);
      
        return temp;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();
        int index=n-1;
        TreeNode* ans = solve(inorder,postorder,index,0,n-1,n);
        return ans;
    }
};
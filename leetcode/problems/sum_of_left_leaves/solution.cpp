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
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root==nullptr) {
            return 0;
        } 
        
        int ans = sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        if(root->left!=nullptr) {
            TreeNode* left = root->left;
            if(left->left==nullptr && left->right==nullptr) {
                ans+=left->val;
            }
        }
        return ans;
    }
};
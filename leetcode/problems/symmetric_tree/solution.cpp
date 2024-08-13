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

    bool helper(TreeNode* one, TreeNode* two) {
        if(one==nullptr && two==nullptr) return true;
        if(one==nullptr || two==nullptr) return false;
        if(one->val!=two->val) return false;
        return helper(one->left,two->right) && helper(one->right,two->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return helper(root->right,root->left);
        
    }
};
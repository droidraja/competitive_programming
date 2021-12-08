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
    void util(TreeNode* root,vector<int> &leaves) {
        if(root==nullptr) return;
        
        if(root->left==nullptr && root->right==nullptr) {
            leaves.push_back(root->val);
        }

        if(root->left!=nullptr) {
            util(root->left,leaves);
        }
        
        if(root->right!=nullptr) {
            util(root->right,leaves);
        }
        return;
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1Leaves;
        vector<int> root2Leaves;
        util(root1,root1Leaves);
        util(root2,root2Leaves);
        
        if(root1Leaves.size()!=root2Leaves.size()) return false;
        
        for(int i=0;i<root1Leaves.size();i++) {
            if(root1Leaves[i]!=root2Leaves[i]) return false;
        }
        return true;
    }
};
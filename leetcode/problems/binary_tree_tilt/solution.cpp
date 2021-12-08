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
    
    pair<int,int> tiltUtil(TreeNode* root) {
        
        pair<int,int> a,left,right;
        left.first = 0;
        left.second = 0;
        right.first = 0;
        right.second = 0;
        if(root==nullptr) return left;
        
        if(root->left!=nullptr) {
            left = tiltUtil(root->left);
        }
        
        if(root->right!=nullptr) {
            right = tiltUtil(root->right);
        }
        if(left.first>right.first) {
            a.second = left.first-right.first;
        } else {
            a.second = right.first-left.first;
        }
        a.second+=left.second;
        a.second+=right.second;
        a.first = left.first + right.first + root->val;
        return a;
    }
    
    int findTilt(TreeNode* root) {
        pair<int,int> ans = tiltUtil(root);
        return ans.second;
    }
};
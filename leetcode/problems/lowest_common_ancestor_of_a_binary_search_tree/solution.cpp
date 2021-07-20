/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    bool findPath(TreeNode* root,TreeNode* searchNode, vector<TreeNode*> &path) {
        if(root==NULL)  return false;
        
        path.push_back(root);
        
        if(root==searchNode) return true;

        if(findPath(root->right,searchNode,path) || findPath(root->left,searchNode,path)) return true;

        path.pop_back();
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(p==q) return p;
        
        vector<TreeNode*> pPath;
        findPath(root,p,pPath);
        vector<TreeNode*> qPath;
        findPath(root,q,qPath);
        int i;
        for(i=0;i<min(pPath.size(),qPath.size());i++) {
            if(pPath[i]!=qPath[i]) break;
        }
        
        return pPath[i-1];
        
    }
};
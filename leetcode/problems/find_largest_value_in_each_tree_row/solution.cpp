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
    vector<int> largestValues(TreeNode* root) {
        map<int,int> maxValues;
        vector<int> ans;
        vector<pair<TreeNode*,int>> stack;
        if(root==NULL)
            return ans;
        stack.push_back({root,0});
        while(stack.size()!=0) {
            
            pair<TreeNode*,int> temp = stack.back();
            
            stack.pop_back();
            
            if(maxValues.find(temp.second)!=maxValues.end()) {
                maxValues[temp.second] = max(maxValues[temp.second],temp.first->val);
            } else {
                maxValues[temp.second] = temp.first->val;
            }
            
            if(temp.first->left!=NULL) {
                stack.push_back({temp.first->left,temp.second+1});        
            }
            if(temp.first->right!=NULL) {
                stack.push_back({temp.first->right,temp.second+1});
            }
            
        }
    
        for(auto p:maxValues) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
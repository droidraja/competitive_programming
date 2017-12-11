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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        queue <TreeNode*> q;
        q.push(root);
        int level_size = q.size();
        
        while(level_size!=0)
        {
            vector <int> a;
            while(level_size!=0)
            {
                TreeNode* temp = q.front();
                a.push_back(temp->val);
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                level_size--;
            }
            result.insert(result.begin(),a);
            level_size = q.size();
        }
        return result;
    }
};
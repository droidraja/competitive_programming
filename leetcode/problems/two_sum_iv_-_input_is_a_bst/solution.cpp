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
    
    void buildElement(TreeNode* root,unordered_map<int,int> &nums) {
        if(root==NULL) return;
        
        if(nums.find(root->val)==nums.end()) 
            nums[root->val] = 0;
        nums[root->val]++;
        buildElement(root->left,nums);
        buildElement(root->right,nums);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> nums;
        buildElement(root,nums);
        
        vector<TreeNode*> s;
        s.push_back(root);
        while(s.size()!=0) {
            TreeNode* temp = s.back();
            s.pop_back();
            if(temp!=NULL) {
                
                if(k-temp->val==temp->val) {
                    if(nums[temp->val]>=2)   return true;
                } else if(nums.find(k-temp->val)!=nums.end())
                    return true;
                s.push_back(temp->left);
                s.push_back(temp->right);
            }
            
        }
        return false;
    }
};
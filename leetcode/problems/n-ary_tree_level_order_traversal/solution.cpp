/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        queue<pair<Node*,int>> q;
        q.push({root,1});
        int level = 1;
        vector<int> level_elems;
        while(!q.empty()) {
            pair<Node*,int> temp = q.front();
            q.pop();
            if(temp.second!=level) {
                level = temp.second;
                ans.push_back(level_elems);
                level_elems = vector<int>();
            }
            level_elems.push_back(temp.first->val);
            for(Node* kid: temp.first->children) {
                if(kid!=NULL) {
                    q.push({kid,temp.second+1});
                }
            }
        }
        ans.push_back(level_elems);
        return ans;
    }
};
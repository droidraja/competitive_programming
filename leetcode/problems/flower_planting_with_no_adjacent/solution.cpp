class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        int gardens[n];
        for(int i=0;i<n;i++) {
            gardens[i] = 0;
        }
        
        vector<int> g[n];
        
        for(vector<int> path:paths) {
            int x = path[0]-1;
            int y = path[1]-1;
            g[x].push_back(y);
            g[y].push_back(x);
            
        }
        
        vector<int> result;
        for(int i=0;i<n;i++) {
            if(gardens[i]==0) {
                unordered_set<int> a;
                a.insert(1);
                a.insert(2);
                a.insert(3);
                a.insert(4);
                for(int child:g[i]) {
                    if(a.find(gardens[child])!=a.end()) {
                        a.erase(gardens[child]);
                    }
                }
                gardens[i] = *(a.begin());
                
            }
         result.push_back(gardens[i]);
        }
        
        return result;
        
    }
};
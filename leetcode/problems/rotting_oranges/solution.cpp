class Solution {
public:
    
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> rottens;
        
        int rt[grid.size()][grid[0].size()];
        int fresh = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==2) {
                    pair<int,int> rotten;
                    rotten.first = i;
                    rotten.second = j;
                    rottens.push(rotten);
                    rt[i][j] = 0;
                } else {
                    rt[i][j] = -1;
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        
        int dirs[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        int maxT = 0;
        while(rottens.size()!=0) {
            pair<int,int> rotten = rottens.front();
            rottens.pop();
                for(auto dir: dirs) {
                    int i=dir[0]+rotten.first, j=dir[1] + rotten.second;
                    
                    if(i<0 || i>=grid.size()) continue;
                    if(j<0 || j >=grid[0].size()) continue;
                    if(rt[i][j]!=-1 || grid[i][j]==0) continue;                       
                    rottens.push({i,j});
                    rt[i][j] = rt[rotten.first][rotten.second] + 1;
                    fresh--;
                    maxT = max(maxT,rt[i][j]);
                }
        }
        
        
        return (fresh==0)?maxT:-1;
    }
};
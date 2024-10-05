#include <bits/stdc++.h>

using namespace std;


vector<pair<int,int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
vector<char> movesC = {'U','D','L','R'};
vector<vector<int>> visited;
vector<vector<char>> parents;
int m,n;
pair<int,int> src,dest;
deque<char> movesTaken;

bool isValid(int x,int y) {
    if(x<0 || x>m || y<0 || y>n) return false;
    if(visited[x][y]) return false;
    return true;
}


bool dfs(int y,int x){

    if(dest.first==y && dest.second==x) return true;
    for(int i=0;i<4;i++) {
        auto move = moves[i];
        int newI = y+move[0];
        int newJ = x+move[1];
        if(isValid(newI,newJ)) {
            bool found = dfs(newI,newJ);
            if(found){
                movesTaken.push_front(movesC[i]);
                break;
            } 
        }
    }
}

vector<char> getPath(int y,int x) {

}


vector<char> bfs(int y,int x) {
    queue<pair<vector<pair<int,int>>,vector<char>>> paths;
    queue<pair<int,int>> toVisit;
    pair<int,int> initial = {y,x};

    while(toVisit.size()!=0) {
        
        auto node = toVisit.front();
        toVisit.pop();
        if(node.first == dest.first && node.second == dest.second) {
            return getPath(y,x);
        }

        for(int i=0;i<4;i++) {
            auto move = moves[i];
            auto moveC = movesC[i];

            int newY = y+move.first;
            int newX = x+move.second;
            if(isValid(newY,newX)) {
                parents[newY][newX] = moveC; 
                toVisit.push({newY,newX});
            
            }
        }
        

    }

}



void solve() {
    cin>>m>>n;
    visited = vector<vector<int>>(m,vector<int>(n,0));
    parents = vector<vector<char>>(m,vector<char>(n));


    for(int i=0;i<m;i++) {
        string row;
        cin>>row;
        for(int j=0;j<n;j++) {
            
            if(row[j]=='#') {
                visited[i][j] = 1;
            } else if(row[j]=='A') {
                src = make_pair(i,j);
            } else if(row[j]=='B') {
                dest = make_pair(i,j);
            }
        }

    }
    dfs(src.first,src.second);
    if(movesTaken)

}

int main(){
    int tc=1;
    // cin>>tc;

    while(tc--) solve();
    return 0;
}
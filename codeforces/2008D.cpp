#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n+1,0);
    for(int i=1;i<=n;i++) {
        cin>>nums[i];
    }
    string col;
    cin>>col;
    col = "0"+col;

    vector<int> visited(n+1,0);
    vector<int> finalized(n+1,0);
    vector<int> black(n+1,0);

    for(int i=1;i<=n;i++) {
        int iter=i;
        if(!visited[i]){
            vector<int> path;
            path.push_back(iter);
            visited[iter] = 1;
            int nextNode = nums[iter];
            // cout<<iter<<" ";
            while(visited[nextNode]==0) {
                // cout<<nextNode<<" ";
                path.push_back(nextNode);
                visited[nextNode]=1;
                nextNode = nums[nextNode];
            }
            // cout<<nextNode<<endl;
            int isLoopEnd = 0;
            if(finalized[nextNode]==0) {
                int blacksInLoop = 0;
                int itr=path.size()-1;
                bool found=false;
                while(!found) {
                    blacksInLoop += col[path[itr]]=='0';
                    found = path[itr]==nextNode;
                    itr--; 
                }
                found=false;
                while(!found) {
                    found = path.back()==nextNode;
                    black[path.back()] = blacksInLoop;
                    finalized[path.back()] = 1;
                    path.pop_back();
                }
            }
            // cout<<endl;
            // cout<<path.size()<<endl;


            int blacks=black[nextNode];
            while(path.size()!=0) {
                black[path.back()] = blacks;
                finalized[path.back()]==1;
                if(col[path.back()]=='0') blacks+=1 ;
                path.pop_back();
            }

        }
    }
    for(int i=1;i<=n;i++) {
        int cnt=black[i];
        cout<<cnt<<" ";
    }
    cout<<endl;
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
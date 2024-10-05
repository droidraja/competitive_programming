#include <bits/stdc++.h>

using namespace std;

#define maxL 200002
void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> nums;

    int maxSecondSmallest = 0;
    for(int i=0;i<n;i++) {
        int l;
        cin>>l;
        
        int visited[maxL];
        memset(visited, 0, maxL);

        
        for(int j=0;j<l;j++) {
            int temp;
             cin>>temp;
            if(temp<=maxL) visited[temp] = 1;    
        }
        int num=0;
        int notVisited=0;
        int secondSmallest=0;
        while(notVisited!=2) {
            if(visited[num]==0) {
                notVisited++;
                secondSmallest=num;
            }
            num++;
        }
        maxSecondSmallest = max(maxSecondSmallest,secondSmallest);
    }

    if(maxSecondSmallest>=m) {
        cout<<(m+1)*maxSecondSmallest<<endl;
    }  else {
        
    int answer = (maxSecondSmallest*(maxSecondSmallest+1))/2 + (m*(m+1))/2;

    cout<<answer<<endl;
    }

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
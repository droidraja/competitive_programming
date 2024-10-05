#include <bits/stdc++.h>

using namespace std;




int gcdA[1001][1001];

int gcdF(int a, int b)
{
    return b == 0 ? a : gcdF(b, a%b);
}

void solve() {
    int l,r;
    cin>>l>>r;
    vector<int> visited(1001,0);
    int ans = 0;
    for(int i=l;i<=r-2;i++) {
        if(visited[i]==1) continue;
        for(int j=i+1;j<=r-1;j++) {
            if(visited[j]==1 || visited[i]==1) continue;
            for(int k=j+1;k<=r;k++) {
                if(visited[k]==1 || visited[i]==1 || visited[j]==1) continue;
                int isPart = (gcdA[i][j]==1 && gcdA[i][k]==1 && gcdA[j][k]==1);
                ans+= isPart;
                if(isPart) {
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    visited[i] =1;
                    visited[j] =1;
                    visited[k] =1;
                }
            }
        }
    }

    cout<<ans<<endl;


}

int main(){
    int tc=1;
    cin>>tc;

    for(int i=1;i<1000;i++) {
        for(int j=i+1;j<=1000;j++)
            gcdA[i][j] = gcd(i,j);
    }

    while(tc--) solve();
    return 0;
}
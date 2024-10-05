#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,x,k;

    cin>>n>>x>>k;

    vector<int> freq(501,0);

    for(int i=0;i<n;i++) {
        int mH;
        cin>>mH;
        freq[mH]++;    
    }

    vector<int> hasMore(501,0);

    for(int i=0;i<501;i++) {
        if(freq[i]>1) hasMore[i]=1;
    }

    vector<int> prefixSum(503,)




}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
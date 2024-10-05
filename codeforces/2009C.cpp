#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x,y,k;
    cin>>x>>y>>k;

    int xJumps= x/k + (x%k>0);
    int yJumps= y/k + (y%k>0);
    
    if(xJumps>yJumps) {
        cout<<2*xJumps-1;
    } else {
        cout<<2*yJumps;
    }
    cout<<endl;
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
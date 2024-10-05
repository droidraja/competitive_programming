#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l,r;
    cin>>l>>r;

    int cur = l;
    int ops = 0;
    int diff=1;
    while(cur<=r) {
        ops++;
        cur+=diff;
        diff++;
    }
    cout<<ops<<endl;


}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
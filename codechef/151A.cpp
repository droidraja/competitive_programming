#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin>>n;
    cin>>s;

    int ones=0;
    int zeros=0;

    for(int i=0;i<n;i++) {
        
        if(s[i]=='1') {
            ones++;
        } else {
            zeros++;
        }
    }

    int total=0;
    for(int k=1;k<=n;k++) {
        if(k<ones&&k<zeros) continue;

        if(k==ones || k==zeros) {
            total++;
            continue;
        }

        if(k>ones) {
            int rem = k-ones;
            if(rem%2==0) {
                total++;
                continue;
            }
        }

        if(k>zeros) {
            int rem = k-zeros;
            if(rem%2==0) {
                total++;
                continue;
            }
        }
    }

    cout<<total<<endl;


}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
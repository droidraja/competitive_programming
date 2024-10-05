#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n,k;
    cin>>n>>k;

    string s,t;
    cin>>s>>t;

    if(s.size()!=t.size()) {
        cout<<"NO"<<endl;
        return;
    }
    int misMatches = 0;
    int ones=0;
    int zeros=0;
    for(int i=0;i<n;i++) {
        if(s[i]!=t[i]) misMatches++;
        if(s[i]=='1') ones++;
        if(t[i]=='1') ones--;
        if(s[i]=='0') zeros++;
    }
    if(ones!=0) {
        cout<<"NO"<<endl;
        return;
    }
    int swapsRequired = misMatches/2;
    bool swapOnes = (zeros>1) || (n-zeros>1);
    if(swapsRequired<=k && ((k-swapsRequired)%2==0 || swapOnes)) {
        
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }





}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
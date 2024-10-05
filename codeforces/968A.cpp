#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    if(s[0]==s[n-1]) {
            cout<<"NO"<<endl;
    } else {
            cout<<"YES"<<endl;
    }

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
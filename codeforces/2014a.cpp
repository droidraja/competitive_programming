#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;

    vector<int> golds(n,0);

    for(int i=0;i<n;i++) {
        cin>>golds[i];
    }

    long long robin=0;
    long long given =0;
    for(auto g:golds) {
        // cout<<g<<" "<<robin<<endl;
        if(g>=k) robin+=g;
        if(g==0 && robin>0) {
            robin--;
            given++;
        }
    }
    cout<<given<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
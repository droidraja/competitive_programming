#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin>>n;
    vector<int> golds(n,0);
    long long total =0;
    for(auto &g: golds) {
        cin>>g;
        total+=g;
    }
    if(n<=2) {
        cout<<-1<<endl;
        return;
    }

    sort(golds.begin(),golds.end());
    // cout<<total<<" ";
    int half = n/2;
    // cout<<half<<" ";
    
    long long toReach = golds[half]*2;
    // cout<<toReach<<" ";

    long long mm = toReach*n-total +1;
    // cout<<mm<<" ";
    mm = max(0ll,mm);

    cout<<mm<<endl;
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n,k;
    cin>>n>>k;
    long long x = k+n-1;
    long long total = (x*(x+1))/2 - (k*(k-1))/2;

    long long minn = total;

    long long i = k+n-1;
    while(total>n*k/2) {
        total-=2*i;
        i--;
    }

    for(;i>=k;i--) {
        // cout<<i<<"-";
        total-=2*i;
        // cout<<total<<" ";
        if(abs(total)>minn) break;
        minn= abs(total);
    }
    // cout<<endl;
    cout<<minn<<'\n';


}

int main(){
    ios_base::sync_with_stdio(false);
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
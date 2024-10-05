#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<long long> nums(n,0);

    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    if(n==1) {cout<<nums[0]<<endl; return;}
    
    if(n==2) {cout<<nums[1]-nums[0]<<endl; return;}

    for(int i=0;i<n-2;i++) {
        nums[n-2] -= nums[i];
    }

    nums[n-1] -= nums[n-2];
    cout<<nums[n-1]<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
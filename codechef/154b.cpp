#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout<<#x<<x<<endl; 

void solve() {
    long long n,k;
    cin>>n>>k;
    vector<long long> nums(n,0);
    bool thruGCD=true;
    bool alreadyK = true;
    bool thruxor = true;
    long long last=-1;

    for(int i=0;i<n;i++){
        cin>>nums[i];

        long long num=nums[i];

        if(!(num==k || (num>k && num%k==0) )) thruGCD= false;

        if(num!=k) alreadyK=false;
        if(last==-1 && num!=k){
            last = num;
        } else if(num!=k && num!=last) thruxor = false;

    }
    if(alreadyK) {
        cout<<0<<endl;
    } else if(thruGCD || thruxor) {
         cout<<1<<endl;
    } else {
         cout<<2<<endl;
    }




}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
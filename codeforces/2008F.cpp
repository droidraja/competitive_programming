#include <bits/stdc++.h>

using namespace std;

int fast_pow(long long base, long long n,long long M) 
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M)
{
    return fast_pow(n,M-2,M);
}

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n,0);
    long long sum=0;
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        sum+=nums[i];
    }


    long double total=0;
    long long mmi = findMMI_fermat((n*(n-1))/2,1000000007);
    // cout<<mmi<<endl; 
    for(auto num:nums) {
  
        total += (num*(sum-num))/(2.0); 
        if(total>=1000000007) total-=1000000007;
    }



    long long tot = (long long)total;
    tot *=mmi;    
    cout<<tot%1000000007<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
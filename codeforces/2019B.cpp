#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    long long left=1;
    long long right = n-1;
    unordered_map<long long,long long> f;
    f[n-1] ++;

    int lastX = nums[0];
    for(int i=1;i<n;i++) {
        
        long long points = nums[i]  - lastX -1;
        long long total_segments = left*right;
        // cout<<points<<" "<<total_segments<<endl;
        f[total_segments] += points;
        right--;
        total_segments = left*right + (left+right);
        f[total_segments]++;
        left++;
        lastX = nums[i];
    }

    for(int i=0;i<q;i++) {
        int k;
        cin>>k;
        cout<<f[k]<<" ";
    }
    cout<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
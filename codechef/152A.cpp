#include <bits/stdc++.h>

using namespace std;

int rem(vector<long long> &nums, int left, int right, int to_remove) {
    if(to_remove==0) return nums[right]-nums[left];

    return min(rem(nums,left+1,right,to_remove-1),rem(nums,left,right-1,to_remove-1));
}

void solve() {
    int n;
    cin>>n;
    vector<long long> nums;

    for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    sort(nums.begin(),nums.end());

    cout<<rem(nums,0,n-1,2)<<endl;
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
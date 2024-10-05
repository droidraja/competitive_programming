#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    int action=1;
    while(nums.size()!=1) {        
        int last = nums.back();
        nums.pop_back();
        int res;
        if(action==1) {
            nums[nums.size()-1] = max(last,nums[nums.size()-1]);    
        } else {
            nums[nums.size()-1] = min(last,nums[nums.size()-1]);
        }
        action *=-1;
    }
    cout<<nums[0]<<endl;
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
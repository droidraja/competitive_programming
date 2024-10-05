#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;

    deque<int> nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    while(k!=0) {
       int front = nums.front();
       int back = nums.back();
       nums.pop_front();
       nums.pop_back();
       nums.push_back(front+back);
       k--;    
    }
    for(auto num:nums) {
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
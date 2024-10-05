#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        // cout<<nums[i]<<" "<<endl;
    }

    // pair<int,int> smallest = {-1,INT_MAX};
    // pair<int,int> largest = {-1,INT_MIN};
    

    int first = -1;
    int last = -1;

    for(int i=0;i<n;i++) {

        if(nums[i]>0) {
            if(first==-1) {
                first=i;
            }
            last = i;
        } 
    }
    if(first==-1) {
        cout<<0<<endl;
        return;
    }
    int negatives=0;
    for(int i=first;i<=last;i++) {
        if(nums[i]<0) negatives++;
    }

    cout<<negatives<<endl;
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
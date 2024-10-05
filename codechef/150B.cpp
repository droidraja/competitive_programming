#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> nums;
    unordered_map<int,int> counts;
    int zeros = 0;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        if(num!=0) {
            counts[num]++;
        } else {
            zeros++;
        }
    }
    int maxCount=0,maxValue;
    long long total = 0;
    // cout<<zeros<<endl;

    for(auto p: counts) {
        // cout<<p.first<<" "<<p.second<<endl;
        if(p.second>maxCount) {
            total += (maxCount*(maxCount-1))/2;
            maxCount=p.second;
            maxValue = p.first;
        } else {
            total += (p.second*(p.second-1))/2;
        }
        // cout<<total<<endl;
    }
    maxCount +=zeros;
    total += (maxCount*(maxCount-1))/2;

    cout<<total<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
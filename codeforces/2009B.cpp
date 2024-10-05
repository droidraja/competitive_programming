#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;

    vector<int> result;
    for(int i=0;i<n;i++) {
        string temp;
        cin>> temp;
        for(int j=0;j<4;j++) {
            if(temp[j]=='#') {
                result.push_back(j+1);
                break;
            }
        }
    }

    reverse(result.begin(),result.end());
    for(auto num:result) {
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
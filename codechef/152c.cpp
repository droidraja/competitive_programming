#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,q;

    cin>>n>>q;

    vector<vector<int>> cnts;
    cnts.push_back({0,0,0});

    int one,two,three;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num==1){
            one++;
        } else if(num==2) {
            two++;

        } else {
            three++;
        }
        cnts.push_back({one,two,three});
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int length = r-l + 1;
        if(length%2==1){
            cout<<"No"<<endl;continue;
        }

        l--;
        r--;
        int ones= cnts[r+1][0]-cnts[l][0];
        int twos= cnts[r+1][1]-cnts[l][1];
        int threes= cnts[r+1][2]-cnts[l][2];
        

    }


}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
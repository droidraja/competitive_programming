#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<long long>> cnts(n,vector<long long>(3,0));

    for(int i=0;i<m;i++) {
        string t;
        cin>>t;

        for(int i=0;i<n;i++) {
            if(t[i]=='0') {
                cnts[i][0]++;
            } else if(t[i]=='1') {
                cnts[i][1]++;
            } else {
                cnts[i][2]++;
            }
        }
    }

    long long score = 0;
    for(int i=0;i<n;i++) {
        long long zero=cnts[i][0],one=cnts[i][1],q=cnts[i][2];
        long long diff = abs(one-zero);
        
        if(q<=diff) {
            if(one<zero) {
                one+=q;
            } else {
                zero+=q;
            }                 
        } else {
            if(one<zero) {
                one=zero;
            } else {
                zero=one;
            }
            q-=diff;
            one += q/2 + q%2;
            zero +=q/2;
        }

        score+=one*zero;

    }
    cout<<score<<endl;


}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
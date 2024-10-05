#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,k;


    cin>>n>>k;
    string a,b;
    cin>>b>>a;

    int cc=1;
    int wrongStart=-1;
    vector<pair<int,char>> results;
    int ccStart=-1,ccEnd;

    for(int i=0;i<n;i++) {
        if(a[i]!=b[i] && wrongStart==-1) {
            wrongStart=i;
        }

        if(i==0) continue;

        if(a[i]==a[i-1]) {
            cc++;
        } else {
            cc=1;
        }
        // cout<<cc<<endl;

        if(cc==k) {
            ccEnd=i;
            ccStart=i-k+1;
            // cout<<ccStart<<" "<<ccEnd<<endl;
            if(wrongStart!=-1) break;
            // cout<<wrongStart<<"cc"<<cc<<"i"<<i-k+1<<endl;
            // if(wrongStart!=-1) {
            //     while(wrongStart<=i-k+1) {
            //         results.push_back({wrongStart+1,a[wrongStart]});    
            //         wrongStart++;
            //     }
            //     wrongStart=-1;
            // }
        }
    }
    if(wrongStart==-1) {
        cout<<0<<endl;
        

    } else if(ccStart!=-1) {
        
        // cout<<n+1<<endl;        
        for(int i=0;i<ccStart;i++) {
            // cout<<i+1<<" "<<a[i]<<endl;
            results.push_back({i+1,a[i]});   
        }
        for(int i=n-1;i-k+1>=ccStart;i--) {
            // cout<<i-k+2<<" "<<a[i]<<endl;
            results.push_back({i-k+2,a[i]});   
        }
        cout<<results.size()<<endl;
        for(auto p:results) {
            cout<<p.first<<" "<<p.second<<endl;
        } 
        
    } else {
        cout<<-1<<endl;
    }


}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
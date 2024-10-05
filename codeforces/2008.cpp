#include <bits/stdc++.h>

using namespace std;

void solve() {
    int ones,twos;

    cin>>ones>>twos;

    if(twos%2==0) {
        if(ones%2==0) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    } else {
        if(ones>0 && ones%2==0) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
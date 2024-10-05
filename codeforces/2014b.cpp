#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    if(k>n) k=n;;
    if(n%2==0) {
        int odds = k/2;
        if(odds%2==0) {
        cout<<"YES"<<endl;

        } else {
        cout<<"NO"<<endl;
        }

    } else {
        int odds = (k+1)/2;
         if(odds%2==0){
            cout<<"YES"<<endl;
        } else {
        cout<<"NO"<<endl;
        }
    }


}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
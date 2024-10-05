#include <bits/stdc++.h>

using namespace std;

vector<long long> multiples;

void solve() {
    long long a,b,k;

    cin>>a>>b>>k;

    int jumps = b/a;

    jumps/=2;
    


}

int main(){
    int tc=1;
    cin>>tc;

    long long last=1;
    multiples.push_back(1);
    multiples.push_back(2);
    cout<<"starting"<<endl;
    for(long long i=1;i<1000000000ll;i++) {
        long long temp = last;
        last = multiples.back();
        multiples.push_back(temp+last);
    }
    cout<<"ended"<<endl;
    while(tc--) solve();
    return 0;
}
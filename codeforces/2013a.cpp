#include <bits/stdc++.h>

using namespace std;

void solve() {
    int total;
    int blender,zhan;
    cin>>total>>blender>>zhan;

    int limiter = min(blender,zhan);

    int result = total/limiter + (total%limiter>0);

    cout<<result<<endl;


}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve() {
int n;


    cin>>n;
    long long sum = 0;
    int smol=INT_MAX;
    int negatives=0;


    for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        if(temp<0) negatives++;
        temp = abs(temp);
        sum+=temp;
        if(temp<smol) smol=temp;
    }
    if(negatives%2==0) {
        cout<<sum<<endl;
    } else {
        cout<<sum-2*smol<<endl;
    }

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
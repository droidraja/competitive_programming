#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;


    int odd_max = INT_MIN;
    int even_max = INT_MIN;
    int is_odd = 1;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(is_odd) {
            odd_max = max(odd_max, temp);    
        } else {
            even_max = max(even_max,temp);
        }
        is_odd ^= 1;
    }
    
    int evens = n/2;
    int odds = n/2 + n%2;
    cout<<max(evens+even_max, odds+odd_max)<<endl;
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve() {
int n;
cin>>n;

unordered_set<int> exes;
unordered_set<int> exOnes;
unordered_set<int> exZeros;


long long doubles=0;
long long totalPoints = 0;
for(int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;

    if(exes.find(x)!=exes.end()) {
        doubles++;
    }
    exes.insert(x);
    totalPoints++;
    if(y==0) exZeros.insert(x);
    if(y==1) exOnes.insert(x);
}

long long total=0;
for(auto x: exOnes) {
    int xZero = x+1;
    int xOne = x+2;
    if(exOnes.find(xOne)!=exOnes.end() && exZeros.find(xZero)!=exZeros.end()) total++;
}
for(auto x: exZeros) {
    int xZero = x+2;
    int xOne = x+1;
    if(exOnes.find(xOne)!=exOnes.end() && exZeros.find(xZero)!=exZeros.end()) total++;
}

cout<<(totalPoints-2)*doubles + total<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
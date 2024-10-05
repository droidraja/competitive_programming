#include <bits/stdc++.h>

using namespace std;

void solve() {
int n;
cin>>n;
vector<pair<int,int>> balls(n);

for(int i=0;i<n;i++) {
    cin>>balls[i].first;
}

for(int i=0;i<n;i++) {
    cin>>balls[i].second;
}

vector<pair<int,long double>> ballTimes(n);

for(int i=0;i<n;i++) {
    ballTimes[i].first = balls[i].first;
    ballTimes[i].second = ((long double)balls[i].first)/balls[i].second;
}

auto comp = [] (pair<int,long double> a, pair<int,long double> b) {
        return a.second < b.second || (a.second==b.second && a.first<b.first);
    };

    sort(ballTimes.begin(),ballTimes.end(),comp);

pair<int,int> last = {0,0};
int total =0;
for(auto balltime:ballTimes) {
    if(balltime.first>last.first) {
        total++;
        last = balltime;
    }
}

cout<<total<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
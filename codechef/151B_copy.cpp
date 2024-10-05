#include <bits/stdc++.h>

using namespace std;

void solve() {
int n;
cin>>n;
vector<pair<long long,long long>> balls(n);

for(int i=0;i<n;i++) {
    cin>>balls[i].first;
}

for(int i=0;i<n;i++) {
    cin>>balls[i].second;
}

// vector<pair<int,long double>> ballTimes(n);

// for(int i=0;i<n;i++) {
//     ballTimes[i].first = balls[i].first;
//     ballTimes[i].second = ((long double)balls[i].first)/balls[i].second;
// }

auto comp = [] (pair<long long,long long> a, pair<long long,long long> b) {
        return a.first*b.second > b.first*b.second;
    };

    sort(balls.begin(),balls.end(),comp);

cout<<balls[0].first<<" "<<balls[0].second<<endl;
pair<long long,long long> last = {0,0};
int total =0;
for(auto balltime:balls) {
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
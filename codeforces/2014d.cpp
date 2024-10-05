#include <bits/stdc++.h>

using namespace std;

bool sortByFirst(pair<int,int> &left, pair<int,int> &right) {
    return left.first<right.first || (left.first==right.first && left.second<right.second);
}

bool sortBySecond(pair<int,int> &left, pair<int,int> &right) {
    return left.second<right.second ;
}
void solve() {
    int n,d,k;

    cin>>n>>d>>k;

    vector<pair<int,int>> jobs;


    vector<long long> jobCount(n+2,0);



    for(int i=0;i<k;i++) {
        int l,r;
        cin>>l>>r;
        jobCount[l]++;
        jobCount[r+1]--;
    }
    int current = 0;
    for(int i=1;i<=n;i++) {
        jobCount[i] += current;
        current = jobCount[i];
    }
    int i=1;
    priority_queue<pair<int,int>> inWin;
    for(;i<=d;i++) {
        inWin.push({jobCount[i],i});
    }

    int bro=inWin.top().first,ma=inWin.top().first;
    int broStart = 1;
    int maStart = 1;
    
    for(;i<=n;i++) {
        inWin.push({jobCount[i],i});
        int start = i-d+1;
        while(inWin.top().second<start) {
            inWin.pop();
        }
        
        int dis = inWin.top().first;

        if(dis>bro) {
            bro = dis;
            broStart=start;    
        }
        if(dis<ma) {
            ma = dis;
            maStart = start;
        }
    }
    cout<<"out"<<broStart<<" "<<maStart<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
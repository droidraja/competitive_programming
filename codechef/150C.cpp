#include <bits/stdc++.h>

using namespace std;

long long gp(int m) {
    long long n = m;
    return (n*(n-1))/2;
} 

void solve() {
    int n;
    cin>>n;
    unordered_map<int,int> counts;
    int zeros = n;
    
    

    int maxCount=0,maxValue=-1;
    long long total = gp(zeros);

    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;

        if(y==maxValue) {
            counts[y]++;
            zeros--;
            maxCount++;
        } else {
            int pCount = counts[y]+1;
            if(pCount>maxCount) {
                long long current = gp(counts[y]);
                long long maxCurrent = gp(maxCount+zeros);
                total-=maxCurrent;
                total+=gp(maxCount);
                total-=current;
                total+=gp(counts[y]+zeros);
                counts[y]++;
                maxCount++;
                maxValue=y;
                zeros--;
            } else {
                total+=counts[y];
                counts[y]++;
                total-=gp(maxCount+zeros);
                zeros--;
                total+=gp(maxCount+zeros);
            }
        }
        cout<<total<<" ";
    }
    cout<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m;
    cin>>m>>n;
    vector<int> a(n,0),b(n,0);
    // cout<<m<<n;
    for(int i=0;i<n;i++) {
        int temp = 0;
        cin>>temp;
        if(temp==1) {
            a[i]=i;
        } else if(temp==2) {
            b[i]==i;
        } else if(temp==3){
            a[i]=i;
            b[i]=i;
        }       
    }

    vector<int> leftSum;
    int last=0;
    for(int i=0;i<n;i++) {
        leftSum.push_back(last+a[i]);
        last=leftSum.back();
    }

    vector<int> rightSum;
    last=0;
    for(int i=n-1;i>=0;i--) {
        // cout<<last<<" ";
        rightSum.push_back(last+a[i]);
        last=rightSum.back();
        cout<<last<<" ";
    }
    cout<<endl;
    reverse(rightSum.begin(),rightSum.end());

    vector<int> leftSumB;
    last=0;
    for(int i=0;i<n;i++) {
        leftSumB.push_back(last+b[i]);
        last=leftSumB.back();
    }

    vector<int> rightSumB;
    last=0;
    for(int i=n-1;i>=0;i--) {
        rightSumB.push_back(last+b[i]);
        last=rightSumB.back();
    }
    reverse(rightSumB.begin(),rightSumB.end());

    // cout<<"computations"<<leftSum.size()<<endl;

    long long aScore=0,bScore=0;
    for(int i=0;i<n;i++) {
          long long aScore=0,bScore=0;
        
        if(i==0) {
            aScore += rightSum[i+1];
            bScore += rightSumB[i+1];
            cout<<aScore<<" "<<bScore<<endl;
            cout<<abs(aScore-bScore)<<" ";
            continue;
        }
        if(i==n-1) {
            aScore += i*i - leftSum[i-1];
            bScore += i*i - leftSumB[i-1];
            cout<<abs(aScore-bScore)<<" ";
            continue;
        }

        aScore += rightSum[i+1]-i*(n-1-i);
        bScore += rightSumB[i+1]-i*(n-1-i);
        aScore += i*i - leftSum[i-1];
        bScore += i*i - leftSumB[i-1];
        cout<<abs(aScore-bScore)<<" ";
        
    }
    cout<<endl;

    return;
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
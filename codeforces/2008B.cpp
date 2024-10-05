#include <bits/stdc++.h>

using namespace std;


bool isPerfectSquare(int num) {
    if (num < 0) {
        return false; 
    }

    int sqrtNum = sqrt(num); 
    return sqrtNum * sqrtNum == num; 
}

bool isValid(int i,int j, char val) {

    return true;
}


void solve() {
    int n;
    cin>>n;
    string inp;
    cin>>inp;
    if(!isPerfectSquare(n)) {
        cout<<"No"<<endl;
        return;
    }
    int r=sqrt(n);
    bool is_valid=true;
    for(int i=0;i<r;i++) {
        for(int j=0;j<r;j++) {
            int index = (i*r+j);
            char val = inp[index];
            if(i==0 || i==r-1 || j==0 || j==r-1) {
                if(val=='0') {
                    is_valid=false;
                    break;
                }
            } else {
                if(val=='1') {
                    is_valid=false;
                    break;
                }
            }

        }
    }
    if(is_valid) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
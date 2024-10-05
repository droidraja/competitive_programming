
#include <bits/stdc++.h>

using namespace std;

void answerRight(string &inp, int n) {
    if(inp.size()==n) return;

    string test0 = inp +"0";
    string test1 = inp +"1";

    cout<<"? "<<test0<<endl;
    int temp;
    cin>>temp;
    if(temp==1) {
        inp=test0;
        answerRight(inp,n);
        return;
    }
    cout<<"? "<<test1<<endl;
    cin>>temp;
    if(temp==1) {
        inp=test1;
        answerRight(inp,n);
    }
}

void answerLeft(string &inp,int n) {
    if(inp.size()==n) return;
    string test0 = "0"+inp;
    string test1 = "1"+inp;

    cout<<"? "<<test0<<endl;
    int temp;
    cin>>temp;
    if(temp==1) {
        inp=test0;
        answerLeft(inp,n);
        return;
    } else {
        inp=test1;
        answerLeft(inp,n);
    }
}


void solve() {
    int n;
    string ans;
    cin>>n;
    cout<<"? 0"<<endl;
    int q;
    cin>>q;
    if(q==1) {
        ans="0";
    } else {
        for(int i=0;i<n;i++) {
            ans+='1';
        }
        cout<<"! "<<ans<<endl;
        return;
    }
    answerRight(ans,n);
    answerLeft(ans,n);
    cout<<"! "<<ans<<endl;
}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
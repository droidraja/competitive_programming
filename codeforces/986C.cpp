#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    map<char,int> mm;

    for(auto c:s) {
        mm[c]++;
    }

    vector<char> result;
    while(mm.size()!=0) {

        for(auto it= mm.begin();it!=mm.end();) {
            (*it).second--;
            result.push_back((*it).first);
            if((*it).second==0) mm.erase(it++); else it++;            
        }
    } 

    cout<<string(result.begin(),result.end())<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
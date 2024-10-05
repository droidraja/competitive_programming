#include <bits/stdc++.h>

using namespace std;

    bool check(int a,int b) {
        if(a==b) return true;
        
        int misMatches=0;
        unordered_set<int> amisses,bmisses;
        
        while(a!=0 ||b !=0) {
            cout<<a<<" "<<b<<endl;
            int arem = a%10;
            int brem = b%10;
            if(arem!=brem){
              misMatches++;
              amisses.insert(arem);
              bmisses.insert(brem);
              if(misMatches>2) break;  
            } 
            a/=10;
            b/=10;
        }
        // cout<<misses.size()<<misMatches<<endl;
        
        for(auto aa:amisses) {
            if(bmisses.find(aa)==bmisses.end()) return false;
        }

        return misMatches==2 && amisses.size()==2;
    } 

void solve() {

    // 12310000
    // 23100010
    cout<<check(2000,2000002002);

}

int main(){
    int tc=1;
    // cin>>tc;

    while(tc--) solve();
    return 0;
}
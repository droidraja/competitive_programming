#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string bin;
    cin>>n;
    cin>>bin;
    vector<char> resultBin;
    long long repeating=0;
    for(int i=0;i<n;i++) {
        if(resultBin.size()==0) {
            resultBin.push_back(bin[i]);
            continue;
        }
        if(bin[i]==resultBin.back()) {
            repeating++;
        } else  {
            resultBin.push_back(bin[i]);
        }
    }

    long long score = (resultBin.size()-1)*(repeating-1);
    long long k = resultBin.size()-1;

    score += ((k)*(k+1))/2;
    cout<<score<<endl;

}

int main(){
    int tc=1;
    cin>>tc;

    while(tc--) solve();
    return 0;
}
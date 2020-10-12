#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int alpha_counts[26] = {0};
        int n = (int) s.size();
        for(int i=0;i<n;i++) {
         alpha_counts[s[i]-'a']++;
        }
        
        vector<char> result;
        int considered[26];
        for(int i=0;i<26;i++) {
            considered[i] = 0;
        }
        
        for(int i=0;i<n;i++) {
            if(result.size()==0) {
                result.push_back(s[i]);
                considered[s[i]-'a'] = 1;
            } else if(considered[s[i]-'a']==0){
        
                while(result.size()!=0 && result.back()>s[i] && alpha_counts[result.back()-'a']!=0) {
                    considered[result.back()-'a'] = 0;
                    result.pop_back();
                }
                result.push_back(s[i]);
                considered[s[i]-'a'] = 1;
            }
            alpha_counts[s[i]-'a']--;
        }
        
        
        
        
        string to_return(result.begin(),result.end());
        return to_return;
    }
};

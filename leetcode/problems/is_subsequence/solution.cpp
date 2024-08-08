class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i=0;
        if(s.size()==0) return true;
        if(s.size()>t.size()) return false;
        for(auto c:t) {
            if(c==s[i]) i++;
            if(i==s.size()) return true;
        }
        return false;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,int> m;
        for(auto c:s) {
            m[c]++;
        }
        for(auto c:t) {
            if(--m[c]<0) return false;
        }

        return true;
    }
};
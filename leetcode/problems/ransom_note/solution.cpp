class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size()) return false;
        unordered_map<char,int> m;
        for(auto c:magazine) {
            m[c]++;
        }

        for(auto c:ransomNote) {
            if(--m[c]<0) {
                return false;
            }
        }

        return true;
    }
};
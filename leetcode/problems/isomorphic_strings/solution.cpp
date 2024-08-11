class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,char> m;
        unordered_set<char> sm;
        for(int i=0;i<s.size();i++) {
            if(m.find(s[i])!=m.end()) {
                if(m[s[i]]!=t[i])
                 return false;
            } else if(sm.find(t[i])!=sm.end()) {
                cout<<s[i]<<" "<<t[i]<<endl;
                return false;
            } 
            else{
                m[s[i]] = t[i];
                sm.insert(t[i]);
            }
        }

        return true;
    }
};
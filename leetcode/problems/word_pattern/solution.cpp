class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> words;
        string word="";
        for(auto c:s) {
            if(c!=' ') {
                word+=c;
            } else {
                words.push_back(word);
                word = "";
            }
        }
        words.push_back(word);

        if(words.size()!=pattern.size()) return false;
        unordered_map<string,char> m;
        unordered_map<char,string> m2;
        for(int i=0;i<words.size();i++) {
            string word = words[i];
            char pc = pattern[i];
            // cout<<word<<" "<<pc<<endl;

            if(m.find(word)!=m.end() || m2.find(pc)!=m2.end()) {
                // cout<<word<<" "<<pc<<" "<<m[word]<<" "<<m2[pc]<<endl;
                if(m[word]!=pc || m2[pc]!=word) {
                    return false;
                }
            } else {
                m[word]=pc;
                m2[pc] = word;
            }
        }
        return true;
    }
};
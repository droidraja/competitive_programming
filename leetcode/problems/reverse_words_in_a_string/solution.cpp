class Solution {
public:
    string reverseWords(string s) {
        

        string current_word = "";
        vector<string> words;
        for(auto c:s) {
            if( c==' ' && current_word!="") {
                words.push_back(current_word);
                current_word = "";
            } else if(c!=' ') {
                current_word+=c;
            }
        }
        string ans="";
        if(current_word!="") ans+=current_word;
        for(int i=words.size()-1;i>=0;i--) {
            if(ans!="") ans+=" ";
            ans+=words[i];
        }
        return ans;
    }
};
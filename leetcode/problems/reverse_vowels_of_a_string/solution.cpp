class Solution {
public:
    string reverseVowels(string s) {
        
        set<char> vowels;
        string vowelsString = "aeiouAEIOU";
        for(char v:vowelsString) 
            vowels.insert(v);
            
        
        vector<char> vowelInS;
        
        for(char a:s) {
            if(vowels.find(a)!=vowels.end()) {
                vowelInS.push_back(a);
            }
        }
        
        int j=vowelInS.size()-1;
        for(int i=0;i<s.size();i++) {
            if(vowels.find(s[i])!=vowels.end()) {
                s[i] = vowelInS[j];
                j--;
            }
        }
        return s;
    }
};
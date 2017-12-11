class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char,int> counts;
        for(char a:magazine)
        {
            if(counts.find(a)!=counts.end())
                counts[a]++;
            else
                counts[a] = 1;
        }
        
        for(char a:ransomNote)
        {
            if(counts.find(a)==counts.end())
                return false;
            
            if(counts[a]==0)
                return false;
            counts[a]--;
        }
        return true;
        
    }
};
class Solution {
public:
    vector<int> partitionLabels(string s) {
       unordered_map<char,int> char_map;
        
        for(char c:s) {
            char_map[c]+=1;
        }
        
        int current_size = 0;
        
        unordered_set<char> toRemove;
        vector<int> partSizes;
        for(char c:s) {
            current_size+=1;
            toRemove.insert(c);
            char_map[c]--;
            
            if(char_map[c]==0) toRemove.erase(c);
            
            if(toRemove.size()==0) {
                partSizes.push_back(current_size);
                current_size=0;
            }
        }
        return partSizes;
        
    }
};
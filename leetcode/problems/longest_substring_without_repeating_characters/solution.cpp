class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> so_far;
        
        int start=0;
        int length = 0;
        int maxLength = 0;
        int n = s.size();
        for(int i=0;i<n;i++) {
            if(so_far.find(s[i])==so_far.end()) {
                length++;
                maxLength = max(maxLength,length);
                so_far[s[i]] = i;
            } else {
                
                while(start<so_far[s[i]]) {
                    so_far.erase(s[start]);
                    start++;
                }
                start = so_far[s[i]]+1;
                so_far[s[i]] = i;
                length = i-start+1;
                
            }
        }
        return maxLength;
        
    }
};
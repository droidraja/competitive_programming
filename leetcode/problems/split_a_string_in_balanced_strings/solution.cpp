class Solution {
public:
    int balancedStringSplit(string s) {
        int total=0;
        int bal=0;
        for(char c:s) {
            if(c=='L') bal--;
            if(c=='R') bal++;
            if(bal==0) {
                total++;        
            }
        }
        return total;
    }
};
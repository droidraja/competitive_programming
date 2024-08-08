class Solution {
public:
    bool isPalindrome(string s) {
        
        string alpha = "";
        for(auto c:s) {
            if(c>='a' && c<='z') {
                alpha += c-'a'+'A';
            }
            if(c>='A' && c<='Z') {
                alpha +=c;
            }
            if(c>='0' && c<='9') {
                alpha+=c;
            }
        
        }
        int left=0;
        int right=alpha.size()-1;

        while(left<right) {
            
            if(alpha[left]!=alpha[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
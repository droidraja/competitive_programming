class Solution {
public:
    
    
    
    string reverseStr(string s, int k) {
        
    for(int i=0;i<s.size();i+=2*k) {
        if(i+k<s.size()){
            for(int j=0;j<k/2;j++) {
            char temp = s[i+j];
            s[i+j] = s[i+k-j-1];
            s[i+k-j-1] = temp;
        }
        } else {
            int l = s.size()-i;
            for(int j=0;j<l/2;j++) {
            char temp = s[i+j];
            s[i+j] = s[i+l-j-1];
            s[i+l-j-1] = temp;
            }
        }
        
        
    }
        return s;
    }
};
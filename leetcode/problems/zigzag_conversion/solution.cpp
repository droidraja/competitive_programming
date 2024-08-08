class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int inc = 2*numRows-2;
        cout<<s.size()<<" "<<inc<<endl;
        if(numRows==1) return s;
       for(int i=0;i<numRows;i++) {
        
        for(int j=i;j<s.size();j+=inc) {
            ans+=s[j];
            if(i!=0 && i!=numRows-1) {
                if(j+2*(numRows-i-1)<s.size()) {
                    ans+=s[j+2*(+numRows-i-1)];
                }
            }
            cout<<ans<<endl;
            cout<<i<<" "<<j<<endl;
        }
       }
       return ans; 
    }
};
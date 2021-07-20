class Solution {
public:
    
    bool isMultiple(string s,string t) {
        if(t.size()>s.size()) return false;
        if(s.size()%t.size()!=0) return false;
        
        int i=0;
        int j=0;
        
        while(i<s.size()) {
            if(s[i]!=t[j]) return false;   
            i++;
            j++;
            j%=t.size();
        }
        return true;
    }
    
    string gcdOfStrings(string str1, string str2) {
        
        if(str2.size()>str1.size()) 
        {
            string temp=str1;
            str1=str2;
            str2=temp;
        }
        
        if(isMultiple(str1,str2)) return str2;
        
        for(int i=str2.size()/2;i>=1;i--) {
            if(str2.size()%i==0 && str1.size()%i==0) {
                string t = str2.substr(0,i);
                if(isMultiple(str1,t) && isMultiple(str2,t))
                    return t;
            }
        }
        return "";
    }
};
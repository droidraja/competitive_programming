class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int start = 0;
        int current = 0;
        if(needle.size()>haystack.size()) return -1;


        for(int i=0;i<haystack.size();) {
            cout<<current<<" "<<start<<endl;
            char c = haystack[i];
            if(needle[current]==c) {
                if(current==0) start=i;
                i++;
                current++;
            } else {
                current=0;
                start+=1;
                i=start;
            }
            
            if(current==needle.size()) {
                return start;
            }
        }
        return -1;
    }
};
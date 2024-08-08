class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int size = strs[0].size();
        for(auto str:strs) {
            int string_size = str.size();
            size = min(size,string_size);
        }

        string ans= "";
        for(int i=0;i<size;i++) {
            int c=' ';
            int done=0;
            for(auto str:strs) {
                if(c==' ') {
                    c = str[i];
                    continue;
                }
                if(c!=str[i]) {
                    done=1;
                    break;
                }
            }
            if(done) break;
            ans+=c;
        }
        return ans;
    }
};
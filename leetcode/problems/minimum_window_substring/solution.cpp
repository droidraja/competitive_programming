class Solution {
public:
    string minWindow(string s, string t) {

        //index t

        unordered_map<char,int> index;

        for(int i=0;i<t.size();i++) {
            index[t[i]]++;
        }

        int totalKeys=0;
        int start=0;
        vector<int> window;
        int minStart = -1;
        int minEnd = s.size();
        unordered_map<char,int> c;

        int end=start;
        while(start<s.size()) {
            // cout<<"before"<<"start"<<start<<"end"<<end<<"keys"<<totalKeys<<endl;

            while(totalKeys<index.size() && end<s.size()) {
                char key = s[end];
                if(index.find(key)!=index.end()) {
                    c[key]++;
                    if(c[key]==index[key]) totalKeys++;
                }
                end++;
            }
            if(totalKeys!=index.size()) break;
            // cout<<"start"<<start<<"end"<<end<<"keys"<<totalKeys<<endl;
            if(minEnd-minStart+1>end-start) {
                // cout<<"set min"<<endl;
                minStart= start;
                minEnd=end-1;
            }
            char key = s[start];
            // cout<<"key"<<key<<endl;
            if(index.find(key)!=index.end()) {
                // cout<<"came here "<<key<<" "<<c[key]<<" "<<index[key]<<endl;
                c[key]--;
                if(c[key]<index[key]) totalKeys--;
            }
            start++;
        }
        // cout<<minStart<<minEnd<<endl;
        return (minStart==-1)?"":s.substr(minStart,minEnd-minStart+1);

    }
};
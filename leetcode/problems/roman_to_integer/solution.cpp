class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        
        vector<int> vals;
        
        for(char c:s) {
            vals.push_back(val[c]);
        }
        
        int prev = 1001;
        int total = 0;
        for(int v:vals) {
            if(prev<v) {
                total -= 2*prev;
            }
            total+=v;
            prev = v;
        }
        
        return total;
        
    }
};
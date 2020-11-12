class Solution {
public:
    
    void permuteHelper(vector<vector<int>> &accum,int length,int n,unordered_map<int,int> cnts,vector<int> &current) {
        
        if(length==n) {
            vector<int> copy = current;
            accum.push_back(copy);
            return;
        }
        for(auto i: cnts) {
            if(i.second!=0) {
                cnts[i.first]--;
                current.push_back(i.first);
                length++;
                permuteHelper(accum,length,n,cnts,current);
                current.pop_back();
                length--;
                cnts[i.first]++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> currentTemp;
        vector<vector<int>> accum;
        unordered_map<int,int> cnts;
        
        for(auto i:nums) {
            if(cnts.find(i)!=cnts.end()) {
                cnts[i]++;
            } else {
                cnts[i] = 1;
            }
        }
        
        permuteHelper(accum,0,nums.size(),cnts,currentTemp);
        return accum;
    }
};
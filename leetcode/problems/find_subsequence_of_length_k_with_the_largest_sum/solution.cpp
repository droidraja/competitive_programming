class Solution {
public:
    bool static sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
        {
            return (a.second > b.second);
        }
    
    
        bool static sortbyfirst(const pair<int,int> &a,
              const pair<int,int> &b)
        {
            return (a.first < b.first);
        }


    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> nums_2;
        for(int i=0;i<nums.size();i++) {
            nums_2.push_back(make_pair(i,nums[i]));
        }
        sort(nums_2.begin(),nums_2.end(),sortbysec);
        
        vector<pair<int,int>> result;
        for(int i=0;i<k;i++) {
            result.push_back(nums_2[i]);
        }
        sort(result.begin(),result.end(),sortbyfirst);
        
        vector<int> finalResult;
        
        for(auto elem:result) {
            finalResult.push_back(elem.second);
        }
        return finalResult;
        
    }
};
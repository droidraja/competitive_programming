class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> m;

        for(auto &s:strs) {
            auto sSorted = s;
            sort(sSorted.begin(),sSorted.end());
            m[sSorted].emplace_back(s);
        }

        vector<vector<string>> answer;
        for(auto i: m){
            answer.push_back(i.second);
        }
        return answer;

    }
};
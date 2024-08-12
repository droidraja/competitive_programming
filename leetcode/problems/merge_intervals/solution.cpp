class Solution {
    static bool compare(vector<int> &intervalA, vector<int> & intervalB) {
        return intervalA[0]<intervalB[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(), compare);

        vector<vector<int>> answer;
        if(intervals.size()==0) return answer;
        vector<int> currentInterval = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(currentInterval[1]>=intervals[i][0]) {
                currentInterval[1] = max(currentInterval[1],intervals[i][1]);
            } else {
                answer.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        answer.push_back(currentInterval);
        return answer;
    }
};
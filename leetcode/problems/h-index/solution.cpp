class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort(citations.begin(),citations.end());
        int hIndex=0;
        for(int i=0;i<citations.size();i++) {
            if(citations[i]>=citations.size()-i) {
                hIndex=citations.size()-i;
                break;
            }
        }

        return hIndex;        
    }
};
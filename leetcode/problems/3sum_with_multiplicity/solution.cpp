class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int> seen;
        if(arr.size()<3) return 0;
        long long so_far = 0;
        seen[arr[0]] = 1;
        for(int i=1;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                int two_sum = arr[i]+arr[j];
                if(seen[target-two_sum]!=0) {
                    so_far = (so_far + seen[target-two_sum])%1000000007l;
                }
            }
            seen[arr[i]] = seen[arr[i]]+1;
        }
        return so_far;
    }
};
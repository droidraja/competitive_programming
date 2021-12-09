class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int visited[arr.size()];
        for(int i=0;i<arr.size();i++) {
            visited[i] = 0;
        }
        
        vector<int> positions;
        
        positions.push_back(start);
        
        while(positions.size()!=0) {
            int pos = positions.back();
            if(visited[pos]==1) {
                positions.pop_back();
                continue;
            }
            positions.pop_back();
            visited[pos]=1;
            if(arr[pos]==0) return true;
            int left = pos-arr[pos];
            int right = pos+ arr[pos];
            if(left>=0&&visited[left]==0) {
                positions.push_back(left);
            }
            if(right<arr.size()&&visited[right]==0) {
                positions.push_back(right);
            }
            
        }
        return false;
        
    }
};
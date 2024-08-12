class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        ios_base::sync_with_stdio(false);

        // vector<vector<int>> arrows;
        sort(points.begin(),points.end());
        vector<int> current = points[0];
        int arrows=0;
        for(int i=1;i<points.size();i++) {
            if(points[i][0]<=current[1]) {
                current[0] = points[i][0];
                current[1] = min(current[1],points[i][1]);
            } else{
                arrows++;
                current[0] = points[i][0];
                current[1] = points[i][1];
            }
        }
        arrows++;
        return arrows;
    }   

};
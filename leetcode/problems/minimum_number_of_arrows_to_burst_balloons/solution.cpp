#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    static bool sortBaloons(vector<int> &b1,vector<int> &b2) {
        return b1[1]<b2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),sortBaloons);
        long currentEnd = LONG_MIN;
        cout<<currentEnd;
        int arrowsShot = 0;
        for(vector<int> point:points) {
            if(point[0]>currentEnd) {
                arrowsShot++;
                currentEnd = point[1];
            }
        }
        return arrowsShot;
    }
};
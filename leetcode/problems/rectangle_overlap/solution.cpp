class Solution {
public:
    
    bool isWithin(vector<int>& rec,int x,int y) {
        
        if((x>rec[0] && y>rec[1])) {
            if((x<rec[2] && y<rec[3])) {
                return true;
            }
        
        }
        
        return false;
    }
    
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        int x1 = max(rec1[0],rec2[0]);
        int y1 = max(rec1[1],rec2[1]);
        int x2 = min(rec1[2],rec2[2]);
        int y2 = min(rec1[3],rec2[3]);
        
        if(x1>=x2 || y1>=y2) return false;
        return true;
    }
};
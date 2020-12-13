class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int jewelCount=0;
        for(auto stone: S) {
            for(auto jewel: J) {
                if(stone==jewel) {
                    jewelCount++; 
                    break;
                }
            }
        }
        return jewelCount;
    }
};
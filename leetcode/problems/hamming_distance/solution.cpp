class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = x ^ y;
        int diff=0;
        while(result!=0) {
            diff += result%2;
            result = result>>1;
        }
        return diff;
    }
};
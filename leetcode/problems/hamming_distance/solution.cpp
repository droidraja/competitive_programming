class Solution {
public:
    int countSetBits(int number) {
        int setBits = 0;
        while(number!=0) {
            if(number & 1) setBits++;
            number = number>>1;
        }
        return setBits;
    }
    int hammingDistance(int x, int y) {
        //doing xor of two ints sets the bits for which x and y bits are diff
        int different_bits = x^y;
        return countSetBits(different_bits);
    }
};
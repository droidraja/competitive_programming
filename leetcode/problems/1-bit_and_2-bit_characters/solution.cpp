class Solution {
public:
    
    bool hasTwoBitCharacter(vector<int>& bits,int index) {
        if(index>=bits.size()-1) return false;
        
        if(index==bits.size()-2) {
            if(bits[index]==1) {
                return true;
            } else return false;
        }
        
        if(bits[index]==1) {
            return hasTwoBitCharacter(bits,index+2);
        } else {
            return hasTwoBitCharacter(bits,index+1);
        }
        
        
    }
    
    bool isOneBitCharacter(vector<int>& bits) {
        return !hasTwoBitCharacter(bits,0);
    }
};
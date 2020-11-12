class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        if(typed.size()<name.size()) {
            return false;
        }
        int n = (int) name.size();
        int j=0;
        char prevTyped = '~';
        for(int i=0;i<n;) {
            if(j==typed.size()){
                return false;
            }
            if(name[i]==typed[j]) {
                prevTyped=typed[j];
                i++;
                j++;
                continue;
            }
            if(prevTyped==typed[j]) {
                j++;
                continue;
            } else {
                return false;
            }
        }
        
        while(j<typed.size()) {
            if(prevTyped==typed[j]) {
                j++;
            } else {
                return false;
            }
        }
        
        return true;
    }
};
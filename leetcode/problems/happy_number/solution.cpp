class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;

        for(;n!=1 && n>0 && visited.find(n)==visited.end();) {
            int newN=0;
               visited.insert(n);
            while(n!=0) {
                newN = newN + (n%10)*(n%10);
                n/=10;
            }
         
            n=newN;
        }

        if(n==1) return true; else return false;
        
    }
};
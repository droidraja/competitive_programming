class Solution {
public:
    bool winnerSquareGame(int n) {
        
        if(n==1) {
            return true;
        } else if(n==2) {
            return false;
        } else if(n==2) {
            return true;
        }
        
        
        bool dp[n+1];
        dp[1] = true;
        dp[2] = false;
        dp[3] = true;
        
        for(int i=4;i<=n;i++) {
            dp[i] = false;
            int sq = floor(sqrt(i));
            if(sq*sq==i) {
                dp[i] = true;
            } else {
                for(int j=1;j<=sq;j++) {
                    if(!dp[i-j*j]) {
                        dp[i]=true;    
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
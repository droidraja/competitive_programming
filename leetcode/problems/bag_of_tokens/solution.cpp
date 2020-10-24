class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int n = (int) tokens.size();
        int i = 0;
        int j = n-1;
        int score = 0;
        int maxScore = 0;
        while(i<=j){
            if(P>=tokens[i]){
                score++;
                maxScore = max(score,maxScore);
                P-=tokens[i];
                i++;
            } else {
                if(score==0) {
                    break;
                }
                P+=tokens[j];
                score--;
                j--;
            }
            
        }
        return maxScore;
        
    }
};
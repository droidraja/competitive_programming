class Solution {
public:
    static int solve(int *alpha_cnts) {
        int local = 0;
        for(int i=0;i<26;i++) {
            if(alpha_cnts[i]!=0) {
                local+=1;
                alpha_cnts[i]--;
                local+=solve(alpha_cnts);
                alpha_cnts[i]++;
            }
        }
        return local;
    }
    
    int numTilePossibilities(string tiles) {
        int alpha_cnts[26];
        for(int i=0;i<26;i++) {
            alpha_cnts[i] = 0;
        }
        int n = (int) tiles.size();
        for(int i=0;i<n;i++) {
            alpha_cnts[tiles[i]-'A']++;
        }
        return solve(alpha_cnts);
    }
};
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        

        int i=0;
        int w=0;
        int n=blocks.size();
        while(i<k) {
            if(blocks[i]=='W') w++;
            i++;
        }
        int min_w=w;
        while(i<n) {
            if(blocks[i-k]=='W') w--;
            if(blocks[i]=='W') w++;
            min_w = min(min_w,w);
            i++;
        }
        return min_w;
    }
};
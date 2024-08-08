class Solution {
public:
    string removeDigit(string number, char digit) {
        
        int count=0;
        for(auto c:number) {
            if(c==digit) {
                count++;
            }
        }

        string ans;
        for(int i=0;i<number.size();i++) {
            char c= number[i];
            if(count==1 && c==digit) {
                count--;
                continue;
            }

            if(c==digit&& count>0){
                count--;
                if(c<number[i+1]) {
                    count=0;
                    continue;
                }
            }
            ans+=c;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
       
        vector<int> B = A;
        reverse(B.begin(),B.end());
        int carry = 0;
        vector<int> result;
        for(int i=0;i<B.size() || K!=0;i++) { 
            int r = 0;
            r+=carry;
            if(K!=0){
                r+= K%10;
                K/=10;
            }
            if(i<B.size()) {
                r +=B[i];
            }
            carry = r/10;
            result.push_back(r%10);
        }
        if(carry==1) {
            result.push_back(1);
        }
        
        reverse(result.begin(),result.end());
        return result;
        
    }
};
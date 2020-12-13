class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        
        int A_sum = 0;
        int B_sum = 0;
        
        for(auto a:A) {
            A_sum += a;
        }
        
        for(auto b:B) {
            B_sum += b;
        }
        
        int final_individual_amt = (A_sum+B_sum)/2;
        
        unordered_set<int> bob_candies;
        for(auto b:B) {
            bob_candies.insert(b);
        }
        
        //consider each candy for exchange; if alice wants to exchange candy of size a, find if the required candy is available with bob.
        // final_individual_amt = A_sum - a + b;
        // b/required_candy = final_individual_amt - A_sum + a;
        vector<int> ans;
        for(auto a:A) {
            int required_candy = final_individual_amt - A_sum +a;
            if(bob_candies.find(required_candy)!=bob_candies.end()) {
                ans.push_back(a);
                ans.push_back(required_candy);
                break;
            }
            
        }
        return ans; 
    }
};
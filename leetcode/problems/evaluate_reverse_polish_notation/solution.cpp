class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        for(auto &tok:tokens) {
            int num1,num2;
            if(tok.size()>1 || (tok[0]>='0' && tok[0]<='9')) {
                nums.push_back(stoi(tok));
                continue;
            }

            switch(tok[0]){
                case '+':
                 num2 = nums.back(); nums.pop_back();
                 num1 = nums.back(); nums.pop_back();
                 nums.push_back(num1+num2);
                 break;
                case '-':
                 num2 = nums.back(); nums.pop_back();
                 num1 = nums.back(); nums.pop_back();
                 nums.push_back(num1-num2);
                 break;
                case '*':
                 num2 = nums.back(); nums.pop_back();
                 num1 = nums.back(); nums.pop_back();
                 nums.push_back(num1*num2);
                 break;
                case '/':
                 num2 = nums.back(); nums.pop_back();
                 num1 = nums.back(); nums.pop_back();
                 nums.push_back(num1/num2);
                 break;
            }
        }
        return nums[0];
    }
};
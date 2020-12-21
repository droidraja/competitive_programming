class Solution {
public:
    bool isValid(string s) {
        stack<char> openBrackets;
        
        for(char symbol:s) {
            if(symbol==')' || symbol==']' || symbol=='}') {
                if(openBrackets.size()==0) {
                    return false;
                }
                char last = openBrackets.top();
                openBrackets.pop();
                char shouldBe;
                switch(symbol) {
                    case ')':
                        shouldBe= '(';
                        break;
                    case '}':
                        shouldBe = '{';
                        break;        
                    case ']':
                        shouldBe = '[';
                        break;
                }
                if(last!=shouldBe) {
                    return false;
                }
            } else {
                openBrackets.push(symbol);
            }
        }
        return openBrackets.size()==0;
        
    }
};
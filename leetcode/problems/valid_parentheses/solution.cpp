class Solution {
public:
    bool isValid(string s) {
        
        vector<char> myStack;
        string opens = "({[";

        for(auto ch:s) {
            if(ch=='(' || ch=='{' || ch=='[') {
                myStack.push_back(ch);
            } else {
                if(myStack.size()==0) return false;
              if(myStack.size()==0) return false;
              char last = myStack[myStack.size()-1];
              bool matching=false;
              switch(last) {
                  case '(': matching = ch==')';break;
                  case '{': matching = ch=='}';break;
                  case '[': matching = ch==']';break;
              }
              if(!matching) return false; 
              myStack.pop_back();
            }
        }

        return myStack.size()==0;
    }
};
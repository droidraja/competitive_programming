class Solution {
public:
    bool isValid(string s) {
        
        vector<char> myStack;
        string opens = "({[";

        for(auto ch:s) {
            if(ch=='(' || ch=='{' || ch=='[') {
                cout<<"pushing "<<ch<<endl;
                myStack.push_back(ch);
            } else {
                if(myStack.size()==0) return false;
                cout<<"Checking close of "<<ch<<" last char: "<<myStack[myStack.size()-1]<<endl;
              if(myStack.size()==0) return false;
              char last = myStack[myStack.size()-1];
              bool matching=false;
              switch(last) {
                  case '(': matching = ch==')';break;
                  case '{': matching = ch=='}';break;
                  case '[': matching = ch==']';break;
              }
              cout<<"mathcin"<<matching<<endl;
              if(!matching) return false; 
              myStack.pop_back();
            }
        }

        return myStack.size()==0;
    }
};
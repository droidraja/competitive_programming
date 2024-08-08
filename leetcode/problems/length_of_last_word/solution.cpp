class Solution {
public:
    int lengthOfLastWord(string s) {

       int encounteredSpace = 0;

       int currentWord = 0;
       for(auto c:s) {
        if(c!=' ') {
            if(encounteredSpace) {
                currentWord=1;
            } else {
                currentWord+=1;
            }
            encounteredSpace=0;
        } else {
            encounteredSpace=1;
        }
       }
       return currentWord; 
    }
};
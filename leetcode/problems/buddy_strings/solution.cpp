class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if(A.size()!=B.size()) {
            return false;
        }
        int n = (int) A.size();
        bool wrong = false;
        bool done = false;
        char a,b;
        bool alphas[26]={false};
        bool done2=false;

        for(int i=0;i<n;i++) {
            if(A[i]!=B[i]) {
                if(done) {
                    return false;
                }
                if(wrong){
                    if(A[i]==b && B[i]==a) {
                        done=true;                        
                    } else {
                        return false;
                    }
                } else {
                    a=A[i];
                    b=B[i];
                    wrong=true;
                }
            } else {
                bool alreadyFound = alphas[A[i]-'a'];
                if(alreadyFound) {
                    done2=true;
                } else {
                    alphas[A[i]-'a']=true;
                }
            }
        }
        if((done&&wrong) || (!wrong && done2)){
            return true;
        } else {
            return false;
        }
            
        
    }
};
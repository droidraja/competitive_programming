class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = (int) asteroids.size();
        vector<int> stack;
        
        for(int i=0;i<n;i++) {
            if(stack.size()==0) {
                stack.push_back(asteroids[i]);
            } else {
                if(asteroids[i]<0) {
                    int asteroidSize = -1 * asteroids[i];
                    bool destroyed = false;
                    while(stack.size()!=0 &&stack.back()>0&&stack.back()<=asteroidSize && !destroyed) {
                        destroyed = stack.back()==asteroidSize;
                        stack.pop_back();
                    }
                    if(!destroyed) {
                        if(stack.size()==0 || stack.back()<0) {
                        stack.push_back(asteroids[i]);
                        }    
                    }
                    
                } else {
                    stack.push_back(asteroids[i]);
                }
            }
        }
        
        return stack;
    }
};
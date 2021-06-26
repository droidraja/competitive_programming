class Solution {
public:
    int min(int a,int b) {
        return (a>b)?b:a;
    }
    vector<string> commonChars(vector<string>& words) {
        
        unordered_map<char,int> char_map;
        bool init = true;
        for(string word:words) {
            if(init) {
                init=false;
                for(char character:word) {
                    char_map[character]+=1;
                }
            }
            unordered_map<char,int> local_map;
            for(char character:word) {
                local_map[character] +=1; 
            }
            unordered_map<char,int> final_map;
            for(pair<char,int> pp:char_map) {
                if(local_map.find(pp.first)!=local_map.end()) {
                    final_map[pp.first] = min(local_map[pp.first],char_map[pp.first]);
                }
            }
            char_map = final_map;
        }
        
        vector<string> results;
        for(pair<char,int> pp:char_map) {
            for(int i=0;i<pp.second;i++) {
                string a;
                a+=pp.first;
                results.push_back(a);    
            }
            
        }
        return results;
    }
};
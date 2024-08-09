class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        int wordLength = words[0].size();
        int n = s.size();
        int totalWords = words.size();
        if(n<totalWords*wordLength) return answer;
        unordered_map<string,int> wordMap;
        for(int i=0;i<totalWords;i++) {
                if(wordMap.find(words[i])==wordMap.end()) wordMap[words[i]]=0;
                wordMap[words[i]]++;
        }
        

        for(int i=0;i<wordLength;i++) {
            //have to do sliding window part for each 
            unordered_set<int> soFar;
            int fail=0;
            
            unordered_map<string,int> m;

            int occurredWords = 0;
            int start=i;
            for(int j=i;j+wordLength-1<n;j+=wordLength) {
                cout<<"j"<<j<<"i"<<i<<"start"<<start<<endl;

                string currentWord = s.substr(j,wordLength);
                cout<<currentWord<<endl;
                if(wordMap.find(currentWord)!=wordMap.end()) {
                    
                    m[currentWord]++;
                    occurredWords++;

                    while(m[currentWord]>wordMap[currentWord]) {
                        string startWord = s.substr(start,wordLength);
                        m[startWord]--;
                        occurredWords--;
                        start+=wordLength;
                    }

                    if(occurredWords==words.size()) {
                        answer.push_back(start);
                    }
                } else {
                    m.clear();
                    occurredWords = 0;
                    start = j+wordLength;
                }
            }
        } 
        return answer;
    }
};
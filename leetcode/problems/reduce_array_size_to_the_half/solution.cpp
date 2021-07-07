class Solution {
public:
    static bool sortBySec(const pair<int,int> &a,const pair<int,int> &b) {
        return a.second>b.second;    
    }
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> cnt_map;
        for(auto e:arr) {
            if(cnt_map.find(e)==cnt_map.end()) cnt_map[e]=0;
            cnt_map[e]++;
        }
        
        vector<pair<int,int>> e_freq;
        
        for(pair<int,int> e: cnt_map) {
            e_freq.push_back(e);
        }
        
        sort(e_freq.begin(),e_freq.end(),sortBySec);
        
        int set_cnt=0;
        int removed_elems=0;
        for(pair<int,int> e:e_freq) {
            cout<<e.first<<" "<<e.second<<endl;
            if(removed_elems>=arr.size()/2) break; 
            set_cnt++;
            removed_elems+=e.second;
         }
    return set_cnt;
    }
};
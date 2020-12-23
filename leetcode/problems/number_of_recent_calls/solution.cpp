class RecentCounter {
public:
    queue<int> pings;
    RecentCounter() {
    }
    
    int ping(int t) {
        while(pings.size()!=0 && pings.front()<(t-3000)) {
            pings.pop();
        }
        pings.push(t);
        return pings.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
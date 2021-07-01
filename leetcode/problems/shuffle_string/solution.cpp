class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        int visited[indices.size()]; 
        
        int n = indices.size();
        
        for(int i=0;i<n;i++) {
            visited[i] = 0;
        }
        for(int i=0;i<n;i++) {
            
            int j=i;
            char currentTemp = s[j];
            while(visited[indices[j]]==0) {
                cout<<i<<" "<<j<<endl;
                visited[indices[j]]=1;
                char temp = s[indices[j]];
                s[indices[j]] = currentTemp;
                currentTemp=temp;
                j=indices[j];
            }
        }
    return s;
    }
};
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> a;
        for(vector<int> row: image ) {
            
            for(int i=0;i<row.size()/2;i++) {
                int temp = row[i];
                row[i] = row[row.size()-1-i];
                row[row.size()-1-i] = temp;
                row[i] ^= 1;
                row[row.size()-1-i] ^= 1;
            }
            if(row.size()%2==1) {
                row[row.size()/2] ^= 1;
            }
            a.push_back(row);
            
        }
        return a;
    }
};
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rows = A.size();
        if(rows==0) return A;
        int cols = A[0].size();
        if(cols==0) return A;
        
        //first flip the image 
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols/2;j++) {
                int temp = A[i][j];
                A[i][j] = A[i][cols-1-j];
                A[i][cols-1-j] = temp;
            }
        }
        
        //invert the image
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                A[i][j] = (A[i][j]==0)?1:0;
            }
        }
        
        return A;
    }
};

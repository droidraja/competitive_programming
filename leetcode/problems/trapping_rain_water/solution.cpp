class Solution {
public:
    int trap(vector<int>& height) {
      int n= height.size();
      int max_so_far=0;
      vector<int> left;
      for(int i=0;i<n;i++) {
        left.push_back(max_so_far);
        max_so_far = max(max_so_far,height[i]);
      }
      
      max_so_far=0;
      vector<int> right;
      for(int i=n-1;i>=0;i--) {
        right.push_back(max_so_far);
        max_so_far = max(max_so_far,height[i]);
      }
      
      int total_water = 0;
      for(int i=0;i<n;i++) {
        int j = n-1-i;
        total_water += max(0,min(left[i],right[j])-height[i]);
      }  
      return total_water;
    }
};
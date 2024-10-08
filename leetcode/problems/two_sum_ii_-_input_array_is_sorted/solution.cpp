class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i=0, j=numbers.size()-1;
        vector<int> result(2,0);
        while(i<j) {
            if(numbers[i]+numbers[j]>target) {
                j--;
            } else if(numbers[i]+numbers[j]<target) {
                i++;
            } else {
                result[0] = i+1;
                result[1]=j+1;
                return result;
            }
        }
        return result;
    }
};
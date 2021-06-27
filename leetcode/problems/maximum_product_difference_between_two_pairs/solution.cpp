class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        int firstMax=0,secondMax = 0;
        int firstMin=10001, secondMin = 10001;
        
        for(int num:nums) {
            
            if(num>secondMax) {
                secondMax = num;
                
                if(secondMax>firstMax) {
                    int temp = secondMax;
                    secondMax = firstMax;
                    firstMax = temp;
                }
                
            }  
            if (num<secondMin) {
                secondMin = num;
                if(secondMin<firstMin) {
                    int temp = secondMin;
                    secondMin = firstMin;
                    firstMin = temp;
                }
                
            }
        }
        cout<<firstMax<<" "<<secondMax<<endl;
        cout<<firstMin<<" "<<secondMin<<endl;
        return (firstMax*secondMax)-(firstMin*secondMin);
    }
};
class Solution {
public:
    int addDigits(int num) {
        
        int temp = num;
        
        while(temp>9)
        {
            int temp2=0;
            while(temp!=0)
            {
                temp2 += temp%10;
                temp = temp/10;
            }
            temp = temp2;
        }
        return temp;
    }
};
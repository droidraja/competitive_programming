class Solution {
public:
    int subtractProductAndSum(int n) {
        
        //Initialize to identity of the operation, for sum it is zero
        // for multiplication it is 1
        int product = 1;
        int sum = 0;
        
        //As a good practice using a temp variable to avoid the loss of value of n.
        int temp = n;
        while(temp!=0) {
            int lastDigit = temp%10;
            sum = sum + lastDigit;
            product = product * lastDigit;
            
            
            temp = temp/10;
        }
     return product-sum;   
    }
};
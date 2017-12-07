class Solution {
public:
    string intToRoman(int num) {
        string romans[] = {"I","V","X","L","C","D","M"};
        
        string finalResult = "";
        int temp = num;
        int index = 0;
        while(temp!=0)
        {
            if(temp%10!=0)
            {
                int dec = temp%10;
                if(dec<4)
                {
                    for(int i=0;i<temp%10;i++)
                    {
                        finalResult = romans[index]+finalResult;
                    }
                } else
                if(dec==4)
                {
                    finalResult = romans[index]+romans[index+1]+finalResult;
                } else
                if(dec==5)
                {
                    finalResult = romans[index+1] +finalResult;
                }
                else
                if(dec<9)
                {
                    
                    for(int i=5;i<dec;i++)
                    {
                        finalResult = romans[index]+finalResult;
                    }
                    finalResult = romans[index+1] +finalResult;
                }
                else
                {
                    finalResult = romans[index] + romans[index+2] + finalResult;
                }
            }
            
            temp = temp/10;
            index = index+2;
        }
        
        return finalResult;
    }
};
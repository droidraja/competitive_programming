class Solution {
public:
    string intToRoman(int num) {
    unordered_map<int,char> m;
	m[1] = 'I'; 
	m[5] = 'V'; 
	m[10] = 'X'; 
	m[50] = 'L'; 
	m[100] = 'C'; 
	m[500] = 'D'; 
	m[1000] = 'M'; 


    unordered_map<int,string> m2;
    string roman = ""; 
    while(num!=0) {
        int temp  = num; int c=1;
        while(temp>10) {temp/=10; c*=10;}
        if(temp==4 || temp==9) {
            roman+= m[c];
            roman+= m[c*(temp+1)];
            num -= temp*c;
            continue;
        }

        if(num>=1000) {
            roman+=m[1000];
            num-=1000;
        } else if(num>=500) {
            roman+=m[500];
            num-=500;
        } else if(num>=100) {
            roman+=m[100];
            num-=100;
        } else if(num>=50) {
            roman+=m[50];
            num-=50;
        } else if(num>=10) {
            roman+=m[10];
            num-=10;
        } else if(num>=5) {
            roman+=m[5];
            num-=5;
        } else {
            roman+=m[1];
            num-=1;
        }
    }
    return roman;
    }
};
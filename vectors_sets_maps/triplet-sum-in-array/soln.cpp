#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--) {
	    int n;
	    int x;
	    cin>>n;
	    cin>>x;
	    vector<int> numbers;
	    
	    for(int i=0;i<n;i++) {
	        int temp;
	        cin>>temp;
	        numbers.push_back(temp);
	    }
	    bool found = false;
	    for(int i=0;i<n-2;i++) {
	        unordered_set<int> c_numbers;
	        for(int j=i+1;j<n;j++) {
	            int a = numbers[i];
	            int b = numbers[j];
	            int a_plus_b = a + b;
	            int c = x-a_plus_b;
	            if(c_numbers.find(c)!=c_numbers.end()){
	               found=true;
	               break;
	            } else {
	                c_numbers.insert(b);
	            }
	        }
	        if(found) break;
	    }
	    if(found) {
	        cout<<1<<endl;
	    } else {
	        cout<<0<<endl;
	    }
	    
	}
	return 0;
}

class Solution {
public:

    struct Node{
        int first;
        int last;
        Node* next=nullptr;
    };
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        if(nums.size()==0) return answer;
        Node* list = new Node();
        Node* iter = list;
        iter->first = nums[0];
        iter->last=nums[0];
        for(int i=1;i<nums.size();i++) {
            cout<<nums[i]<<" "<<iter->first<<" "<<iter->last<<endl;
            if(nums[i]-1==nums[i-1]){
                iter->last=nums[i];
            } else {
                iter->next = new Node();
                iter = iter->next;
                iter->first=nums[i];
                iter->last=nums[i];
            }
        }

        iter = list;
        while(iter!=nullptr) {
            if(iter->first==iter->last) {
                answer.push_back(to_string(iter->first));
            }else{
                cout<<iter->first<<" "<<iter->last<<endl;
                string range = to_string(iter->first)+"->"+to_string(iter->last);
                answer.push_back(range);
            }
            iter=iter->next;
        }
        return answer;
    }
};
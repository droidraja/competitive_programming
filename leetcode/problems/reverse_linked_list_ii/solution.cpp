/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int start = 1;
        ListNode *startNode = head;
        while(start<left) {
            startNode = startNode->next;
            start+=1;
        }
        
        ListNode *iterNode = startNode;
        vector<int> stack;
        
        while(start<=right) {
            stack.push_back(iterNode->val);
            iterNode = iterNode->next;
            start+=1;
        }
        
        start = left;
        iterNode = startNode;
        while(start<=right) {
            iterNode->val= stack.back();
            stack.pop_back();
            iterNode = iterNode->next;
            start+=1;
        }
        return head;
    }
};
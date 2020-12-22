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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* prev = nullptr;
        ListNode* iter = head; 
        while(iter!=nullptr) {
            
            if(iter->val==val && prev!=nullptr) {
                prev->next = iter->next;
            } else {
                prev = iter;    
            }
            iter = iter->next;
        }
        
        if(head!=nullptr && head->val==val) {
            return head->next;
        } else {
            return head;
        }
    }
};
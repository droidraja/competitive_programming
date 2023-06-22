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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* mergedList = new ListNode();
        ListNode* pointer = mergedList;

    while(list1!=nullptr && list2!=nullptr) {
        ListNode* smaller;
        if(list1->val<list2->val) {
            smaller = list1;
            list1 = list1->next;
        } else {
            smaller = list2;
            list2 = list2->next;
        }

        pointer->next= new ListNode(smaller->val);
        pointer = pointer->next;            
    }
    if(list1!=nullptr) {
        pointer->next = list1;
    } else {
pointer->next = list2;
    }

    return mergedList->next;
    }
};
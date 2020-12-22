/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// if n is size of list A
// if m is size of list B
// then time complexity is O(n*m) ==> simplied O(N^2) assuming n==m

// Time complexity: O(N^2) Space complexity: O(1)

// ListNode* list_one = headA;
// while(list_one!=nullptr) {
//     ListNode* list_two = headB;
//     while(list_two!=nullptr) {
//         if(list_one==list_two) {
//             return list_one;
//         }
//         list_two = list_two->next;
//     }
//     list_one = list_one->next;
// }
// return nullptr;

//time complexity: O(N) space complexity O(N)

// unordered_set<ListNode *> pointers;
//         for(ListNode* temp=headA;temp!=nullptr;temp=temp->next) {
//             pointers.insert(temp);
//         }
        
//         for(ListNode* temp=headB;temp!=nullptr;temp=temp->next) {
//             if(pointers.find(temp)!=pointers.end()) {
//                 return temp;
//             }
//         }
        
//         return nullptr; 


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1 = 0, size2=0;    
        
        for(ListNode* temp=headA;temp!=nullptr;temp=temp->next) {
            size1++;
        }
        for(ListNode* temp=headB;temp!=nullptr;temp=temp->next) {
            size2++;
        }

        if(size1>size2) {
            for(int i=0;i<size1-size2;i++) {
                headA = headA->next;
            }
        } else if(size2>size1) {
            for(int i=0;i<size2-size1;i++) {
                headB = headB->next;
            }
        }
        
        while(headA&&headB) {
            if(headA==headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;



    }
    
};
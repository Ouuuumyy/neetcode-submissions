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
        ListNode start(0);
        ListNode *merged = &start;

        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                merged->next = list1;
                list1 = list1->next; 
            }
            else
            {
                merged->next = list2;
                list2 = list2->next;  
            }
            merged = merged->next;
        }

        merged->next = list1 ? list1 : list2;
        return start.next;
    }   
};

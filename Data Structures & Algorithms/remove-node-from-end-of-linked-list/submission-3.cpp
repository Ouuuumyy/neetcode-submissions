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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //dummy node solution
        ListNode dummy(0, head);
        ListNode *first = &dummy;
        ListNode *second = &dummy;
        
        int i = 0;
        while(i <= n)
        {
            first = first->next;
            i++;
        }

        while(first)
        {
            second = second->next;
            first = first->next;
        }

        ListNode *to_delete = second->next;
        second->next = second->next->next;
        delete to_delete;
        return dummy.next;
    }
};

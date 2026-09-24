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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        
        ListNode res(0);
        ListNode *tmp = &res;
        while(l1 || l2)
        {
            int val1 = 0;
            int val2 = 0;
            if(l1)
            {
                val1 = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            sum =  val1 + val2 + carry;
            carry = sum /10;
            ListNode *node = new ListNode(sum % 10);
            tmp->next = node;
            tmp = tmp->next;
        }
        if(carry)
            tmp->next = new ListNode(carry);
        

        return res.next;
    }
};

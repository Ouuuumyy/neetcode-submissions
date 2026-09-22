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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        int len = 0;
        ListNode *tmp = head;
        while(tmp)
        {
            tmp = tmp->next;
            len++;
        }
        ListNode *first_half = head;
        int i = 0;
        while(i < len / 2)
        {
            i++;
            head = head->next;
        }
        ListNode *second_half = head->next;
        head->next = nullptr;
        ListNode *curr = second_half;
        ListNode *prev = nullptr;
        while(curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        second_half = prev;
        head = first_half;
        while(first_half && second_half)
        {
            ListNode *temp1 = first_half->next;
            ListNode *temp2 = second_half->next;
            first_half->next = second_half;
            second_half->next = temp1;
            second_half = temp2;
            first_half = temp1;
        }
        
    }
};

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
        if(!head || !head->next)
            return nullptr;
        int len = 0;
        ListNode *tmp = head;
        while(tmp)
        {
            len++;
            tmp = tmp->next;
        }
        if(n > len)
            return head;
        tmp = head;
        int i = 0;
        int pos = len - n;
        if(pos == 0)
            return head->next;
        while(i < pos - 1)
        {
            tmp = tmp->next;
            i++;
        }
        if(tmp->next->next)
            tmp->next = tmp->next->next;
        else
            tmp->next = nullptr;
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 递归
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode node(1);
        ListNode* head0 = &node;
        head0->next = head;

        ListNode* pre = head0;
        while (pre->next && pre->next->next) {
            ListNode* start = pre->next;
            ListNode* end = pre->next->next;
            start->next = end->next;
            end->next = start;
            pre->next = end;
            pre = start;
        }
        return head0->next;
    }
};
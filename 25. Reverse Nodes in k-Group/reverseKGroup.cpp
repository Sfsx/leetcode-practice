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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode node(1);
        ListNode* head0 = &node;
        head0->next = head;

        ListNode* pre = head0;
        ListNode* end = head0;
        while(end->next) {
            ListNode* start = pre->next;
            for(int i = 0; i < k && end; i++) {
                end = end->next;
            }
            if (!end->next) break;
            ListNode* next = end->next;
            end->next = NULL;
            pre->next = reserve(start)
            
        }
    }
};
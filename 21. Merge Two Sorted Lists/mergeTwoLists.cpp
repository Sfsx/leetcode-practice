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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res;
        if (l1 == NULL) return res = l2;
        if (l2 == NULL) return res = l1;
        res = l1->val <= l2->val ? l1 : l2;

        ListNode* walk1 = l1;
        ListNode* walk2 = l2;

        while(walk2 != NULL) {
            if (walk1->val <= walk2->val) {
                while(walk1->next != NULL && walk1->next->val <= walk2->val) {
                    walk1 = walk1->next;
                }
                ListNode* newWakl1 = walk1->next;
                walk1->next = walk2;
                if (newWakl1 == NULL) return res;

                while(walk2->next != NULL && walk2->next->val <= newWakl1->val) {
                    walk2 = walk2->next;
                }
                ListNode* newWalk2 = walk2->next;
                walk2->next = newWakl1;
                if (newWalk2 == NULL) return res;

                walk1 = newWakl1;
                walk2 = newWalk2;
            } else {
                ListNode* mid = walk1;
                walk1 = walk2;
                walk2 = mid;
            }
        }
        return res;
    }
};
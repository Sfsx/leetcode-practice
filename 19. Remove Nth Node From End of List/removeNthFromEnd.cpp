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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
        	return head;
		}
        ListNode *slow = head;
		ListNode *fast = head;
        int slow_cnt = 1, fast_cnt = 1;
        while(fast->next != NULL && fast->next->next != NULL) {
    		slow = slow->next;
    		fast = fast->next->next;
    		slow_cnt++;
    		fast_cnt += 2;		
		}
		if(fast->next != NULL) {
			fast_cnt++;
			fast = fast->next;
		}
        int nodeRemoved = fast_cnt - n + 1;

        if (nodeRemoved == 1) {
            ListNode *rem = head;
			head = head->next;
			delete rem;
        } else {
            ListNode *walk = nodeRemoved > slow_cnt ? slow : head;
            int i = nodeRemoved > slow_cnt ? slow_cnt : 1;
            for(; i + 1 < nodeRemoved; i++) {
                walk = walk->next;
            }
            ListNode *rem = walk->next;
            walk->next = walk->next->next;
            delete rem;
        }
        return head;
    }
};

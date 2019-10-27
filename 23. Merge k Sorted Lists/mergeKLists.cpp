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
    /**
     * - 遍历所有链表，将所有节点的值放到一个数组中。
     * - 将这个数组排序，然后遍历所有元素得到正确顺序的值。
     * - 用遍历得到的值，创建一个新的有序链表。 
     * 
     * - 时间复杂度：O(NlogN)，其中 N 是节点总数
     *   - 遍历所有的值需要花费 O(N) 的时间
     *   - 一个稳定的排序算法花费 O(NlogN) 的时间。
     *   - 遍历同时创建新的有序链表花费 O(N) 的时间。
     * - 空间复杂度：O(N)
     *   - 排序花费 O(N) 空间（这取决于你的算法）。
     *   - 创建一个新的链表花费 O(N) 的空间。
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> res;
        for(int i = 0; i < lists.size(); i++) {
            ListNode* walk = lists[i];
            while(walk != NULL) {
                res.push_back(walk);
                walk = walk->next;
            }
        }
        
        sort(res.begin(), res.end(), [](auto x,auto y){ return ((x->val) < (y->val));});
        if (res.size() == 0) { return NULL; }
        for(int j = 0; j < res.size() - 1; j++) {
            res[j]->next = res[j + 1];
        }
        res[res.size() - 1]->next = NULL;
        return res[0];
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> res;
        for(int i = 0; i < lists.size(); i++) {
            ListNode* walk = lists[i];
            while(walk != NULL) {
                res.push_back(walk);
                walk = walk->next;
            }
        }
        
        sort(res.begin(), res.end(), [](auto x,auto y){ return ((x->val) < (y->val));});
        if (res.size() == 0) { return NULL; }
        for(int j = 0; j < res.size() - 1; j++) {
            res[j]->next = res[j + 1];
        }
        res[res.size() - 1]->next = NULL;
        return res[0];
    }
};
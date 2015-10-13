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
     * @param head a ListNode
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *p = head, *q = head;
        ListNode *last = NULL, *begin = NULL, *next = NULL, *prev = NULL;
        ListNode dummy(0);
        dummy.next = head;
        int i, val;
        while (p) {
            begin = p;
            for (i = 0; i < k - 1 && p != NULL; ++i) {
                p = p->next;
            }
            if ((i < k - 1) || (p == NULL)) {
                return dummy.next;
            }
            next = p->next;
            prev = next;
            while (q != next) {
                ListNode *tmp = q->next;
                q->next = prev;
                prev = q;
                q = tmp;
            }
            if (last == NULL) {
                last = begin;
                dummy.next = p;
            } else {
                last->next = p;
                last = begin;
            }
            p = q;
        }
        return dummy.next;
    }
};

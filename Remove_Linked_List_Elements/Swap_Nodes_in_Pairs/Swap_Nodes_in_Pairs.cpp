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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = head, *q = head->next, *prev = &dummy, *next = NULL;
        while (q != NULL) {
            if (q->next != NULL) {
                next = q->next;
            } else {
                next = NULL;
            }
            p->next = next;
            q->next = p;
            prev->next = q;
            prev = p;
            if (next != NULL) {
                p = next;
                q = next->next;
            } else {
                break;
            }
        }
        return dummy.next;
    }
};

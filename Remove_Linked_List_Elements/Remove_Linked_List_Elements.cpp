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
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        if (head == NULL) {
            return NULL;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        while(p->next != NULL) {
            if (p->next->val == val) {
                ListNode *tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            } else {
                p = p->next;
            }
        }
        
        return dummy.next;
    }
};

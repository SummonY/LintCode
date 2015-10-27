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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        int len = listLength(head);
        ListNode *p = head, *q = head, *past = NULL;
        for (int i = 1; i < len / 2; ++i) {
            q = q->next;
        }
        if (len % 2 == 0) {
            past = q->next;
        } else {
            past = q->next->next;
        }
        q->next = NULL;
        past = reverse(past);
        return isSame(p, past);
    }
    bool isSame(ListNode *l1, ListNode *l2) {
        ListNode *p = l1, *q = l2;
        while (p != NULL && q != NULL) {
            if (p->val != q->val) {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        if (p != NULL || q != NULL) {
            return false;
        }
        return true;
    }
    int listLength(ListNode *head) {
        int length = 0;
        ListNode *p = head;
        while(p != NULL) {
            ++length;
            p = p->next;
        }
        return length;
    }
    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL;
        while (head) {
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};

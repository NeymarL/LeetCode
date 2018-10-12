/**
 * 25 Reverse Nodes in k-Group
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * Example:
 *     Given this linked list: 1->2->3->4->5
 *     For k = 2, you should return: 2->1->4->3->5
 *     For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *     Only constant extra memory is allowed.
 *     You may not alter the values in the list's nodes, only nodes itself may be changed.
 *
 * Another solution: https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11413/Share-my-Java-Solution-with-comments-in-line
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (!head) {
            return NULL;
        }
        ListNode *pre = NULL, *t = NULL;
        ListNode *p = head, *next = NULL, *tmp = NULL, *q = NULL;
        bool can_divide = true;
        while (p) {
            bool need_reverse = false;
            bool has_head = (pre != NULL);
            int i = 0;
            tmp = p;
            while (tmp) {
                t = tmp;
                tmp = tmp->next;
                i++;
                if (i == k) {
                    need_reverse = true;
                    break;
                }
            }
            next = tmp;
            if (!need_reverse) {
                if (pre)
                    pre->next = p;
                can_divide = false;
                break;
            }
            tmp = p->next;
            if (!pre) {
                p->next = next;
            } else {
                pre->next = t;
            }
            pre = p;
            for (int i = 0; i < k - 1; i++) {
                if (i == k - 2 && !has_head) {
                    head = tmp;
                }
                q = tmp->next;
                tmp->next = p;
                p = tmp;
                tmp = q;
            }
            p = next;
        }
        if (can_divide) {
            if (pre)
                pre->next = p;
        }
        return head;
    }
};


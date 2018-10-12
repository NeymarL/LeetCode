/**
 * #24 Swap Nodes in Pairs
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * Example:
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Note:
 *     Your algorithm should use only constant extra space.
 *     You may not modify the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* swapPairs(ListNode* head) 
    {
        if (!head) {
            return NULL;
        }
        ListNode *pre = NULL, *p = head, *q = head->next, *next = NULL;
        while (p) {
            q = p->next;
            if (q) {
                next = q->next;
                if (pre) {
                    pre->next = q;
                } else {
                    head = q;
                }
                p->next = next;
                q->next = p;
            } else {
                break;
            }
            pre = p;
            p = next;
        }
        return head;
    }
};

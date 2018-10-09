/**
 * 合并两个排序的链表
 * https://leetcode.com/problems/merge-two-sorted-lists/
 *
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *head = NULL, *p = NULL;
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        while (l1 && l2) {
            if (!head) {
                if (l1->val < l2->val) {
                    head = l1;
                    p = l1;
                    l1 = l1->next;
                } else {
                    head = l2;
                    p = l2;
                    l2 = l2->next;
                }
                continue;
            }
            if (l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        while (l1) {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
        while (l2) {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
        return head;
    }
};

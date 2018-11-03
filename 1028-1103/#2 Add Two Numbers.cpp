/**
 * 2. Add Two Numbers
 * https://leetcode.com/problems/add-two-numbers/
 * 
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example:
 *      Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *      Output: 7 -> 0 -> 8
 *      Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode *p, *root = NULL;
        while (l1 && l2) {
            if (!root) {
                root = new ListNode((l1->val + l2->val + carry) % 10);
                if (l1->val + l2->val + carry >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                p = root;
            } else {
                ListNode* q = new ListNode((l1->val + l2->val + carry) % 10);
                if (l1->val + l2->val + carry >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                p->next = q;
                p = q;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            ListNode* q = new ListNode((l1->val + carry) % 10);
            if (l1->val + carry >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            p->next = q;
            p = q;
            l1 = l1->next;
        }
        while (l2) {
            ListNode* q = new ListNode((l2->val + carry) % 10);
            if (l2->val + carry >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            p->next = q;
            p = q;
            l2 = l2->next;
        }
        if (carry) {
            ListNode* q = new ListNode(carry);
            p->next = q;
        }
        return root;
    }
};

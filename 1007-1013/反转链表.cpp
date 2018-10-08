/**
 * 反转链表
 * https://leetcode.com/problems/reverse-linked-list/
 *
 * 输入一个链表，反转链表后，输出新链表的表头。
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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *p = NULL, *next = NULL;
        while (head) {
            next = head->next;
            head->next = p;
            p = head;
            head = next;
        }
        return p;
    }
};

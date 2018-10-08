/**
 * 链表中倒数第k个结点
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/solution/
 *
 * 输入一个链表，输出该链表中倒数第k个结点。
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
        ListNode *first = pListHead, *second = NULL;
        int i = 1;
        while (first) {
            if (i == k) {
                second = pListHead;
            }
            if (i > k && second) {
                second = second->next;
            }
            first = first->next;
            i++;
        }
        return second;
    }
};

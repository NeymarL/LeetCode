/**
 * 删除链表中重复的结点
 * https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 * 
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
 * 重复的结点不保留，返回链表头指针。 
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode *pre = NULL, *head = pHead, *p = pHead;
        while (p) {
            if (p->next && p->val == p->next->val) {
                while (p->next && p->val == p->next->val) {
                    p = p->next;
                }
                p = p->next;
                if (pre) {
                    pre->next = p;
                } else {
                    head = p;
                }
            } else {
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};

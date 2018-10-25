/**
 * 链表中环的入口结点
 * https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 * 
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
 */

#include <iostream>
#include <unordered_set>

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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        unordered_set<ListNode*> set;
        while (pHead) {
            if (set.find(pHead) != set.end()) {
                return pHead;
            }
            set.insert(pHead);
            pHead = pHead->next;
        }
        return NULL;
    }
};

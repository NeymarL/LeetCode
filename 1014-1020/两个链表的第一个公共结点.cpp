/**
 * 两个链表的第一个公共结点
 * https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 * 
 * 输入两个链表，找出它们的第一个公共结点。
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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
    {
        unordered_set<ListNode*> set;
        ListNode* p = pHead1;
        while (p) {
            set.insert(p);
            p = p->next;
        }
        p = pHead2;
        while (p) {
            if (set.find(p) != set.end()) {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
};


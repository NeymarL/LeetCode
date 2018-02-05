/**
 * 141. Linked List Cycle
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * Given a linked list, determine if it has a cycle in it.
 * 
 * Follow up:
 * Can you solve it without using extra space?
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) 
{
    set<ListNode*> s;
    ListNode* p = head;
    while (p) {
        if (s.find(p) != s.end()) {
            return true;
        }
        s.insert(p);
        p = p->next;
    }
    return false;
}

/**
 * 1. Use two pointers, walker and runner.
 * 2. Walker moves step by step. runner moves two steps at time.
 * 3. If the Linked List has a cycle walker and runner will meet at some point.
 */
bool hasCycleClever(ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return false;
    }
    ListNode *walker = head, *runner = head->next;
    while (runner && runner->next) {
        if (walker == runner) {
            return true;
        }
        walker = walker->next;
        runner = runner->next->next;
    }
    return false;
}

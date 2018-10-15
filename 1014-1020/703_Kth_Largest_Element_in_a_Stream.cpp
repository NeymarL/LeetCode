/**
 * 703. Kth Largest Element in a Stream
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * 
 * Design a class to find the kth largest element in a stream. 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Your KthLargest class will have a constructor which accepts an integer k and an integer 
 * array nums, which contains initial elements from the stream. For each call to the method 
 * KthLargest.add, return the element representing the kth largest element in the stream.
 * 
 * Example:
 *      int k = 3;
 *      int[] arr = [4,5,8,2];
 *      KthLargest kthLargest = new KthLargest(3, arr);
 *      kthLargest.add(3);   // returns 4
 *      kthLargest.add(5);   // returns 5
 *      kthLargest.add(10);  // returns 5
 *      kthLargest.add(9);   // returns 8
 *      kthLargest.add(4);   // returns 8
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct comp {
    bool operator() (const int a, const int b) const {
        return a > b;
    }
};

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) 
    {
        this->k = k;
        for (int num: nums) {
            pq.push(num);
        }
        while (pq.size() > k) {
            pq.pop();
        }
    }
    
    int add(int val) 
    {
        if (pq.empty() || pq.size() < k) {
            pq.push(val);
            return pq.top();
        }
        if (val <= pq.top()) {
            return pq.top();
        }
        pq.pop();
        pq.push(val);
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, comp> pq;
    int k = 0;
};

int main()
{
    int k = 1;
    vector<int> nums;
    KthLargest kl(k, nums);
    cout << kl.add(-3) << endl;
    cout << kl.add(-2) << endl;
    cout << kl.add(-4) << endl;
    cout << kl.add(0) << endl;
    cout << kl.add(4) << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> nums, int total_score)
{
    if (nums.size() == 1) {
        return nums[0] + total_score;
    }
    int max_score = 0;
    int n = nums.size();
    int tmp, score = 0;
    for (int i = 0; i < n; i++) {
        tmp = nums[i];
        if (i > 0 && i < nums.size() - 1) {
            score = nums[i - 1] * nums[i] * nums[i + 1];
        } else if (i > 0) {
            score = nums[i - 1] * nums[i];
        } else if (i < nums.size() - 1) {
            score = nums[i] * nums[i + 1];
        } else {
            score = nums[i];
        }
        nums.erase(nums.begin() + i, nums.begin() + i + 1);
        max_score = max(max_score, solution(nums, total_score + score));
        nums.insert(nums.begin() + i, tmp);
    }
    return max_score;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << solution(nums, 0) << endl;
    return 0;
}

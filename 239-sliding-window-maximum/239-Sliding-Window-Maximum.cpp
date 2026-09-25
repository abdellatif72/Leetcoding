class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        const int& n = nums.size();
        vector<int> next_larger(n, -1);
        deque<int> qu;

        for (int i = 0; i < n; i++) {
            while (!qu.empty() && i - qu.front() >= k) {
                qu.pop_front();
            }

            while (!qu.empty() && nums[qu.back()] <= nums[i]) {
                qu.pop_back();
            }

            if (!qu.empty()) next_larger[i] = qu.front();

            qu.push_back(i);
        }

        int l = 0;
        for (int r = k - 1; r < n; l++, r++) {
            if (next_larger[r] != -1) {
                ret.push_back(nums[next_larger[r]]);
            } else {
                ret.push_back(nums[r]);
            }
        }

        return ret;
    }

};
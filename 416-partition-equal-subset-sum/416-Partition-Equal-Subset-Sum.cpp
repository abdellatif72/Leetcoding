class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(begin(nums), end(nums), 0);
        if(s&1) return false;

        s/=2;

        bitset<10005> dp;
        dp[0] = 1;

        for(int num : nums){
            dp |= (dp << num);
        }

        return dp[s];
    }
};
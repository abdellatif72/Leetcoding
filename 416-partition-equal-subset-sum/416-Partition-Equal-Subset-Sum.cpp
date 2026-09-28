class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
            for the sum of 2 subsets to be equal, say x
            then the sum of the original array is 2x
            which is an even number
            -> if the sum of array is odd, then return false

            if we could choose a subset that already have sum of x, then we know that other numbers forms sum of x too
            and we return true

            alright, how to know if i can make a specific sum value from an array or not?

            find(x, idx) = find(x-nums[idx], idx+1)
        */

        const int &n = (int)nums.size();
        int x = 0;
        for(const int &num : nums){
            x+=num;
        }
        if(x&1) return false;
        x/=2;

        vector<vector<int>> dp(20005, vector<int>(205, -1));

        function<int(int,int)> findx = [&](int target, int idx){
            if(idx>=n){
                if(target == 0) return 1;
                return 0;
            }
            
            if(target == 0) return 1;
            if(target<0)    return 0;

            int &ret = dp[target][idx];
            if(ret!=-1) return ret;

            ret = 0;

            int go = findx(target-nums[idx], idx+1);
            int skip = findx(target, idx+1);

            ret = go|skip;

            return ret;
        };

        return findx(x, 0);
    }
};
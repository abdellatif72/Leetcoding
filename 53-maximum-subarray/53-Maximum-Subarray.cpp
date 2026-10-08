class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = -1e5;
        int current = -1e5;
        for(int i = 0; i < nums.size(); ++i){
            current = max(current + nums[i], nums[i]);
            ret = max(ret, current);
        }
        return ret;
    }
};
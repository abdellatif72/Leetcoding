class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> can(nums.size(), false);
        can[0] = true;
        int ptr = 1;
        for(int i = 0; i < nums.size(); i++){
            while(ptr<nums.size() && ptr-i <= nums[i] && can[i]){
                can[ptr++] = true;
            }
        }
        return can[nums.size()-1];
    }
};
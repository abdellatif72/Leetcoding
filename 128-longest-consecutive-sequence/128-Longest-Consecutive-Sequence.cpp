class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = 1;
        unordered_set <int> s (begin(nums),end(nums));
        for(int num : s){
            if(!s.count(num-1)){
                int streak = 1;
                int next_value = num+1;
                while(s.count(next_value)){
                    streak++;
                    next_value++;
                }
                ans = max(ans, streak);
            }
        }
        return ans;
    }
};
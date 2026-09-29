class Solution {
public:

    // this solution works also in case that numbers are not sorted
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();

        int bad = 0;

        vector<int> frq(1e4 * 2 + 10);
        
        const int M = 1e4;

        for(int i = 0; i < n; i++){
            nums[i-bad] = nums[i];
            if(++frq[nums[i]+M] > 2){
                bad++;
            }
        }

        return n-bad;
    }
};
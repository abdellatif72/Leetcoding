class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> frq(101);
        for(const int num : nums) ++frq[num];
        vector<int> ret;
        ret.reserve(nums.size());
        while(true){
            bool found = false;
            for(int i = 0; i <= 100; i++){
                if(frq[i]){
                    ret.push_back(i);
                    --frq[i];
                    found = true;
                }
            }
            if(!found) break;
        }
        return ret;
    }
};
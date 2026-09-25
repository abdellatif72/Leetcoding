class Solution {
public:
    int countSequences(vector<int>& nums, long long k) {
        const int &n  = (int)(nums.size());
        
        // [idx][mult][divide]
        using ll = long long;
        map<array<ll,3>, int> dp;
        
        function<int(ll,ll,ll)> go = [&](
            ll idx,
            ll mult,
            ll divide
        ) {
            if(idx>=n){
                if(mult%divide == 0){
                    mult/=divide;
                    if(mult==k){
                        return 1;
                    }
                } 
                return 0;
            }

            array<ll,3> arr = {idx, mult, divide};
            if(dp.count(arr)) return dp[arr];

            dp[arr] = 0;

            return dp[arr] = go(idx+1, mult*nums[idx], divide)
                  +go(idx+1, mult, divide*nums[idx])
                  +go(idx+1, mult, divide);
        };

        return go(0,1,1);
    }

};
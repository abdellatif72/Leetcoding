class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = false;
        const int n = (int)s.size();
        vector<int> dp(n+1, -1);
        unordered_set ust (begin(wordDict),end(wordDict));
        function<int(int)> go = [&] (int r){
            if(r>=n) return 1;

            if(dp[r]!=(-1)) return dp[r];

            dp[r] = 0;
            int &ret = dp[r];

            string cur = "";
            while(r<n){
                cur.push_back(s[r]);
                if(ust.contains(cur)){
                    ret |= go(r+1);
                }
                r++;
            }

            return ret;
        };

        ans |= (bool)go(0);
        return ans;
    }
};
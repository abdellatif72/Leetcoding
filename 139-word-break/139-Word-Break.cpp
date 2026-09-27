class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = false;
        const int n = (int)s.size();
        using T = pair<int, string>;
        map<T,bool> dp;
        unordered_set ust (begin(wordDict),end(wordDict));
        function<bool(int,string)> go = [&] (int r, string cur){
            if(r>=n) return true;

            T t = make_pair(r, cur);
            if(dp.count(t)) return dp[t];

            dp[t] = false;
            bool &ret = dp[t];

            while(r<n){
                cur.push_back(s[r]);
                if(ust.contains(cur)){
                    ret |= go(r+1, "");
                }
                r++;
            }

            return ret;
        };
        ans |= go(0,"");
        return ans;
    }
};

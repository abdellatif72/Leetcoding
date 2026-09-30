class Solution {
public:
    int dp[1001][1001];
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof dp);
        return solve(s, 0, s.size() - 1);
    }
    int solve(string& s, int l, int r) {
        if (l == r)
            return 1;
        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        dp[l][r] = 0;

        // take it
        if (s[l] == s[r]) {
            dp[l][r] = 2 + solve(s, l + 1, r - 1);
        }
        // leave it
        else {
            dp[l][r] = max(dp[l][r], solve(s, l + 1, r));
            dp[l][r] = max(dp[l][r], solve(s, l, r - 1));
        }

        return dp[l][r];
    }
};
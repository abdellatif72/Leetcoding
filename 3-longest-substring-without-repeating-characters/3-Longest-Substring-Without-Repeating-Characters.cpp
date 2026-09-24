class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> frq(127,0);
        const int &n = (int)s.size();
        int l = 0;
        int ans = 0;
        for(int r = 0; r < n;){
            frq[s[r]-'\0']++;
            while(frq[s[r]-'\0']>1){
                frq[s[l++]-'\0']--;
            }
            ans = max(ans, r-l+1);
            r = max(r+1, l);
        }

        return ans;
    }
};
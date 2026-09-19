class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = 46340, m, ans=r;
        while(l<=r){
            m = (l+r)/2;
            if(m*m<=x) {
                ans = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return ans;
    }
};